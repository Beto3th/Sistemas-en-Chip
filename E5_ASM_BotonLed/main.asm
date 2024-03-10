/*---------------------------------------------------------------------------
 *  *         I N S T I T U T O   P O L I T É C N I C O   N A C I O N A L *
 *       UNIDAD PROFESIONAL INTERDISCIPLINARIA DE INGENIERÍA CAMPUS ZACATECAS
 *   *----------------------------------------------------------------------------
 *                    Unidad de aprendizaje: Sistemas en Chip
 *                 Carrera: Ingeniería en Sistemas Computacionales
 *                    Profesor: Dr. Teodoro Ibarra Pérez
 *                          Alumno: Roberto Pichardo Mier
 *----------------------------------------------------------------------------
 *--------------------------------- Boton Y led --------------------------------------
 *----------------------------------------------------------------------------
 *      Objetivo de la práctica: Encender dos led por medio de un boton
 *----------------------------------------------------------------------------
 *                          Nombre de archivo: main.c
 *                          Nombre del proyecto: E5_ASM_BotonLed
 *                      Fecha de realización: 5 de marzo de 2024
 *                  Entorno de desarrollo: CCSv12.2, lenguaje Ensamblador, versión 1.0
 *----------------------------------------------------------------------------
 *                       Reloj base por defecto MCLK ~ 1.045 MHz
* *                                  MSP430F5529
 *                              -------------------
 *                           /|\|                 |
 *                            | |                 |
 *                            --|RST              |
 *                              |             P4.7|--> LED
 *                  Boton -->   |B1.0             |
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

Main:		bic.b 	#0x02, &P2DIR
			bis.b 	#0x80, &P4DIR
			bis.b 	#0X02, &P2REN	; Habilitar resistencia
			bis.b 	#0x02, &P2OUT   ; Conectaar a Vcc la resistenncia
If:			bit.b	#0x02, &P2IN	;
			jnz		Else

			bis.b	#0x80, &P4OUT	;Encender el led
			jmp		If

Else:		bic.b	#0x80, &P4OUT	; Apagar el Led
			jmp		If

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
            
