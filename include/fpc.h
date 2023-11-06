#ifndef CONVERTIONS_H
#define CONVERTIONS_H

typedef unsigned long long ULL;

unsigned *sp_dec2hex(float *f);
ULL *dp_dec2hex(double *f);

float *sp_hex2dec(unsigned *u);
double *dp_hex2dec(ULL *u);

#endif // CONVERTIONS_H