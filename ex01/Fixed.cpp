#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val) {
  std::cout << "Int constructor called" << std::endl;
  this->value = val << this->bits;
}

Fixed::Fixed(const float val) {
  std::cout << "Float constructor called" << std::endl;
  this->value = roundf(val * (1 << this->bits)); // 1 << this->bits = 256
}

// copy constructor
Fixed::Fixed(const Fixed &fixed) {
  std::cout << "Copy constructor called" << std::endl;
  this->setRawBits(fixed.getRawBits());
}

// copy assignment operator
Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other)
    this->value = other.getRawBits();
  return *this;
}

int Fixed::getRawBits() const { return this->value; }

void Fixed::setRawBits(int const raw) { this->value = raw; }

float Fixed::toFloat(void) const {
  return static_cast<float>(this->getRawBits()) / (1 << this->bits);
}

int Fixed::toInt(void) const { return (this->getRawBits() >> this->bits); }

std::ostream &operator<<(std::ostream &out, Fixed const &value) {
  out << value.toFloat();
  return out;
}

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }
