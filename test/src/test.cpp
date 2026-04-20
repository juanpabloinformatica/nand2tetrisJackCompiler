#include <iostream>
#include <regex>
int main() {

  std::string expression = "do Output.printString(Score: 0)";
  bool hasAString =
      (std::regex_search(expression, std::regex(R"(\".*\")"))) ? true : false;
  if (hasAString)
    std::cout << "matched";
  else
    std::cout << "NOT matched";
}
