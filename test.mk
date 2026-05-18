
# CXXFLAGS := -g -std=c++17 -Werror -Wall
# CXX := g++
TARGET:= test
SIMULATE_MEMORY:= simulateMemory
TEST_DIR:= ./test
BUILD_DIR:= ./build




test: ${BUILD_DIR}/${TEST_DIR}/src ${BUILD_DIR}/${TEST_DIR}/src/${TARGET}

${BUILD_DIR}/${TEST_DIR}/src/${TARGET}:${TEST_DIR}/src/${TARGET}.cpp
	$(CXX) $(CXXFLAGS) -g3 $^ -o $@


simulate_memory: ${BUILD_DIR}/${TEST_DIR}/src ${BUILD_DIR}/${TEST_DIR}/src/${SIMULATE_MEMORY}

${BUILD_DIR}/${TEST_DIR}/src/${SIMULATE_MEMORY}:${TEST_DIR}/src/${SIMULATE_MEMORY}.c
	gcc -fsanitize=address -fno-omit-frame-pointer -Wall -Werror -pedantic -std=c23 -g3 $^ -o $@ -lasan

${BUILD_DIR}/${TEST_DIR}/src:
	printf "In here"
	mkdir -p $@


