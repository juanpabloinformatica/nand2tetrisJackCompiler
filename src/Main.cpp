#include "JackTokenizer.hpp"
#include "VmWritter.hpp"
#include <JackAnalyzer.hpp>
#include <cassert>
#include <cstdlib>
#include <iterator>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
  // std::sregex_token_iterator(expression.begin(),
  //                                                                                        expression.end(),
  //                                                                                        exp_regex, 1),
  //                                    std::sregex_token_iterator()
  // const std::regex reg_ = std::regex(R"(.*?\((.*)\))");
  // std::string expression = "doOutput.printInt(1+(2*3))";
  // std::vector<std::string> result;
  // result = std::vector<std::string>(
  //     std::sregex_token_iterator(expression.begin(), expression.end(), reg_, 1),
  //     std::sregex_token_iterator());
  // std::stringstream streamExpression = std::stringstream(result.at(0).c_str());
  // std::string e = "";
  // for (; std::getline(streamExpression, e, ',');) {
  //   std::cout << e << "\n";
  // }
  // exit(0);

  /*
   * argv[0] = source file argv[1] = jack file to be parsed
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
  // VmWritter vmWritter = VmWritter("./templates/output_file");
  // // vmWritter.writeCall("Main","main",0);
  // vmWritter.writeFunction("Main","main",3);
  return EXIT_SUCCESS;
}
