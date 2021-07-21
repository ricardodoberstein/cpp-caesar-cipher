#include <iostream>

namespace dcp
{
  class ASCII
  {
  public:
    ASCII();
    ~ASCII();
    int get_encode_target(int start, int shift);
    int get_decode_target(int start, int shift);
  };
}
