/*---------------------------------------------------------------------------
 *  *         I N S T I T U T O   P O L I T � C N I C O   N A C I O N A L *
 *       UNIDAD PROFESIONAL INTERDISCIPLINARIA DE INGENIER�A CAMPUS ZACATECAS
 *   *----------------------------------------------------------------------------
 *                    Unidad de aprendizaje: Sistemas en Chip
 *                 Carrera: Ingenier�a en Sistemas Computacionales
 *                    Profesor: Dr. Teodoro Ibarra P�rez
 *                          Alumno: Roberto Pichardo Mier
 *----------------------------------------------------------------------------
 *--------------------------------- Encender dos led intermitentemente --------------------------------------
 *----------------------------------------------------------------------------
 *      Objetivo de la pr�ctica: Encender dos led intermitentemente  no sincronizada
 *----------------------------------------------------------------------------
 *                          Nombre de archivo: main.c
 *                          Nombre del proyecto: E4_ASM_EncenderDosLed
 *                      Fecha de realizaci�n: 5 de marzo de 2024
 *                  Entorno de desarrollo: CCSv12.2, lenguaje Ensamblador, versi�n 1.0
 *----------------------------------------------------------------------------
 *                       Reloj base por defecto MCLK ~ 1.045 MHz
* *                                  MSP430F5529
 *                              -------------------
 *                           /|\|                 |
 *                            | |                 |
 *                            --|RST              |
 *                              |             P4.7|--> LED
 *                              |             P1.0|--> LED
*/

;-------------------------------------------------------------------------------
; MSP430 Assembler Code Template for use with TI Code Composer Studio
;
;
;-------------------------------------------------------------------------------
            .cdecls C,LIST,"msp430.h"       ; Include device header file
            
;-------------------------------------------------------------------------------
            .def    RESET                   ; Export program entry-point to
                                            ; make it known to linker.
;-------------------------------------------------------------------------------
            .text                           ; Assemble into program memory.
            .retain                         ; Override ELF conditional linking
                                            ; and retain current section.
            .retainrefs                     ; And retain any sections that have
                                            ; references to current section.

;-------------------------------------------------------------------------------
RESET       mov.w   #__STACK_END,SP         ; Initialize stackpointer
StopWDT     mov.w   #WDTPW|WDTHOLD,&WDTCTL  ; Stop watchdog timer


;-------------------------------------------------------------------------------
; Main loop here
;-------------------------------------------------------------------------------

Main:		bis.b #0x80, &P4DIR     ; P4.7 como salida
			bis.b #0x01, &P1DIR
			bic.b #0x80, &P4OUT
			bis.b #0x01, &P1OUT



Salto:		xor.b #0x80, &P4OUT     ; Invertir el estado del LED verde en P4.7
			xor.b #0x01, &P1OUT
    		mov.w #0xFFFF, R10      ; R10 = 0xFFFF = 65535

Delay:		dec.w R10
    		jnz Delay                ; Cuenta hasta que R10 llegue a cero
    		jmp Salto                ; Salta de vuelta al inicio del bucle para invertir nuevamente el estado del LED
			nop
                                            

;-------------------------------------------------------------------------------
; Stack Pointer definition
;-------------------------------------------------------------------------------
            .global __STACK_END
            .sect   .stack
            
;-------------------------------------------------------------------------------
; Interrupt Vectors
;-------------------------------------------------------------------------------
            .sect   ".reset"                ; MSP430 RESET Vector
            .short  RESET
            
