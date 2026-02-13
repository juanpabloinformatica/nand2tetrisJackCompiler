#include "JackTokenizer.hpp"
#include <JackAnalyzer.hpp>
#include <cassert>
#include <cstdlib>

int main(int argc, char *argv[]) {

  /*
   * argv[0] = source file
   * argv[1] = jack file to be parsed
   * argv[2] = output file name
   *
   * */
  if (argc != 3) {
    std::cout << "Not Given input file";
    EXIT_FAILURE;
  }

  std::string inputFile = argv[1];
  std::string outputFilePath = argv[2];
  JackAnalyzer jackAnalyzer = JackAnalyzer(inputFile, outputFilePath);
  jackAnalyzer.run();
  return EXIT_SUCCESS;
}
