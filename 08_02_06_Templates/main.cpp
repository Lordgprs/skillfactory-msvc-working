#include <iostream>
#include <string>

template <typename T>
void show(T a) {
	std::cout << "Значение аргумента функции равно " << a << std::endl;
}

int main() {
	setlocale(LC_ALL, "");

	int n{ 5 };
	double a{ 1.5 };
	std::string s{"Test"};
	show<int>(n);
	show<double>(a);
	show<std::string>(s);
	show("Test");

	return EXIT_SUCCESS;
}