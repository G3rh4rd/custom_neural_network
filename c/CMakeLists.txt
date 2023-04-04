cmake_minimum_required(VERSION 2.8.11)
project(custom_neural_network)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(custom_neural_network src/main.c src/perceptron.c src/activation_functions.c)

target_link_libraries(custom_neural_network "-lm")
