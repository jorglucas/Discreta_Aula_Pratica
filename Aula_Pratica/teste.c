#include <stdio.h>
#include <time.h>

void pause (float delay1) {

   if (delay1<0.001) return; // pode ser ajustado e/ou evita-se valores negativos.

   float inst1=0, inst2=0;

   inst1 = (float)clock()/(float)CLOCKS_PER_SEC;

   while (inst2-inst1<delay1)
   {
       printf("ola\n");
       inst2 = (float)clock()/(float)CLOCKS_PER_SEC;
   }
   return;

}

int main (void) {

   printf ("Favor olhar para o relogio da maquina para conferir.\n");
   printf ("5,5 segundos antes...\n");
   pause (1.5);
   printf ("5,5 segundos depois...\n");

   return 0;

}