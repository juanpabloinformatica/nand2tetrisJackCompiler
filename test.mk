
# CXXFLAGS := -g -std=c++17 -Werror -Wall
# CXX := g++
TARGET:= test
TEST_DIR:= ./test
BUILD_DIR:= ./build



test: ${BUILD_DIR}/${TEST_DIR}/src ${BUILD_DIR}/${TEST_DIR}/src/${TARGET}

${BUILD_DIR}/${TEST_DIR}/src/${TARGET}:${TEST_DIR}/src/${TARGET}.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

${BUILD_DIR}/${TEST_DIR}/src:
	printf "In here"
	mkdir -p $@


