
;**************************************************************************
; LandScape over my fractal - Alberto Garcia-Baquero, Jul'96
;
; WiseFX - Ali�N '96.
;**************************************************************************
;==========================================================================
; CONSTANTES
;==========================================================================
VGA            EQU 0A000h       ;Segmento de la posici�n de inicio de la VGA
AnchoPanta     EQU 320
AltoPanta      EQU 200

	      .MODEL TINY
	      .386
	      .CODE
	       ORG 100h

;========================================================================
; CODIGO
;========================================================================

Main    PROC
	CALL    Memoria
	MOV     AX,13h         ;��� Modo 320x200 256c. VGA
	INT     10h            ;�����������������������������

        push    SegiMAGEN
	pop     fs

        PUSH    sEGbuffer
	POP     ES
	MOV     DI, 0
	mov     cx,0ffffh
	mov     al,  1
	rep     stosb

        call    landpal

BUCLE1:
       ;call    cielo
	call ScrollLand
        call LandScape
        mov     ax, ds
        push    es
        pop     ds
        mov     si, 256
        xor     di, di
        mov     cx, (0ffffh-512)/2
        rep     movsw
        mov     ds, ax
        call    cielo

	;----------------------------------------
	; miramos el teclado
	;----------------------------------------
	mov    ah,01h
	int    16h
	jz    BUCLE1
	;----------------------------------------------------------
ADIOS:  MOV     AX,03h         ;��� Modo 80x20 texto
	INT     10h            ;�����������������������������
        MOV  AX,4C00h          ;���  N� de ifunci�n de la INT 21 a utilizar
        INT  21h               ;���  Vuelta al DOS

Main    ENDP

;�������������������������������������������������������Ĳ��
;��      Crea una linea del mapa                          ��
;��           Linea -> Linea a crear.                     ��
;�������������������������������������������������������Ĳ��
ScrollLand      PROC
        ;mov     ah,Linea
        ;xor     al,al
        ;mov     cx, 255
           mov     cx, 128
        mov     di, 131*256 ;ax
          push    ax
       ;///////////////////////////////////////////////////
        ;mov     dx,40h
        ;rep     insb
rndt1:      call    random
            stosw
            loop    rndt1
            pop     ax

        add     di,256*19
	mov     ch,    26
	MEDIA:
         movzx ax,es:[di+256 ]
         movzx bx,es:[di+257 ]
         add   ax,bx
         mov   bl,es:[di-255 ]
         add   ax,bx
         mov   bl,es:[di]
         add   ax,bx
         shr    ax, 2
         mov   es:[di],al
         dec   di
        loop  media

	RET
       ;///////////////////////////////////////////////////
ScrollLand      ENDP

;�������������������������������������������������������Ĳ��
;��              HACE LANDSCAPE                           ��
;��     rX = X inical    ; rY = Y inicial.                ��
;�������������������������������������������������������Ĳ��
LandScape       PROC

	mov     Xp, 1

	OTRA_X: ;��� for( ; Xp<  300; Xp++ )
	mov     di,(320*199)      ;���
	add     di,Xp             ;��� DI = Punto inferior de la pantalla.
	mov     ax,rX             ;���
	shl     ax,8              ;���  Xt      = ((rX)<<8);
	mov     Xt,ax             ;���  X inicial de la camara.
	mov     si, 2             ;���  Z = SI = 2  . Empieza desde Z =2
	mov     LastY,200         ;���
	OTRA_Z:                   ;��� for(; Z <  160; Z++, Xt += (Xp-160)  )
	    mov     ax,Xt            ;���
	    mov     al, 0            ;���  ax = (abs(Xt>>8))<<8
	    add     ax,si            ;���  ax += Z
	    add     ax,rY            ;���  ax += rY
	    xchg    ah,al
	    mov     bx,ax            ;���
	    mov     al,es:[bx]       ;���  al = Datos[ ax ];
	    mov     color,al         ;���  color = Datos[abs(Xt>>8)][(Z+rY)];
	    movzx   ax,color         ;���
	    neg     ax
	    inc     ah
            shl     ax,5             ;���  ax = color<<6;
	    cwd                      ;���
	    idiv    si               ;���  ax /= Z;
	    mov     Yp,ax            ;���  Yp = (color<<6)/(Z))
	    cmp     ax, LastY        ;���
	    jge     NO_PINTA         ;���
		mov     cx, LastY      ;���
		sub     cx, Yp         ;���
		mov     al,color       ;���
	    eti:mov     fs:[di],al     ;���
		sub     di,320         ;���
		dec     cx             ;���
		jnz     eti            ;���
		mov     ax,Yp          ;��� LastY = Yp;
		mov     LastY,ax       ;���
	    NO_PINTA:                ;���
	    mov     ax,Xp            ;���
	    add     ax,-160          ;���
	    add     Xt,ax            ;��� Xt += (Xp-160)
	    inc     si               ;��� Z++
	    cmp     si,120           ;���
	    jl      OTRA_Z           ;��� Hasta que Z llegue hasta el limite.
	inc     word ptr Xp          ;��� Xp++
	cmp     Xp,319               ;��� Hasta que Xp llegue a la derecha .. 300
	jl      OTRA_X            ;���
	RET
LandScape       ENDP


;����----�������������� Manejo de paleta ��������������������-----����

DAC     PROC
        MOV     DX, 3c8h
        MOV     AL, [DACREG]
        OUT     DX, AL

        INC     DX
        MOV     AL, [R1]
        OUT     DX, AL
        MOV     AL, [G1]
        OUT     DX, AL
        MOV     AL, [B1]
        OUT     DX, AL

        INC     [DACREG]

        RET
ENDP    DAC

;����----�������������� Refresco vertical ��������������������-----����

;retrace proc
;        mov     dx,03dah         ; Espera a la pantalla
;@SINC0: in      al, dx
;        test    al,  8
;        jnz     @SINC0
;@SINC1: in      al, dx
;        test    al,  8
;        jz      @SINC1
;        ret
;endp    retrace

;����----�������������� Paleta de landscape ��������������������-----����

landpal proc
        mov     [dacreg], 0
lpal1:
        mov     al, [dacreg]
        mov     [b1], al
        shr     al, 1
        mov     [g1], al
        xor     al, al
        mov     [r1], al
        call    dac

        cmp     [dacreg], 48

        jne     lpal1

lpal2:  mov     al, [dacreg]
        sub     al, 32
        shr     al, 2
        add     al, 10
        mov     [r1], al
        mov     al, [dacreg]
        sub     al, 32
        shl     al, 1
        add     al, [dacreg]
        add     al, 63
        xor     ah, ah
        shr     al, 4
        add     al, 7
        mov     [g1], al
        mov     al, [dacreg]
        sub     al, 32
        shr     al, 3
        add     al, 10
        mov     [b1], al
        call    dac
        cmp     [dacreg], 48+26
        jne     lpal2

lpal3:  cmp     [g1], 62
        je      nomg
        inc     [g1]
        inc     [g1]
nomg:   cmp     [r1], 62
        je      nomr
        inc     [r1]
        inc     [r1]
nomr:   cmp     [b1], 62
        je      nomb
        inc     [b1]
        inc     [b1]
nomb:   call    dac
        cmp     [dacreg], 200
        jne     lpal3

        ret

endp    landpal


cielo   proc
        push    es
        mov     ax, segpanta
        mov     es, ax
        mov     dl, 42
        xor     di, di
        mov     es, ax
        mov     di, 320*5
        ;xor     di, di
cltag1: mov     cx, 160
        mov     al, dl
        mov     ah, dl
        rep     stosw
        inc     al
        inc     ah
        dec     dl
        jnz     cltag1
        pop     es

        ret
endp    cielo

random  proc
        MOV     AX, SEED                            ; linear congruence
        XOR     AX,0AA55h                           ; random generation
        SHL     AX,1                                ; 7 clock ticks (486)!
        ADC     AX,118h
        MOV     SEED, AX                            ; keep result as next seed
        ret
endp    random


;========================================================================
; INCLUDES
;========================================================================
include MEMO.INC

;==========================================================================
;       DATOS
;==========================================================================
SegiMAGEN       EQU    0a000h
RandSeed        DB 37h
RandSeed2       DB 7Ah
Linea           DB   (131)       ;���  Linea a generar.
rX              DW   (128)       ;���  X origen.
rY              DW   (?)         ;���  Y origen.
sEGBUFFER       DW   (?)
color           DB   (?)         ;���  color
Xt              DW   (?)         ;���  X en mapa.
Xp              DW   (?)         ;���  X en pantalla
Yp              DW   (?)         ;���  Y en pantalla
LastY           DW   (?)         ;��� Ultima Y.
r1              db    ?
g1              db    ?
b1              db    ?
dacreg          db    ?
world           dw    ?
seed            dw    ?

	END     Main
