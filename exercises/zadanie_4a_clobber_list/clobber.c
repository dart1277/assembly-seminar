#include<stdio.h>

struct S { 
int a;
};
typedef struct S S_t;

int clobber(S_t* s_ptr) {
    int b = 10;
    asm  ("add %0,5 \n\t"
        :"+a"(b)::);
    
    asm volatile ("mov eax,%0 \n\t"
         "add eax,%1 \n\t"
         "mov %0,eax \n\t"
        : "+m"(s_ptr->a) : "r" (1) );
    return b;
}

int main(void){
S_t s = {1};
printf("Wynik: %d\n", clobber(&s));
printf("s.a: %d\n", s.a);

}
