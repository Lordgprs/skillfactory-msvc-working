#include <iostream>

int main() {
	system("chcp 1251");
	char operation;
	constexpr int difference = 'Z' - 'A' + 1;

	do {
		std::cout << std::endl <<
			"--------------------" << std::endl <<
			"Выберите операцию. Введите одну строчную латинскую букву" << std::endl <<
			"\t- 'c' для шифрования;" << std::endl <<
			"\t- 'd' для дешифровки" << std::endl <<
			"\t- 'q' для выхода" << std::endl <<
			"Операция: ";
		std::cin >> operation;

		switch (operation) {
		case 'q':
			std::cout << "Выходим из программы..." << std::endl;
			break;

		case 'c':
		case 'd': {
			int length, x;
			bool errors_occured = false;
			char min_value, max_value;
			std::cout << "Введите длину исходной строки: ";
			std::cin >> length;
			std::cout << "Введите размер сдвига: ";
			std::cin >> x;
			x %= difference;
			if (operation == 'd') {
				x = -x;
			}
			std::cout << "Введите строку длиной " << length << " символов: ";
			char* arr = new char[length + 1];
			std::cin >> arr;

			if (arr[length] != '\0') {
				std::cout << "Ошибка: длина введённой строки не соответствует заявленной!" << std::endl;
				delete[] arr;
				continue;
			}

			for (int i = 0; i < length; ++i) {
				if (arr[i] == '\0') {
					std::cout << "Ошибка: длина введённой строки не соответcтвует заявленной!" << std::endl;
					errors_occured = true;
					break;
				}
				if (!(arr[i] >= 'a' && arr[i] <= 'z' || arr[i] >= 'A' && arr[i] <= 'Z')) {
					std::cout << "Предупреждение: обнаружен неалфавитный символ '" << arr[i] << "'. Пропускаем..." << std::endl;
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
				std::cout << "Шифрованная строка: ";
			}
			else {
				std::cout << "Дешифрованная строка: ";
			}
			std::cout << arr << std::endl;
			delete[] arr;
			break;
		}

		default:
			std::cout << "Неизвестная операция: попробуйте ещё раз" << std::endl;
		}
	} while (operation != 'q');

	return 0;
}