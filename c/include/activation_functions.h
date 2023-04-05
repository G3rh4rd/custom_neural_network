/**
 ********************************************************************************
 * @file    activation_functions.h
 * @author  Gerhard Dick
 * @date    04.04.2023
 * @brief   Activation functions for custom neural network implementation.
 ********************************************************************************
 */

#ifndef ACTIVATION_FUNCTIONS_H
#define ACTIVATION_FUNCTIONS_H

/************************************
 * INCLUDES
 ************************************/

/************************************
 * MACROS AND DEFINES
 ************************************/

/************************************
 * TYPEDEFS
 ************************************/

/************************************
 * EXPORTED VARIABLES
 ************************************/

/************************************
 * GLOBAL FUNCTION PROTOTYPES
 ************************************/

float binary_step_function(float x);
float linear_function(float x);
float sigmoid_function(float x);
float tanh_function(float x);
float relu_function(float x);
float relu_leaky_function(float x);

#endif /* ACTIVATION_FUNCTIONS_H */