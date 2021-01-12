#include<stdio.h>

int label(int x) {
    int b = 15;
    //if(x == 5) goto skip_2;
    //else if(x < 5)goto skip_1;

    asm volatile ("nop"
        : : :  );

    b = 10;
    goto skip_2;
skip_1:
    b = 20;
skip_2:
    return b;
}

int main(void){
printf("Wynik x=4: %d\n", label(4));
printf("Wynik x=5: %d\n", label(5));
printf("Wynik x=6: %d\n", label(6));


}
