#include <iostream>
#include <fstream>
#include <vector>

namespace dcp
{
  class FileReader
  {
  public:
    FileReader();
    ~FileReader();
    std::vector<std::string> readFile(std::string path);
  };
}