#include <stdio.h>
int main()
void converterCelsius(float celsius, float *fahrenheit, float *kelvin);
{
  float celsius, fahrenheit, kelvin;
  printf ("Insira o valor em Celsius: ");
  scanf ("%f", &celsius);
  converterCelsius(celsius, &fahrenheit, &kelvin);
  printf("\nValor em Fahrenheit é: %.2f", fahrenheit);
  printf("\nValor em Kelvin é: %.2f", kelvin);
return 0;
}

void converterCelsius (float celsius, float *fahrenheit, float *kelvin) {
*fahrenheit=((celsius*(9.0/5.0))+32);
*kelvin=(celsius+273.15);
}
