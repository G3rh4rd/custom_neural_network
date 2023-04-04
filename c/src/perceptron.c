#include "perceptron.h"

perceptron_t init_perceptron(float bias, float (*activation_function)(float), connections_t *connections) {
    perceptron_t perceptron = {
        .bias = bias,
        .output = 0.f,
        .activation_function = activation_function,
        .input_connections = connections
    };

    return perceptron;
}

void process_perceptron(perceptron_t *perceptron) {
    // apply bias
    float total_weights = perceptron->bias;

    // sum up weighted output values from connect perceptrons 
    for(uint32_t i = 0; i < perceptron->input_connections->count; i++) {
        total_weights += *(perceptron->input_connections->connection_result_ptrs[i]) * perceptron->input_connections->weight_list[i];
    }

    // execute activation function
    perceptron->output = (*perceptron->activation_function)(total_weights);
}