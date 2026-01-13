#include <stdio.h>

void SumaIntervalo(int,int);

int main(void) {
  SumaIntervalo(3, 5);
  return 0;
}

void SumaIntervalo(int Num1, int Num2){
  int Sum=0, i;
  for (i=Num1; i<=Num2; i++){
    Sum+=i;
    printf ("%d ", i);
    if(i<Num2) printf("+ ");
  }
  printf(" = %d\n", Sum);
}