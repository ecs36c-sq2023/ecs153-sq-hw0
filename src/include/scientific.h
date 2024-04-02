#ifndef SCIENTIFIC_H
#define SCIENTIFIC_H

#include <stdio.h>
#include <stdint.h>
#include <math.h>

#define PI 3.14159265

/**
 * This function takes a floating-point number as degree and returns the sine of the degree.
 * 
 * @param num The floating-point number.
 * @return The sine of the input number.
 * Example usage:
 * float result = sinOfDegree(30); // result will be 0.5
 */
float sinOfDegree(float num);

/**
 * This function takes a floating-point number as degree and returns the cosine of the degree.
 * 
 * @param num The floating-point number.
 * @return The cosine of the input number.
 * Example usage:
 * float result = cosOfDegree(60); // result will be 0.5
 */
float cosOfDegree(float num);

#endif // SCIENTIFIC_H
