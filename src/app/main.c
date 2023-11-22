#include <fpc.h>
#include <stdio.h>

int main()
{
  switch (getchar())
  {
  case '1':
    unsigned u;
    scanf("%X", &u);
    printf("%.8e", *sp_hex2dec(&u));
    break;
  case '2':
    float f;
    scanf("%f", &f);
    printf("%08X", *sp_dec2hex(&f));
    break;
  case '3':
    ULL ull;
    scanf("%llX", &ull);
    printf("%.18e", *dp_hex2dec(&ull));
    break;
  case '4':
    double d;
    scanf("%lf", &d);
    printf("%016llX", *dp_dec2hex(&d));
    break;
  }
}
