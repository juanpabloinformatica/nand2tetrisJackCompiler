#ifndef __TOKENIZER__
#define __TOKENIZER__
#include <fstream>
class JackTokenizer {
public:
  std::ifstream inputFile;
  JackTokenizer(std::string inputFilePath) {};
  bool hasMoreTokens();
  void advance();
  enum TokenType {
    KEYWORD,
    SYMBOL,
    IDENTIFIER,
    INT_CONST,
    STRING_CONST,
  };
  TokenType getTokenType();
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
};

#endif
