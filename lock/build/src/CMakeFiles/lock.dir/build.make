# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ccy00808/project/lock

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ccy00808/project/lock/build

# Include any dependencies generated for this target.
include src/CMakeFiles/lock.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/lock.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/lock.dir/flags.make

src/CMakeFiles/lock.dir/rwlock.cpp.o: src/CMakeFiles/lock.dir/flags.make
src/CMakeFiles/lock.dir/rwlock.cpp.o: ../src/rwlock.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ccy00808/project/lock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/lock.dir/rwlock.cpp.o"
	cd /home/ccy00808/project/lock/build/src && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lock.dir/rwlock.cpp.o -c /home/ccy00808/project/lock/src/rwlock.cpp

src/CMakeFiles/lock.dir/rwlock.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lock.dir/rwlock.cpp.i"
	cd /home/ccy00808/project/lock/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ccy00808/project/lock/src/rwlock.cpp > CMakeFiles/lock.dir/rwlock.cpp.i

src/CMakeFiles/lock.dir/rwlock.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lock.dir/rwlock.cpp.s"
	cd /home/ccy00808/project/lock/build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ccy00808/project/lock/src/rwlock.cpp -o CMakeFiles/lock.dir/rwlock.cpp.s

src/CMakeFiles/lock.dir/rwlock.cpp.o.requires:

.PHONY : src/CMakeFiles/lock.dir/rwlock.cpp.o.requires

src/CMakeFiles/lock.dir/rwlock.cpp.o.provides: src/CMakeFiles/lock.dir/rwlock.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/lock.dir/build.make src/CMakeFiles/lock.dir/rwlock.cpp.o.provides.build
.PHONY : src/CMakeFiles/lock.dir/rwlock.cpp.o.provides

src/CMakeFiles/lock.dir/rwlock.cpp.o.provides.build: src/CMakeFiles/lock.dir/rwlock.cpp.o


# Object files for target lock
lock_OBJECTS = \
"CMakeFiles/lock.dir/rwlock.cpp.o"

# External object files for target lock
lock_EXTERNAL_OBJECTS =

src/liblock.a: src/CMakeFiles/lock.dir/rwlock.cpp.o
src/liblock.a: src/CMakeFiles/lock.dir/build.make
src/liblock.a: src/CMakeFiles/lock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ccy00808/project/lock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liblock.a"
	cd /home/ccy00808/project/lock/build/src && $(CMAKE_COMMAND) -P CMakeFiles/lock.dir/cmake_clean_target.cmake
	cd /home/ccy00808/project/lock/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lock.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/lock.dir/build: src/liblock.a

.PHONY : src/CMakeFiles/lock.dir/build

src/CMakeFiles/lock.dir/requires: src/CMakeFiles/lock.dir/rwlock.cpp.o.requires

.PHONY : src/CMakeFiles/lock.dir/requires

src/CMakeFiles/lock.dir/clean:
	cd /home/ccy00808/project/lock/build/src && $(CMAKE_COMMAND) -P CMakeFiles/lock.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/lock.dir/clean

src/CMakeFiles/lock.dir/depend:
	cd /home/ccy00808/project/lock/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ccy00808/project/lock /home/ccy00808/project/lock/src /home/ccy00808/project/lock/build /home/ccy00808/project/lock/build/src /home/ccy00808/project/lock/build/src/CMakeFiles/lock.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/lock.dir/depend

