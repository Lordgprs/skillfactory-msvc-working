#include "VendingMachine.h"
#include "SnackSlot.h"

VendingMachine::VendingMachine():
	capacity_{ 0 },
	size_{ 0 },
	manufacturer_{ std::string{} },
	model_{ std::string{} },
	year_{ kFirstYear },
	weight_{ 0 },
	balance_{ 0.0 },
	slots_{ nullptr }
{}

VendingMachine::VendingMachine(const std::string &manufacturer, const std::string &model, unsigned short year, unsigned short slot_count):
	capacity_{ slot_count },
	manufacturer_{ manufacturer },
	model_{ model },
	year_{ year },
	size_{ 0 },
	balance_{ 0.0 } {
	if (slot_count == 0) {
		return;
	}
	slots_ = new SnackSlot * [slot_count];
	for (unsigned short i = 0; i < slot_count; ++i) {
		slots_[i] = nullptr;
	}
}

VendingMachine::VendingMachine(unsigned short slot_count) :
	capacity_{ slot_count },
	size_{ 0 },
	manufacturer_{ std::string{} },
	model_{ std::string{} },
	year_{ 1970 },
	weight_{ 0 } {
	if (slot_count == 0) {
		slots_ = nullptr;
		return;
	}
	slots_ = new SnackSlot * [slot_count];
	for (unsigned short i = 0; i < slot_count; ++i) {
		slots_[i] = nullptr;
	}
}

void VendingMachine::addSlot(SnackSlot *slot) {
	if (size_ == capacity_) {
		// Machine is too small, we can't add a new slot here
		return;
	}
	slot->install();
	slots_[size_++] = slot;
}

void VendingMachine::removeSlot(const unsigned short index) {
	if (isEmpty()) {
		std::cerr << "class VendingMachine removeSlot: array is empty" << std::endl;
		return;
	}
	if (index >= size_) {
		std::cerr << "class VendingMachine removeSlot: index out of range" << std::endl;
		return;
	}
	(*this)[index].uninstall();
	--size_;
	// Shifting all array items left
	for (unsigned short i = index; i < size_; ++i) {
		slots_[i] = slots_[i + 1];
	}
	slots_[size_] = nullptr;
}

unsigned short VendingMachine::getEmptySlotsCount() const {
	unsigned short count = 0;
	for (unsigned short i = 0; i < size_; ++i) {
		if (slots_[i]->isEmpty()) {
			++count;
		}
	}
	return count;
}

unsigned short VendingMachine::getUninstalledSlotsCount() const {
	return capacity_ - size_;
}

VendingMachine::~VendingMachine() {
	delete[] slots_;
}

unsigned short VendingMachine::getCapacity() const {
	return capacity_;
}

unsigned short VendingMachine::getSize() const {
	return size_;
}

void VendingMachine::sellSnack(unsigned short slot) {
	if (isEmpty()) {
		std::cerr << "class VendingMachine sellSnack: array is empty" << std::endl;
		return;
	}
	if (slot >= size_) {
		std::cerr << "class VendingMachine sellSnack: index out of range" << std::endl;
		return;
	}
	if (!(*this)[slot].isInstalled()) {
		std::cerr << "class VendingMachine sellSnack: slot is not installed in machine" << std::endl;
		return;
	}
	if ((*this)[slot].isEmpty()) {
		std::cerr << "class VendingMachine sellSnack: slot is empty" << std::endl;
		return;
	}
	balance_ += (*this)[slot].getPrice();
}

bool VendingMachine::isEmpty() const {
	return size_ == 0;
}

SnackSlot &VendingMachine::operator[](const unsigned short index) {
	if (isEmpty()) {
		std::cerr << "class VendingMachine operator[]: array is empty" << std::endl;
		// Nothing to return: program will crash
	}
	// If index is out of range, returning last array item
	if (index >= size_) {
		std::cerr << "class VendingMachine operator[]: index out of range" << std::endl;
		return *(slots_[size_ - 1]);
	}
	return *(slots_[index]);
}

double VendingMachine::getBalance() const {
	return balance_;
}

std::ostream &operator<<(std::ostream &os, VendingMachine &machine) {
	if(!machine.manufacturer_.empty()) {
		os << "Manufacturer: " << machine.manufacturer_ << "\n";
	}
	if (!machine.model_.empty()) {
		os << "Model: " << machine.model_ << "\n";
	}
	if (machine.year_ > machine.kFirstYear) {
		os << "Year of manufacturing: " << machine.year_ << "\n";
	}
	os << "Vending machine capacity is " << machine.capacity_ << " slots\n" <<
		"There are " << machine.size_ << " slots installed\n" <<
		"Machine current balance is " << machine.balance_ << "\n";

	for (unsigned short i = 0; i < machine.size_; ++i) {
		os << i + 1 << ") Slot #" << i + 1 << "\n" <<
			machine[i] << "\n";
	}

	return os;
}
