#include "JackTokenizer.hpp"
#include <JackAnalyzer.hpp>
#include <cstdlib>

int main(int argc, char *argv[]) {

  if (argc != 2) {
    std::cout << "Not Given input file";
    EXIT_FAILURE;
  }

  std::string inputFile = argv[1];
  JackAnalyzer jackAnalyzer = JackAnalyzer(inputFile);
  jackAnalyzer.run();
  return EXIT_SUCCESS;
}
