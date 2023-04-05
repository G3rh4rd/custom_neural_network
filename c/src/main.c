/**
 ********************************************************************************
 * @file    main.c
 * @author  Gerhard Dick
 * @date    04.04.2023
 * @brief   Main file for custom neural network.
 ********************************************************************************
 */

/************************************
 * INCLUDES
 ************************************/

#include "perceptron.h"
#include "activation_functions.h"

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


int main() {

    // test code for testing perceptron and activation function
    input_node_t input_node_0;
    input_node_t input_node_1;

    connections_t *connections = (connections_t*)malloc(sizeof(connections_t));

    connections->count = 2;
    connections->weight_list = (float*)malloc(sizeof(float) * 2);
    connections->weight_list[0] = 1.f;
    connections->weight_list[1] = 2.f;
    connections->connection_result_ptrs = (float**)malloc(sizeof(float*) * 2);
    connections->connection_result_ptrs[0] = &(input_node_0.output);
    connections->connection_result_ptrs[1] = &(input_node_1.output);

    input_node_0.output = 1.f;
    input_node_1.output = 0.1f;

    printf("results: %f, %f\n", *connections->connection_result_ptrs[0], *connections->connection_result_ptrs[1]);
    
    perceptron_t perceptron = init_perceptron(1.f, &linear_function, connections);
    process_perceptron(&perceptron);
    printf("process_perceptron: %f\n", perceptron.output);

    return 0;
}