# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/support/Desktop/okienko_wykres/matplotlib-cpp-master

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/support/Desktop/okienko_wykres/matplotlib-cpp-master/build

# Include any dependencies generated for this target.
include CMakeFiles/animation.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/animation.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/animation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/animation.dir/flags.make

CMakeFiles/animation.dir/examples/animation.cpp.o: CMakeFiles/animation.dir/flags.make
CMakeFiles/animation.dir/examples/animation.cpp.o: /home/support/Desktop/okienko_wykres/matplotlib-cpp-master/examples/animation.cpp
CMakeFiles/animation.dir/examples/animation.cpp.o: CMakeFiles/animation.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/support/Desktop/okienko_wykres/matplotlib-cpp-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/animation.dir/examples/animation.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/animation.dir/examples/animation.cpp.o -MF CMakeFiles/animation.dir/examples/animation.cpp.o.d -o CMakeFiles/animation.dir/examples/animation.cpp.o -c /home/support/Desktop/okienko_wykres/matplotlib-cpp-master/examples/animation.cpp

CMakeFiles/animation.dir/examples/animation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/animation.dir/examples/animation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/support/Desktop/okienko_wykres/matplotlib-cpp-master/examples/animation.cpp > CMakeFiles/animation.dir/examples/animation.cpp.i

CMakeFiles/animation.dir/examples/animation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/animation.dir/examples/animation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/support/Desktop/okienko_wykres/matplotlib-cpp-master/examples/animation.cpp -o CMakeFiles/animation.dir/examples/animation.cpp.s

# Object files for target animation
animation_OBJECTS = \
"CMakeFiles/animation.dir/examples/animation.cpp.o"

# External object files for target animation
animation_EXTERNAL_OBJECTS =

bin/animation: CMakeFiles/animation.dir/examples/animation.cpp.o
bin/animation: CMakeFiles/animation.dir/build.make
bin/animation: /usr/local/lib/libpython3.9.a
bin/animation: CMakeFiles/animation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/support/Desktop/okienko_wykres/matplotlib-cpp-master/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/animation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/animation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/animation.dir/build: bin/animation
.PHONY : CMakeFiles/animation.dir/build

CMakeFiles/animation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/animation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/animation.dir/clean

CMakeFiles/animation.dir/depend:
	cd /home/support/Desktop/okienko_wykres/matplotlib-cpp-master/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/support/Desktop/okienko_wykres/matplotlib-cpp-master /home/support/Desktop/okienko_wykres/matplotlib-cpp-master /home/support/Desktop/okienko_wykres/matplotlib-cpp-master/build /home/support/Desktop/okienko_wykres/matplotlib-cpp-master/build /home/support/Desktop/okienko_wykres/matplotlib-cpp-master/build/CMakeFiles/animation.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/animation.dir/depend

