#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>


int primteszt(unsigned long long m);
int eukl(unsigned long long a,unsigned long long m);
int modularisHatvanyozas(unsigned long long a,unsigned long long b, unsigned long long m);

unsigned long long generate_large_random() {
    unsigned long long high = ((unsigned long long)rand() << 32) | rand();
    unsigned long long mid = ((unsigned long long)rand() << 32) | rand();
    unsigned long long mid2 = ((unsigned long long)rand() << 32) | rand();
    unsigned long long low = ((unsigned long long)rand() << 32) | rand();
    // Combine high and low to form a 128-bit number
    unsigned long long large_num = ((unsigned long long)high << 64) | mid;
    large_num = ((unsigned long long)large_num << 64) | mid2;
    large_num = ((unsigned long long)large_num << 64) | low;
    return large_num;
}

int main(void) {
    srand(time(NULL));
    //18446744073672978079
    //18446744073709551614
    //unsigned long long szam = (unsigned long long)18446744073672978079;
    unsigned long long szam = (unsigned long long) generate_large_random();
    printf("%llu",szam);

    int isprime = 0;
    szam = rand();
    while(isprime == 0){
        if (szam % 2 != 0&&szam % 3 != 0&&szam % 5 != 0){
            if (szam >42949836610&&primteszt(szam) == 0)
            {
                isprime = 1;  
            }else{
                printf("\nnem a %llu\n",szam);
                szam = generate_large_random();
                //--szam;
            }
            
        }else{
            szam = generate_large_random();
            //--szam;
        }
    }
   printf("\n\nA talalt prim: %llu",szam);
    return 0;
}

int primteszt(unsigned long long m) { //0, ha talán prím, 1, ha nem prím
    int k = 1;
    while(k!=100) {
        unsigned long long a = (generate_large_random() % (m-1))+1;//random szám 0 és m-1 között
        if(eukl(m,a)!=1) {
            return 1;
        }
        if(modularisHatvanyozas(a,m-1,m)!=1){
            return 1;
        }
        k++;
    }
    return 0;
}

int eukl(unsigned long long a, unsigned long long m){//ahol 0<a<m
    unsigned long long na = a;
    unsigned long long nm = m;
    unsigned long long r = nm%na;
    while(r!=0) {
        nm = na;
        na = r;
        r = nm%na;
    }
    return na;
}

int modularisHatvanyozas(unsigned long long a,unsigned long long b, unsigned long long m) {//a^b(mod m)
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