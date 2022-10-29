#include<stdio.h>
int FibonacciSeries(int);
int main() {
int n, m= 0;
printf("Enter the total number of terms: ");
scanf("%d", &n);

for(int i = 1; i <= n; i++) {
printf("%d\n", FibonacciSeries(m));
m++; }
return 0;
}

int FibonacciSeries(int n) {
if(n == 0 || n == 1)
return n;
else
return(FibonacciSeries(n-1) + FibonacciSeries(n-2)); 
}
