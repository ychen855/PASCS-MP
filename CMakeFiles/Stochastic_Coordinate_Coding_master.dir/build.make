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
CMAKE_SOURCE_DIR = /home/jianfen6/sparse/Stochastic-Coordinate-Coding-master/cmake-build-debug_norandom

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jianfen6/sparse/Stochastic-Coordinate-Coding-master/cmake-build-debug_norandom

# Include any dependencies generated for this target.
include CMakeFiles/Stochastic_Coordinate_Coding_master.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Stochastic_Coordinate_Coding_master.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Stochastic_Coordinate_Coding_master.dir/flags.make

CMakeFiles/Stochastic_Coordinate_Coding_master.dir/run.cpp.o: CMakeFiles/Stochastic_Coordinate_Coding_master.dir/flags.make
CMakeFiles/Stochastic_Coordinate_Coding_master.dir/run.cpp.o: run.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jianfen6/sparse/Stochastic-Coordinate-Coding-master/cmake-build-debug_norandom/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Stochastic_Coordinate_Coding_master.dir/run.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Stochastic_Coordinate_Coding_master.dir/run.cpp.o -c /home/jianfen6/sparse/Stochastic-Coordinate-Coding-master/cmake-build-debug_norandom/run.cpp

CMakeFiles/Stochastic_Coordinate_Coding_master.dir/run.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Stochastic_Coordinate_Coding_master.dir/run.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jianfen6/sparse/Stochastic-Coordinate-Coding-master/cmake-build-debug_norandom/run.cpp > CMakeFiles/Stochastic_Coordinate_Coding_master.dir/run.cpp.i

CMakeFiles/Stochastic_Coordinate_Coding_master.dir/run.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Stochastic_Coordinate_Coding_master.dir/run.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jianfen6/sparse/Stochastic-Coordinate-Coding-master/cmake-build-debug_norandom/run.cpp -o CMakeFiles/Stochastic_Coordinate_Coding_master.dir/run.cpp.s

CMakeFiles/Stochastic_Coordinate_Coding_master.dir/run.cpp.o.requires:
.PHONY : CMakeFiles/Stochastic_Coordinate_Coding_master.dir/run.cpp.o.requires

CMakeFiles/Stochastic_Coordinate_Coding_master.dir/run.cpp.o.provides: CMakeFiles/Stochastic_Coordinate_Coding_master.dir/run.cpp.o.requires
	$(MAKE) -f CMakeFiles/Stochastic_Coordinate_Coding_master.dir/build.make CMakeFiles/Stochastic_Coordinate_Coding_master.dir/run.cpp.o.provides.build
.PHONY : CMakeFiles/Stochastic_Coordinate_Coding_master.dir/run.cpp.o.provides

CMakeFiles/Stochastic_Coordinate_Coding_master.dir/run.cpp.o.provides.build: CMakeFiles/Stochastic_Coordinate_Coding_master.dir/run.cpp.o

# Object files for target Stochastic_Coordinate_Coding_master
Stochastic_Coordinate_Coding_master_OBJECTS = \
"CMakeFiles/Stochastic_Coordinate_Coding_master.dir/run.cpp.o"

# External object files for target Stochastic_Coordinate_Coding_master
Stochastic_Coordinate_Coding_master_EXTERNAL_OBJECTS =

Stochastic_Coordinate_Coding_master: CMakeFiles/Stochastic_Coordinate_Coding_master.dir/run.cpp.o
Stochastic_Coordinate_Coding_master: CMakeFiles/Stochastic_Coordinate_Coding_master.dir/build.make
Stochastic_Coordinate_Coding_master: CMakeFiles/Stochastic_Coordinate_Coding_master.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable Stochastic_Coordinate_Coding_master"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Stochastic_Coordinate_Coding_master.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Stochastic_Coordinate_Coding_master.dir/build: Stochastic_Coordinate_Coding_master
.PHONY : CMakeFiles/Stochastic_Coordinate_Coding_master.dir/build

CMakeFiles/Stochastic_Coordinate_Coding_master.dir/requires: CMakeFiles/Stochastic_Coordinate_Coding_master.dir/run.cpp.o.requires
.PHONY : CMakeFiles/Stochastic_Coordinate_Coding_master.dir/requires

CMakeFiles/Stochastic_Coordinate_Coding_master.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Stochastic_Coordinate_Coding_master.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Stochastic_Coordinate_Coding_master.dir/clean

CMakeFiles/Stochastic_Coordinate_Coding_master.dir/depend:
	cd /home/jianfen6/sparse/Stochastic-Coordinate-Coding-master/cmake-build-debug_norandom && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jianfen6/sparse/Stochastic-Coordinate-Coding-master/cmake-build-debug_norandom /home/jianfen6/sparse/Stochastic-Coordinate-Coding-master/cmake-build-debug_norandom /home/jianfen6/sparse/Stochastic-Coordinate-Coding-master/cmake-build-debug_norandom /home/jianfen6/sparse/Stochastic-Coordinate-Coding-master/cmake-build-debug_norandom /home/jianfen6/sparse/Stochastic-Coordinate-Coding-master/cmake-build-debug_norandom/CMakeFiles/Stochastic_Coordinate_Coding_master.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Stochastic_Coordinate_Coding_master.dir/depend
