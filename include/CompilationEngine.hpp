#ifndef __C_ENGINE__
#define __C_ENGINE__
#include <string>

#include "SymbolTable.hpp"
#include "Types.hpp"
#include "VmWritter.hpp"
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
          &tokenList,
      const std::string &outputFilePath);

  /*Not extended*/
  ~CompilationEngine();
  const std::vector<std::map<std::string, JackTypes::TokenType> *> &
  getTokenList();
  void run();

private:
  const std::vector<std::map<std::string, JackTypes::TokenType> *> tokenList;
  int tokenListIndex;
  int flagIsDoStatement;
  SymbolTable classSymbolTable;
  SymbolTable subroutineSymbolTable;
  /*This will be needed for identify if the subroutine is a method or a
   * function* this is necessary for knowing how the call command will be
   * invoked, if is a method I need to push the object as 1 argument if not is
   * not needed.
   */
  /*subroutineName:type*/
  std::map<std::string, std::string> subroutineTable;
  VmWritter vmWritter;
  /**/
  std::string currentClass;
  /*above all for labels*/
  std::string currentSubroutine;
  /*For functions, methods, static functions*/
  std::string currentSubroutineType;
  /**/
  /* For handling loops */
  std::string label;
  std::stack<std::string> labelStack;
  /**/
  inline std::string tokenListKey(int offset = 0);
  inline JackTypes::TokenType tokenListValue(int offset = 0);
  void compileClass();
  bool compileClassVarDec();
  bool compileSubroutine();
  /*Manual*/
  bool compileSubroutineBody();
  bool _compileSubroutineCall();
  void compileParameterList(int *nArgsCounter);
  bool compileVarDec();
  bool compileStatements();
  bool compileDo();
  bool compileLet();
  bool compileWhile();
  bool compileReturn();
  bool compileIf();
  bool compileExpression();
  /*for handling expressions*/
  void _codeWrite(std::string &expression);
  /*For getting the symbol information*/
  SymbolTable::Symbol *_getSymbol(const std::string &symbolName);
  /*For getting subroutineType*/
  std::string _getSubroutineType(const std::string &subroutineName);
  void compileTerm(int *iteration, bool *succesfull);
  void compileExpressionList();
  // bool tokenIsOp();
  /*When terminal reached this method will be called*/
  void writeToFile();
  void writeToFileStartNonTerminal(const std::string &nonTerminal);
  void writeToFileFinishNonTerminal(const std::string &nonTerminal);
  /*For handling loops*/
  int labelCounter;
  /*Needed for been able to know when a subroutine that belongs
   * to the same module is either a method of a function*/
  void populateSubroutineTable();
};

#endif
