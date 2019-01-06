/* components.c */

#include <stdio.h>
#include <stdlib.h>
#include "equalizer.h"
#include "mensajes.h"


status_t leer_resistor (const char *msg, double minimo, double maximo, double *val)
{
	char str[MAX_STR];
	char *temp;

	if (msg == NULL || val == NULL) {
		return ERROR_NULL;
	}

	printf("%s%s\n", msg, UNIDAD_RESISTOR);

	if ((fgets(str, MAX_STR, stdin)) == NULL) {
		return ERROR_INVALID_DATA;
	}

	*val = strtod(str, &temp);

	if (*temp != '\0' && *temp != '\n') {
		return ERROR_INVALID_DATA;
	}

	*val = *val * MULTIPLICADOR_RESISTENCIA;

	if (*val < minimo || *val > maximo) {
		return ERROR_INVALID_DATA;
	}

	return OK;
}

status_t leer_factor_calidad  (const char *msg, double minimo, double maximo, double *val)
{
	char str[MAX_STR];
	char *temp;

	if (msg == NULL || val == NULL) {
		return ERROR_NULL;
	}

	printf("%s\n", msg);

	if ((fgets(str, MAX_STR, stdin)) == NULL) {
		return ERROR_INVALID_DATA;
	}

	*val = strtod(str, &temp);

	if (*temp != '\0' && *temp != '\n') {
		return ERROR_INVALID_DATA;
	}

	if (*val < minimo || *val > maximo) {
		return ERROR_INVALID_DATA;
	}

	return OK;
}

status_t leer_frecuencia (const char *msg, double minimo, double maximo, double *val)
{
	char str[MAX_STR];
	char *temp;

	if (msg == NULL || val == NULL) {
		return ERROR_NULL;
	}

	printf("%s%s\n", msg, UNIDAD_FRECUENCIA);

	if ((fgets(str, MAX_STR, stdin)) == NULL) {
		return ERROR_INVALID_DATA;
	}

	*val = strtod(str, &temp);

	if (*temp != '\0' && *temp != '\n') {
		return ERROR_INVALID_DATA;
	}

	if (*val < minimo || *val > maximo) {
		return ERROR_INVALID_DATA;
	}

	return OK;
}

status_t print_resistor (const char *msg, double value)
{
	if (msg == NULL)
	{
		return ERROR_NULL;
	}

	printf("%s%.2f%s\n", msg, value, UNIDAD_RESISTOR);

	return OK;
}

status_t print_capacitor (const char *msg, double value)
{
	if (msg == NULL)
	{
		return ERROR_NULL;
	}

	printf("%s%.2f%s\n", msg, value * MULTIPLICADOR_CAPACITOR, UNIDAD_CAPACITOR);

	return OK;
}

status_t print_inductor (const char *msg, double value)
{
	if (msg == NULL)
	{
		return ERROR_NULL;
	}

	printf("%s%.2f%s\n", msg, value, UNIDAD_INDUCTOR);

	return OK;
}

status_t print_frecuencia (const char *msg, double value)
{
	if (msg == NULL)
	{
		return ERROR_NULL;
	}

	printf("%s%.2f%s\n", msg, value, UNIDAD_FRECUENCIA);

	return OK;
}

status_t print_factor_calidad (const char *msg, double value)
{
	if (msg == NULL)
	{
		return ERROR_NULL;
	}

	printf("%s%.2f\n", msg, value);

	return OK;
}