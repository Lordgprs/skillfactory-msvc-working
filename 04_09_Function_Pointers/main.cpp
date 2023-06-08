#include <iostream>

int foo(int a) {
	return a++;
}

bool Ascending(int a, int b) {
	return a > b;
}

bool Descending(int a, int b) {
	return a < b;
}

void BubbleSort(int* arr, int n, bool (*compare)(int, int)) {
	for (size_t i = 0; i < n - 1; ++i) {
		for (size_t j = 0; j < n - i - 1; ++j) {
			if ((*compare)(arr[j], arr[j + 1])) {
				arr[j] ^= arr[j + 1];
				arr[j + 1] ^= arr[j];
				arr[j] ^= arr[j + 1];
			}
		}
	}
}

void ShowElement(int e) {
	std::cout << e << " ";
}

void ShowElementMod(int e) {
	e = e < 0 ? -e : e;
	std::cout << e << " ";
}

void proccessArray(int* arr, int size, void (*callback)(int)) {
	for (int i = 0; i < size; ++i) {
		(*callback)(arr[i]);
	}
	std::cout << std::endl;
}

int main() {
	int arr[10] = { 0, 1, -6, 87, -4, -7, 9, 11, -34, 2 };
	for (auto item : arr) {
		std::cout << item << " ";
	}
	std::cout << "\n";
	bool ascend = false;
	std::cout << "Sort type: ";
	std::cin >> ascend;
	bool (*sorter)(int, int) = ascend ? Ascending : Descending;
	BubbleSort(arr, 10, sorter);
	for (auto item : arr) {
		std::cout << item << " ";
	}
	std::cout << "\n";
	void (*callback)(int);
	bool abs_required;
	std::cout << "Show abs? ";
	std::cin >> abs_required;
	callback = abs_required ? ShowElementMod : ShowElement;
	proccessArray(arr, 10, callback);

	return 0;
}