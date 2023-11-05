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
};

std::ostream &operator<<(std::ostream &out, Fixed const &value);
