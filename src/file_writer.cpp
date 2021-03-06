#include "file_writer.h"

namespace dcp
{
  FileWriter::FileWriter()
  {
  }

  FileWriter::~FileWriter()
  {
  }

  void FileWriter::write_to_file(std::string path, std::vector<std::string> data)
  {
    std::ofstream file;
    file.open(path);
    if (file.is_open())
    {
      for (int i = 0; i < data.size(); i += 1)
      {
        file << data[i];
        file << "\n";
      }
      file.close();
    }
    else
    {
    }
  }
}