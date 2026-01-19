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
  std::ifstream &getOutputFile();
  void run();

private:
  std::ofstream outputFile;
  const std::vector<std::map<std::string, JackTypes::TokenType> *> tokenList;
  int tokenListIndex;
  inline std::string tokenListKey(int tokenListIndex);
  inline JackTypes::TokenType tokenListValue(int tokenListIndex);
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
};

#endif
