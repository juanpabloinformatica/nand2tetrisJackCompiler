#ifndef __SYMBOL_TABLE__
#define __SYMBOL_TABLE__
#include <cassert>
#include <map>
#include <string>
/*
 * easier for looking up
 * identifier : {.type = type, .kind=kind, .scope=scope}
 * identifier : {.type = type, .kind=kind, .scope=scope}
 * identifier : {.type = type, .kind=kind, .scope=scope}
 * identifier : {.type = type, .kind=kind, .scope=scope}
 * identifier : {.type = type, .kind=kind, .scope=scope}
 * */
class SymbolTable {
public:
  SymbolTable();
  ~SymbolTable();

  class Symbol {
  public:
    std::string name;
    std ::string type;
    std ::string kind;
    int posInSegment;
    Symbol(std ::string name = "", std ::string type = "",
           std ::string kind = "", int posInSegment = -1)
        : name(name), type(type), kind(kind), posInSegment(posInSegment) {};
    void setName(const std::string& name);
    void setType(const std::string& type);
    void setKind(const std::string& kind);
    void setPosInSegment(int posInSegment);
  };
  std::map<std::string, Symbol> const& getSymbolTable();
  Symbol* allocateSymbol();
  void addSymbol(Symbol* symbol);
  Symbol* getSymbol();
  void setSymbol(Symbol* symbol);
  void resetSymbolTable();

private:
  std::map<std::string, Symbol*> symbolTable;
  Symbol* currentSymbol;
  int staticSymbolCounter;
  int fieldSymbolCounter;
  int argumentSymbolCounter;
  int localSymbolCounter;
  void incrementSymbolCounter(const std::string& kind);
  void setSymbolPosInSegment(Symbol* symbol);
  void _deallocateSymbols();
};
/*I prefer composition*/
// I do it after
//  class SubroutineSymbolTable{
//  public:
//    SymbolTable
//  };

#endif
