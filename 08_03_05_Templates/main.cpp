#include <iostream>
#include <string>

template <typename T>
T Max(T a, T b) {
	return a > b ? a : b;
}

template <typename T>
T Max(T a, T b, T c) {
	T temp{ Max<T>(a, b) };
	return Max<T>(temp, c);
}

int main() {
	int n1{ 1 };
	int n2{ 2 };
	int n3{ 3 };
	float f1{ 1.1 };
	float f2{ 2.2 };
	float f3{ 3.3 };
	std::string s1{"Test1"};
	std::string s2{"Test2"};
	std::string s3{"Test3"};
	
	std::cout << Max(n2, n1) << std::endl;
	std::cout << Max(n3, n2, n1) << std::endl;
	std::cout << Max(f2, f1) << std::endl;
	std::cout << Max(f3, f2, f1) << std::endl;
	std::cout << Max(s2, s1) << std::endl;
	std::cout << Max(s3, s2, s1) << std::endl;

	return EXIT_SUCCESS;
}