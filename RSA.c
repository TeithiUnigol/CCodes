#include <stdlib.h>
#include <stdio.h>

unsigned long long modularisHatvanyozas(unsigned long long a,unsigned long long b, unsigned long long m);
char* Coder(char* original,int code,unsigned long long n);
char* Decoder(char* coded, int code, unsigned long long n, unsigned long long fi);
int lnko(int num1,int num2);

unsigned long long EulerFi(unsigned long long prime1,unsigned long long prime2){
    return (prime1-1)*(prime2-1);
}

unsigned long long modInverse(unsigned long long a, unsigned long long m) ;
unsigned long long extendedGCD(unsigned long long a, unsigned long long b, unsigned long long *x, unsigned long long *y);

void numprinter(char* szoveg){
    for (int i = 0;szoveg[i]!='\0'; ++i)
    {
        printf("%d-",(int)szoveg[i]);
    }
    printf("\n");
}

int main(){
    unsigned long long prime1 = 4294991927;
    unsigned long long prime2 = 4294997149;
    /*unsigned long long prime3 = 4294991887;
    unsigned long long prime4 = 4294983661;
    unsigned long long prime5 = 4294995121;

    unsigned long long prime6 = 4294997723;
    int prime7 = 0;
    int prime8 = 0;
    int prime9 = 0;
    int prime10 = 0;*/

    int code = 11;
    char* original = "alma";
    char* coded = Coder(original,code,prime1*prime2);
    
    printf("Eredeti:");
    numprinter(original);
    printf("Coded:");
    numprinter(coded);
    
    unsigned long long fi = EulerFi(prime1, prime2);
    char* decoded = Decoder(coded, code, prime1 * prime2, fi);
    printf("Vissza: %s\n", decoded);

    free(coded);
    free(decoded);
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

char* Decoder(char* coded, int code, unsigned long long n, unsigned long long fi) {
    int len = 0;
    while (coded[len] != '\0') {
        ++len;
    }

    // Kiszámítjuk a privát kulcsot (d), ami az inverz
    unsigned long long d = modInverse(code, fi);

    char* decoded = malloc(sizeof(char) * (len + 1));
    for (int i = 0; i < len; ++i) {
        decoded[i] = (char)(modularisHatvanyozas((int)coded[i], d, n));
    }
    decoded[len] = '\0';
    return decoded;
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

unsigned long long modInverse(unsigned long long a, unsigned long long m) {
    unsigned long long x, y;
    unsigned long long g = extendedGCD(a, m, &x, &y);
    
    if (g != 1) {
        printf("Inverz nem létezik.\n");
        return -1; // Nincs inverz
    } else {
        return (x % m + m) % m;
    }
}

// Kiterjesztett Euklideszi algoritmus
unsigned long long extendedGCD(unsigned long long a, unsigned long long b, unsigned long long *x, unsigned long long *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    unsigned long long x1, y1;
    unsigned long long gcd = extendedGCD(b, a % b, &x1, &y1);
    *x = y1;
    *y = x1 - (a / b) * y1;
    return gcd;
}