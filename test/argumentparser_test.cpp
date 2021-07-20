#include <gtest/gtest.h>
#include "../src/argumentparser.h"

TEST(Test, Test)
{
  ASSERT_EQ(1, 1);
}

TEST(ArgumentParser, helpReturnsTrue)
{
  char argv0[] = "test";
  char argv1[] = "--help";
  char *argv[] = {argv0, argv1};

  ArgumentParser *parser = new ArgumentParser(argv, 2);

  ASSERT_EQ(parser->getHelp(), true);
  delete parser;
}

TEST(ArgumentParser, helpReturnsFalse)
{
  char argv0[] = "test";
  char argv1[] = "-e";
  char argv2[] = "--path";
  char argv3[] = "./input.txt";
  char *argv[] = {argv0, argv1, argv2, argv3};

  ArgumentParser *parser = new ArgumentParser(argv, 4);

  ASSERT_EQ(parser->getHelp(), false);
  delete parser;
}

TEST(ArgumentParser, commandReturnsEncode)
{
  char argv0[] = "test";
  char argv1[] = "-e";
  char argv2[] = "--path";
  char argv3[] = "./input.txt";
  char *argv[] = {argv0, argv1, argv2, argv3};

  ArgumentParser *parser = new ArgumentParser(argv, 4);

  ASSERT_EQ(parser->getCommand(), Command::Encode);
  delete parser;
}

TEST(ArgumentParser, commandReturnsDecode)
{
  char argv0[] = "test";
  char argv1[] = "-d";
  char argv2[] = "--path";
  char argv3[] = "./input.txt";
  char *argv[] = {argv0, argv1, argv2, argv3};

  ArgumentParser *parser = new ArgumentParser(argv, 4);

  ASSERT_EQ(parser->getCommand(), Command::Decode);
  delete parser;
}

TEST(ArgumentParser, pathReturnsPath)
{
  char argv0[] = "test";
  char argv1[] = "-d";
  char argv2[] = "--path";
  char argv3[] = "./input.txt";
  char *argv[] = {argv0, argv1, argv2, argv3};

  ArgumentParser *parser = new ArgumentParser(argv, 4);

  ASSERT_EQ(parser->getPath(), "./input.txt");
  delete parser;
}

TEST(ArgumentParser, shiftReturnsShift)
{
  char argv0[] = "test";
  char argv1[] = "-d";
  char argv2[] = "--path";
  char argv3[] = "./input.txt";
  char argv4[] = "--shift";
  char argv5[] = "5";
  char *argv[] = {argv0, argv1, argv2, argv3, argv4, argv5};

  ArgumentParser *parser = new ArgumentParser(argv, 6);

  ASSERT_EQ(parser->getShift(), 5);
  delete parser;
}

TEST(ArgumentParser, outputFile)
{
  char argv0[] = "test";
  char argv1[] = "-d";
  char argv2[] = "--path";
  char argv3[] = "./input.txt";
  char argv4[] = "--shift";
  char argv5[] = "5";
  char argv6[] = "--output";
  char argv7[] = "file";

  char *argv[] = {argv0, argv1, argv2, argv3, argv4, argv5, argv6, argv7};

  ArgumentParser *parser = new ArgumentParser(argv, 8);

  ASSERT_EQ(parser->getOutputFileName(), "file");
  delete parser;
}

TEST(ArgumentParser, outputFileDefault)
{
  char argv0[] = "test";
  char argv1[] = "-d";
  char argv2[] = "--path";
  char argv3[] = "./input.txt";
  char argv4[] = "--shift";
  char argv5[] = "5";
  char *argv[] = {argv0, argv1, argv2, argv3, argv4, argv5};

  ArgumentParser *parser = new ArgumentParser(argv, 6);

  ASSERT_EQ(parser->getOutputFileName(), "output");
  delete parser;
}
