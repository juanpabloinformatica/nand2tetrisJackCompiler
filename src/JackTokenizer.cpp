#include "JackTokenizer.hpp"
#include <algorithm>
#include <iostream>
#include <regex>
JackTokenizer::JackTokenizer(std::ifstream &inputFile) : inputFile(inputFile) {
  this->tokenList = std::vector<std::map<std::string, TokenType> *>();
}

void JackTokenizer::showTokenList() {
  int i = 0;
  for (const auto &token : this->tokenList) {
    for (const auto &mapa : *token) {
      std::cout << "i:" << i << "--> " << mapa.first << "\n";
      i++;
    }
  }
}

bool JackTokenizer::isTokenSymbol(const char &character) {
  return character == ' ' || character == '{' || character == '}' ||
         character == '(' || character == ')' || character == '[' ||
         character == ']' || character == '.' || character == ',' ||
         character == ';' || character == '+' || character == '-' ||
         character == '*' || character == '/' || character == '&' ||
         character == '|' || character == '<' || character == '>' ||
         character == '=' || character == '~';
}

void JackTokenizer::run() {
  std::string currentLine;
  std::string token;
  /*Logic*/
  for (; std::getline(this->inputFile, currentLine);) {
    for (const auto &character : currentLine) {
      if (character == ' ') {
        if (token.length() < 1) {
          continue;
        }
        this->appendTokenToTokenList(token);
        token.clear();
        continue;
      } else if (this->isTokenSymbol(character)) {
        if (token.length() >= 1) {
          this->appendTokenToTokenList(token);
          token.clear();
        }
        token.append(&character, 1);
        this->appendTokenToTokenList(token);
        token.clear();
        continue;
      }
      token.append(&character, 1);
    }
  }
}
void JackTokenizer::appendTokenToTokenList(const std::string &token) {
  this->tokenList.push_back(
      this->allocateMapObject(token, this->getTokenType(token)));
  return;
}
std::map<std::string, JackTokenizer::TokenType> *
JackTokenizer::allocateMapObject(const std::string &token,
                                 const TokenType tokenType) {

  std::map<std::string, JackTokenizer::TokenType> *newObject =
      new std::map<std::string, JackTokenizer::TokenType>();
  newObject->insert({token, tokenType});
  return newObject;
}

JackTokenizer::TokenType JackTokenizer::getTokenType(const std::string &token) {
  TokenType tokenType;
  if (token.compare("class") == 0 || token.compare("constructor") == 0 ||
      token.compare("function") == 0 || token.compare("method") == 0 ||
      token.compare("field") == 0 || token.compare("static") == 0 ||
      token.compare("var") == 0 || token.compare("int") == 0 ||
      token.compare("char") == 0 || token.compare("boolean") == 0 ||
      token.compare("void") == 0 || token.compare("true") == 0 ||
      token.compare("false") == 0 || token.compare("null") == 0 ||
      token.compare("this") == 0 || token.compare("let") == 0 ||
      token.compare("do") == 0 || token.compare("if") == 0 ||
      token.compare("else") == 0 || token.compare("while") == 0 ||
      token.compare("return") == 0) {
    tokenType = KEYWORD;
  } else if (token.at(0) == '{' || token.at(0) == '}' || token.at(0) == '(' ||
             token.at(0) == ')' || token.at(0) == '[' || token.at(0) == ']' ||
             token.at(0) == '.' || token.at(0) == ',' || token.at(0) == ';' ||
             token.at(0) == '+' || token.at(0) == '-' || token.at(0) == '*' ||
             token.at(0) == '/' || token.at(0) == '&' || token.at(0) == '|' ||
             token.at(0) == '<' || token.at(0) == '>' || token.at(0) == '=' ||
             token.at(0) == '~') {
    tokenType = SYMBOL;
    /*check more idiomatic stuff such as this*/
  } else if (std::all_of(token.begin(), token.end(), ::isdigit)) {
    tokenType = INT_CONST;
  } else if (token.at(0) == '"' && token.at(token.length() - 1) == '"') {
    tokenType = STRING_CONST;
  } else if (!std::regex_match(token, std::regex(R"(^[0-9].*)"))) {
    tokenType = IDENTIFIER;
  } else {
    tokenType = UNDEFINED;
  }
  return tokenType;
}
JackTokenizer::~JackTokenizer() {
  std::cout << "removing addresses" << "\n";
  for (const auto &mapObjectPointer : this->tokenList) {
    delete mapObjectPointer;
  }
}
