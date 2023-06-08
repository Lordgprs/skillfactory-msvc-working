#include "Snack.h"
#include <string>

Snack::Snack(const std::string &name):
  name_{ name },
  calories_{ 0 },
  proteins_{ 0 },
  fats_{ 0 },
  carbohydrates_{ 0 },
  weight_{ 0 }
{}

Snack::Snack(const std::string &name, unsigned short calories, unsigned short weight):
  name_{ name },
  calories_{ calories },
  weight_{ weight }
{}

Snack::Snack(const Snack &other):
  name_{other.name_},
  calories_{other.calories_},
  proteins_{other.proteins_},
  fats_{other.fats_},
  weight_{other.weight_}
{}

std::string Snack::getName() const {
  return name_;
}

unsigned short Snack::getCalories() const {
    return calories_;
}

unsigned short Snack::getProteins() const {
    return proteins_;
}

unsigned short Snack::getFats() const {
    return fats_;
}

unsigned short Snack::getCarbohydrates() const {
    return carbohydrates_;
}

unsigned short Snack::getWeight() const {
    return weight_;
}

void Snack::setName(const std::string new_name) {
  name_ = new_name;
}

void Snack::setCalories(const unsigned short calories) {
  calories_ = calories;
}

void Snack::setProteins(const unsigned short proteins) {
  proteins_ = proteins;
}

void Snack::setFats(const unsigned short fats) {
  fats_ = fats;
}

void Snack::setCarbohydrates(const unsigned short carbohydrates) {
  carbohydrates_ = carbohydrates;
}

void Snack::setWeight(const unsigned short weight) {
  weight_ = weight;
}

std::ostream &operator<<(std::ostream &os, const Snack &snack) {
  os << "Name: " << snack.name_ << "\n" <<
    "Calories: " << snack.calories_ << "\n" <<
    "Proteins: " << snack.proteins_ << "\n" <<
    "Fats: " << snack.fats_ << "\n" <<
    "Carbohydrates: " << snack.carbohydrates_ << "\n" <<
    "Weight: " << snack.weight_;
  return os;
}
