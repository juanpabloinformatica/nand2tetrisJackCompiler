#include <JackAnalyzer.hpp>
JackAnalyzer::JackAnalyzer(const std::string &filepath)
    : sourcePath(filepath) {}
void JackAnalyzer::run() { 
	if (!std::filesystem::exists(this->sourcePath))
		return;
	if(std::filesystem::is_regular_file(this->sourcePath))
		this->handleFile();
	if(std::filesystem::is_directory(this->sourcePath))
	
}
void JackAnalyzer::handleFile() {}
void JackAnalyzer::handleFolder() {}
JackAnalyzer::~JackAnalyzer() {
  std::cout << "Calling destructor" << std::endl;
}
