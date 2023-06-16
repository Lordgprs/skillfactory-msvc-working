#include <iostream>
#include <string>

template <typename T>
class MyPair {
public:
	void set_first(const T first) {
		first_ = first;
	}
	void set_second(const T second) {
		second_ = second;
	}
	T get_first() const {
		return first_;
	}
	T get_second() const {
		return second_;
	}
	MyPair(const T first, const T second) :
		first_{ first },
		second_{ second } {}
	T get_max() const {
		return first_ > second_ ? first_ : second_;
	}
private:
	T first_;
	T second_;
};

int main() {
	MyPair<int> int_pair{3, 2};
	MyPair<float> float_pair{3.3, 2.2};
	MyPair<std::string> string_pair{"Text 1", "Text 2"};

	std::cout << "Integer maximum: " << int_pair.get_max() << std::endl;
	std::cout << "Float maximum: " << float_pair.get_max() << std::endl;
	std::cout << "String maximum: " << string_pair.get_max() << std::endl;

	return EXIT_SUCCESS;
}