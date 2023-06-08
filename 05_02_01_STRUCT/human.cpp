#include "human.h"

#include <iostream>
namespace module_oop {
	void Human::Print() const {
		std::cout << "First name: " << first_name << "\n" <<
			"Last name: " << last_name << "\n" <<
			"Age: " << age << "\n" <<
			"Weight: " << weight << "\n" <<
			"Height: " << height << std::endl;
	}

	unsigned short Human::YearOfBirth(const unsigned short current_year) const {
		return current_year - age;
	}

	double Human::Imt() const {
		double meters = height;
		return (weight / 2.205) / (meters / 39.37) / (meters / 39.37);
	}

	std::string &module_oop::Human::get_first_name() const {
		return first_name;
	}

	std::string &module_oop::Human::get_last_name() const {
		return last_name;
	}

	unsigned short Human::get_age() const {
		return this->age;
	}

	unsigned short Human::get_weight() const {
		return this->weight;
	}

	unsigned short Human::get_height() const {
		return this->height;
	}

	void Human::set_first_name(const char* name) {
		this->first_name = name;
	}

	void Human::set_last_name(const char* name) {
		this->last_name = name;
	}

	void Human::set_age(const unsigned short age) {
		this->age = age;
	}

	void Human::set_weight(const unsigned short weight) {
		this->weight = weight;
	}

	void Human::set_height(const unsigned short height) {
		this->height = height;
	}

	Human& Human::operator++() {
		++height;
		return *this;
	}

	Human Human::operator++(int) {
		Human temp{ *this };
		++(*this);
		return temp;
	}

	Human& Human::operator--() {
		--height;
		return*this;
	}

	Human Human::operator--(int) {
		Human temp{ *this };
		--(*this);
		return temp;
	}

	bool Human::operator<(const Human& human) {
		return height < human.height;
	}

	bool Human::operator>(const Human& human) {
		return height > human.height;
	}

	Human::Human(const char* first_name, const char* last_name, unsigned short age, unsigned short weight, unsigned short height, Occupation occupation) :
		first_name{ first_name },
		last_name{ last_name },
		age{ age },
		weight{ weight },
		height{ height },
		occupation{ occupation } {}

	Human::Human(const char* first_name) :
		first_name{ first_name },
		last_name{ "" },
		age{ 18 },
		weight{ 80 },
		height{ 175 } {}

	Human::Human(const Human& human) {
		age = human.age;
		weight = human.weight;
		height = human.height;
		first_name = human.first_name;
		last_name = human.last_name;
	}

	std::ostream& operator<<(std::ostream& os, const Human& human) {
		os << "First name: " << human.first_name << "\n" <<
			"Last name: " << human.last_name << "\n" <<
			"Age: " << human.age << "\n" <<
			"Weight: " << human.weight << "\n" <<
			"Height: " << human.height << "\n" << 
			"Occupation: " << human.occupation << std::endl;
		return os;
	}
}