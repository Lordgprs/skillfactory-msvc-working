#pragma once
#include "Snack.h"

class SnackSlot {
public:
	SnackSlot();
	SnackSlot(unsigned short capacity, bool installed = false);
	SnackSlot(const SnackSlot &slot);
	~SnackSlot();
	unsigned short getSize() const;
	unsigned short getCapacity() const;
	void setCapacity(unsigned short capacity);
	void addSnack(Snack *snack);
	void removeSnack(unsigned short snack);
	bool isEmpty() const;
	bool isInstalled() const;
	void install();
	void uninstall();
	double getPrice() const;
	void setPrice(double price);
	void pop();
	SnackSlot &operator++();
	SnackSlot &operator++(int);
	SnackSlot &operator--();
	SnackSlot &operator--(int);
	Snack &operator[](unsigned short index);
	friend std::ostream &operator<<(std::ostream &os, SnackSlot &slot);

private:
	Snack **snacks_;					// Array of snacks (pointers to these)
	unsigned short size_;			// Installed snacks count
	unsigned short capacity_; // Count of cells for snacks
	bool installed_;					// We can work only with slots that not installed int machine; 
														// otherwise, we only can to remove the top item when the machine sales it
														// default: false
	double price_;						// Each snack in the same slot must have the same price
};

