#include <stdio.h>

void TablaDeMultiplicar(int n);

int main(void) {
  TablaDeMultiplicar(5);
  return 0;
}

void TablaDeMultiplicar(int numero){
  for (int i = 1; i <= 10; i++) printf("%dx%d=%d\n", numero, i, numero*i);
}