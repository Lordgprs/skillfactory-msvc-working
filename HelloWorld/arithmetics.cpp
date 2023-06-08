#include <iostream>

int main() {
	int a, b, int_result;
	float float_result;
	setlocale(LC_ALL, "");
	std::cout << "Введите два числа: " << sizeof(int) << " " << sizeof(long) << sizeof(float) << sizeof(double);
	std::cin >> a >> b;
	std::cout <<
		a << " + " << b << " = " << (a + b) << std::endl <<
		a << " - " << b << " = " << (a - b) << std::endl <<
		a << " * " << b << " = " << (a * b) << std::endl <<
		a << " / " << b << " = " << (a * 1.0 / b) << std::endl <<
		a << " & " << b << " = " << (a & b) << std::endl <<
		a << " | " << b << " = " << (a | b) << std::endl <<
		a << " ^ " << b << " = " << (a ^ b) << std::endl;
	return 0;
}