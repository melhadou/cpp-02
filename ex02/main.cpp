#include "Fixed.hpp"

int main(void) {
  Fixed a;
  Fixed const b(Fixed(5.05f) * Fixed(2));

  std::cout << "a = " << a << std::endl;
  std::cout << "++a = " << ++a << std::endl;
  std::cout << "a = " << a << std::endl;
  std::cout << "a++ = " << a++ << std::endl;
  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;
  std::cout << "b = " << b / 3 << std::endl;
  std::cout << "Fixed = " << Fixed::max(a, b) << std::endl;

  return 0;
}
