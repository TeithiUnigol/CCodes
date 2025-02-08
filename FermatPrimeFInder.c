#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int primteszt(unsigned long long m);
int eukl(unsigned long long a, unsigned long long m);
unsigned long long modularisHatvanyozas(unsigned long long a, unsigned long long b, unsigned long long m);

unsigned long long generate_large_random() {
    return ((unsigned long long)rand() << 48) | ((unsigned long long)rand() << 32) | rand();
}

int main(void) {
    srand(time(NULL));
    unsigned long long szam = ULLONG_MAX;
    printf("Kezdő szám: %llu\n", szam);

    if (szam % 2 == 0) --szam; // Kezdjük páratlan számmal

    while (primteszt(szam) != 0) {
        printf("not\n");
        szam -= 2; // Csak páratlan számokat vizsgálunk
    }
    printf("A talált prím: %llu\n", szam);
    return 0;
}

int primteszt(unsigned long long m) { // 0, ha prím, 1, ha nem prím
    for (int k = 0; k < 100; k++) {
        unsigned long long a = (generate_large_random() % (m - 1)) + 1; // 1 és m-1 között

        if (eukl(m, a) != 1) {
            return 1;
        }
        if (modularisHatvanyozas(a, m - 1, m) != 1) {
            return 1;
        }
    }
    return 0;
}

int eukl(unsigned long long a, unsigned long long m) {
    while (m != 0) {
        unsigned long long temp = m;
        m = a % m;
        a = temp;
    }
    return a;
}

unsigned long long modularisHatvanyozas(unsigned long long a, unsigned long long b, unsigned long long m) {
    unsigned long long result = 1;
    a = a % m;

    while (b > 0) {
        if (b % 2 == 1) {
            result = (result * a) % m;
        }
        b = b / 2;
        a = (a * a) % m;
    }
    return result;
}
