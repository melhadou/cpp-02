#include "Fixed.hpp"

Fixed::Fixed() : _bits(8) {
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : _bits(8) {
  std::cout << "Copy constructor called" << std::endl;
  this->setRawBits(other.getRawBits());
}

Fixed &Fixed::operator=(Fixed const &other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &other)
    this->_value = other.getRawBits();
  return *this;
}

int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called" << std::endl;
  return this->_value;
}
void Fixed::setRawBits(int const raw) { this->_value = raw; }

Fixed::~Fixed() { std::cout << "Destructor called" << std::endl; }
