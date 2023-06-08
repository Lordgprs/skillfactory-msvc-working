#pragma once
#include <iostream>
#include <string>

class Snack {
public:
	Snack() = delete; // We cannot have unnamed snack
	Snack(const std::string &name);
	Snack(const std::string &name, unsigned short calories, unsigned short weight);
	Snack(const Snack &other);
	std::string getName() const;
	unsigned short getCalories() const;
	unsigned short getProteins() const;
	unsigned short getFats() const;
	unsigned short getCarbohydrates() const;
	unsigned short getWeight() const;
	void setName(const std::string new_name);
	void setCalories(unsigned short calories);
	void setProteins(unsigned short proteins);
	void setFats(unsigned short fats);
	void setCarbohydrates(unsigned short carbohydrates);
	void setWeight(unsigned short weight);
	friend std::ostream &operator<<(std::ostream &os, const Snack &snack);

private:
	std::string name_;
	unsigned short calories_;
	unsigned short proteins_;
	unsigned short fats_;
	unsigned short carbohydrates_;
	unsigned short weight_;
};

