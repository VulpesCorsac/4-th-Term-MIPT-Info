#include <stdio.h>
#include <math.h>
#include <omp.h>

int main()
{
double pi;
int i = 0;
double s = 0.0;
double x[10000], y[10000];
#pragma omp parallel for
for(i=0; i<9999; i++)
{
x[i] =(double) i/10000.0f;
x[i+1] = (double) (i+1)/10000.0f;
y[i] = sqrt(1- x[i] * x[i]);
y[i+1] = sqrt(1 - x[i+1] * x[i+1]);
#pragma omp critical
s+= (y[i] + y[i+1]) / 2.0f /10000.0f;
}

printf("%10.9f\n", 4.0f*s);
return 0;
}
// gcc -fopenmp -lm open_mp_pi.c -o 1
