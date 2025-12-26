#include "JackTokenizer.hpp"
#include <JackAnalyzer.hpp>
#include <cstdlib>

int main() {
  JackAnalyzer jackAnalyzer =
      JackAnalyzer("<any_path>");
  jackAnalyzer.run();
  return EXIT_SUCCESS;
}
