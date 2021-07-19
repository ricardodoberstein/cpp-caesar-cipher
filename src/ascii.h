#include <iostream>

namespace dcp
{
  class ASCII
  {
  public:
    ASCII();
    ~ASCII();
    int getEncodeTarget(int start, int shift);
    int getDecodeTarget(int start, int shift);
  };
}
