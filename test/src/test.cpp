#include <cassert>
#include <iostream>
#include <regex>
int main() {
  std::string expression = "a[b[[[[]]";
  int value = std::count_if(expression.begin(), expression.end(),
                            [](char letter) { return letter == '['; });
  std::cout << "Value\t" << value;

  //
  // std::string expression = "a[a[5]] * b[((7 - a[3]) - Main.double(2)) + 1]+";
  // std::string right = expression.substr(expression.find_first_of("["),
  //                                       expression.find_last_of("]") -
  //                                           expression.find_first_of("[") +
  //                                           1);
  // const std::regex _operatorsPatternRegex(R"([\+|\~|\-|\*|\/|&|\||<|>|=])");
  // std::regex arrayDelimeters = std::regex(R"(\[|\])");
  // if (std::regex_search(expression, arrayDelimeters) &&
  //     !std::regex_search(expression.substr(expression.find_last_of("]")),
  //                        _operatorsPatternRegex) &&
  //     !std::regex_search(expression.substr(0, expression.find_first_of("[")),
  //                        _operatorsPatternRegex))
  //   std::cout << "hereeee" << "\n";
  //
  // assert(true ==
  //        std::regex_search(expression.substr(expression.find_last_of("]")),
  //                          _operatorsPatternRegex));
  // assert(true ==
  //        std::regex_search(expression.substr(0,
  //        expression.find_first_of("[")),
  //                          _operatorsPatternRegex));
  //
  // std::string lef = expression.substr(expression.find_last_of("]"));
  // std::string rig = expression.substr(0, expression.find_first_of("["));
  //
  // int firstOpeningP = expression.find_first_of('[');
  // int lastClosingP = expression.find_last_of(']');
  // std::cout << firstOpeningP << "\n";
  // std::cout << lastClosingP << "\n";
  // std::cout << right << "\n";
}
