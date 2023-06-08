#include "SnackSlot.h"
#include "Snack.h"

SnackSlot::SnackSlot():
  snacks_{ nullptr },
  capacity_{ 0 },
  size_{ 0 },
  installed_{ false },
  price_{ 0.0 } {}

SnackSlot::SnackSlot(const unsigned short capacity, bool installed):
  capacity_{ capacity },
  size_{ 0 },
  installed_{ installed },
  price_{ 0.0 } {
  if (capacity == 0) {
    snacks_ = nullptr;
    return;
  }
  snacks_ = new Snack*[capacity];
  for (unsigned short i = 0; i < capacity; ++i) {
    snacks_[i] = nullptr;
  }
}

SnackSlot::SnackSlot(const SnackSlot &slot):
  capacity_{ slot.capacity_ },
  size_{ slot.size_ },
  installed_{ slot.installed_ },
  price_{ slot.price_ } {
  if (capacity_ == 0) {
    snacks_ = nullptr;
    return;
  }
  snacks_ = new Snack * [capacity_];
  for (unsigned short i = 0; i < capacity_; ++i) {
    snacks_[i] = slot.snacks_[i];
  }
}

SnackSlot::~SnackSlot() {
  delete[] snacks_;
}

unsigned short SnackSlot::getSize() const {
    return size_;
}

unsigned short SnackSlot::getCapacity() const {
    return capacity_;
}

void SnackSlot::setCapacity(const unsigned short capacity) {
  if (installed_) {
    std::cerr << "SnackSlot::setCapacity: cannot modify slot when it is installed to machine" << std::endl;
    return;
  }
  //Current capacity and new capacity are equal: doing nothing
  if (capacity == capacity_) {
    return;
  }
  unsigned short min = capacity < capacity_ ? capacity : capacity_;
  Snack **new_snacks = new Snack*[capacity];
  for (unsigned short i = 0; i < min; ++i) {
    new_snacks[i] = snacks_[i];
  }
  // If this method is called for reduce slot size
  if (min == capacity) {
    // We have to remove snacks that will overflow this slot after its size change 
    if (capacity < size_) {
      size_ = capacity;
    }
  }
  // Otherwise, this method is called to enlarge slot size: filling new empty slots with nullptr
  for (unsigned short i = capacity_; i < capacity; ++i) {
    new_snacks[i] = nullptr;
  }
  delete[] snacks_;
  capacity_ = capacity;
  snacks_ = new_snacks;
  return;
}

void SnackSlot::addSnack(Snack *snack) {
  if (installed_) {
    std::cerr << "SnackSlot::addSnack: cannot modify slot when it is installed to machine" << std::endl;
    return;
  }
  if (size_ == capacity_) {
    // Slot is too small, we can't add a new snack here
    return;
  }
  snacks_[size_++] = snack;
}

void SnackSlot::removeSnack(const unsigned short snack) {
  if (isEmpty()) {
    std::cerr << "class SnackSlot removeSnack: array is empty" << std::endl;
    return;
  }
  if (snack >= size_) {
    std::cerr << "class SnackSlot removeSnack: index out of range" << std::endl;
    return;
  }
  if (installed_) {
    std::cerr << "class SnackSlot operator++: cannot modify slot when it is installed to machine" << std::endl;
    return;
  }
  --size_;
  // Shifting all array items left
  for (unsigned short i = snack; i < size_; ++i) {
    snacks_[i] = snacks_[i + 1];
  }
  snacks_[size_] = nullptr;
}

bool SnackSlot::isEmpty() const {
  return size_ == 0;
}

bool SnackSlot::isInstalled() const {
  return installed_;
}

void SnackSlot::install() {
  installed_ = true;
}

void SnackSlot::uninstall() {
  installed_ = false;
}

double SnackSlot::getPrice() const {
  return price_;
}

void SnackSlot::setPrice(double price) {
  if (price <= 0.0) {
    std::cerr << "SnackSlot::setPrice: price have to be greater than zero" << std::endl;
    return;
  }
  price_ = price;
}

void SnackSlot::pop() {
  if (isEmpty()) {
    std::cerr << "SnackSlot::pop: array is empty" << std::endl;
  }
  snacks_[--size_] = nullptr;
}

SnackSlot &SnackSlot::operator++() {
  if (installed_) {
		std::cerr << "SnackSlot::operator++: cannot modify slot when it is installed to machine" << std::endl;
		return (*this);
	}
  setCapacity(capacity_ + 1);
  return *this;
}

SnackSlot &SnackSlot::operator++(int) {
  if (installed_) {
    std::cerr << "SnackSlot::operator++: cannot modify slot when it is installed to machine" << std::endl;
    return (*this);
  }
  SnackSlot temp{ *this };
  ++(*this);
  return temp;
}

SnackSlot &SnackSlot::operator--() {
  if (installed_) {
    std::cerr << "SnackSlot::operator--: cannot modify slot when it is installed to machine" << std::endl;
    return (*this);
  }
  setCapacity(capacity_ - 1);
  return *this;
}

SnackSlot &SnackSlot::operator--(int) {
  if (installed_) {
    std::cerr << "SnackSlot::operator--: cannot modify slot when it is installed to machine" << std::endl;
    return (*this);
  }
  SnackSlot temp{ *this };
  --(*this);
  return temp;
}

Snack &SnackSlot::operator[](const unsigned short index) {
  if (isEmpty()) {
    std::cerr << "class SnackSlot operator[]: array is empty" << std::endl;
    // Nothing to return: program will crash
  }
  // If index is out of range, returning last array item
  if (index >= size_) {
    std::cerr << "class SnackSlot operator[]: index out of range" << std::endl;
    return *(snacks_[size_ - 1]);
  }
  return *(snacks_[index]);
}

std::ostream &operator<<(std::ostream &os, SnackSlot &slot) {
  os << "Slot capacity: " << slot.capacity_ << "\n" <<
    "Now there is " << slot.size_ << " snacks in this slot:" << "\n";
  for (unsigned short i = 0; i < slot.size_; ++i) {
    os << static_cast<char>(i + 'a') << ") " << slot[i] << "\n";
  }
  os << "\n";
  return os;
}
