#include <string>
#include <fstream>
#include <vector>

class CmakeBuilder {
public:
  CmakeBuilder(); // Constructor
  ~CmakeBuilder(); // Destructor

  void open(const std::string& path);
  void close();

  void addCmakeMinimumRequired(const int version);
  void addProject(const std::string& name);
  void addCMakeCXXStandard(const int version);

  void addExecutable(const std::string& name, const std::string& source);
  void addLibrary(const std::string& name, const std::string& source);
  void addTargetCompileOptions(const std::vector<std::string>& flags);
  void addTargetLinkLibraries(const std::vector<std::string>& libraries);

private:
  std::ofstream cmake;
  bool isClose;
};

CmakeBuilder::CmakeBuilder() {
  isClose = true;
}

CmakeBuilder::~CmakeBuilder() {
  if (!isClose) {
    close();
  }
}

void CmakeBuilder::open(const std::string& path) {
  if (!std::filesystem::exists(path)) {
    std::filesystem::create_directory(path); 
  }
  cmake.open(path + "/CMakeLists.txt");
  isClose = false;
}

void CmakeBuilder::close() {
  cmake.close();
  isClose = true;
}

void CmakeBuilder::addCmakeMinimumRequired(const int version) {
  cmake << "cmake_minimum_required(VERSION " << version << ")" << std::endl;
}

void CmakeBuilder::addProject(const std::string& name) {
  cmake << "project(" << name << ")" << std::endl;
}

void CmakeBuilder::addCMakeCXXStandard(const int version) {
  cmake << "set(CMAKE_CXX_STANDARD " << version << ")" << std::endl;
}

//Exucatable or Library
void CmakeBuilder::addExecutable(const std::string& name, const std::string& source) {
  cmake << "add_executable(" << name << " " << source << ")" << std::endl;
}

void CmakeBuilder::addLibrary(const std::string& name, const std::string& source) {
  cmake << "add_library(" << name << " " << source << ")" << std::endl;
}

//Flags
void CmakeBuilder::addTargetCompileOptions(const std::vector<std::string>& flags) {
  cmake << "target_compile_options(${PROJECT_NAME} PRIVATE";
  for (const auto& flag : flags) {
    cmake << " " << flag;
  }
  cmake << ")" << std::endl;
}

void CmakeBuilder::addTargetLinkLibraries(const std::vector<std::string>& libraries) {
  cmake << "target_link_libraries(${PROJECT_NAME} PRIVATE";
  for (const auto& library : libraries) {
    cmake << " " << library;
  }
  cmake << ")" << std::endl;
}
