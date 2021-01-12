
#ifdef N
void fun(int a){
}
#endif

#define SZ 112
int main(){

unsigned char a[SZ];

a[0]=0;
#ifdef N
fun(a[0]);
#endif

return 0;
}


