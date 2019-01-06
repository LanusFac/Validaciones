/* main.c */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "equalizer.h"
#include "mensajes.h"
#include "components.h"



int main (void)
{ 
	double inductor;
	double capacitor_c1;
	double capacitor_c2;
	double resistor_r1;
	double resistor_r2;
	double factor_calidad;
	double frecuencia;
	status_t status;

	if ((status = leer_resistor(MENSAJE_INGRESO_RESISTOR_1, MINIMO_VALOR_RESISTENCIA, MAXIMO_VALOR_RESISTENCIA, &resistor_r1)) != OK) 
	{
		fprintf(stderr, "%s\n", MENSAJE_ERROR);
		return status;
	}

	if ((status = leer_resistor(MENSAJE_INGRESO_RESISTOR_2, MINIMO_VALOR_RESISTENCIA, MAXIMO_VALOR_RESISTENCIA, &resistor_r2)) != OK) 
	{
		fprintf(stderr, "%s\n", MENSAJE_ERROR);
		return status;
	}	

	if ((status = leer_factor_calidad(MENSAJE_INGRESO_FACTOR_CALIDAD, MINIMO_VALOR_FACTOR_CALIDAD, MAXIMO_VALOR_FACTOR_CALIDAD, &factor_calidad)) != OK) 
	{
		fprintf(stderr, "%s\n", MENSAJE_ERROR);
		return status;
	}	

	if ((status = leer_frecuencia(MENSAJE_INGRESO_FRECUENCIA, MINIMO_VALOR_FRECUENCIA, MAXIMO_VALOR_FRECUENCIA, &frecuencia)) != OK) 
	{
		fprintf(stderr, "%s\n", MENSAJE_ERROR);
		return status;
	}	

	if ((status = calcular_inductor(resistor_r2, factor_calidad, frecuencia, &inductor)) != OK)
	{
		fprintf(stderr, "%s\n", MENSAJE_ERROR);
		return status;
	}

	if ((status = calcular_capacitor_c1(inductor, resistor_r1, resistor_r2, &capacitor_c1)) != OK)
	{
		fprintf(stderr, "%s\n", MENSAJE_RESISTENCIA_INVALIDA);
		return status;
	}

	if ((status = calcular_capacitor_c2(frecuencia, inductor, &capacitor_c2)) != OK)
	{
		switch (status)
		{
			case ERROR_INVALID_FRECUENCY:
			fprintf(stderr, "%s\n", MENSAJE_FRECUENCIA_INVALIDA);
			break;

			case ERROR_INVALID_INDUCTANCE:
			fprintf(stderr, "%s\n", MENSAJE_INDUCTANCIA_INVALIDA);
			break;

			default:
			fprintf(stderr, "%s\n", MENSAJE_ERROR);
		}
		return status;
	}

	if ((status = print_resistor(MENSAJE_MOSTRAR_RESISTOR_R1, resistor_r1)) != OK)
	{
		return status;
	}

	if ((status = print_resistor(MENSAJE_MOSTRAR_RESISTOR_R2, resistor_r2)) != OK)
	{
		return status;
	}

	if ((status = print_capacitor(MENSAJE_MOSTRAR_CAPACITOR_C1, capacitor_c1)) != OK)
	{
		return status;
	}

	if ((status = print_capacitor(MENSAJE_MOSTRAR_CAPACITOR_C2, capacitor_c2)) != OK)
	{
		return status;
	}

	if ((status = print_frecuencia(MENSAJE_MOSTRAR_FRECUENCIA, frecuencia)) != OK)
	{
		return status;
	}

	if ((status = print_inductor(MENSAJE_MOSTRAR_INDUCTOR, inductor)) != OK)
	{
		return status;
	}

	if ((status = print_factor_calidad(MENSAJE_MOSTRAR_FACTOR_CALIDAD, factor_calidad)) != OK)
	{
		return status;
	}	

	return OK;
	
}