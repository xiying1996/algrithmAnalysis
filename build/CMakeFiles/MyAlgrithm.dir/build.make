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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/wgx/project/algrithm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/wgx/project/algrithm/build

# Include any dependencies generated for this target.
include CMakeFiles/MyAlgrithm.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MyAlgrithm.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MyAlgrithm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MyAlgrithm.dir/flags.make

CMakeFiles/MyAlgrithm.dir/src/singleton.cpp.o: CMakeFiles/MyAlgrithm.dir/flags.make
CMakeFiles/MyAlgrithm.dir/src/singleton.cpp.o: /Users/wgx/project/algrithm/src/singleton.cpp
CMakeFiles/MyAlgrithm.dir/src/singleton.cpp.o: CMakeFiles/MyAlgrithm.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/wgx/project/algrithm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MyAlgrithm.dir/src/singleton.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MyAlgrithm.dir/src/singleton.cpp.o -MF CMakeFiles/MyAlgrithm.dir/src/singleton.cpp.o.d -o CMakeFiles/MyAlgrithm.dir/src/singleton.cpp.o -c /Users/wgx/project/algrithm/src/singleton.cpp

CMakeFiles/MyAlgrithm.dir/src/singleton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/MyAlgrithm.dir/src/singleton.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wgx/project/algrithm/src/singleton.cpp > CMakeFiles/MyAlgrithm.dir/src/singleton.cpp.i

CMakeFiles/MyAlgrithm.dir/src/singleton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/MyAlgrithm.dir/src/singleton.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wgx/project/algrithm/src/singleton.cpp -o CMakeFiles/MyAlgrithm.dir/src/singleton.cpp.s

# Object files for target MyAlgrithm
MyAlgrithm_OBJECTS = \
"CMakeFiles/MyAlgrithm.dir/src/singleton.cpp.o"

# External object files for target MyAlgrithm
MyAlgrithm_EXTERNAL_OBJECTS =

MyAlgrithm: CMakeFiles/MyAlgrithm.dir/src/singleton.cpp.o
MyAlgrithm: CMakeFiles/MyAlgrithm.dir/build.make
MyAlgrithm: CMakeFiles/MyAlgrithm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/wgx/project/algrithm/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MyAlgrithm"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyAlgrithm.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MyAlgrithm.dir/build: MyAlgrithm
.PHONY : CMakeFiles/MyAlgrithm.dir/build

CMakeFiles/MyAlgrithm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MyAlgrithm.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MyAlgrithm.dir/clean

CMakeFiles/MyAlgrithm.dir/depend:
	cd /Users/wgx/project/algrithm/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wgx/project/algrithm /Users/wgx/project/algrithm /Users/wgx/project/algrithm/build /Users/wgx/project/algrithm/build /Users/wgx/project/algrithm/build/CMakeFiles/MyAlgrithm.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/MyAlgrithm.dir/depend

