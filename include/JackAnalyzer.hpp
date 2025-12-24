#ifndef __ANALYZER__
#define __ANALYZER__
// #import <JackTokenizer.h>
#include <filesystem>
#include <iostream>
#include <string>
class JackAnalyzer {
public:
  // JackTokenizer jackTokenizer;
  const std::string &sourcePath;
  JackAnalyzer(const std::string &filepath);
  ~JackAnalyzer();
  void run();

private:
  void handleFile();
  void handleFolder();
};

#endif
