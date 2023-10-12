#include <stdio.h>

#define ULL unsigned long long

int main() {
    switch (getchar()) {
        case '1':
            unsigned u;
            scanf("%X", &u);
            printf("%f", *((float*)&u));
            break;
        case '2':
            float f;
            scanf("%f", &f);
            printf("%08X", *((unsigned*)&f));
            break;
        case '3':
            ULL ull;
            scanf("%llX", &ull);
            printf("%llf", *((double*)&ull));
            break;
        case '4':
            double d;
            scanf("%llf", &d);
            printf("%016llX", *((ULL*)&ull));
            break;
    }

    return 0;
}