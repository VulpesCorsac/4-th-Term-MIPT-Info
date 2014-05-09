#include <stdio.h>
#include <omp.h>
#include <math.h>

int main()
{
    int N = 4000000;
    double smi[1000];
    int i;    
    for (i = 0; i < 1000; i++)
		smi[i] = 0;
    #pragma omp parallel for
    for (i = 0; i < N; i++) {
        double x1 = i / ( (double) N);
        double x2 = (i+1) / ( (double) N);
        double y1 = sqrt(1 - x1*x1);
        double y2 = sqrt(1 - x2*x2);
        smi[omp_get_thread_num()] += (x2-x1) * (y1+y2) * 0.5;
    }
    double sm = 0;
    for (i = 0; i < 1000; i++)
		sm += smi[i];
    printf("%.12f\n\n", sm*4);
    for (i = 0; i < 10; i++) {
		printf("%.12f\n", 4*smi[i]);
    }
    return 0;
}

// compile gcc -fopenmp -lm 1.c -o 1
