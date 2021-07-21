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
    std::vector<std::string> read_file(std::string path);
  };
}