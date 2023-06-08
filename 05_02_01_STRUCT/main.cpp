#include "human.h"

#include <iostream>

int main() {
	const unsigned short kCurrentYear = 2023;
	module_oop::Human* human = new module_oop::Human{ "Maksim", "Velgach", 34, 105, 187, module_oop::kProgrammer };
	module_oop::Human human2{ "Vasya" };

	human->set_first_name("Maksim2");
	std::cout << *human << std::endl;
	std::cout << human2 << std::endl;
	++human2;
	std::cout << human2 << std::endl;
	human2++;
	std::cout << human2 << std::endl;
	std::cout << (human2 < *human) << std::endl;
	std::cout << (human2 > *human) << std::endl;
	


	delete human;
	return 0;
}