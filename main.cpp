#include <iostream>
#include <vector>
#include "src/cipher.h"
#include "src/file_reader.h"
#include "src/file_writer.h"
#include "src/argument_parser.h"

int main(int argc, char *argv[])
{
  dcp::ArgumentParser *parser = new dcp::ArgumentParser(argv, argc);

  if (parser->get_help() == true)
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

  if (parser->get_command() != dcp::Command::Encode && parser->get_command() != dcp::Command::Decode)
  {
    std::cout << "Please use -d (decode) or -e (encode) args" << std::endl;
    std::cout << "Example usage: ./CaesarCipher -e ./text.txt 3" << std::endl;
    return 0;
  }

  dcp::Cipher cipher;
  dcp::FileReader reader;
  std::vector<std::string> in = reader.read_file(parser->get_path());
  std::vector<std::string> out;

  for (int i = 0; i < in.size(); i += 1)
  {    
    if (parser->get_command() == dcp::Command::Decode)
    {
      out.push_back(cipher.decode(in[i], parser->get_shift()));
    }
    else
    {
      out.push_back(cipher.encode(in[i], parser->get_shift()));
    }
  }

  dcp::FileWriter writer;
  writer.write_to_file(parser->get_output_filename() + ".txt", out);
}