#ifndef BASIC_H
#define BASIC_H

#include <stdio.h>
#include <stdint.h>

/**
 * This function takes two floating-point numbers as input and returns the sum of the numbers.
 * 
 * @param num1 The first floating-point number.
 * @param num2 The second floating-point number.
 * @return The sum of the input numbers.
 */
float add(float num1, float num2);

/**
 * This function takes two floating-point numbers as input and returns the difference of the numbers.
 * 
 * @param num1 The first floating-point number.
 * @param num2 The second floating-point number.
 * @return The difference of the input numbers.
 */
float subtract(float num1, float num2);

/**
 * This function takes two floating-point numbers as input and returns the product of the numbers.
 * 
 * @param num1 The first floating-point number.
 * @param num2 The second floating-point number.
 * @return The product of the input numbers.
 */
float multiply(float num1, float num2);

/**
 * This function takes two floating-point numbers as input and returns the result of dividing the first number by the second number.
 * 
 * @param num1 The dividend.
 * @param num2 The divisor.
 * @return The result of dividing the first number by the second number.
 */
float divide(float num1, float num2);

/**
 * This function takes two integers as input and returns the remainder of dividing the first number by the second number.
 * 
 * @param num1 The dividend.
 * @param num2 The divisor.
 * @return The remainder of dividing the first number by the second number.
 */
int mod(int num1, int num2);

/**
 * This function takes a floating-point number as input and returns the square of the number.
 * 
 * @param num The floating-point number.
 * @return The square of the input number.
 */
float square(float num1);

#endif // BASIC_H
