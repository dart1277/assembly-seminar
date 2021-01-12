#include<stdio.h>


int clobber() {
    int b;
    asm("mov %0, %1\n\t"
        "add %0, %0\n\t"
        "add %0, %1\n\t"
        : "=&r" (b) : "r" (1):);
    return b;
}

int main(void){

printf("Wynik: %d\n", clobber());

}
