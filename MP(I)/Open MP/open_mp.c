#include <stdio.h>
#include <omp.h>
int main() {
  #pragma omp parallel
  {
    printf("Hello\n");
  }
  return 0;
}
// export OMP_NUM_THREADS=N
// compile gcc -fomp 1.c -o 1
