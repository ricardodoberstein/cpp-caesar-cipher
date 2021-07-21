#include <iostream>
#include <vector>
#include <fstream>

namespace dcp
{
  class FileWriter
  {
  public:
    FileWriter();
    ~FileWriter();

    void write_to_file(std::string path, std::vector<std::string> data);
  };
}