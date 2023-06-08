#pragma once
#include <iostream>
#include <string>

namespace module_oop {
	enum Occupation {
		kTeacher = 0,
		kStudent,
		kProgrammer
	};

	class Human {
	private:
		std::string first_name_; // Строковые литералы в C++ имеют тип const char*
		std::string last_name_;
		unsigned short age_;
		unsigned short weight_;
		unsigned short height_;
		Occupation occupation_;

	public:
		// Функции, являющиеся членами класса, называются методами или функциями-членами
		double Imt() const;
		unsigned short YearOfBirth(unsigned short current_year) const;
		void PrintHuman() const;
		Human();
		Human(std::string first_name, std::string last_name, unsigned short age, unsigned short weight, unsigned short height, Occupation occupation);
		Human(std::string first_name, std::string last_name);
		Human(std::string last_name);
		Human(const Human &human);
		void set_first_name(std::string new_name);
		void set_last_name(std::string new_name);
		void set_age(unsigned short new_age);
		void set_weight(unsigned short new_weight);
		void set_height(unsigned short new_height);
		std::string get_first_name() const;
		std::string get_last_name() const;
		unsigned short get_age() const;
		unsigned short get_weight() const;
		unsigned short get_height() const;
		Human operator++();
		Human operator++(int);
		Human operator--();
		Human operator--(int);
		bool operator<(const Human &other) const;
		bool operator>(const Human &other) const;
		friend std::ostream &operator<<(std::ostream &os, const module_oop::Human &human);
	};
}


