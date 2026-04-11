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
  std::string outputFilePath;
  JackAnalyzer(const std::string &inputFilepath);
  ~JackAnalyzer();
  void run();

private:
  void handleFile(const std::filesystem::path &filePath);
  void handleFolder(const std::filesystem::path &fileFolder);
  void setOutputFilePath(const std::filesystem::path &filePath);
  bool isJackFile(const std::filesystem::path &filePath);
};

#endif
