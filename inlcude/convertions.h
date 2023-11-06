#ifndef CONVERTIONS_H
#define CONVERTIONS_H

typedef unsigned long long ULL;

unsigned *dec2hex(float *f);
ULL *dec2hex(double *f);

float *hex2dec(unsigned *u);
double *hex2dec(ULL *u);

#endif