#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int primteszt(int m);
int eukl(int a,int m);
int modularisHatvanyozas(int a,int b, int m);

int main(void) {
    srand(time(NULL));

    return 0;
}

int primteszt(int m) { //0, ha talán prím, 1, ha nem prím
    int k = 1;
    while(k!=100) {
        int a = rand() % (m);//random szám 0 és m-1 között
        if(eukl(m,a)!=1) {
            return 1;
        }

        k++;
    }
    return 0;
}

int eukl(int a, int m){//ahol 0<a<m
    int na = a;
    int nm = m;
    int r = nm%na;
    while(r!=0) {
        nm = na;
        na = r;
        r = nm%na;
    }
    return na;
}

int modularisHatvanyozas(int a,int b, int m) {
    int na = a;
    int nb = b;
    int c = 1;
    while(nb>0) {
        if(a%2 == 0) {

        }else {
            c = c*(a%m);
        }
        b = b/2;
    }
}