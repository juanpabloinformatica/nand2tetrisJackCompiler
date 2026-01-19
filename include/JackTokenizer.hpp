#ifndef __TOKENIZER__
#define __TOKENIZER__
#include "Types.hpp"
#include <filesystem>
#include <fstream>
#include <map>
#include <string>
#include <vector>
class JackTokenizer {
public:
  std::ifstream inputFile;
  JackTokenizer(const std::filesystem::path &inputFilePath);
  ~JackTokenizer();
  std::vector<std::map<std::string, JackTypes::TokenType> *> tokenList;
  JackTypes::Keyword getKeyword();
  char getSymbol();
  std::string getIdentifier();
  int getIntVal();
  std::string getStringVal();
  void run();
  void showTokenList();
  void showTokenizerOutput();

  const std::vector<std::map<std::string, JackTypes::TokenType> *> &
  getTokenList();

private:
  /*list of mapObjects*/
  /*This list needs to be traverse and deallocate each map object pointer*/
  std::map<std::string, JackTypes::TokenType> *
  allocateMapObject(const std::string &token,
                    const JackTypes::TokenType tokenType);

  JackTypes::TokenType getTokenType(const std::string &token);
  void appendTokenToTokenList(std::string &token);
  bool isTokenSymbol(const char &character);
  void skipLines(std::string &currentLine);
  void trimLines(std::string &currentLine);
  void removeRightComments(std::string &currentLine);
};

#endif
