cmake_minimum_required(VERSION 3.17)
project(480_Lab3_RPN)

set(CMAKE_CXX_STANDARD 14)

add_executable(480_Lab3_RPN main.cpp InfixParser.cpp InfixParser.h RPNSolver.cpp RPNSolver.h)