#ifndef __C_ENGINE__
#define __C_ENGINE__
#include "Types.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
class CompilationEngine {
public:
  CompilationEngine(
      const std::vector<std::map<std::string, JackTypes::TokenType> *>
          &tokenList);

  /*Not extended*/
  ~CompilationEngine();
  const std::vector<std::map<std::string, JackTypes::TokenType> *> &
  getTokenList();
  std::ofstream &getOutputFile();
  void run();

private:
  std::ofstream outputFile;
  const std::vector<std::map<std::string, JackTypes::TokenType> *> tokenList;
  int tokenListIndex;
  inline std::string tokenListKey();
  inline JackTypes::TokenType tokenListValue();
  void compileClass();
  void compileClassVarDec();
  void compileSubroutine();
  void compileParameterList();
  void compileVarDec();
  void compileStatements();
  void compileDo();
  void compileLet();
  void compileWhile();
  void compileReturn();
  void compileIf();
  void compileExpression();
  void compileTerm();
  void compileExpressionList();
  /*When terminal reached this method will be called*/
  void writeToFile();
};

#endif
