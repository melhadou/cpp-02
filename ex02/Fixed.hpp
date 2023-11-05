#pragma once
#include <cmath>
#include <iostream>

class Fixed {
private:
  int value;
  static const int bits = 8;

public:
  Fixed();
  Fixed(const int val);
  Fixed(const float val);

  Fixed(const Fixed &fixed);
  Fixed &operator=(Fixed const &other);

  ~Fixed();

  int getRawBits(void) const;
  void setRawBits(int const raw);

  float toFloat(void) const;
  int toInt(void) const;

  // comparison operator overloading
  bool operator>(const Fixed &other) const;
  bool operator<(const Fixed &other) const;
  bool operator>=(const Fixed &other) const;
  bool operator<=(const Fixed &other) const;
  bool operator==(const Fixed &other) const;
  bool operator!=(const Fixed &other) const;

  // Arithmetic operators
  Fixed operator+(const Fixed &other) const;
  Fixed operator-(const Fixed &other) const;
  Fixed operator*(const Fixed &other) const;
  Fixed operator/(const Fixed &other) const;

  Fixed &operator++(void);
  Fixed operator++(int);
  Fixed &operator--(void);
  Fixed operator--(int);

  // static fucnstion min max
  const static Fixed &min(const Fixed &a, const Fixed &b);
  const static Fixed &max(const Fixed &a, const Fixed &b);
  static Fixed &min(Fixed &a, Fixed &b);
  static Fixed &max(Fixed &a, Fixed &b);
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);
