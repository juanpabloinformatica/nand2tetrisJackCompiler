#ifndef __ANALYZER__
#define __ANALYZER__
#include "JackTokenizer.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
class JackAnalyzer {
public:
  // JackTokenizer jackTokenizer;
  const std::filesystem::path sourcePath;
  JackAnalyzer(const std::string &filepath);
  ~JackAnalyzer();
  void run();

private:
  void handleFile(const std::filesystem::path &filePath);
  void handleFolder(const std::filesystem::path &fileFolder);
};

#endif
