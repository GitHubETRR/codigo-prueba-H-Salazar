#include <stdio.h>

union num {
  float num;
  char vector[4];
} var;

union{
    struct{
        unsigned int bit0:1;
        unsigned int bit1:1;
        unsigned int bit2:1;
        unsigned int bit3:1;
        unsigned int bit4:1;
        unsigned int bit5:1;
        unsigned int bit6:1;
        unsigned int bit7:1;
    };
    unsigned char byte;
}vari;


int main()
{
  var.num=12.25;
  var.vector[3]|=0x80; //reemplazo el bit mas significativo (el del signo) por eso lo hace negativo
  printf("Float: %f\n", var.num);
  printf("0x%x", var.vector[3]);
  for(int i=2; i>=0; i--) {
    printf("%x", var.vector[i]);
  }
  var.num=-12.25;
  var.vector[3]^=0x80; //es una compuerta xor
    printf("\nFloat: %f\n", var.num);
    printf("0x%x", var.vector[3]);
    for(int i=2; i>=0; i--){
        printf("%x", var.vector[i]);
    }

    //Uniones anonimas
    vari.byte=0x12; //00010010
    printf("\n%d%d%d%d%d%d%d%d", vari.bit7, vari.bit6, vari.bit5, vari.bit4, vari.bit3, vari.bit2, vari.bit1, vari.bit0);

  return 0;
}
