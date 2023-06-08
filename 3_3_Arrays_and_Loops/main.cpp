#include <iostream>

int main() {
	// Ex. 3.3.1
	int array[7] = {2, 3, 4, 5, 2, 8, 10};
	for (int i = 0; i < 7; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;

	// Ex. 3.3.2
	int arr[] = { 500, 4, 24, 15, 100, 105 };
	int sum = 0;
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
		sum += arr[i];
	}
	std::cout << "Sum = " << sum << std::endl;

	// Ex. 3.3.3
	int divisor = 0;
	while (divisor == 0) {
		std::cout << "Enter not null divisor: ";
		std::cin >> divisor;
		if (divisor == 0) {
			continue;
		}
		int dividing_count = 0;
		for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
			if (arr[i] % divisor == 0) {
				++dividing_count;
			}
		}
		std::cout << "There are " << dividing_count << " items in the array that are dividing by " << divisor << std::endl;
	}

	// Ex. 3.3.4
	int arr2[] = { 5, 4, 3, 4, 9 };
	int min = arr2[0];
	for (int i = 0; i < sizeof(arr2) / sizeof(arr2[0]); ++i) {
		if (arr2[i] < min) {
			min = arr2[i];
		}
	}
	std::cout << "Array minimum item is " << min << std::endl;

	// Ex. 3.3.5
	int arr3[] = { 5, 4, 3, 4, 9 };
	min = arr3[0];
	int max = arr3[0];
	int pos_max = 0;
	for (int i = 0; i < sizeof(arr3) / sizeof(arr3[0]); ++i) {
		if (arr3[i] < min) {
			min = arr3[i];
		}
		if (arr3[i] > max) {
			max = arr3[i];
			pos_max = i;
		}
	}
	std::cout << "Array max and min delta is " << max - min << ", max element position is " << pos_max << std::endl;

	return 0;
}