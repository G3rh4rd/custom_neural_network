#include <math.h>
#include "activation_functions.h"

#define EULER_NUMBER 2.71828f

float binary_step_function(float x) {
    if(x >= 0.f) return 1.f;
    else return 0.f;
}

float linear_function(float x) {
    return x;
}

float sigmoid_function(float x) {
    return (1.f / (1.f + pow(EULER_NUMBER, -x)));
}

float tanh_function(float x) {
    return tanhf(x);
}

float relu_function(float x) {
    if(x >= 0.f) return x;
    else return 0.f;
}

float relu_leaky_function(float x) {
    float x_01 = x * 0.1f;

    if(x >= x_01) return x;
    else return x_01;
}