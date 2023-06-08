#include <iostream>

int main() {
	system("chcp 1251");
	char operation;
	constexpr int difference = 'Z' - 'A' + 1;

	do {
		std::cout << std::endl <<
			"--------------------" << std::endl <<
			"�������� ��������. ������� ���� �������� ��������� �����" << std::endl <<
			"\t- 'c' ��� ����������;" << std::endl <<
			"\t- 'd' ��� ����������" << std::endl <<
			"\t- 'q' ��� ������" << std::endl <<
			"��������: ";
		std::cin >> operation;

		switch (operation) {
		case 'q':
			std::cout << "������� �� ���������..." << std::endl;
			break;

		case 'c':
		case 'd': {
			int length, x;
			bool errors_occured = false;
			char min_value, max_value;
			std::cout << "������� ����� �������� ������: ";
			std::cin >> length;
			std::cout << "������� ������ ������: ";
			std::cin >> x;
			x %= difference;
			if (operation == 'd') {
				x = -x;
			}
			std::cout << "������� ������ ������ " << length << " ��������: ";
			char* arr = new char[length + 1];
			std::cin >> arr;

			if (arr[length] != '\0') {
				std::cout << "������: ����� �������� ������ �� ������������� ����������!" << std::endl;
				delete[] arr;
				continue;
			}

			for (int i = 0; i < length; ++i) {
				if (arr[i] == '\0') {
					std::cout << "������: ����� �������� ������ �� �������c����� ����������!" << std::endl;
					errors_occured = true;
					break;
				}
				if (!(arr[i] >= 'a' && arr[i] <= 'z' || arr[i] >= 'A' && arr[i] <= 'Z')) {
					std::cout << "��������������: ��������� ������������ ������ '" << arr[i] << "'. ����������..." << std::endl;
					continue;
				}
				if (arr[i] >= 'a' && arr[i] <= 'z') {
					min_value = 'a';
					max_value = 'z';
				}
				else {
					min_value = 'A';
					max_value = 'Z';
				}
				arr[i] = min_value + (arr[i] - min_value + x) % difference;
				if (arr[i] < min_value) {
					arr[i] += difference;
				}
			}
			if (errors_occured) {
				delete[] arr;
				continue;
			}

			if (operation == 'c') {
				std::cout << "����������� ������: ";
			}
			else {
				std::cout << "������������� ������: ";
			}
			std::cout << arr << std::endl;
			delete[] arr;
			break;
		}

		default:
			std::cout << "����������� ��������: ���������� ��� ���" << std::endl;
		}
	} while (operation != 'q');

	return 0;
}