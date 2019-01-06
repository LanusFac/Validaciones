#include <stdio.h>

#define MSG "Ingrese el valor del resistor en "
#define MSG_ERROR_RANGO "Valor ingresado fuera de rango."
#define MSG_ERROR_INCORRECTO "Valor ingresado incorrecto."
#define MSG_FINAL "El valor ingresado resulta: "
#define UNIDAD_RESISTENCIA "KOhm"

#define VALOR_MINIMO 0
#define VALOR_MAXIMO 1000000000
#define FACTOR_KILO 1000

void flush_buffer(void);


int main(void)
{
	char temp;
	double valor_ingresado;

	printf("%s%s\n", MSG, UNIDAD_RESISTENCIA);

	if ((temp = scanf("%lf", &valor_ingresado)) == EOF || temp != 1) 
	{

		fprintf(stderr, "%s\n", MSG_ERROR_INCORRECTO);
		return 1;
	}
		flush_buffer();

	if (valor_ingresado < VALOR_MINIMO || valor_ingresado > VALOR_MAXIMO) 
	{
		fprintf(stderr, "%s\n", MSG_ERROR_RANGO);
		return 1;	
	}

	valor_ingresado = valor_ingresado * FACTOR_KILO;

	printf("%s%f\n", MSG_FINAL, valor_ingresado);

	return 0;
}

void flush_buffer(void)
{
	int c;

	while ((c = getchar() != '\n') && c != EOF)
	{
		if (c == EOF)
		{
			break;
		}
	}	
}