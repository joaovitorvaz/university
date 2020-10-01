/*Marcus vinícius Souza Fernandes  -  19.1.40.46 -  BCC201-61P*/
#include <stdio.h>
void converterCelsius (float celsius, float *fahrenheit, float *kelvin);
int main()
{
  float celsius, fahrenheit, kelvin;
  printf("Insira uma temperatura em Celsius: ");
  scanf("%f", &celsius);
  converterCelsius (celsius, &fahrenheit, &kelvin);
  printf("O valor em Fahrenheit é: %.2f", fahrenheit);
  printf("\nO valor em Kelvin é: %.2f\n", kelvin);

  return 0;
}
void converterCelsius (float celsius, float *fahrenheit, float *kelvin)
{
  *fahrenheit=(celsius*(9.0/5.0)+32);
  *kelvin=(celsius+273.15);
}
