#include "JackTokenizer.hpp"
#include <algorithm>
#include <iostream>
#include <regex>
#include <string>
JackTokenizer::JackTokenizer(const std::filesystem::path &inputFilePath)
    : inputFile(inputFilePath) {
  this->tokenList =
      std::vector<std::map<std::string, JackTypes::TokenType> *>();

  std::cout << "address in tokenizer" << std::endl;
  std::cout << std::addressof(this->tokenList) << std::endl;
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
/*This should know when reached EOF*/
void JackTokenizer::skipLines(std::string &currentLine) {
  while ((currentLine.substr(0, 2) == "//" || currentLine == "" ||
          currentLine == "\r" || currentLine == "\t") &&
         !this->inputFile.eof()) {
    std::getline(this->inputFile, currentLine);
  }

  if (std::regex_search(currentLine, std::regex(R"(\s*\/\*.*\n?)"))) {
    while (currentLine.find("*/") == std::string::npos) {
      std::getline(this->inputFile, currentLine);
    }
    std::getline(this->inputFile, currentLine);
  }
}

void JackTokenizer::trimLines(std::string &currentLine) {
  /*ltrim*/
  currentLine.erase(0, currentLine.find_first_not_of(" \n\t\r"));
  /*rtrim*/
  currentLine.erase(currentLine.find_last_not_of(" //\n\t\r") + 1);
}
void JackTokenizer::removeRightComments(std::string &currentLine) {
  currentLine.erase(currentLine.find_last_of("//") - 1);
}

void JackTokenizer::run() {
  std::string currentLine;
  std::string token;
  /*Logic*/
  /*To improve to do it in only one passed*/
  for (; std::getline(this->inputFile, currentLine);) {
    /*Ignoring comments and lines with \t \r*/
    this->skipLines(currentLine);
    this->trimLines(currentLine);

    if (currentLine.find("//") != std::string::npos)
      this->removeRightComments(currentLine);

    bool isString = false;
    for (const auto &character : currentLine) {
      if (character == '"')
        isString = !isString;

      if (character == ' ' && !isString) {
        if (token.length() < 1) {
          continue;
        }
        this->appendTokenToTokenList(token);
        token.clear();
        continue;

      } else if (this->isTokenSymbol(character) && !isString) {
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
void JackTokenizer::appendTokenToTokenList(std::string &token) {

  JackTypes::TokenType tokenType = JackTypes::UNDEFINED;
  tokenType = this->getTokenType(token);
  if (tokenType == JackTypes::STRING_CONST)
    token.erase(std::remove(token.begin(), token.end(), '"'), token.end());

  this->tokenList.push_back(this->allocateMapObject(token, tokenType));
  return;
}
std::map<std::string, JackTypes::TokenType> *
JackTokenizer::allocateMapObject(const std::string &token,
                                 const JackTypes::TokenType tokenType) {

  std::map<std::string, JackTypes::TokenType> *newObject =
      new std::map<std::string, JackTypes::TokenType>();
  newObject->insert({token, tokenType});
  return newObject;
}

JackTypes::TokenType JackTokenizer::getTokenType(const std::string &token) {
  JackTypes::TokenType tokenType;
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
    tokenType = JackTypes::KEYWORD;
  } else if (token.at(0) == '{' || token.at(0) == '}' || token.at(0) == '(' ||
             token.at(0) == ')' || token.at(0) == '[' || token.at(0) == ']' ||
             token.at(0) == '.' || token.at(0) == ',' || token.at(0) == ';' ||
             token.at(0) == '+' || token.at(0) == '-' || token.at(0) == '*' ||
             token.at(0) == '/' || token.at(0) == '&' || token.at(0) == '|' ||
             token.at(0) == '<' || token.at(0) == '>' || token.at(0) == '=' ||
             token.at(0) == '~') {
    tokenType = JackTypes::SYMBOL;
    /*check more idiomatic stuff such as this*/
  } else if (std::all_of(token.begin(), token.end(), ::isdigit)) {
    tokenType = JackTypes::INT_CONST;
  } else if (token.at(0) == '"' && token.at(token.length() - 1) == '"') {
    tokenType = JackTypes::STRING_CONST;
  } else if (!std::regex_match(token, std::regex(R"(^[0-9].*)"))) {
    tokenType = JackTypes::IDENTIFIER;
  } else {
    tokenType = JackTypes::UNDEFINED;
  }
  return tokenType;
}
void JackTokenizer::showTokenizerOutput() {

  std::string outputFilename =
      std::string("/home/jppm/Documents/projects/nand2tetris/jack_compiler/"
                  "test/outputT.xml");
  std::ofstream outputTokenizer = std::ofstream(outputFilename);

  outputTokenizer << "<tokens>" << "\n";
  // int i = 0;
  for (const auto &token : this->tokenList) {
    for (const auto &mapa : *token) {
      switch (mapa.second) {
      case JackTypes::KEYWORD:
        outputTokenizer << "<keyword> " << mapa.first << " </keyword>" << "\n";
        break;
      case JackTypes::SYMBOL: {
        std::string symbol = mapa.first;
        if (mapa.first == "<")
          symbol = "&lt;";
        if (mapa.first == ">")
          symbol = "&gt;";
        if (mapa.first == "\"")
          symbol = "quot;";
        if (mapa.first == "&")
          symbol = "&amp;";

        outputTokenizer << "<symbol> " << symbol << " </symbol>" << "\n";
      } break;
      case JackTypes::IDENTIFIER:
        outputTokenizer << "<identifier> " << mapa.first << " </identifier>"
                        << "\n";
        break;
      case JackTypes::INT_CONST:
        outputTokenizer << "<integerConstant> " << mapa.first
                        << " </integerConstant>"
                        << "\n";
        break;
      case JackTypes::STRING_CONST:
        outputTokenizer << "<stringConstant> " << mapa.first
                        << " </stringConstant>"
                        << "\n";
        break;
      default:
        break;
      }
    }
  }
  outputTokenizer << "</tokens>";
  outputTokenizer.close();
}

const std::vector<std::map<std::string, JackTypes::TokenType> *> &
JackTokenizer::getTokenList() {
  return this->tokenList;
}
JackTokenizer::~JackTokenizer() {
  // std::cout << "removing addresses" << "\n";
  for (const auto &mapObjectPointer : this->tokenList) {
    delete mapObjectPointer;
  }
}
