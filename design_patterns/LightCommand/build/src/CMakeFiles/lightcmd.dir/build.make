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
CMAKE_SOURCE_DIR = /home/ccy00808/design_patterns/LightCommand

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ccy00808/design_patterns/LightCommand/build

# Include any dependencies generated for this target.
include src/CMakeFiles/lightcmd.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/lightcmd.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/lightcmd.dir/flags.make

src/CMakeFiles/lightcmd.dir/command.cpp.o: src/CMakeFiles/lightcmd.dir/flags.make
src/CMakeFiles/lightcmd.dir/command.cpp.o: ../src/command.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ccy00808/design_patterns/LightCommand/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/lightcmd.dir/command.cpp.o"
	cd /home/ccy00808/design_patterns/LightCommand/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lightcmd.dir/command.cpp.o -c /home/ccy00808/design_patterns/LightCommand/src/command.cpp

src/CMakeFiles/lightcmd.dir/command.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lightcmd.dir/command.cpp.i"
	cd /home/ccy00808/design_patterns/LightCommand/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ccy00808/design_patterns/LightCommand/src/command.cpp > CMakeFiles/lightcmd.dir/command.cpp.i

src/CMakeFiles/lightcmd.dir/command.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lightcmd.dir/command.cpp.s"
	cd /home/ccy00808/design_patterns/LightCommand/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ccy00808/design_patterns/LightCommand/src/command.cpp -o CMakeFiles/lightcmd.dir/command.cpp.s

src/CMakeFiles/lightcmd.dir/invoker.cpp.o: src/CMakeFiles/lightcmd.dir/flags.make
src/CMakeFiles/lightcmd.dir/invoker.cpp.o: ../src/invoker.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ccy00808/design_patterns/LightCommand/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/lightcmd.dir/invoker.cpp.o"
	cd /home/ccy00808/design_patterns/LightCommand/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lightcmd.dir/invoker.cpp.o -c /home/ccy00808/design_patterns/LightCommand/src/invoker.cpp

src/CMakeFiles/lightcmd.dir/invoker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lightcmd.dir/invoker.cpp.i"
	cd /home/ccy00808/design_patterns/LightCommand/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ccy00808/design_patterns/LightCommand/src/invoker.cpp > CMakeFiles/lightcmd.dir/invoker.cpp.i

src/CMakeFiles/lightcmd.dir/invoker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lightcmd.dir/invoker.cpp.s"
	cd /home/ccy00808/design_patterns/LightCommand/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ccy00808/design_patterns/LightCommand/src/invoker.cpp -o CMakeFiles/lightcmd.dir/invoker.cpp.s

src/CMakeFiles/lightcmd.dir/receiver.cpp.o: src/CMakeFiles/lightcmd.dir/flags.make
src/CMakeFiles/lightcmd.dir/receiver.cpp.o: ../src/receiver.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ccy00808/design_patterns/LightCommand/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/lightcmd.dir/receiver.cpp.o"
	cd /home/ccy00808/design_patterns/LightCommand/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lightcmd.dir/receiver.cpp.o -c /home/ccy00808/design_patterns/LightCommand/src/receiver.cpp

src/CMakeFiles/lightcmd.dir/receiver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lightcmd.dir/receiver.cpp.i"
	cd /home/ccy00808/design_patterns/LightCommand/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ccy00808/design_patterns/LightCommand/src/receiver.cpp > CMakeFiles/lightcmd.dir/receiver.cpp.i

src/CMakeFiles/lightcmd.dir/receiver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lightcmd.dir/receiver.cpp.s"
	cd /home/ccy00808/design_patterns/LightCommand/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ccy00808/design_patterns/LightCommand/src/receiver.cpp -o CMakeFiles/lightcmd.dir/receiver.cpp.s

# Object files for target lightcmd
lightcmd_OBJECTS = \
"CMakeFiles/lightcmd.dir/command.cpp.o" \
"CMakeFiles/lightcmd.dir/invoker.cpp.o" \
"CMakeFiles/lightcmd.dir/receiver.cpp.o"

# External object files for target lightcmd
lightcmd_EXTERNAL_OBJECTS =

src/liblightcmd.a: src/CMakeFiles/lightcmd.dir/command.cpp.o
src/liblightcmd.a: src/CMakeFiles/lightcmd.dir/invoker.cpp.o
src/liblightcmd.a: src/CMakeFiles/lightcmd.dir/receiver.cpp.o
src/liblightcmd.a: src/CMakeFiles/lightcmd.dir/build.make
src/liblightcmd.a: src/CMakeFiles/lightcmd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ccy00808/design_patterns/LightCommand/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library liblightcmd.a"
	cd /home/ccy00808/design_patterns/LightCommand/build/src && $(CMAKE_COMMAND) -P CMakeFiles/lightcmd.dir/cmake_clean_target.cmake
	cd /home/ccy00808/design_patterns/LightCommand/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lightcmd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/lightcmd.dir/build: src/liblightcmd.a

.PHONY : src/CMakeFiles/lightcmd.dir/build

src/CMakeFiles/lightcmd.dir/clean:
	cd /home/ccy00808/design_patterns/LightCommand/build/src && $(CMAKE_COMMAND) -P CMakeFiles/lightcmd.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/lightcmd.dir/clean

src/CMakeFiles/lightcmd.dir/depend:
	cd /home/ccy00808/design_patterns/LightCommand/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ccy00808/design_patterns/LightCommand /home/ccy00808/design_patterns/LightCommand/src /home/ccy00808/design_patterns/LightCommand/build /home/ccy00808/design_patterns/LightCommand/build/src /home/ccy00808/design_patterns/LightCommand/build/src/CMakeFiles/lightcmd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/lightcmd.dir/depend
