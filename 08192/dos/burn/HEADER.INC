;様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様融
; makra tworzace naglowek EXE                                               �
; autor: Lukasz Sterkowicz vel Gutz                                         �
;        gutz@mops.uci.agh.edu.pl                                           �
;様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様夕

;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳朕
; nalezy umiescic na poczatku programu                                      �
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳潰
%macro START_PROGRAM 0
  section .header
              db 4Dh,5Ah
              dw (HEADER_SIZE + TEXT_SIZE + DATA_SIZE + INCLUDE_SIZE) % 512
              dw (HEADER_SIZE + TEXT_SIZE + DATA_SIZE + INCLUDE_SIZE + 511) / 512
              dw 0
              dw HEADER_SIZE / 16
              dw (BSS_SIZE - INCLUDE_SIZE + STACK_SIZE + 15) / 16
              dw 0xFFFF
              dw (TEXT_SIZE + DATA_SIZE + BSS_SIZE) / 16
              dw STACK_SIZE
              align 16,db 0

  section .text
  bits 16
TEXT_START:

  section .data
DATA_START:

  section .bss
BSS_START:

  section .include
INCLUDE_START:
%endmacro

;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳朕
; nalezy umiescic na koncu programu                                         �
;陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳潰
%macro END_PROGRAM 0
  section .text
              align 16,db 0
TEXT_END:
  section .data
              align 16,db 0
DATA_END:
  section .bss
              align 16,resb 1
BSS_END:
  section .include
INCLUDE_END:

HEADER_SIZE   equ 32
TEXT_SIZE     equ TEXT_END-TEXT_START
DATA_SIZE     equ DATA_END-DATA_START
BSS_SIZE      equ BSS_END-BSS_START
INCLUDE_SIZE  equ INCLUDE_END-INCLUDE_START
%endmacro
