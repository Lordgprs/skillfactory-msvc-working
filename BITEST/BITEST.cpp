#include <iostream>
#include <string>
#include <memory>
#include <sstream>
#include <cassert>

class BigInteger {
public:
  BigInteger(const std::string s) {
    size_ = s.length();
    data_ = std::make_unique<uint16_t[]>(size_);
    for (size_t i = 0; i < size_; i++) {
      data_[i] = s[size_ - i - 1] - '0';
    }
  }
  BigInteger(const BigInteger& big_integer) : size_(big_integer.size_) {
    data_ = std::make_unique<uint16_t[]>(big_integer.size_);
    for (size_t i = 0; i < size_; i++) {
      data_[i] = big_integer.data_[i];
    }
  }
  BigInteger& operator=(const BigInteger& big_integer) {
    data_ = std::make_unique<uint16_t[]>(big_integer.size_);
    size_ = big_integer.size_;
    for (size_t i = 0; i < size_; i++) {
      data_[i] = big_integer.data_[i];
    }
    return *this;
  }
  BigInteger operator+(const BigInteger& a) {
    BigInteger b{ *this };
    std::stringstream s;
    s << a.ToString() << " + " << b.ToString() << " = ";
    auto max_size = a.size_ > b.size_ ? a.size_ : b.size_;
    bool remembered_value = false;
    for (size_t i = 0; i < max_size; i++) {
      if (b.size_ - 1 < i) {
        b.Expand();
      }
      uint16_t a_digit = (a.size_ + 1 < i) ? 0 : a.data_[i];
      //uint16_t a_digit = 0;
      uint16_t sum = b.data_[i] + a_digit;
      if (remembered_value) {
        sum++;
      }
      remembered_value = sum >= 10 ? true : false;
      b.data_[i] = sum % 10;
      //std::cout << " i: " << i << " a_digit: " << a_digit << " a.data_[i]: " << a.data_[i] << " b.data[i]: " << b.data_[i] << " sum: " << sum << " b.size_: " << b.size_ << std::endl;
    }
    if (remembered_value) {
      b.Expand();
      b.data_[b.size_ - 1] = 1;
    }
    s << b.ToString() << std::endl;
    //std::cout << s.str();
    return b;
  }
  BigInteger operator-(const BigInteger& b) {
    BigInteger result{ "0" };
    uint16_t remembered_value = 0;
    auto max_size = size_ > b.size_ ? size_ : b.size_;
    for (size_t i = 0; i < max_size; i++) {
      if (result.size_ - 1 < i) {
        result.Expand();
      }
      uint16_t b_digit = b.size_ - 1 < i ? 0 : b.data_[i];
      int16_t diff = data_[i] - b_digit - remembered_value;
      //std::cout << data_[i] << " " << b_digit << "-" << remembered_value << " " << diff << std::endl;
      if (diff < 0) {
        diff += 10;
        remembered_value = 1;
      }
      else {
        remembered_value = 0;
      }
      result.data_[i] = diff;
    }
    return result;
  }
  BigInteger operator*(const uint16_t a) const {
    //assert(a < 10);
    BigInteger b{ "0" };
    uint16_t remembered_value = 0;
    for (uint16_t i = 0; i < size_; i++) {
      uint16_t product = data_[i] * a + remembered_value;
      if (b.size_ - 1 < i) {
        b.Expand();
      }
      b.data_[i] = product % 10;
      remembered_value = product / 10;
    }
    if (remembered_value != 0) {
      b.Expand();
      b.data_[b.size_ - 1] = remembered_value;
    }
    return b;
  }
  BigInteger operator*(const BigInteger& a) const {
    BigInteger result{ "0" };
    for (size_t i = 0; i < size_; i++) {
      BigInteger intermediate = a * data_[i];
      intermediate.ShiftLeft(i);
      result = result + intermediate;
    }
    return result;
  }
  std::string ToString() const {
    std::stringstream s;
    //    std::cout << std::endl;
    for (int32_t i = static_cast<int32_t>(size_) - 1; i >= 0; i--) {
      //      std::cout << "Index: " << i << "; Value: " << data_[i] << std::endl;
      s << data_[i];
    }
    return s.str();
  }
  size_t size() const {
    return size_;
  }
  uint16_t digit(const size_t index) const {
    if (index > size_)
      return -1;
    return data_[size_ - index];
  }
  void ShiftLeft(size_t size) {
    if (size == 0) {
      return;
    }
    auto new_size = size_ + size;
    auto new_data = std::make_unique<uint16_t[]>(new_size);
    for (size_t i = 0; i < size; i++) {
      new_data[i] = 0;
    }
    for (size_t i = size; i < new_size; i++) {
      new_data[i] = data_[i - size];
    }
    data_ = std::move(new_data);
    size_ = new_size;
  }
  void Expand() {
    auto new_size = size_ + 1;
    auto new_data = std::make_unique<uint16_t[]>(new_size);
    for (size_t i = 0; i < size_; i++) {
      new_data[i] = data_[i];
    }
    new_data[size_] = 0;
    size_ = new_size;
    data_ = std::move(new_data);
  }

  friend std::ostream& operator<<(std::ostream& os, const BigInteger& big_integer) {
    return os << big_integer.ToString();
  }

private:
  std::unique_ptr<uint16_t[]> data_;
  size_t size_;
};

BigInteger Karatsuba(BigInteger& a, BigInteger& b) {
  std::stringstream s;
  BigInteger result{ "0" };
  if (a.size() == 1) {
    BigInteger result{ b * a.digit(1) };
    std::cout << b << " * " << a.digit(1) << " = " << result << std::endl;
    return result;
  }
  if (b.size() == 1) {
    return a * b.digit(1);
  }
  size_t b_half = b.size() / 2;
  size_t b_shift = b.size() - b_half;
  size_t a_left_size = a.size() - b_shift;
  size_t a_right_size = b_shift;
  BigInteger a_left{ a.ToString().substr(0, a_left_size) };
  BigInteger a_right{ a.ToString().substr(a.size() - b_shift, a_right_size) };
  BigInteger b_left{ b.ToString().substr(0, b_half) };
  BigInteger b_right{ b.ToString().substr(b_half, b.size() - b_half) };
  std::cout << std::endl << a_left << "|" << a_right << " * " << b_left << "|" << b_right << " = ";
  BigInteger a_lpr{ a_left + a_right };
  BigInteger b_lpr{ b_left + b_right };
  BigInteger a_lpr_m_b_lpr{ Karatsuba(a_lpr, b_lpr) };
  BigInteger a_left_m_b_left{ Karatsuba(a_left, b_left) };
  BigInteger a_right_m_b_right{ Karatsuba(a_right, b_right) };
  BigInteger a_left_m_b_left_shifted = a_left_m_b_left;
  a_left_m_b_left_shifted.ShiftLeft(b_shift * 2);
  BigInteger midsum = a_lpr_m_b_lpr - a_left_m_b_left - a_right_m_b_right;
  BigInteger midsum_shifted = midsum;
  midsum_shifted.ShiftLeft(b_shift);
  s << a_left_m_b_left << " * 10^" << (b_shift * 2) << "[" << a_left_m_b_left_shifted << "] + (" << a_lpr_m_b_lpr << "-" << a_left_m_b_left << "-" << a_right_m_b_right << ")[" << midsum << "] * 10^" << b_shift << "[" << midsum_shifted << "] + " << a_right_m_b_right;
  result = a_left_m_b_left_shifted + midsum_shifted;
  BigInteger test1{ "860" };
  BigInteger test2{ "36" };
  std::cout << "=" << (test1 + test2).ToString() << std::endl;
  result = result + a_right_m_b_right;
  std::cout << s.str() << " = [" << a_right_m_b_right << "]" << std::endl;
  std::cout << a_left_m_b_left_shifted + midsum_shifted << std::endl;
  std::cout << a_left_m_b_left_shifted + midsum_shifted + a_right_m_b_right << std::endl;
  return result;
}

void Multiply(BigInteger& a, BigInteger& b) {

}

int main() {
  //  BigInteger a{"667495948725284400748444283177999667495948725284400748444283177999667495948725284400748444283177999444667495948725284400748444283495948725284400748444283177999667495948725284400748444283177999444667495949594872528440074844428317799966749594872528440074844428317799944466749594959487252844007484442831779996674959487252844007484442831779994446674959495948725284400748444283177999667495948725284400748444283177999444667495949594872528440074844428317799966749594872528440074844428317799944466749594959487252844007484442831779996674959487252844007484442831779994446674959495948725284400748444283177999667495948725284400748444283177999444667495949594872528440074844428317799966749594872528440074844428317799944466749594959487252844007484442831779996674959487252844007484442831779994446674959495948725284400748444283177999667495948725284400748444283177999444667495949594872528440074844428317799966749594872528440074844428317799944466749594959487252844007484442831779996674959487252844007484442831779994446674959495948725284400748444283177999667495948725284400748444283177999444667495949594872528440074844428317799966749594872528440074844428317799944466749594959487252844007484442831779996674959487252844007484442831779994446674959495948725284400748444283177999667495948725284400748444283177999444667495949594872528440074844428317799966749594872528440074844428317799944466749594959487252844007484442831779996674959487252844007484442831779994446674959495948725284400748444283177999667495948725284400748444283177999444667495949594872528440074844428317799966749594872528440074844428317799944466749591779996674959487252844007484442831779994446674959487252844007484442831779996674959487252844007484442831779994446674959487252844007484442831779996674959487252844007484442831779994446674959487252844007484442831779994"};
  BigInteger a{ "16" };
  //std::cout << "a = " << a.ToString() << std::endl;
  //  BigInteger b{"52844007484442831779996674959487252844007484442831779952844007484442831779996748444283177995284400748444283177999667495948725284400748444283177974844428317799528440074797484442831779952844007484442831779996674959487252844007484442831779674959487252844007484442831779952844007484442831779996674959487252797484442831779952844007484442831779996674959487252844007484442831779674959487252844007484442831779952844007484442831779996674959487252797484442831779952844007484442831779996674959487252844007484442831779674959487252844007484442831779952844007484442831779996674959487252797484442831779952844007484442831779996674959487252844007484442831779674959487252844007484442831779952844007484442831779996674959487252797484442867495948725288888888888444283177999667495948725284400748444283177974844428317799528440074844428317799966749594872528440074844428317796749594872528440074844428317799528440074844428317799966749594872528440074844428317799"};
  BigInteger b{ "56" };
  //std::cout << "b = " << b.ToString() << std::endl;
  //BigInteger c = a * b;
  //std::cout << "a * b = " << c << " " << c.size() << std::endl;
  //BigInteger d = a - b;
  //std::cout << "a - b = " << d << " " << d.size() << std::endl;
  std::cout << "Karatsuba a * b = " << Karatsuba(a, b) << std::endl;
  BigInteger n{ "860" };
  BigInteger m{ "36" };
  BigInteger l = n + m;
  std::cout << n << " + " << m << " = " << l << std::endl;

  //Karatsuba(a, b);
  //std::cout << "a * b = " << Karatsuba(a, b).ToString() << std::endl;

  return EXIT_SUCCESS;
}

