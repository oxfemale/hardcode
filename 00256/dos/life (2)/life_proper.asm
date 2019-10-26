;
;  LIFE - a 256b intro
;  made by -SP- ^ lce
;  released in May 2012
;
;  Graphical implementation of The Game Of Life 
;  by John Horton Conway, 1970
;
;  Short description: each pixel represent a cell, and each cell can have two states: alive or dead.
;  Dead pixels are black, alive pixels are colored. Color intensity corresponds to the cell's lifetime.
;  During each iteration, the following rules are applied:
;  1) Living cells with fewer than two live neighbours die
;  2) Living cells with two or three live neighbours live on
;  3) Living cells with more than three live neighbours die
;  4) Dead cells with exactly three live neighbours become alive
;
;  The state map of cells are stored at FS:[0-64000] with values 1 (alive) or 0 (dead)
;  After each iteration, video memory at ES is updated based on the values in FS
;
;  This is the proper version of the algorithm
;


org 100h                  ; so here we go

mov ax, 13h               ; 320x200x8
int 10h                   ; video mode

push 0a000h               ; video memory in ES
pop es
push 08000h
pop ds
push 09000h               ; cell state segment in FS
pop fs

mov cx, 64000             ; clear the whole cell state block, set each cell to dead state
clear:
mov di, cx
mov [fs:di], bx           ; bx shall be 0 here
mov [ds:di], bx           
loop clear

mov cx, 64000
init:
mov di, cx
in al, 40h                ; with not-perfectly random seeding of the initial configuration
shr al, 7                 ; we put 1 or 0
mov [fs:di], al           ; into the cell state
mov [ds:di], al           
loop init



pal:	                    ; palette tampering to achieve the reddish color
mov	dx, 0x3c8
mov	al, cl
out	dx, al
inc	dx
and al, 0xff
out	dx, al
and al, 0x00
out	dx, al
out	dx, al
loop	pal

main_loop:

mov dx,03DAh              ; vertical sync
vsync:
in al,dx
test al,8
jz vsync  
    
mov cx, 64000             ; okay, fun begins here
updatestate:                
mov di, cx                ; DI -> pixel (cell) position
mov al, [fs:di]           ; fetch the current cell
mov [ds:di], al
xor bl, bl

add bl, [fs:di+1]         ; -
add bl, [fs:di-1]         ;  \ 
add bl, [fs:di+320]       ;   -- yeah, this is pretty horrible. eats up space and damn slow, gotta find a way to optimize.
add bl, [fs:di-320]       ;   -- anyway, for each cell we check the 8 adjacent cells in FS
add bl, [fs:di+321]       ;   -- and sum their values (if the adjacent cell is alive, BL will be incremented by one, otherwise no change)
add bl, [fs:di-321]       ;   -- later we check the value of BL to decide what to do with the cell
add bl, [fs:di+319]       ;  /
add bl, [fs:di-319]       ; -

cmp al, 0                 ; now, if the current cell state is zero, it's dead
jnz living                ; otherwise it's alive

dead:                     ; when the cell is DEAD
cmp bl, 3                 ; check if the adjacent living cells' count equals to 3
jnz next                  ; if not, skip the whole thing, cell remains dead
lives:                    ; if yes, the cell becomes alive
mov byte [ds:di], 1       ; set cell state to 1
jp next                   ; and move on to the next cell in the iteration

living:                   ; when the cell is ALIVE
cmp bl, 2                 ; check if the adjacent living cells' count equals to 2
jz grows                  ; 
cmp bl, 3                 ; or equals to 3
jz grows                  ;
dies:                     ; if not, the cell dies
mov byte [ds:di], 0       ; set state to 0
jmp next                  ; next iteration
grows:                    ; if the cell is alive, and has 2 or 3, then it's "aging"
mov byte [ds:di], 2
next:                     ;
loop updatestate          ; and on to the next iteration

mov cx, 64000             ; here we check the updates to the pixels and apply them
applystate:               ; this is to avoid udpated pixels affecting the others in the previous iteration series
mov di, cx
mov al, [ds:di]
mov [fs:di], al
cmp al, 0
jz cell_dies
cmp al, 1
jz cell_born
mov dl, [es:di]            ; fetch current "age", which is represented by it's color value in ES
add dl, 4                  ; increment the age
cmp dl, 128                ; but set a maximum to avoid overflow (actually not necessary, it won't reach the upper limit)
jnz grow                   ;
mov dl, 127                ; 
grow:                      ;
mov [es:di], dl            ; update pixel color with the new value
mov byte [fs:di], 1 
jmp next_cell
cell_dies:
mov byte [es:di], 0
jmp next_cell
cell_born:
mov byte [es:di], 1
jmp next_cell
next_cell:
loop applystate

in al, 60h                ; ESC test
dec al                    ; to exit program
jnz main_loop

mov ax, 03h               ; back to textmode
int 10h

ret                       ; yay.

