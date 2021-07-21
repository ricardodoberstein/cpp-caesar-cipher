#include <iostream>

namespace dcp
{
  enum Command
  {
    Encode,
    Decode,
    None
  };
  
  class ArgumentParser
  {
  public:
    ArgumentParser(char *argv[], int argc);
    ~ArgumentParser();

    bool get_help();
    Command get_command();
    std::string get_path();
    int get_shift();
    std::string get_output_filename();

  private:
    bool help = false;
    Command command = Command::None;
    std::string path = "undefined";
    int shift = 0;
    std::string output = "output";
  };
}