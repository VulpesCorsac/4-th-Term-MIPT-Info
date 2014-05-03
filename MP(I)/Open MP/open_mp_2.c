#include <stdio.h>
#include <omp.h>
const int NMAX = 1000000;
const int TMAX = 100; 
int main() {
  omp_set_num_threads(TMAX);
  int a[NMAX];
  int b[NMAX];
  int i;
  for (i = 0; i < 10000; i++) {
    a[i] = i;
    b[i] = 0;
  }
  
  long long t1 = omp_get_wtime();
  
  #pragma omp parallel for
    for (i = 0; i < NMAX; i++)
      b[i] = a[i];
  
  printf("\n");
  for (i = 0; i < TMAX/10; i++)
    printf("b[%d] = %d\n", i + TMAX, b[i+TMAX]);
  
  long long t2 = omp_get_wtime();
  printf("t2 = %d, t1 = %d, dt = %lld\n", t2, t1, t2-t1);

  return 0;
}
// export OMP_NUM_THREADS=N
// compile gcc -fomp 1.c -o 1
