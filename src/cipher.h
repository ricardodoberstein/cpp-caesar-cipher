#include <iostream>
#include <map>
#include "ascii.h"

namespace dcp
{
  class Cipher
  {
  private:
    std::string value;

  public:
    Cipher();
    ~Cipher();

    std::string encode(std::string value, int shift);
    std::string decode(std::string value, int shift);
  };
}