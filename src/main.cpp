#include <iostream>
#include <vector>
#include "cipher.h"
#include "filereader.h"
#include "filewriter.h"
#include "argumentparser.h"

int main(int argc, char *argv[])
{
  ArgumentParser *parser = new ArgumentParser(argv, argc);
  if (parser->getHelp() == true)
  {
    std::cout << "Usage: {executable} <command>" << std::endl;
    std::cout << "where <command> is one of:" << std::endl;
    std::cout << "            --help (display information)," << std::endl;
    std::cout << "            -d       Decode a file," << std::endl;
    std::cout << "            -e       Encode a file," << std::endl;
    std::cout << "            --shift   (required) How much to shift," << std::endl;
    std::cout << "            --path   (required) Path to file for processing," << std::endl;
    std::cout << "            --output (optional) filename to output decoded or encoded .txt" << std::endl;
    return 0;
  }

  if (parser->getCommand() != Command::Encode && parser->getCommand() != Command::Decode)
  {
    std::cout << "Please use -d (decode) or -e (encode) args" << std::endl;
    std::cout << "Example usage: ./CaesarCipher -e ./text.txt 3" << std::endl;
    return 0;
  }

  dcp::Cipher cipher;
  dcp::FileReader reader;
  std::vector<std::string> in = reader.readFile(parser->getPath());
  std::vector<std::string> out;

  for (int i = 0; i < in.size(); i += 1)
  {    
    if (parser->getCommand() == Command::Decode)
    {
      out.push_back(cipher.decode(in[i], parser->getShift()));
    }
    else
    {
      out.push_back(cipher.encode(in[i], parser->getShift()));
    }
  }

  dcp::FileWriter writer;
  writer.writeToFile(parser->getOutputFileName() + ".txt", out);
}