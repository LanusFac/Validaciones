/* equalizer.c */

#include <stdio.h>
#include <math.h>
#include "components.h"
#include "types.h"
#include "mensajes.h"



status_t calcular_inductor (double resistor_r2, double factor_calidad, double frecuencia, double *inductor)
{
	if (frecuencia <= 2) 
	{
		return ERROR_INVALID_FRECUENCY;
	}

	*inductor = (factor_calidad * resistor_r2) / (2 * M_PI * frecuencia);

	return OK;
}

status_t calcular_capacitor_c1 (double inductor, double resistor_r1, double resistor_r2, double *capacitor_c_1)
{
	if (resistor_r2 < 0 || resistor_r1 < resistor_r2) 
	{
		return ERROR_INVALID_RESISTOR_VALUES;
	}

	*capacitor_c_1 = inductor / ((resistor_r1 - resistor_r2) * resistor_r2);

	return OK;
}

status_t calcular_capacitor_c2 (double frecuencia, double inductor, double *capacitor_c_2) 
{
	if (frecuencia <= 0) 
	{
		return ERROR_INVALID_FRECUENCY;
	}

	if (inductor == 0) 
	{
		return ERROR_INVALID_INDUCTANCE;
	}

	*capacitor_c_2 = 1 / (((2 * M_PI * frecuencia) * (2 * M_PI * frecuencia)) * inductor);

	return OK;
}
