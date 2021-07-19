#include <iostream>

enum Command { Encode, Decode, None };

class ArgumentParser
{
public:
  ArgumentParser(char *argv[], int argc);
  ~ArgumentParser();

  bool getHelp();
  Command getCommand();
  std::string getPath();
  int getShift();
  std::string getOutputFileName();

private:
  bool help = false;
  Command command = Command::None;
  std::string path = "undefined";
  int shift = 0;
  std::string output = "output";
};