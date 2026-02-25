#ifndef __VM_WRITTER__
#define __VM_WRITTER__
#include <filesystem>
#include <fstream>
#include <map>
#include <vector>
class VmWritter {
public:
  VmWritter(const std::filesystem::path& outputFilePath);
  void writePush(const std::string& virtualSegment, int virtualSegmentIndex);
  void writePop(const std::string& virtualSegment, int virtualSegmentIndex);
  void writeArithmetic(const std::string& command);
  void writeLabel(const std::string& label);
  void writeGoto(const std::string& label);
  void writeIf(const std::string& label);
  void writeCall(const std::string& className, const std::string& name,
                 int nArgs);
  void writeFunction(const std::string& className, const std::string& name,
                     int nLocals);
  void writeReturn(void);
  ~VmWritter();

private:
  std::ofstream outputFile;
  std::string writePushTemplate;
  std::string writePopTemplate;
  std::string writeArithmeticTemplate;
  std::string writeLabelTemplate;
  std::string writeGotoTemplate;
  std::string writeIfTemplate;
  std::string writeCallTemplate;
  std::string writeFunctionTemplate;
  std::string writeReturnTemplate;
  std::string getTemplate(const std::string& writeTemplate);
  class PatternMgr {
  public:
    std::map<std::string, std::string> patternMap;
    std::vector<std::string> patternInsertionTrack;
    void addPattern(const std::string& pattern, const std::string& replacement);
  };
  void transformInstanceTemplate(PatternMgr& patternMgr,
                                 std::string& assemblyTemplate, bool firstOnly);
};
#endif
