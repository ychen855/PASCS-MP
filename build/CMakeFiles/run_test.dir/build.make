# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /scratch/ychen855/correntropy_dict

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /scratch/ychen855/correntropy_dict/build

# Include any dependencies generated for this target.
include CMakeFiles/run_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/run_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/run_test.dir/flags.make

CMakeFiles/run_test.dir/run_test.cpp.o: CMakeFiles/run_test.dir/flags.make
CMakeFiles/run_test.dir/run_test.cpp.o: ../run_test.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /scratch/ychen855/correntropy_dict/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/run_test.dir/run_test.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/run_test.dir/run_test.cpp.o -c /scratch/ychen855/correntropy_dict/run_test.cpp

CMakeFiles/run_test.dir/run_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run_test.dir/run_test.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /scratch/ychen855/correntropy_dict/run_test.cpp > CMakeFiles/run_test.dir/run_test.cpp.i

CMakeFiles/run_test.dir/run_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run_test.dir/run_test.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /scratch/ychen855/correntropy_dict/run_test.cpp -o CMakeFiles/run_test.dir/run_test.cpp.s

CMakeFiles/run_test.dir/run_test.cpp.o.requires:
.PHONY : CMakeFiles/run_test.dir/run_test.cpp.o.requires

CMakeFiles/run_test.dir/run_test.cpp.o.provides: CMakeFiles/run_test.dir/run_test.cpp.o.requires
	$(MAKE) -f CMakeFiles/run_test.dir/build.make CMakeFiles/run_test.dir/run_test.cpp.o.provides.build
.PHONY : CMakeFiles/run_test.dir/run_test.cpp.o.provides

CMakeFiles/run_test.dir/run_test.cpp.o.provides.build: CMakeFiles/run_test.dir/run_test.cpp.o

# Object files for target run_test
run_test_OBJECTS = \
"CMakeFiles/run_test.dir/run_test.cpp.o"

# External object files for target run_test
run_test_EXTERNAL_OBJECTS =

run_test: CMakeFiles/run_test.dir/run_test.cpp.o
run_test: CMakeFiles/run_test.dir/build.make
run_test: CMakeFiles/run_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable run_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/run_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/run_test.dir/build: run_test
.PHONY : CMakeFiles/run_test.dir/build

CMakeFiles/run_test.dir/requires: CMakeFiles/run_test.dir/run_test.cpp.o.requires
.PHONY : CMakeFiles/run_test.dir/requires

CMakeFiles/run_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/run_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/run_test.dir/clean

CMakeFiles/run_test.dir/depend:
	cd /scratch/ychen855/correntropy_dict/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /scratch/ychen855/correntropy_dict /scratch/ychen855/correntropy_dict /scratch/ychen855/correntropy_dict/build /scratch/ychen855/correntropy_dict/build /scratch/ychen855/correntropy_dict/build/CMakeFiles/run_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/run_test.dir/depend

