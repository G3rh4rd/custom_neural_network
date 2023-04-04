#ifndef PERCEPTRON_H
#define PERCEPTRON_H
#include <stdint.h>

#include "activation_functions.h"

typedef struct {
    uint32_t count;
    float *weight_list;
    float **connection_result_ptrs;  // can be perceptron or input / output node
} connections_t;

typedef struct {
    float bias;
    float (*activation_function)(float);
    connections_t *input_connections;
    float output;
} perceptron_t;

typedef struct {
    connections_t *input_connections;
    float output;
} input_node_t, output_node_t;

perceptron_t init_perceptron(float bias, float (*activation_function)(float), connections_t *connections);

void process_perceptron(perceptron_t *perceptron);

#endif /* PERCEPTRON_H */