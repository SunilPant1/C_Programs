//Program to convert binary to decimal
#include <stdio.h>
#include <math.h>

// Binary number to Decimal Number

int main()
{
  int rem, i = 0, dec = 0;
  long long n;
  printf("Enter any Binary Number: ");
  scanf("%lld", &n);

  while (n!=0) 
  {
    rem = n % 10;
    n = n / 10;
    dec = dec + rem * pow(2, i);
    ++i;
  }

  printf("Conversion to Decimal Number: %d", dec);

  return 0;
}
