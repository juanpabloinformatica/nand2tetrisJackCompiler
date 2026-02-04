#ifndef __TYPES__
#define __TYPES__
#include <algorithm>
#include <regex>
#include <string>
class JackTypes {
public:
  enum TokenType {
    UNDEFINED = -1,
    KEYWORD,
    SYMBOL,
    IDENTIFIER,
    INT_CONST,
    STRING_CONST,
  };
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
    FALSE,
    _NULL,
    THIS
  };

  static inline bool tokenIsIntegerConstant(const std::string &token) {
    return std::all_of(token.begin(), token.end(), ::isdigit);
  }

  static inline bool tokenIsStringConstant(const std::string &token) {
    return token.at(0) == '"' && token.at(token.length() - 1) == '"';
  }

  static inline bool tokenIsKeywordConstant(const std::string &token) {
    return token.compare("true") == 0 || token.compare("false") == 0 ||
           token.compare("null") == 0 || token.compare("this") == 0;
  }

  static inline bool tokenIsUnaryOp(const std::string &token) {
    return token == "-" || token == "~";
  }
  static inline bool tokenIsOp(const std::string &token) {
    return token == "+" || token == "-" || token == "*" || token == "/" ||
           token == "&" || token == "|" || token == "<" || token == ">" ||
           token == "=";
  };
};
#endif
