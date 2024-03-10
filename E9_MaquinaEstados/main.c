/*---------------------------------------------------------------------------
 *  *         I N S T I T U T O   P O L I T É C N I C O   N A C I O N A L *
 *       UNIDAD PROFESIONAL INTERDISCIPLINARIA DE INGENIERÍA CAMPUS ZACATECAS
 *   *----------------------------------------------------------------------------
 *                    Unidad de aprendizaje: Sistemas en Chip
 *                 Carrera: Ingeniería en Sistemas Computacionales
 *                    Profesor: Dr. Teodoro Ibarra Pérez
 *                          Alumno: Roberto Pichardo Mier
 *----------------------------------------------------------------------------
 *--------------------------------- Maquina de Estado --------------------------------------
 *----------------------------------------------------------------------------
 *      Objetivo de la práctica: Realizar una maquina de estado en lenguaje c para el microcontrolador
 *----------------------------------------------------------------------------
 *                          Nombre de archivo: main.c
 *                          Nombre del proyecto: E8_MaquinaEstado
 *                      Fecha de realización: 8 de marzo de 2024
 *                  Entorno de desarrollo: CCSv12.2, lenguaje C, versión 1.0
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

#include <msp430.h> 
char estado = 'A';

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	P1DIR |= BIT0; //Led Rojo como salida
	P4DIR |= BIT7; //lED VERDE COMO SALIDA
	P2DIR &= ~BIT1; //Boton 2.1 como entrada
	P2REN |= BIT1; //Hab. la resistencia
	P2OUT |= BIT1; // cONECTAMOS LA RESISTENCIA A Vcc Pullup

	while(1){
	    // Logica de estado siguiente
	    if (estado == 'A' && !(P2IN & BIT1)){ // Si estoy en estado A y presiono
	        estado ='B';
	    }

	    if (estado == 'B' && (P2IN & BIT1)){ // Si estoy en estado B y suelto
	        estado ='C';
	    }

	    if (estado == 'C' && !(P2IN & BIT1)){ // Si estoy en estado C y presiono
            estado ='D';
        }

	    if (estado == 'D' && (P2IN & BIT1)){ // Si estoy en estado D y suelto
            estado ='A';
        }

	    //Logica de salida
	    switch (estado){
	    case 'B': // 01
	        P1OUT &= ~BIT0;
	        P4OUT |= BIT7;
	        break;
	    case 'C': // 10
	        P1OUT |= BIT0;
            P4OUT &= ~BIT7;
            break;
	    case 'D': // 11
	        P1OUT |= BIT0;
	        P4OUT |= BIT7;
	        break;
	    default: // 00
	        P1OUT &= ~BIT0;
            P4OUT &= ~BIT7;
	    }
	}
}
