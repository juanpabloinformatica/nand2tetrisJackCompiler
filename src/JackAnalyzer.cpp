#include "JackAnalyzer.hpp"
JackAnalyzer::JackAnalyzer(const std::string &filepath)
    : sourcePath(filepath) {}

void JackAnalyzer::run() {

  if (!std::filesystem::exists(this->sourcePath) == true) {
    std::cout << "file doesn't exist" << "\n";
    return;
  }

  std::filesystem::is_regular_file(this->sourcePath)
      ? this->handleFile(this->sourcePath)
      : this->handleFolder(this->sourcePath);
}
void JackAnalyzer::handleFolder(const std::filesystem::path &folderFolder) {

  for (const auto &dirEntry :
       std::filesystem::recursive_directory_iterator(sourcePath)) {
    if (dirEntry.is_regular_file())
      this->handleFile(dirEntry.path());
  }
}
void JackAnalyzer::handleFile(const std::filesystem::path &filePath) {
  std::ifstream file(filePath);
  JackTokenizer JackTokenizer = ::JackTokenizer(file);
  JackTokenizer.run();
  JackTokenizer.showTokenList();
  return;
  /*Logic*/
}

JackAnalyzer::~JackAnalyzer() {
  std::cout << "Calling destructor" << std::endl;
}
