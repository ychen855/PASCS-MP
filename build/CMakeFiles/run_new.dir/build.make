# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/d/Projects/correntropy_dict

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d/Projects/correntropy_dict/build

# Include any dependencies generated for this target.
include CMakeFiles/run_new.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/run_new.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/run_new.dir/flags.make

CMakeFiles/run_new.dir/run_new.cpp.o: CMakeFiles/run_new.dir/flags.make
CMakeFiles/run_new.dir/run_new.cpp.o: ../run_new.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d/Projects/correntropy_dict/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/run_new.dir/run_new.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/run_new.dir/run_new.cpp.o -c /mnt/d/Projects/correntropy_dict/run_new.cpp

CMakeFiles/run_new.dir/run_new.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/run_new.dir/run_new.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d/Projects/correntropy_dict/run_new.cpp > CMakeFiles/run_new.dir/run_new.cpp.i

CMakeFiles/run_new.dir/run_new.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/run_new.dir/run_new.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d/Projects/correntropy_dict/run_new.cpp -o CMakeFiles/run_new.dir/run_new.cpp.s

# Object files for target run_new
run_new_OBJECTS = \
"CMakeFiles/run_new.dir/run_new.cpp.o"

# External object files for target run_new
run_new_EXTERNAL_OBJECTS =

run_new: CMakeFiles/run_new.dir/run_new.cpp.o
run_new: CMakeFiles/run_new.dir/build.make
run_new: CMakeFiles/run_new.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d/Projects/correntropy_dict/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable run_new"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/run_new.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/run_new.dir/build: run_new

.PHONY : CMakeFiles/run_new.dir/build

CMakeFiles/run_new.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/run_new.dir/cmake_clean.cmake
.PHONY : CMakeFiles/run_new.dir/clean

CMakeFiles/run_new.dir/depend:
	cd /mnt/d/Projects/correntropy_dict/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d/Projects/correntropy_dict /mnt/d/Projects/correntropy_dict /mnt/d/Projects/correntropy_dict/build /mnt/d/Projects/correntropy_dict/build /mnt/d/Projects/correntropy_dict/build/CMakeFiles/run_new.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/run_new.dir/depend
