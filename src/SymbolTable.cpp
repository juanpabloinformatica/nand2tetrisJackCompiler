#include "SymbolTable.hpp"
#include "CompilationEngine.hpp"
#include <iostream>
#include <stdexcept>
SymbolTable::SymbolTable()
    : symbolTable(std::map<std::string, Symbol *>()), currentSymbol(nullptr),
      staticSymbolCounter(0), fieldSymbolCounter(0), argumentSymbolCounter(0),
      localSymbolCounter(0) {}

/*Need to be destroy in table destructor*/
void SymbolTable::setSymbol(Symbol *symbol) { this->currentSymbol = symbol; }
SymbolTable::Symbol *SymbolTable::getCurrentSymbol() {
  return this->currentSymbol;
}
SymbolTable::Symbol *SymbolTable::getSymbol(const std::string &symbolName) {
  SymbolTable::Symbol *symbol;
  try {
    symbol = this->symbolTable.at(symbolName);
  } catch (const std::out_of_range &oor) {
    symbol = NULL;
  }
  return symbol;
}
const std::map<std::string, SymbolTable::Symbol *> &
SymbolTable::getSymbolTable() {
  return this->symbolTable;
}
SymbolTable::Symbol *SymbolTable::allocateSymbol() {
  return new SymbolTable::Symbol();
}
/*In this function I should handle the # field of the hashtable*/
void SymbolTable::incrementSymbolCounter(const std::string &kind) {
  if (kind == "static")
    this->staticSymbolCounter++;
  else if (kind == "field")
    this->fieldSymbolCounter++;
  else if (kind == "argument")
    this->argumentSymbolCounter++;
  else
    this->localSymbolCounter++;
  return;
}
void SymbolTable::addSymbol(SymbolTable::Symbol *symbol) {
  assert(symbol->name != "");
  this->setSymbolPosInSegment(symbol);
  this->incrementSymbolCounter(symbol->kind);
  this->symbolTable.insert({symbol->name, symbol});
}
void SymbolTable::setSymbolPosInSegment(Symbol *symbol) {

  std::cout << "In here" << "\n";
  if (symbol->kind == "static")
    symbol->posInSegment = staticSymbolCounter;
  else if (symbol->kind == "field")
    symbol->posInSegment = fieldSymbolCounter;
  else if (symbol->kind == "argument")
    symbol->posInSegment = argumentSymbolCounter;
  else
    symbol->posInSegment = localSymbolCounter;
  return;
}
void SymbolTable::Symbol::setName(const std::string &name) {
  this->name = name;
}
void SymbolTable::Symbol::setKind(const std::string &kind) {
  if (kind == "var") {
    this->kind = "local";
    return;
  }
  this->kind = kind;
}
void SymbolTable::Symbol::setType(const std::string &type) {
  this->type = type;
}

void SymbolTable::Symbol::setPosInSegment(int posInSegment) {
  this->posInSegment = posInSegment;
}

int SymbolTable::getLocalSymbolCounter() { return this->localSymbolCounter; }

void SymbolTable::resetSymbolTable() {
  this->_deallocateSymbols();
  this->symbolTable.clear();
  this->staticSymbolCounter = 0;
  this->fieldSymbolCounter = 0;
  this->argumentSymbolCounter = 0;
  this->localSymbolCounter = 0;
}

void SymbolTable::_deallocateSymbols() {
  /*Destroying each created symbol*/
  for (auto symbol : this->symbolTable) {
    delete symbol.second;
  }
}
SymbolTable::~SymbolTable() {
  /*Destroying each created symbol*/
  this->_deallocateSymbols();
}
