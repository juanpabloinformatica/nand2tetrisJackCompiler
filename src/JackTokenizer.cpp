#include "JackTokenizer.hpp"
JackTokenizer::JackTokenizer(std::ifstream &inputFile) : inputFile(inputFile) {}

// bool JackTokenizer::hasMoreTokens() {
//   return this->inputFile.eof() ? false : true;
// }
// void JackTokenizer::advance(std::string&) {
// 	this->inputFile.getline();
// }
void JackTokenizer::run() {

  std::string currentLine;
  std::string token;
  /*Logic*/
  for (; std::getline(this->inputFile, currentLine);) {
    std::getline(this->inputFile, currentLine);
    for (const auto &character : currentLine) {
      if (character == ' ') {
        token.clear();
      }
      token.append(&character, 1);
    }
  }
}
