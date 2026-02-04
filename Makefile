#Usefule compile commands 
#make VERBOSE=y all &>make_output.txt
#compiledb --parse make_output.txt

.PHONY: all clean

CXXFLAGS := -g -std=c++17 -Werror -Wall
CXX := g++
executable := jack_compiler

build_dir := build
src_dir := src
include_dir := include


srcs := $(shell find ${src_dir} -type f -name "*.cpp" )
srcs_objs := $(patsubst %,${build_dir}/%.o,${srcs})
deps := $(patsubst %,${build_dir}/%.d,${srcs})
$(info ${srcs})
$(info ${srcs_objs})
$(info ${deps})
#$(error stop)

CXXFLAGS += $(addprefix -I,${include_dir})
CXXFLAGS += -MMD -MP
#DEBUGFLAGS:= -DDEBUG


all: target

target: ${build_dir}/${executable}	##		For generating executable that will run the vm translator

${build_dir}/${executable}: ${srcs_objs}
	$(info $^)
	$(CXX) $^ -o $@

${build_dir}/${src_dir}/%.cpp.o: ${src_dir}/%.cpp
		$(info par ici)
		mkdir -p ${@D}
			$(CXX) $(CXXFLAGS) $(DEBUGFLAGS) -c $< -o $@

-include $(deps)

clean:
	rm -rf ./build
