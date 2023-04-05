/**
 ********************************************************************************
 * @file    perceptron.c
 * @author  Gerhard Dick
 * @date    04.04.2023
 * @brief   Perceptron implementation of the custom neural network.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/

#include "perceptron.h"

/************************************
 * EXTERN VARIABLES
 ************************************/

/************************************
 * PRIVATE MACROS AND DEFINES
 ************************************/

/************************************
 * PRIVATE TYPEDEFS
 ************************************/

/************************************
 * STATIC VARIABLES
 ************************************/

/************************************
 * GLOBAL VARIABLES
 ************************************/

/************************************
 * STATIC FUNCTION PROTOTYPES
 ************************************/

/************************************
 * STATIC FUNCTIONS
 ************************************/

/************************************
 * GLOBAL FUNCTIONS
 ************************************/

/*
 * Function: init_perceptron
 * ----------------------------
 *   Assigns perceptron with it's initial bias, activation function and connections.
 *
 *   bias: initial bias value to assign to perceptron
 *   activation_function: activation function callback to assign to perceptron
 *   connections: connections from this perceptron to it's prior layer
 *
 *   returns: The initialized perceptron. 
 */
perceptron_t init_perceptron(float bias, float (*activation_function)(float), connections_t *connections) {
    perceptron_t perceptron = {
        .bias = bias,
        .output = 0.f,
        .activation_function = activation_function,
        .input_connections = connections
    };

    return perceptron;
}

/*
 * Function: init_perceptron
 * ----------------------------
 *   Processes perceptron by summing up all weighted input connection values and executing activation function.
 *
 *   perceptron: The perceptron to process
 *   
 *   returns: The perception after processing
 */
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