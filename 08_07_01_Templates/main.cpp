#include <iostream>
#include <string>

template <typename T>
void show(T arg) {
	std::cout << arg << std::endl;
}

template <typename T, typename ... Args>
void show(T arg, Args ... args) {
	std::cout << arg << "; ";
	show(args ...);
}



int main() {
	std::string s1{"Test 1"};
	std::string s2{"Test 2"};
	auto a{ 5 };
	auto p{ 0.33 };

	show(s1, s2, a, p);

	return EXIT_SUCCESS;
}