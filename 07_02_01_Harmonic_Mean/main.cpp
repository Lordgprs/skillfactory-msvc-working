#include <iostream>
#include <cassert>

class BadHarmonicMean {
public:
	BadHarmonicMean(const float value):
		value_{ value } { }

	void Show() const {
		std::cerr << "Harmonic mean exception: " << value_ << std::endl;
	}

private:
	float value_;
};

void HarmonicMean(const float arr[], const size_t size, float &hmean) {
	if (size == 0) {
		throw BadHarmonicMean{static_cast<float>(size)};
	}
	const float epsilon = 1e-4;
	float sum = 0.0;
	for (size_t i = 0; i < size; ++i) {
		if (abs(arr[i]) < epsilon) {
			throw BadHarmonicMean{arr[i]};
		}
		sum = sum + 1.0 / arr[i];
	}
	if (abs(sum) < epsilon) {
		throw BadHarmonicMean{sum};
	}
	hmean = size / sum;
}

int main() {
	float array1[]{ 0.0, 0.0 };
	float array2[]{ 1.5, -1.5 };
	float array3[]{ 2.3, 0.5 };
	float hmean = 0.0;

	try {
		HarmonicMean(array1, sizeof(array1) / sizeof(array1[0]), hmean);
		std::cout << hmean << std::endl;
	}
	catch (const BadHarmonicMean &bhm) {
		std::cerr << "Array 1 processing error: ";
		bhm.Show();
	};
	try {
		HarmonicMean(array2, sizeof(array2) / sizeof(array2[0]), hmean);
		std::cout << hmean << std::endl;
	}
	catch (const BadHarmonicMean &bhm) {
		std::cerr << "Array 2 processing error: ";
		bhm.Show();
	};
	try {
		HarmonicMean(array3, sizeof(array3) / sizeof(array3[0]), hmean);
		std::cout << hmean << std::endl;
	}
	catch (const BadHarmonicMean &bhm) {
		std::cerr << "Array 3 processing error: ";
		bhm.Show();
	};

	return 0;
}