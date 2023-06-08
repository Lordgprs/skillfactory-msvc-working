#include <iostream>
#include "calculate.h"

int main() {
	system("chcp 1251");

	char operation;
	float result;
	int a, b;
	do {
		std::cout << "----------------------------------" << std::endl << std::endl <<
			"Введите операцию: ";
		std::cin >> operation;

		switch (operation) {
		case 'q':
			std::cout << "Выходим. До новых встреч!" << std::endl;
			break;
		case '!':
			std::cout << "Введите неотрицательное целое число: ";
			std::cin >> a;
			result = 1.0;
			if (a < 0) {
				std::cout << "Факториал можно вычислить только от неотрицательного целого числа!" << std::endl;
				continue;
			}

			for (int i = 1; i <= a; i++) {
				result *= i;
			}
			std::cout << a << "! = " << result << std::endl;
			break;
		case '+':
			std::cout << "Введите два целых числа: ";
			std::cin >> a >> b;
			std::cout << a << " + " << b << " = " << add(a, b) << std::endl;
			break;
		case '-':
			std::cout << "Введите два целых числа: ";
			std::cin >> a >> b;
			std::cout << a << " - " << b << " = " << sub(a, b) << std::endl;
			break;
		case '*':
			std::cout << "Введите два целых числа: ";
			std::cin >> a >> b;
			std::cout << a << " * " << b << " = " << mul(a, b) << std::endl;
			break;
		case '/':
			std::cout << "Введите два целых числа: ";
			std::cin >> a >> b;
			if (b == 0) {
				std::cout << "Делить на ноль нельзя!" << std::endl;
				continue;
			}
			std::cout << a << " / " << b << " = " << divide(a, b) << std::endl;
			break;
		case '^': {
			std::cout << "Введите два целых числа: ";
			std::cin >> a >> b;
			if (a == 0 && b == 0) {
				std::cout << "Невозможно решить неопределённость 0 ^ 0!" << std::endl;
				continue;
			}
			std::cout << a << " ^ " << b << " = " << power(a,b) << std::endl;
			break;
		}
		default:
			std::cout << "Неизвестная операция: '" << operation << "'" << std::endl;
		}
	} while (operation != 'q');

	return 0;
}