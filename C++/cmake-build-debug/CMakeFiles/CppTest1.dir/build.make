# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/walter/Desktop/CppTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/walter/Desktop/CppTest/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/CppTest1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CppTest1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CppTest1.dir/flags.make

CMakeFiles/CppTest1.dir/main.cpp.o: CMakeFiles/CppTest1.dir/flags.make
CMakeFiles/CppTest1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/walter/Desktop/CppTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CppTest1.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CppTest1.dir/main.cpp.o -c /Users/walter/Desktop/CppTest/main.cpp

CMakeFiles/CppTest1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CppTest1.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/walter/Desktop/CppTest/main.cpp > CMakeFiles/CppTest1.dir/main.cpp.i

CMakeFiles/CppTest1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CppTest1.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/walter/Desktop/CppTest/main.cpp -o CMakeFiles/CppTest1.dir/main.cpp.s

CMakeFiles/CppTest1.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/CppTest1.dir/main.cpp.o.requires

CMakeFiles/CppTest1.dir/main.cpp.o.provides: CMakeFiles/CppTest1.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/CppTest1.dir/build.make CMakeFiles/CppTest1.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/CppTest1.dir/main.cpp.o.provides

CMakeFiles/CppTest1.dir/main.cpp.o.provides.build: CMakeFiles/CppTest1.dir/main.cpp.o


# Object files for target CppTest1
CppTest1_OBJECTS = \
"CMakeFiles/CppTest1.dir/main.cpp.o"

# External object files for target CppTest1
CppTest1_EXTERNAL_OBJECTS =

CppTest1: CMakeFiles/CppTest1.dir/main.cpp.o
CppTest1: CMakeFiles/CppTest1.dir/build.make
CppTest1: CMakeFiles/CppTest1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/walter/Desktop/CppTest/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CppTest1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CppTest1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CppTest1.dir/build: CppTest1

.PHONY : CMakeFiles/CppTest1.dir/build

CMakeFiles/CppTest1.dir/requires: CMakeFiles/CppTest1.dir/main.cpp.o.requires

.PHONY : CMakeFiles/CppTest1.dir/requires

CMakeFiles/CppTest1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CppTest1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CppTest1.dir/clean

CMakeFiles/CppTest1.dir/depend:
	cd /Users/walter/Desktop/CppTest/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/walter/Desktop/CppTest /Users/walter/Desktop/CppTest /Users/walter/Desktop/CppTest/cmake-build-debug /Users/walter/Desktop/CppTest/cmake-build-debug /Users/walter/Desktop/CppTest/cmake-build-debug/CMakeFiles/CppTest1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CppTest1.dir/depend

