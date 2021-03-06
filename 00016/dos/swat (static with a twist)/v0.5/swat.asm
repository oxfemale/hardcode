;SWAT - Static With A Twist - v0.5
;(The way it was meant to be! :D )
;Marquete's first demo in 12 bytes
;me@marquete.com.ar
;compile like this: nasm swat.asm -o swat.com

        mov al,13h          ;MGCA mode (320x200x256).
        int 10h             ;Video interrupt request.

        les bp,[bx]         ;es points to the video memory (instead of
                            ; "push word 0a000h" and then "pop es").

DRAW    stosb               ;Write al (color) at es:di (instead of
                            ; "mov [es:di],al" and then "inc di").

        adc ax,di           ;Let's see. I want to increase both al (color)
        xchg ax,di          ;and di (offset). This is a nice combination,
                            ;because adc avoids overflowing (as opposed to
                            ; add) and by exchanging the values I get di to
                            ;grow more than ax (remember stosb also
                            ; increases di), thus drawing in a more "erratic"
                            ;pattern, so to speak. ;)

        jmp short DRAW      ;Repeat like there's no tomorrow.