/**
 * -------------------------------------
 * @file  fibonacci.c
 * file description
 * -------------------------------------
 * @author Giuseppe Akbari, 169057752, akba7752@mylaurier.ca
 *
 * @version 2025-01-18
 *
 * -------------------------------------
 */
#include "fibonacci.h"
/**
 * Cmpute and return the nth Fibonacci number F(n) using iterative algorithm,
 *  namely using a for or while loop.
 *
 * @param n - the n for F(n)
 * @return - the nth Fibonacci number
 */
int iterative_fibonacci(int n) {
	int f_value;
	if (n < 0) {
		printf("input must be greater than or equal to 0");
		f_value = -1;
	} else if (n == 0) {
		f_value = 0;
	} else if (n == 1) {
		f_value = 1;
	} else {
		int temp0 = 0;
		int temp1 = 1;
		int temp2;
		for (int i = 1; i < n; i++) {
			temp2 = temp0 + temp1;
			temp0 = temp1;
			temp1 = temp2;
		}
		f_value = temp2;
	}
	return f_value;
}

/**
 * Cmpute and return the nth Fibonacci number F(n) using recurisve algorithm,
 *  namely using recursion function.
 *
 * @param n - the n for F(n)
 * @return - the nth Fibonacci number
 */
int recursive_fibonacci(int n) {
	int f_value;
	if (n < 0) {
		f_value = -1;
		printf("input must be greater than or equal to 0");
	} else if (n == 0) {
		f_value = 0;
	} else if (n == 1) {
		f_value = 1;
	} else {
		f_value = recursive_fibonacci(n - 1) + recursive_fibonacci(n - 2);
	}
	return f_value;
}

/**
 * Compute and return the nth Fibonacci number F(n) using dynamic programming
 * bottom-up method with external array f[n+1] of initial value -1 for all elements.
 * Namely it fills up f[] by f[0]=0, f[1]=1, a[i]= a[i-2]+a[i-1] for i=2,...,n, and
 * return f[n].
 *
 * @param n - the n for F(n)
 * @return - the nth Fibonacci number
 */
int dpbu_fibonacci(int *f, int n) {

	if (n == 0) {
		f[0] = 0;
	} else if (n == 1) {
		f[0] = 0;
		f[1] = 1;
	} else {
		f[0] = 0;
		f[1] = 1;
		for (int i = 2; i <= n; i++) {
			f[i] = f[i - 1] + f[i - 2];
			//*(f + i) = *(f + i -1) + *(f + i -2);
		}
	}

	return f[n];
}

/**
 * Compute and return the nth Fibonacci number F(n) using dynamic programming
 * top-down method with external array f[n+1] of initial value -1 for all elements.
 * Namely it fills up f[n+1] by recursion function call. Specifically it returns
 * f[n] if f[n]>0 else sets f[n] = dptd_fibonacci(f, n-2) + dptd_fibonacci(f, n-1)
 * and then returns f[n]
 *
 * @param n - the n for F(n)
 * @return - the nth Fibonacci number F(n).
 */
int dptd_fibonacci(int *f, int n) {
	if (n == 0) {
		f[0] = 0;
	} else if (n == 1) {
		f[0] = 0;
		f[1] = 1;
	} else {
		f[n] = dptd_fibonacci(f, n - 1) + dptd_fibonacci(f, n - 2);
	}
	return f[n];
}
