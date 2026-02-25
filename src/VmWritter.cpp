#include "VmWritter.hpp"
#include <regex>
#include <string>

VmWritter::VmWritter(const std::filesystem::path& outputFilePath)
    : outputFile(std::ofstream(outputFilePath)),
      writePushTemplate(this->getTemplate("writePushTemplate.txt")),
      writePopTemplate(this->getTemplate("writePopTemplate.txt")),
      writeArithmeticTemplate(this->getTemplate("writeArithmeticTemplate.txt")),
      writeLabelTemplate(this->getTemplate("writeLabelTemplate.txt")),
      writeGotoTemplate(this->getTemplate("writeGotoTemplate.txt")),
      writeIfTemplate(this->getTemplate("writeIfTemplate.txt")),
      writeCallTemplate(this->getTemplate("writeCallTemplate.txt")),
      writeFunctionTemplate(this->getTemplate("writeFunctionTemplate.txt")),
      writeReturnTemplate(this->getTemplate("writeReturnTemplate.txt")) {}

void VmWritter::PatternMgr::addPattern(const std::string& pattern,
                                       const std::string& replacement) {

  this->patternMap[pattern] = replacement;
  this->patternInsertionTrack.push_back(pattern);
}

void VmWritter::writePush(const std::string& virtualSegment,
                          int virtualSegmentIndex) {
  PatternMgr patternMgr = PatternMgr();

  std::string virtualSegmentRegex = R"(\#\#memorySegment\#\#)";
  std::string virtualSegmentIndexRegex = R"(\#\#memorySegmentIndex\#\#)";

  patternMgr.addPattern(virtualSegmentRegex, virtualSegment);
  patternMgr.addPattern(virtualSegmentIndexRegex,
                        std::to_string(virtualSegmentIndex));

  std::string writePushTemplateInstance = this->writePushTemplate;

  this->transformInstanceTemplate(patternMgr, writePushTemplateInstance, false);

  this->outputFile << writePushTemplateInstance << "\n";
}
void VmWritter::writePop(const std::string& virtualSegment,
                         int virtualSegmentIndex) {
  PatternMgr patternMgr = PatternMgr();

  std::string virtualSegmentRegex = R"(\#\#memorySegment\#\#)";
  std::string virtualSegmentIndexRegex = R"(\#\#memorySegmentIndex\#\#)";

  patternMgr.addPattern(virtualSegmentRegex, virtualSegment);
  patternMgr.addPattern(virtualSegmentIndexRegex,
                        std::to_string(virtualSegmentIndex));

  std::string writePopTemplateInstance = this->writePopTemplate;

  this->transformInstanceTemplate(patternMgr, writePopTemplateInstance, false);

  this->outputFile << writePopTemplateInstance << "\n";
}
void VmWritter::writeArithmetic(const std::string& command) {

  PatternMgr patternMgr = PatternMgr();

  std::string commandRegex = R"(\#\#command\#\#)";

  patternMgr.addPattern(commandRegex, command);

  std::string writeArithmeticTemplateInstance = this->writeArithmeticTemplate;

  this->transformInstanceTemplate(patternMgr, writeArithmeticTemplateInstance,
                                  false);

  this->outputFile << writeArithmeticTemplateInstance << "\n";
}
void VmWritter::writeLabel(const std::string& label) {

  PatternMgr patternMgr = PatternMgr();

  std::string labelRegex = R"(\#\#label\#\#)";

  patternMgr.addPattern(labelRegex, label);

  std::string writeLabelTemplateInstance = this->writeLabelTemplate;

  this->transformInstanceTemplate(patternMgr, writeLabelTemplateInstance,
                                  false);

  this->outputFile << writeLabelTemplateInstance << "\n";
}
void VmWritter::writeGoto(const std::string& label) {

  PatternMgr patternMgr = PatternMgr();

  std::string labelRegex = R"(\#\#label\#\#)";

  patternMgr.addPattern(labelRegex, label);

  std::string writeGotoTemplateInstance = this->writeGotoTemplate;

  this->transformInstanceTemplate(patternMgr, writeGotoTemplateInstance, false);

  this->outputFile << writeGotoTemplateInstance << "\n";
}
void VmWritter::writeIf(const std::string& label) {

  PatternMgr patternMgr = PatternMgr();

  std::string labelRegex = R"(\#\#label\#\#)";

  patternMgr.addPattern(labelRegex, label);

  std::string writeIfTemplateInstance = this->writeIfTemplate;

  this->transformInstanceTemplate(patternMgr, writeIfTemplateInstance, false);

  this->outputFile << writeIfTemplateInstance << "\n";
}
void VmWritter::writeCall(const std::string& className, const std::string& name,
                          int nArgs) {
  PatternMgr patternMgr = PatternMgr();

  std::string classNameRegex = R"(\#\#className\#\#)";
  std::string functionNameRegex = R"(\#\#functionName\#\#)";
  std::string nArgsRegex = R"(\#\#nArgs\#\#)";

  patternMgr.addPattern(classNameRegex, className);
  patternMgr.addPattern(functionNameRegex, name);
  patternMgr.addPattern(nArgsRegex, std::to_string(nArgs));

  std::string writeCallTemplateInstance = this->writeCallTemplate;

  this->transformInstanceTemplate(patternMgr, writeCallTemplateInstance, false);

  this->outputFile << writeCallTemplateInstance << "\n";
}
void VmWritter::writeFunction(const std::string& className,
                              const std::string& name, int nLocals) {
  PatternMgr patternMgr = PatternMgr();

  std::string classNameRegex = R"(\#\#className\#\#)";
  std::string functionNameRegex = R"(\#\#functionName\#\#)";
  std::string nLocalsRegex = R"(\#\#nLocals\#\#)";

  patternMgr.addPattern(classNameRegex, className);
  patternMgr.addPattern(functionNameRegex, name);
  patternMgr.addPattern(nLocalsRegex, std::to_string(nLocals));

  std::string writeFunctionTemplateInstance = this->writeFunctionTemplate;

  this->transformInstanceTemplate(patternMgr, writeFunctionTemplateInstance,
                                  false);

  this->outputFile << writeFunctionTemplateInstance << "\n";
}
void VmWritter::writeReturn(void) {
  this->outputFile << this->writeReturnTemplate << "\n";
}

void VmWritter::transformInstanceTemplate(PatternMgr& patternMgr,
                                          std::string& assemblyTemplate,
                                          bool firstOnly) {
  for (auto element : patternMgr.patternInsertionTrack) {
    assemblyTemplate =
        firstOnly ? std::regex_replace(assemblyTemplate, std::regex(element),
                                       patternMgr.patternMap[element],
                                       std::regex_constants::format_first_only)
                  : std::regex_replace(assemblyTemplate, std::regex(element),
                                       patternMgr.patternMap[element]);
  }
}
std::string VmWritter::getTemplate(const std::string& writeTemplate) {
  std::filesystem::path cwd = std::filesystem::current_path();
  std::filesystem::path filepath =

      cwd.string() + "/" + "templates" + "/" + writeTemplate;
  if (!std::filesystem::exists(filepath.string())) {
    return "";
  }

  std::string result = std::string();
  std::string currentLine;
  std::ifstream file = std::ifstream(filepath);

  while (std::getline(file, currentLine)) {
    result += currentLine;
    result += "\n";
  }
  result.pop_back();
  file.close();
  return result;
}
VmWritter::~VmWritter() { this->outputFile.close(); }
