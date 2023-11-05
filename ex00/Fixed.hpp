#pragma once
#include <iostream>

class Fixed {
private:
  int _value;
  const int _bits;

public:
  Fixed();
  Fixed(const Fixed &fixed);
  Fixed &operator=(Fixed const &other);
  ~Fixed();

  int getRawBits(void) const;
  void setRawBits(int const raw);
};
