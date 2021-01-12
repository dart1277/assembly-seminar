#include<stdio.h>


int clobber() {
    int a = 1;
    asm("add %[a], %1\n\t"
        "add %0, %1"
        : [a]"+r" (a) : "r" (1));
    return a;
}

int main(void){

printf("Wynik: %d\n", clobber());

}
