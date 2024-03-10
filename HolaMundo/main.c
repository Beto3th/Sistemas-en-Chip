/*---------------------------------------------------------------------------
 *  *         I N S T I T U T O   P O L I T É C N I C O   N A C I O N A L *
 *       UNIDAD PROFESIONAL INTERDISCIPLINARIA DE INGENIERÍA CAMPUS ZACATECAS
 *   *----------------------------------------------------------------------------
 *                    Unidad de aprendizaje: Sistemas en Chip
 *                 Carrera: Ingeniería en Sistemas Computacionales
 *                    Profesor: Dr. Teodoro Ibarra Pérez
 *                          Alumno: Roberto Pichardo Mier
 *----------------------------------------------------------------------------
 *--------------------------------- Hola Mundo  --------------------------------------
 *----------------------------------------------------------------------------
 *      Objetivo de la práctica: Encender dos leds intermitentemente al mismo tiempo
 *----------------------------------------------------------------------------
 *                          Nombre de archivo: main.c
 *                          Nombre del proyecto: HolaMundo
 *                      Fecha de realización: 5 de marzo de 2024
 *                  Entorno de desarrollo: CCSv12.2, lenguaje C, versión 1.0
 *----------------------------------------------------------------------------
 *                       Reloj base por defecto MCLK ~ 1.045 MHz
* *                                  MSP430F5529
 *                              -------------------
 *                           /|\|                 |
 *                            | |                 |
 *                          --|RST                |
 *                            |               P4.7|--> LED
 *                            |               P1.0|--> LED
*/


#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	P4DIR |= BIT7; //Configuro P4.7 como salida
	P1DIR |= BIT0; //Configurar P1.0 como salida
	P1OUT &= ~BIT0;
	P4OUT &= ~BIT7;

	while (1){
	    P4OUT ^= BIT7;
	    P1OUT ^= BIT0;
	    __delay_cycles(1045000);
	}
	
	//return 0;
}
