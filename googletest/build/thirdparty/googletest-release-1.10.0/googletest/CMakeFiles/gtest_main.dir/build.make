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
CMAKE_SOURCE_DIR = /home/ccy00808/project/googletest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ccy00808/project/googletest/build

# Include any dependencies generated for this target.
include thirdparty/googletest-release-1.10.0/googletest/CMakeFiles/gtest_main.dir/depend.make

# Include the progress variables for this target.
include thirdparty/googletest-release-1.10.0/googletest/CMakeFiles/gtest_main.dir/progress.make

# Include the compile flags for this target's objects.
include thirdparty/googletest-release-1.10.0/googletest/CMakeFiles/gtest_main.dir/flags.make

thirdparty/googletest-release-1.10.0/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: thirdparty/googletest-release-1.10.0/googletest/CMakeFiles/gtest_main.dir/flags.make
thirdparty/googletest-release-1.10.0/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o: ../thirdparty/googletest-release-1.10.0/googletest/src/gtest_main.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/ccy00808/project/googletest/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object thirdparty/googletest-release-1.10.0/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"
	cd /home/ccy00808/project/googletest/build/thirdparty/googletest-release-1.10.0/googletest && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.o -c /home/ccy00808/project/googletest/thirdparty/googletest-release-1.10.0/googletest/src/gtest_main.cc

thirdparty/googletest-release-1.10.0/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gtest_main.dir/src/gtest_main.cc.i"
	cd /home/ccy00808/project/googletest/build/thirdparty/googletest-release-1.10.0/googletest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/ccy00808/project/googletest/thirdparty/googletest-release-1.10.0/googletest/src/gtest_main.cc > CMakeFiles/gtest_main.dir/src/gtest_main.cc.i

thirdparty/googletest-release-1.10.0/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gtest_main.dir/src/gtest_main.cc.s"
	cd /home/ccy00808/project/googletest/build/thirdparty/googletest-release-1.10.0/googletest && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/ccy00808/project/googletest/thirdparty/googletest-release-1.10.0/googletest/src/gtest_main.cc -o CMakeFiles/gtest_main.dir/src/gtest_main.cc.s

thirdparty/googletest-release-1.10.0/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires:
.PHONY : thirdparty/googletest-release-1.10.0/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires

thirdparty/googletest-release-1.10.0/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides: thirdparty/googletest-release-1.10.0/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires
	$(MAKE) -f thirdparty/googletest-release-1.10.0/googletest/CMakeFiles/gtest_main.dir/build.make thirdparty/googletest-release-1.10.0/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides.build
.PHONY : thirdparty/googletest-release-1.10.0/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides

thirdparty/googletest-release-1.10.0/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.provides.build: thirdparty/googletest-release-1.10.0/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o

# Object files for target gtest_main
gtest_main_OBJECTS = \
"CMakeFiles/gtest_main.dir/src/gtest_main.cc.o"

# External object files for target gtest_main
gtest_main_EXTERNAL_OBJECTS =

lib/libgtest_main.a: thirdparty/googletest-release-1.10.0/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o
lib/libgtest_main.a: thirdparty/googletest-release-1.10.0/googletest/CMakeFiles/gtest_main.dir/build.make
lib/libgtest_main.a: thirdparty/googletest-release-1.10.0/googletest/CMakeFiles/gtest_main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library ../../../lib/libgtest_main.a"
	cd /home/ccy00808/project/googletest/build/thirdparty/googletest-release-1.10.0/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean_target.cmake
	cd /home/ccy00808/project/googletest/build/thirdparty/googletest-release-1.10.0/googletest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gtest_main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
thirdparty/googletest-release-1.10.0/googletest/CMakeFiles/gtest_main.dir/build: lib/libgtest_main.a
.PHONY : thirdparty/googletest-release-1.10.0/googletest/CMakeFiles/gtest_main.dir/build

thirdparty/googletest-release-1.10.0/googletest/CMakeFiles/gtest_main.dir/requires: thirdparty/googletest-release-1.10.0/googletest/CMakeFiles/gtest_main.dir/src/gtest_main.cc.o.requires
.PHONY : thirdparty/googletest-release-1.10.0/googletest/CMakeFiles/gtest_main.dir/requires

thirdparty/googletest-release-1.10.0/googletest/CMakeFiles/gtest_main.dir/clean:
	cd /home/ccy00808/project/googletest/build/thirdparty/googletest-release-1.10.0/googletest && $(CMAKE_COMMAND) -P CMakeFiles/gtest_main.dir/cmake_clean.cmake
.PHONY : thirdparty/googletest-release-1.10.0/googletest/CMakeFiles/gtest_main.dir/clean

thirdparty/googletest-release-1.10.0/googletest/CMakeFiles/gtest_main.dir/depend:
	cd /home/ccy00808/project/googletest/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ccy00808/project/googletest /home/ccy00808/project/googletest/thirdparty/googletest-release-1.10.0/googletest /home/ccy00808/project/googletest/build /home/ccy00808/project/googletest/build/thirdparty/googletest-release-1.10.0/googletest /home/ccy00808/project/googletest/build/thirdparty/googletest-release-1.10.0/googletest/CMakeFiles/gtest_main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : thirdparty/googletest-release-1.10.0/googletest/CMakeFiles/gtest_main.dir/depend

