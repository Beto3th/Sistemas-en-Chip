/*---------------------------------------------------------------------------
 *  *         I N S T I T U T O   P O L I T � C N I C O   N A C I O N A L *
 *       UNIDAD PROFESIONAL INTERDISCIPLINARIA DE INGENIER�A CAMPUS ZACATECAS
 *   *----------------------------------------------------------------------------
 *                    Unidad de aprendizaje: Sistemas en Chip
 *                 Carrera: Ingenier�a en Sistemas Computacionales
 *                    Profesor: Dr. Teodoro Ibarra P�rez
 *                          Alumno: Roberto Pichardo Mier
 *----------------------------------------------------------------------------
 *--------------------------------- Maquina de Estado --------------------------------------
 *----------------------------------------------------------------------------
 *      Objetivo de la pr�ctica: Realizar una maquina de estado en lenguaje c para el microcontrolador
 *----------------------------------------------------------------------------
 *                          Nombre de archivo: main.c
 *                          Nombre del proyecto: E8_MaquinaEstado
 *                      Fecha de realizaci�n: 8 de marzo de 2024
 *                  Entorno de desarrollo: CCSv12.2, lenguaje C, versi�n 1.0
 *----------------------------------------------------------------------------
 *                       Reloj base por defecto MCLK ~ 1.045 MHz
* *                                  MSP430F5529
 *                              -------------------
 *                           /|\|                 |
 *                            | |                 |
 *                            --|RST              |
 *                              |             P4.7|--> LED
 *                              |             P1.0|--> LED
*/100 ms

#include <msp430.h> 


/**
 * main.c
 */
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	
	return 0;
}
