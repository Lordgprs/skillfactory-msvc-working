#pragma once
#include <iostream>
#include <string>

namespace module_oop {
	enum Occupation {
		kTeacher = 0,
		kWorker,
		kScientist,
		kProgrammer,
		kStudent
	};

	class Human {
	public:
		Human(const char* first_name, const char* last_name, unsigned short age, unsigned short weight, unsigned short height, Occupation occupation = kStudent);
		Human(const char* first_name);
		Human(const Human& human);
		void Print() const;
		unsigned short YearOfBirth(unsigned short current_year) const;
		double Imt() const;
		std::string &get_first_name() const;
		std::string &get_last_name() const;
		unsigned short get_age() const;
		unsigned short get_weight() const;
		unsigned short get_height() const;
		void set_first_name(const char* name);
		void set_last_name(const char* name);
		void set_age(unsigned short age);
		void set_weight(unsigned short weight);
		void set_height(unsigned short height);
		Human& operator++();
		Human operator++(int);
		Human& operator--();
		Human operator--(int);
		bool operator<(const Human& human);
		bool operator>(const Human& human);
		friend std::ostream& operator<<(std::ostream& os, const Human& human);
		~Human() = default;

	private:
		std::string first_name;
		std::string last_name;
		unsigned short age;
		unsigned short weight;
		unsigned short height;
		Occupation occupation;
	};
}