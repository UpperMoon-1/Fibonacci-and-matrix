/**
 * -------------------------------------
 * @file  polynomial.c
 * file description
 * -------------------------------------
 * @author Giuseppe Akbari, 169057752, akba7752@mylaurier.ca
 *
 * @version 2025-01-18
 *
 * -------------------------------------
 */
#include <stdio.h>
#include "polynomial.h"
#define EPSILON 1e-6
#define MAXCOUNT 100

/**
 * Cmpute and return the value of the (n-1)-th degree polynomial
 * p(x) = p[0]*x^{n-1} +  p[1]*x^{n-2} +...+ p[n-2]*x^1 + p[n-1]*x^0
 * using Horner's algorithm (https://en.wikipedia.org/wiki/Horner%27s_method)
 *
 * @param *p - pointer to float number array
 * @param n  - the number of coefficients
 * @return - the value of the above polynomial
 */
float horner(float *p, int n, float x) {
	float r = 0;
	for (int i = 0; i < n; i++) {
		r = r * x + *(p + i);
	}
	return r;
}

/**
 * Compute the derivative of input (n-1)-th degree polynomial
 * p(x) = p[0]*x^{n-1} +  p[1]*x^{n-2} +...+ p[n-2]*x^1 + p[n-1]*x^0
 * output the coefficients of the derivative polynomial in an array.
 * The derivative of the above polynomial p(x) is as follows.
 * p'(x) = (n-1)* p[0]*x^{n-2} +  (n-2)*p[1]*x^{n-3} +...+ p[n-2]*x^0
 *
 * @param *p - pointer to coefficient array of input polynomial.
 * @param *d - pointer to coefficient array of output polynomial.
 * @param n  - the number of coefficients of the input polynomial
 */
void derivative(float *p, float *d, int n) {
	int i;
	for (i = 0; i < n - 1; i++) {
		d[i] = p[i] * (n - (i + 1));
	}

}

float myFabs(float x) {
	if (x < 0) {
		x = (float) x * -1;
	}
	return x;
}

/**
 * Compute approximate real root x of polynomial p(x) using Newton's
 * method(https://en.wikipedia.org/wiki/Newton%27s_method).
 * Use fault tolerant 1e-6 (or 0.000001) and maximum 100 iterations.
 *
 * @param *p - pointer to coefficient array of input polynomial.
 * @param n  - the number of coefficients of the input polynomial
 * @param x0 - start point for Newton method
 * @return -  the root if found, otherwise x0.
 */

float newton(float *p, int n, float x0) {
	float x = x0, px, d[n - 1];
	derivative(p, d, n);
	do {
		x0 = x;
		px = horner(p, n, x);
		x = x0 - (px / *d);
	} while (myFabs(px) > EPSILON && myFabs(x - x0) > EPSILON);
	return x;
}

