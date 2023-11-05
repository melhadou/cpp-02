#include "Fixed.hpp"

// ----------------- Orthodoxe Canonicals Functions-----------------
Fixed::Fixed() : value(0) {}

Fixed::Fixed(const int val) { this->value = val << this->bits; }

Fixed::Fixed(const float val) { this->value = roundf(val * (1 << this->bits)); }

// copy constructor
Fixed::Fixed(const Fixed &fixed) { *this = fixed; }

// copy assignment operator
Fixed &Fixed::operator=(const Fixed &other) {
  if (this != &other)
    this->value = other.getRawBits();
  return *this;
}

Fixed::~Fixed() {}

// ----------------- Member Functions-----------------
int Fixed::getRawBits() const { return this->value; }
void Fixed::setRawBits(int const raw) { this->value = raw; }

int Fixed::toInt(void) const { return (this->getRawBits() >> this->bits); }

float Fixed::toFloat(void) const {
  return static_cast<float>(this->getRawBits()) / (1 << this->bits);
}

// ----------------- Operators Overloading -----------------
std::ostream &operator<<(std::ostream &out, Fixed const &value) {
  out << value.toFloat();
  return out;
}

// ----------------- Comparison OPERATORS Overloading -----------------
bool Fixed::operator>(const Fixed &other) const {
  return this->getRawBits() > other.getRawBits();
}

bool Fixed::operator<(const Fixed &other) const {
  return this->getRawBits() < other.getRawBits();
}

bool Fixed::operator>=(const Fixed &other) const {
  return this->getRawBits() >= other.getRawBits();
}

bool Fixed::operator<=(const Fixed &other) const {
  return this->getRawBits() <= other.getRawBits();
}

bool Fixed::operator==(const Fixed &other) const {
  return this->getRawBits() == other.getRawBits();
}

bool Fixed::operator!=(const Fixed &other) const {
  return this->getRawBits() != other.getRawBits();
}
// ----------------- Comparison OPERATORS Overloading -----------------

// ----------------- Arithmetics OPERATORS Overloading -----------------
Fixed Fixed::operator+(const Fixed &other) const {
  return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const {
  return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const {
  return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const {
  return Fixed(this->toFloat() / other.toFloat());
}

// ----------------- Arithmetics OPERATORS Overloading -----------------
// ----------------- Increment OPERATORS Overloading -----------------
Fixed &Fixed::operator++(void) {
  ++value;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed res(*this); // usign copy constructor
  ++value;
  return res;
}

Fixed &Fixed::operator--(void) {
  --value;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed res(*this); // usign copy constructor
  --value;
  return res;
}

// ----------------- Static Min Functions -----------------
const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
  if (a.getRawBits() < b.getRawBits())
    return a;
  return b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
  if (a.getRawBits() < b.getRawBits())
    return a;
  return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
  if (a.getRawBits() > b.getRawBits())
    return a;
  return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
  if (a.getRawBits() > b.getRawBits())
    return a;
  return b;
}

// ----------------- Static Min Functions -----------------
