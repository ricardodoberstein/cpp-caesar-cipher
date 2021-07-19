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

    void writeToFile(std::string path, std::vector<std::string> data);
  };
}