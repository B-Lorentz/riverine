#ifndef SPH_H
#define SPH_H
#include <math.h>
double W(double r, double h){
    float q = r/h;
    if (q > 1.0) {return 0.0;}
    else if (q > 0.5) {return 6.0*q*q*(q - 1);}
    else if (q >= 0.0) {return 2.0*pow(1-q, 3);}
    else {return 0.0;};
}

#endif
