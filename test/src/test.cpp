#include <cassert>
#include <cstdio>
#include <iostream>
#include <regex>
#include <sstream>
#include <stack>
#include <string>
int main() {

  std::string testExpression = "(a,b,3)";
  std::cout << (testExpression.substr(0, 1) == "(" &&
                testExpression.substr(testExpression.size() - 1, 1) == ")")
            << "\n";
  testExpression = testExpression.substr(1, testExpression.size() - 2);
  std::cout << "Here" << testExpression << "\n";

  std::string resultingExpression = testExpression.substr(
      testExpression.find_first_of('('),
      testExpression.size() - testExpression.find_first_of('('));

  const std::regex _operatorsPatternRegex(R"([\+|\-|\*|\/|&|\||<|>|=])");

  std::string beforeOpenPar =
      testExpression.substr(0, testExpression.find_first_of('('));
  // * a+b(...)
  if (std::regex_search(beforeOpenPar, _operatorsPatternRegex)) {
    int i = 0;
    for (;
         !std::regex_match(testExpression.substr(i, 1), _operatorsPatternRegex);
         i++)
      ;
    std::string lefts = testExpression.substr(0, i);
    std::cout << lefts << "\n";
    std::string _op = testExpression.substr(i, 1);
    std::cout << _op << "\n";
    std::string right = testExpression.substr(i + 1);
    std::cout << right << "\n";
    return 1;
  }
  // * a+b(...)

  std::stack<char> parenthesisStack{};
  std::stringstream str;
  size_t i = 0;
  str << resultingExpression.at(i);
  parenthesisStack.push(resultingExpression.at(i++));
  while (!parenthesisStack.empty() && i <= resultingExpression.size() - 1) {
    if (resultingExpression.at(i) == ')') {
      parenthesisStack.pop();
    }
    if (resultingExpression.at(i) == '(') {
      parenthesisStack.push(i);
    }
    // std::cout << resultingExpression.substr(0, i) << "\n";
    str << resultingExpression.at(i);
    i++;
  }
  i--;
  std::cout << "INDEX: " << i + testExpression.find_first_of('(') << "\n";
  /*This assert means the following if true then it means the expression
   * continues so more likely to follow the 'exp op exp', otherwise it finish
   * with ')' so will be of the type f(......) */
  if (testExpression.size() - 1 > i + testExpression.find_first_of('(')) {
    std::string lefts =
        testExpression.substr(0, i + testExpression.find_first_of('(') + 1);
    std::cout << lefts << "\n";
    std::string _op =
        testExpression.substr(i + testExpression.find_first_of('(') + 1, 1);
    std::cout << _op << "\n";
    std::string right =
        testExpression.substr(i + testExpression.find_first_of('(') + 2);
    std::cout << right << "\n";
  }

  if (testExpression.substr(i + testExpression.find_first_of('('), 1) == ")") {
    std::cout << testExpression.substr(testExpression.find_first_of('(') + 1,
                                       i - 1)
              << "\n";
    return 1;
  }
  // std::cout << str.str() << "\n";
  // const std::string _operatorsPattern = R"([\+|\-|\*|\/|&|\||<|>|=])";
  // std::string expression = "xyz1-yyyy1";
  // if (std::regex_match(expression.substr(1, 1),
  // std::regex(_operatorsPattern)))
  //   std::cout << "here" << "\n";
  // if (expression.find_first_of('(') == std::string::npos &&
  //     std::regex_search(expression, std::regex(_operatorsPattern))) {
  //
  //   std::string _op;
  //   std::string right;
  //   if (std::regex_match(expression.substr(0, 1),
  //                        std::regex(_operatorsPattern))) {
  //     _op = expression.substr(0, 1);
  //     right = expression.substr(1);
  //     std::cout << "op: " << _op << "\n";
  //     std::cout << "right: " << right << "\n";
  //     // this->vmWritter.writeArithmetic(_op);
  //     return 1;
  //   }
  //   std::stringstream left;
  //   size_t i = 0;
  //   while (i < expression.size() &&
  //          !std::regex_match(expression.substr(i, 1),
  //                            std::regex(_operatorsPattern))) {
  //     std::cout << expression.at(i) << "\n";
  //     left << expression.substr(i, 1);
  //     i++;
  //   }
  //   std::cout << left.str() << "\n";
  //   _op = expression.substr(left.str().size(), 1);
  //   right = expression.substr(left.str().size() + 1);
  //
  //   std::cout << "left: " << left.str() << "\n";
  //   std::cout << "op: " << _op << "\n";
  //   std::cout << "right: " << right << "\n";
  // }
}
