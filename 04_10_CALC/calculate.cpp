#include <iostream>
#include "calculate.h"

int add(const int a, const int b) {
	return a + b;
}

int sub(const int a, const int b) {
	return a - b;
}

int mul(const int a, const int b) {
	return a * b;
}

double divide(const int a, const int b) {
	if (b == 0) {
		std::cerr << "Ошибка! На ноль делить нельзя!" << std::endl;
		return 0.0;
	}
	return static_cast<double>(a) / b;
}

double divide(const int a, const double b) {
	if (b == 0) {
		std::cerr << "Ошибка! На ноль делить нельзя!" << std::endl;
		return 0.0;
	}
	return static_cast<double>(a) / b;
}

int factorial(int a) {
	if (a < 0) {
		std::cerr << "Ошибка! Факторивал можно вычислить только от неотрицательного целого числа" << std::endl;
		return 0;
	}
	if (a == 0) {
		return 1;
	}
	else {
		return mul(a, factorial(a - 1));
	}
}

double power(int a, int b) {
	if (a == 0 && b == 0) {
		std::cerr << "Ошибка! Невозможно разрешить неопределённость 0 ^ 0" << std::endl;
		return 0;
	}
	if (b == 0) {
		return 1;
	}
	int abs_exponent = b < 0 ? -b : b;
	double result = mul(a, power(a, abs_exponent - 1));
	if (b < 0) {
		result = divide(1, result);
	}
	return result;
}