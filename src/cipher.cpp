#include "cipher.h"

namespace dcp
{
  Cipher::Cipher()
  {
    std::cout << "Constructed" << std::endl;
  }

  Cipher::~Cipher()
  {
    std::cout << "Destructed" << std::endl;
  }

  std::string Cipher::encode(std::string value, int shift)
  {
    ASCII ascii = ASCII();
    for (int i = 0; i < value.length(); i += 1)
    {
      int start = (int)value[i];
      int target = ascii.get_encode_target(start, shift);
      value[i] = (char)target;
    }

    return value;
  }

  std::string Cipher::decode(std::string value, int shift)
  {
    ASCII ascii = ASCII();
    for (int i = 0; i < value.length(); i += 1)
    {
      int start = (int)value[i];
      int target = ascii.get_decode_target(start, shift);
      value[i] = (char)target;
    }

    return value;
  }
}