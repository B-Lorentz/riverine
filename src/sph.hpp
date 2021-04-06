#ifndef SPH_H
#define SPH_H
#include <math.h>
#include "three_dimension.hpp"
namespace sph{
double W(double r, double h){
    float q = r/h;
    float sigma = 8.0/(h*h*h)/M_PI;
    if (q > 1.0) {return 0.0;}
   
    else if (q > 0.5) {return sigma*2.0*pow(1-q, 3);}
    else if (q >= 0.0){return sigma*(6.0*q*q*(q - 1) + 1.0);} 
    else {return 0.0;};
}

double W(thd::PVector &r, double h){
    return W(r.Length(), h);
}

double dWdr(double r, double h){
    float q = r/h;
   
    if (q > 1.0) {return 0.0;}
    else if (q > 0.5) {return -48.0*pow((q-1), 2)/M_PI/pow(h, 4);}
    else if (q >= 0.0) {return 48.0*q*(3*q -2)/M_PI/pow(h, 4);}
    else {return 0.0;};
}

thd::PVector gradW(thd::PVector v, double h){
    double r =v.Length();
    double dW = dWdr(r, h);
    v *= dW/r;
    return v;
}
}
#endif
