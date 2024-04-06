#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <fun.h>
#include <scientific.h>
#include <basic.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_EXPRESSION_LENGTH 512
#define MAX_STACK 100
#define MAX_FUNC_LEN 15

typedef struct Calculator {
  // The expression to be evaluated
  char expression[MAX_EXPRESSION_LENGTH];
  /* Your code here to declare the struct */
} Calculator;

// Initialize your calculator
Calculator *init_calculator();

// Parse the mathematical expression given as a string.
// Returns the result of the expression.
float parseExpression(Calculator expression);

// Free the calculator
void free_Calculator(Calculator *calc);

#endif // CALCULATOR_H
