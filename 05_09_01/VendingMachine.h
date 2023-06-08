#pragma once
#include "SnackSlot.h"
#include <iostream>
#include <string>

class VendingMachine {
public:
	VendingMachine();
	VendingMachine(const std::string &manufacturer, const std::string &model, unsigned short year, unsigned short slot_count);
	VendingMachine(unsigned short slot_count);
	void addSlot(SnackSlot *slot);
	void removeSlot(unsigned short index);
	unsigned short getEmptySlotsCount() const; // Count of slots that are installed in the machine, but are empty
	unsigned short getUninstalledSlotsCount() const; // Count of slots that are not installed int the machine (free cells count)
	~VendingMachine();
	unsigned short getCapacity() const;
	unsigned short getSize() const;
	void setCapacity(unsigned short capacity);
	void sellSnack(unsigned short slot);
	bool isEmpty() const;
	SnackSlot &operator[](unsigned short index);
	double getBalance() const;

	friend std::ostream &operator<<(std::ostream &os, VendingMachine &machine);

private:
	double balance_; // Money amount in the machine;
	const unsigned short kFirstYear = 1970;
	unsigned short capacity_;
	unsigned short size_;
	std::string manufacturer_;
	std::string model_;
	unsigned short year_;
	unsigned short weight_;
	SnackSlot **slots_;
};

