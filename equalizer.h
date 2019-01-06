/* equalizer.h */

#include <stdio.h>
#include "components.h"
#include "types.h"

status_t leer_resistor (const char *msg, double minimo, double maximo, double *val);
status_t leer_factor_calidad  (const char *msg, double minimo, double maximo, double *val);
status_t leer_frecuencia (const char *msg, double minimo, double maximo, double *val);

status_t calcular_capacitor_c1 (double inductor, double resistor_r1, double resistor_r2, double *capacitor_c1);
status_t calcular_capacitor_c2 (double frecuencia, double inductor, double *capacitor_c2);
status_t calcular_inductor (double resistor_r2, double factor_calidad, double frecuencia, double *inductor);

status_t print_resistor (const char *msg, double value);
status_t print_capacitor (const char *msg, double value);
status_t print_frecuencia (const char *msg, double value);
status_t print_inductor (const char *msg, double value);
status_t print_factor_calidad (const char *msg, double value);


