/*---------------------------------------------------------------------------
 *  *         I N S T I T U T O   P O L I T � C N I C O   N A C I O N A L *
 *       UNIDAD PROFESIONAL INTERDISCIPLINARIA DE INGENIER�A CAMPUS ZACATECAS
 *   *----------------------------------------------------------------------------
 *                    Unidad de aprendizaje: Sistemas en Chip
 *                 Carrera: Ingenier�a en Sistemas Computacionales
 *                    Profesor: Dr. Teodoro Ibarra P�rez
 *                          Alumno: Roberto Pichardo Mier
 *----------------------------------------------------------------------------
 *--------------------------------- Timers --------------------------------------
 *----------------------------------------------------------------------------
 *      Objetivo de la pr�ctica: Conocer el funcionamiento y configuraci�n b�sica
 *               del ADC mediante la captura de datos del sensor de
 *                              temperatura interno
 *----------------------------------------------------------------------------
 *                          Nombre de archivo: main.c
 *                          Nombre del proyecto: E7_Timer
 *                      Fecha de realizaci�n: 5 de marzo de 2024
 *                  Entorno de desarrollo: CCSv12.2, lenguaje C, versi�n 1.0
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

int unsigned c=0;

/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
    P4DIR |= BIT7; //Configuro P4.7 como salida
    P1DIR |= BIT0; //Configurar P1.0 como salida
    P1OUT &= ~BIT0;//apagar
    P4OUT &= ~BIT7;//apagr
    TA0CTL |= TASSEL__ACLK | MC__UP; // Selecciono la fuente
    TA0CCR0 = 0x7FFF; // Re+gistro Captura /Comparacion o l�mite de conteo
    TA0CCTL0 |= CCIE; //Habilitamos la int. del registro CC en el Timer
    _bis_SR_register(LPM0_bits + GIE); // Se manda a dormir la CPU y se habilitan interrupciones generale
}
	
#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer0( void){

    if(c==5){
        P1OUT ^= BIT0;// leD ROJO
        P4OUT ^= BIT7;// Led Verde
        c=0;
    }else{
        c++;
    }

}


