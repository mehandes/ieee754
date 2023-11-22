#include <fpc.h>

inline unsigned *sp_dec2hex(float *f)
{
    return (unsigned *)f;
}

inline ULL *dp_dec2hex(double *f)
{
    return (ULL *)f;
}

inline float *sp_hex2dec(unsigned *u)
{
    return (float *)u;
}

inline double *dp_hex2dec(ULL *u)
{
    return (double *)u;
}
