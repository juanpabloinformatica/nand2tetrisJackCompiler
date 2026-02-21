#ifndef __SYMBOL_TABLE__
#define __SYMBOL_TABLE__
#include <string>
#include <vector>
class SymbolTable {

public:
  SymbolTable();
  void addSymbolTableObject(std::string name, std::string type,
                            std::string kind, int scope);
  void getSymbolTableObject(std::string name);

private:
  class SymbolTableObject {
  public:
    std::string name;
    std::string type;
    std::string kind;
    int scope;
    SymbolTableObject(std::string name, std::string type, std::string kind,
                      int scope);
  };
  std::vector<SymbolTableObject> tableList;
};
#endif
