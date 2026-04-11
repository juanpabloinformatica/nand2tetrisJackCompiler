#include "JackTokenizer.hpp"
#include "VmWritter.hpp"
#include <JackAnalyzer.hpp>
#include <cassert>
#include <cstdlib>
#include <string>

int main(int argc, char *argv[]) {

  /*
   * argv[0] = source file argv[1] = jack file to be parsed
   * argv[2] = output file name
   *
   * */

  if (argc != 2) {
    std::cout << "Not Given input file";
    EXIT_FAILURE;
  }

  std::string inputFilePath = argv[1];
  JackAnalyzer jackAnalyzer = JackAnalyzer(inputFilePath);
  jackAnalyzer.run();
  return EXIT_SUCCESS;
}
