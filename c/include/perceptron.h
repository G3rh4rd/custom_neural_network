/**
 ********************************************************************************
 * @file    perceptron.h
 * @author  Gerhard Dick
 * @date    04.04.2023
 * @brief   Perceptron implementation of the custom neural network.
 ********************************************************************************
 */

#ifndef PERCEPTRON_H
#define PERCEPTRON_H

/************************************
 * INCLUDES
 ************************************/

#include <stdint.h>
#include "activation_functions.h"

/************************************
 * MACROS AND DEFINES
 ************************************/

/************************************
 * TYPEDEFS
 ************************************/

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

/************************************
 * EXPORTED VARIABLES
 ************************************/

/************************************
 * GLOBAL FUNCTION PROTOTYPES
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
perceptron_t init_perceptron(float bias, float (*activation_function)(float), connections_t *connections);

/*
 * Function: init_perceptron
 * ----------------------------
 *   Processes perceptron by summing up all weighted input connection values and executing activation function.
 *
 *   perceptron: The perceptron to process
 *   
 *   returns: The perception after processing
 */
void process_perceptron(perceptron_t *perceptron);

#endif /* PERCEPTRON_H */