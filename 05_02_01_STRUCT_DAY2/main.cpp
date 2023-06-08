#include "human.h"
#include <iostream>

int main() {
	const unsigned short current_year = 2023;
	module_oop::Human human1;	// Ёкземпл€р структуры
	human1.set_first_name("Maksim");
	human1.set_last_name("Velgach");
	human1.set_age(34);
	human1.set_height(187);
	human1.set_weight(105);
	module_oop::Human human5{ human1 };
	module_oop::Human human2 = { "Vasya", "Pupkin", 18, 175, 80, module_oop::kStudent };
	module_oop::Human human3{ "Vasya", "Pisechkin", 45, 170, 70, module_oop::kProgrammer}; // ”ниверсальна€ инициализаци€ (uniform initialization)
	module_oop::Human *human4 = new module_oop::Human{"Testname", "Testsurname", 20, 85, 190, module_oop::kProgrammer};
	++(*human4);
	std::cout << (*human4) << std::endl;
	(*human4)++;
	std::cout << (*human4) << std::endl;
	//std::cout << "Imt: " << human4->Imt() <<
	//	"\nYear of birth: " << human4->YearOfBirth(current_year);

	delete human4;
	return EXIT_SUCCESS;
}
