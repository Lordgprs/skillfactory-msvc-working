#include <iostream>

int main() {
	system("chcp 1251");

	char operation;
	float result;
	int a, b;
	do {
		std::cout << "----------------------------------" << std::endl << std::endl <<
			"������� ��������: ";
		std::cin >> operation;

		switch (operation) {
		case 'q':
			std::cout << "�������. �� ����� ������!" << std::endl;
			break;
		case '!':
			std::cout << "������� ��������������� ����� �����: ";
			std::cin >> a;
			result = 1.0;
			if (a < 0) {
				std::cout << "��������� ����� ��������� ������ �� ���������������� ������ �����!" << std::endl;
				continue;
			}

			for (int i = 1; i <= a; i++) {
				result *= i;
			}
			std::cout << a << "! = " << result << std::endl;
			break;
		case '+':
			std::cout << "������� ��� ����� �����: ";
			std::cin >> a >> b;
			std::cout << a << " + " << b << " = " << (a + b) << std::endl;
			break;
		case '-':
			std::cout << "������� ��� ����� �����: ";
			std::cin >> a >> b;
			std::cout << a << " - " << b << " = " << (a - b) << std::endl;
			break;
		case '*':
			std::cout << "������� ��� ����� �����: ";
			std::cin >> a >> b;
			std::cout << a << " * " << b << " = " << (a * b) << std::endl;
			break;
		case '/':
			std::cout << "������� ��� ����� �����: ";
			std::cin >> a >> b;
			if (b == 0) {
				std::cout << "������ �� ���� ������!" << std::endl;
				continue;
			}
			std::cout << a << " / " << b << " = " << (static_cast<float>(a) / b) << std::endl;
			break;
		case '^': {
			std::cout << "������� ��� ����� �����: ";
			std::cin >> a >> b;
			if (a == 0 && b == 0) {
				std::cout << "���������� ������ ��������������� 0 ^ 0!" << std::endl;
				continue;
			}
			result = 1.0;

			int abs_exponent = b < 0 ? -b : b;
			for (int i = 0; i < abs_exponent; i++) {
				result *= a;
			}
			if (b < 0) {
				result = 1.0 / result;
			}
			std::cout << a << " ^ " << b << " = " << result << std::endl;
			break;
		}
		default:
			std::cout << "����������� ��������: '" << operation << "'" << std::endl;
		}
	} while (operation != 'q');

	return 0;
}