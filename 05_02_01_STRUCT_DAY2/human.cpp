#include "human.h"
#include <iostream>
#include <string>

namespace module_oop {
	double Human::Imt() const {
		return (weight_ / 2.205) / ((height_ / 39.37) * (height_ / 39.37));
	}

	unsigned short Human::YearOfBirth(const unsigned short current_year) const {
		return current_year - age_;
	}

	void Human::PrintHuman() const {
		std::cout << "Name: " << first_name_ << " " << last_name_ <<
			"\nAge: " << age_ <<
			"\nHeight: " << height_ <<
			"\nWeight: " << weight_ << "\n" << std::endl;
	}

	Human::Human() :
		first_name_{ "Unnamed" },
		last_name_{ "" },
		age_{ 18 },
		weight_{ 80 },
		height_{ 175 } {}

	Human::Human(std::string first_name, std::string last_name, const unsigned short age, const unsigned short weight, const unsigned short height, const Occupation occupation = kStudent) :
		first_name_{ first_name },
		last_name_{ last_name },
		age_{ age },
		weight_{ weight },
		height_{ height },
		occupation_{ occupation } {}

	Human::Human(std::string first_name, std::string last_name) :
		first_name_{ first_name },
		last_name_{ last_name },
		age_{ 18 },
		weight_{ 80 },
		height_{ 175 } {}

	Human::Human(const Human &human) {
		first_name_ = human.first_name_;
		last_name_ = human.last_name_;
		age_ = human.age_;
		weight_ = human.weight_;
		height_ = human.height_;
	}

	void Human::set_first_name(std::string new_name) {
		first_name_ = new_name;
	}
	void Human::set_last_name(std::string new_name) {
		last_name_ = new_name;
	}
	void Human::set_age(const unsigned short new_age) {
		age_ = new_age;
	}
	void Human::set_weight(const unsigned short new_weight) {
		weight_ = new_weight;
	}
	void Human::set_height(const unsigned short new_height) {
		height_ = new_height;
	}
	std::string Human::get_first_name() const {
		return first_name_;
	}
	std::string Human::get_last_name() const {
		return last_name_;
	}
	unsigned short Human::get_age() const {
		return age_;
	}
	unsigned short Human::get_weight() const {
		return weight_;
	}
	unsigned short Human::get_height() const {
		return height_;
	}

	Human Human::operator++() {
		++height_;
		return *this;
	}
	Human Human::operator++(int) {
		Human temp(*this);
		++(*this);
		return temp;
	}
	Human Human::operator--() {
		--height_;
		return *this;
	}
	Human Human::operator--(int) {
		Human temp(*this);
		--(*this);
		return *this;
	}

	bool Human::operator<(const Human &other) const {
		return height_ < other.height_;
	}
	bool Human::operator>(const Human &other) const {
		return height_ > other.height_;
	}
	std::ostream &operator<<(std::ostream &os, const Human &human) {
		os << "Name: " << human.first_name_ << " " << human.last_name_ <<
			"\nAge: " << human.age_ <<
			"\nHeight: " << human.height_ <<
			"\nWeight: " << human.weight_ << 
			"\nOccupation: " << human.occupation_ << "\n" << std::endl;
		return os;
	}
}
