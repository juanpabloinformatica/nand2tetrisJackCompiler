#ifndef __C_ENGINE__
#define __C_ENGINE__
#include "SymbolTable.hpp"
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
      const std::vector<std::map<std::string, JackTypes::TokenType>*>&
          tokenList,
      const std::string& outputFilePath);

  /*Not extended*/
  ~CompilationEngine();
  const std::vector<std::map<std::string, JackTypes::TokenType>*>&
  getTokenList();
  std::ofstream& getOutputFile();
  void run();

private:
  std::ofstream outputFile;
  const std::vector<std::map<std::string, JackTypes::TokenType>*> tokenList;
  int tokenListIndex;
  int flagIsDoStatement;
  SymbolTable classSymbolTable;
  SymbolTable subroutineSymbolTable;
  std::string currentClass;
  inline std::string tokenListKey(int offset = 0);
  inline JackTypes::TokenType tokenListValue(int offset = 0);
  void compileClass();
  bool compileClassVarDec();
  bool compileSubroutine();
  bool compileSubroutineBody();
  bool _compileSubroutineCall();
  void compileParameterList();
  bool compileVarDec();
  bool compileStatements();
  bool compileDo();
  bool compileLet();
  bool compileWhile();
  bool compileReturn();
  bool compileIf();
  bool compileExpression();

  void compileTerm(int* iteration, bool* succesfull);
  void compileExpressionList();
  // bool tokenIsOp();
  /*When terminal reached this method will be called*/
  void writeToFile();
  void writeToFileStartNonTerminal(const std::string& nonTerminal);
  void writeToFileFinishNonTerminal(const std::string& nonTerminal);
};

#endif
