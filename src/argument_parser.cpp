#include "argument_parser.h"

namespace dcp
{
  ArgumentParser::ArgumentParser(char *argv[], int argc)
  {
    for (int i = 0; i < argc; i += 1)
    {
      std::string arg = (std::string)argv[i];

      if (arg == "--help")
        this->help = true;
      if (arg == "-e")
        this->command = Command::Encode;
      if (arg == "-d")
        this->command = Command::Decode;
      if (arg == "--path")
        this->path = (std::string)argv[i + 1];
      if (arg == "--shift")
        this->shift = stoi((std::string)argv[i + 1]);
      if (arg == "--output")
        this->output = (std::string)argv[i + 1];
    }
  }

  ArgumentParser::~ArgumentParser()
  {
  }

  bool ArgumentParser::get_help()
  {
    return this->help;
  }

  Command ArgumentParser::get_command()
  {
    return this->command;
  }

  std::string ArgumentParser::get_path()
  {
    return this->path;
  }

  int ArgumentParser::get_shift()
  {
    return this->shift;
  }

  std::string ArgumentParser::get_output_filename()
  {
    return this->output;
  }
}