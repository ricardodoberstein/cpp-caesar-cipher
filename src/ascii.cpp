#include "ascii.h"

namespace dcp
{
  ASCII::ASCII()
  {
  }

  ASCII::~ASCII()
  {
  }

  int ASCII::getEncodeTarget(int start, int shift)
  {
    if (start == 32)
      return 32;

    int min = 0;
    int max = 126;

    for (int i = 1; i <= shift; i += 1)
    {
      if (start < 126)
      {
        start += 1;
      }
      else
      {
        start = 0;
      }
    }

    return start;
  }

  int ASCII::getDecodeTarget(int start, int shift)
  {
    if (start == 32)
      return 32;

    int min = 0;
    int max = 126;

    for (int i = 1; i <= shift; i += 1)
    {
      if (start > 0)
      {
        start -= 1;
      }
      else
      {
        start = 126;
      }
    }

    return start;
  }
}