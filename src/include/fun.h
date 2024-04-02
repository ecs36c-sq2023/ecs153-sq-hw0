#ifndef FUN_H
#define FUN_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/**
 * This function takes a single floating-point number as input
 * and returns its integer part by discarding the fractional part.
 *
 * @param num The floating-point number.
 * @return The integer part of the input number.
 */
int getIntPart(float num);

/**
 * This function takes a single floating-point number as input
 * and returns its fractional part by discarding the integer part.
 *
 * @param num The floating-point number.
 * @return The fractional part of the input number.
 */
float getDecimalPart(float num);


/**
 * This function takes a floating-point number (`num`) and an integer (`n`), and returns
 * a new floating-point number that contains only the first `n` digits of the decimal
 * part of `num`.
 * 
 * @param num The floating-point number from which to extract digits.
 * @param n The number of digits to extract from the decimal part of `num`.
 * @return A floating-point number.
 * 
 * Example usage:
 * float result = getXdigit(3.14, 2); // result will be 3.1
 */
float getXdigit(float num, int n);

/**
 * This function takes a floating-point number as input and calculates the sum
 * of the Fibonacci sequence up to that number (inclusive). The Fibonacci sequence
 * starts with two ones, and each subsequent number is the sum of the two preceding
 * ones.
 * 
 * @param num The upper limit (inclusive) for the Fibonacci sequence sum, as a float.
 *            It is truncated to the nearest lower integer for calculation.
 * @return The sum of the Fibonacci sequence up to the specified limit.
 */
int sumFibonacci(float num);

/**
 * This function takes two floating-point numbers as input and calculates the sum
 * of the integer parts of the numbers.
 * 
 * @param num1 The first floating-point number.
 * @param num2 The second floating-point number.
 * @return The sum of the integer parts of the input numbers.
 */
int sumIntPart(float num1, float num2);

/**
 * This function takes two floating-point numbers as input and calculates the sum
 * of the decimal parts of the numbers.
 * 
 * @param num1 The first floating-point number.
 * @param num2 The second floating-point number.
 * @return The sum of the decimal parts of the input numbers.
 */
float sumDecimalPart(float num1, float num2);

/**
 * This function takes two float numbers as input. It then performs the following operations:
 * 1. Multiplies the integer part of the first number by the fractional part of the second number.
 * 2. Multiplies the fractional part of the first number by the integer part of the second number.
 * 3. Sums the results of steps 1 and 2 together.
 *
 * @param num1 The first float number.
 * @param num2 The second float number.
 * @return a float number.
 * Example usage:
 * float result = crossMultiply(3.1, 2.6); // result will be 3*0.6 + 0.1*2 = 2.0
 */
float crossMultiply(float num1, float num2);


/**
 * This function takes an integer as input and calculates the factorial of that number.
 * The factorial of a non-negative integer n is the product of all positive integers less
 * than or equal to n.
 * 
 * @param n The integer for which to calculate the factorial.
 * @return The factorial of the input integer.
 */
int factorial(int n);


#endif // FUN_H
