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
  const std::string& outputFilePath;
  JackAnalyzer(const std::string &filepath, const std::string &outputFilePath);
  ~JackAnalyzer();
  void run();

private:
  void handleFile(const std::filesystem::path &filePath);
  void handleFolder(const std::filesystem::path &fileFolder);
};

#endif
