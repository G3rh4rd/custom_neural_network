#include "perceptron.h"


perceptron_t init_perceptron(connections_t *connections, activation_function_t *activation_function) {
    perceptron_t perceptron = {
        .bias = 0.f,
        .output = 0.f,
        .activation_function = activation_function,
        .input_connections = connections
    };
}

void process_perceptron(perceptron_t *perceptron) {
    float total_weights = perceptron->bias;
    for(uint32_t i = 0; i < perceptron->input_connections->count; i++) {
        total_weights += *(perceptron->input_connections->connection_result_ptrs[i]) * perceptron->input_connections->weight_list[i];
    }

    perceptron->output = perceptron->activation_function(total_weights);
}