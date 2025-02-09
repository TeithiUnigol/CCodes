#include <stdlib.h>
#include <stdio.h>

unsigned long long modularisHatvanyozas(unsigned long long a,unsigned long long b, unsigned long long m);
char* Coder(char* original,int code,unsigned long long n);

unsigned long long EulerFi(unsigned long long prime1,unsigned long long prime2){
    return (prime1-1)*(prime2-1);
}

int main(){
    unsigned long long prime1 = 4294991927;
    unsigned long long prime2 = 4294997149;
    unsigned long long prime3 = 4294991887;
    unsigned long long prime4 = 4294983661;
    unsigned long long prime5 = 4294995121;

    unsigned long long prime6 = 4294997723;
    int prime7 = 0;
    int prime8 = 0;
    int prime9 = 0;
    int prime10 = 0;
    char* coded = Coder("alma",10,EulerFi(prime1,prime2));
    for (int i = 0;coded[i]!='\0'; ++i)
    {
        printf("%c -- %d\n",coded[i],(int)coded[i]);
    }
    
    free(coded);
}

char* Coder(char* original,int code,unsigned long long n){
    int index = 0;
    int len = 0;
    while (original[len]!='\0')
    {
        ++len;
    }
    

    char* coded = malloc(sizeof(char)*(len+1));
    for(int i = 0;i<len;++i){
        coded[i] = (char)(modularisHatvanyozas((int)original[i],code,n));
    }
    coded[len] =  '\0';
   return coded;
}

unsigned long long modularisHatvanyozas(unsigned long long a,unsigned long long b, unsigned long long m) {//a^b(mod m)
    unsigned long long na = a;
    unsigned long long nb = b;
    unsigned long long nm = m;
    unsigned long long c = 1;
    while(nb!=0) {
        if(nb%2 == 1) {
            c = (c*na)%nm;
        }
        nb = nb/2;
        if(nb==0){
            return c;
        }
        na = (na*na)%nm;
    }
}