#include "JackAnalyzer.hpp"
#include "CompilationEngine.hpp"
#include <cassert>
#include <cstdio>
JackAnalyzer::JackAnalyzer(const std::string &inputFilepath)
    : sourcePath(inputFilepath), outputFilePath(std::string()) {}

void JackAnalyzer::setOutputFilePath(const std::filesystem::path &filePath) {
  if (filePath.string().empty())
    return;
  /*I need to replace the file extension*/
  /* from .jack -----> .vm */
  std::string absPath = filePath.lexically_normal().string();
  this->outputFilePath = absPath.substr(0, absPath.find_last_of(".")) + ".vm";
}

void JackAnalyzer::run() {

  if (!std::filesystem::exists(this->sourcePath) == true) {
    std::cout << "file doesn't exist" << "\n";
    return;
  }

  std::filesystem::is_regular_file(this->sourcePath)
      ? this->handleFile(this->sourcePath)
      : this->handleFolder(this->sourcePath);
}
void JackAnalyzer::handleFolder(const std::filesystem::path &fileFolder) {

  for (const auto &dirEntry :
       std::filesystem::recursive_directory_iterator(this->sourcePath)) {
    if (dirEntry.is_regular_file()) {
      this->handleFile(dirEntry.path());
    }
  }
}

bool JackAnalyzer::isJackFile(const std::filesystem::path &filePath) {
  std::string absPath = filePath.lexically_normal().string();
  return (absPath.substr(absPath.find_last_of("."),
                         absPath.size() - absPath.find_last_of(".")) == ".jack")
             ? true
             : false;
}
void JackAnalyzer::handleFile(const std::filesystem::path &filePath) {

  if (!isJackFile(filePath))
    return;

  /*setting the output file*/
  this->setOutputFilePath(filePath);

  JackTokenizer jackTokenizer = JackTokenizer(filePath);
  jackTokenizer.run();
  CompilationEngine compilationEngine =
      CompilationEngine(jackTokenizer.getTokenList(), this->outputFilePath);
  compilationEngine.run();
  return;
}

JackAnalyzer::~JackAnalyzer() {
  std::cout << "Calling destructor" << std::endl;
}
