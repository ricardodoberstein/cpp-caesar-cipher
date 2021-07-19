#include "filereader.h"

namespace dcp
{
  FileReader::FileReader()
  {
  }

  FileReader::~FileReader()
  {
  }

  std::vector<std::string> FileReader::readFile(std::string path)
  {
    std::ifstream file;
    file.open(path);
    std::vector<std::string> text;

    if (file.is_open())
    {
      std::string line;
      while (std::getline(file, line))
      {
        text.push_back(line);
      }
      file.close();
    }
    else
    {
      std::cout << "File does not exist" << std::endl;
    }

    return text;
  }
}
