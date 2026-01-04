#ifndef __TOKENIZER__
#define __TOKENIZER__
#include <fstream>
#include <map>
#include <string>
#include <vector>
class JackTokenizer {
public:
  std::ifstream &inputFile;
  JackTokenizer(std::ifstream &inputFile);
  ~JackTokenizer();
  enum TokenType {
    UNDEFINED = -1,
    KEYWORD,
    SYMBOL,
    IDENTIFIER,
    INT_CONST,
    STRING_CONST,
  };
  std::vector<std::map<std::string, TokenType> *> tokenList;
  enum Keyword {
    CLASS,
    METHOD,
    FUNCTION,
    CONSTRUCTOR,
    INT,
    BOOLEAN,
    CHAR,
    VOID,
    VAR,
    STATIC,
    FIELD,
    LET,
    DO,
    IF,
    ELSE,
    WHILE,
    RETURN,
    TRUE,
    FLASE,
    _NULL,
    THIS
  };
  Keyword getKeyword();
  char getSymbol();
  std::string getIdentifier();
  int getIntVal();
  std::string getStringVal();
  void run();
	void showTokenList();

private:
  /*list of mapObjects*/
  /*This list needs to be traverse and deallocate each map object pointer*/
  std::map<std::string, TokenType> *
  allocateMapObject(const std::string &token, const TokenType tokenType);

  TokenType getTokenType(const std::string &token);
  void appendTokenToTokenList(const std::string &token);
  bool isTokenSymbol(const char& character);
};

#endif
