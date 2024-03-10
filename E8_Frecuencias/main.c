/*---------------------------------------------------------------------------
 *  *         I N S T I T U T O   P O L I T É C N I C O   N A C I O N A L *
 *       UNIDAD PROFESIONAL INTERDISCIPLINARIA DE INGENIERÍA CAMPUS ZACATECAS
 *   *----------------------------------------------------------------------------
 *                    Unidad de aprendizaje: Sistemas en Chip
 *                 Carrera: Ingeniería en Sistemas Computacionales
 *                    Profesor: Dr. Teodoro Ibarra Pérez
 *                          Alumno: Roberto Pichardo Mier
 *----------------------------------------------------------------------------
 *--------------------------------- Timers Tonos --------------------------------------
 *----------------------------------------------------------------------------
 *      Objetivo de la práctica: Conocer el funcionamiento y configuración básica
 *               del ADC mediante la captura de datos del sensor de
 *                              temperatura interno
 *----------------------------------------------------------------------------
 *                          Nombre de archivo: main.c
 *                          Nombre del proyecto: E8_Timer
 *                      Fecha de realización: 6 de marzo de 2024
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

int unsigned c=0;

/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    P2DIR &= ~BIT1;
    P2REN |= BIT1;
    P2OUT |= BIT1;
    P3DIR |= BIT4; //Configuro P4.7 como salida
    P3OUT &= ~BIT4;//apagr
    TA0CTL |= TASSEL__ACLK | MC__UP; // Selecciono la fuente
    TA0CCR0 = 62; // DO
    TA0CCTL0 |= CCIE; //Habilitamos la int. del registro CC en el Timer
    _bis_SR_register(LPM0_bits + GIE); // Se manda a dormir la CPU y se habilitan interrupciones generale
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer0( void){
    P3OUT ^= BIT4;
    if(!(P2IN & BIT1)){
        TA0CCR0=48;
    }else{
        TA0CCR0=62;
    }

}
