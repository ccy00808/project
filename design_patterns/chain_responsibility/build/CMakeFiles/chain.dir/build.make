# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /opt/cmake-3.17.2-Linux-x86_64/bin/cmake

# The command to remove a file.
RM = /opt/cmake-3.17.2-Linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ccy00808/design_patterns/chain_responsibility

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ccy00808/design_patterns/chain_responsibility/build

# Include any dependencies generated for this target.
include CMakeFiles/chain.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/chain.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/chain.dir/flags.make

CMakeFiles/chain.dir/main.cpp.o: CMakeFiles/chain.dir/flags.make
CMakeFiles/chain.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ccy00808/design_patterns/chain_responsibility/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/chain.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/chain.dir/main.cpp.o -c /home/ccy00808/design_patterns/chain_responsibility/main.cpp

CMakeFiles/chain.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/chain.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ccy00808/design_patterns/chain_responsibility/main.cpp > CMakeFiles/chain.dir/main.cpp.i

CMakeFiles/chain.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/chain.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ccy00808/design_patterns/chain_responsibility/main.cpp -o CMakeFiles/chain.dir/main.cpp.s

# Object files for target chain
chain_OBJECTS = \
"CMakeFiles/chain.dir/main.cpp.o"

# External object files for target chain
chain_EXTERNAL_OBJECTS =

chain: CMakeFiles/chain.dir/main.cpp.o
chain: CMakeFiles/chain.dir/build.make
chain: src/libhandler.a
chain: CMakeFiles/chain.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ccy00808/design_patterns/chain_responsibility/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable chain"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/chain.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/chain.dir/build: chain

.PHONY : CMakeFiles/chain.dir/build

CMakeFiles/chain.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/chain.dir/cmake_clean.cmake
.PHONY : CMakeFiles/chain.dir/clean

CMakeFiles/chain.dir/depend:
	cd /home/ccy00808/design_patterns/chain_responsibility/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ccy00808/design_patterns/chain_responsibility /home/ccy00808/design_patterns/chain_responsibility /home/ccy00808/design_patterns/chain_responsibility/build /home/ccy00808/design_patterns/chain_responsibility/build /home/ccy00808/design_patterns/chain_responsibility/build/CMakeFiles/chain.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/chain.dir/depend

