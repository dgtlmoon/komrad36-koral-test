# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /tmp/KORAL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/KORAL/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ORB_LATCH_K2NN.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ORB_LATCH_K2NN.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ORB_LATCH_K2NN.dir/flags.make

CMakeFiles/ORB_LATCH_K2NN.dir/main.cpp.o: CMakeFiles/ORB_LATCH_K2NN.dir/flags.make
CMakeFiles/ORB_LATCH_K2NN.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/KORAL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ORB_LATCH_K2NN.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ORB_LATCH_K2NN.dir/main.cpp.o -c /tmp/KORAL/main.cpp

CMakeFiles/ORB_LATCH_K2NN.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ORB_LATCH_K2NN.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /tmp/KORAL/main.cpp > CMakeFiles/ORB_LATCH_K2NN.dir/main.cpp.i

CMakeFiles/ORB_LATCH_K2NN.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ORB_LATCH_K2NN.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /tmp/KORAL/main.cpp -o CMakeFiles/ORB_LATCH_K2NN.dir/main.cpp.s

CMakeFiles/ORB_LATCH_K2NN.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/ORB_LATCH_K2NN.dir/main.cpp.o.requires

CMakeFiles/ORB_LATCH_K2NN.dir/main.cpp.o.provides: CMakeFiles/ORB_LATCH_K2NN.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/ORB_LATCH_K2NN.dir/build.make CMakeFiles/ORB_LATCH_K2NN.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/ORB_LATCH_K2NN.dir/main.cpp.o.provides

CMakeFiles/ORB_LATCH_K2NN.dir/main.cpp.o.provides.build: CMakeFiles/ORB_LATCH_K2NN.dir/main.cpp.o


# Object files for target ORB_LATCH_K2NN
ORB_LATCH_K2NN_OBJECTS = \
"CMakeFiles/ORB_LATCH_K2NN.dir/main.cpp.o"

# External object files for target ORB_LATCH_K2NN
ORB_LATCH_K2NN_EXTERNAL_OBJECTS =

ORB_LATCH_K2NN: CMakeFiles/ORB_LATCH_K2NN.dir/main.cpp.o
ORB_LATCH_K2NN: CMakeFiles/ORB_LATCH_K2NN.dir/build.make
ORB_LATCH_K2NN: CMakeFiles/ORB_LATCH_K2NN.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/KORAL/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ORB_LATCH_K2NN"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ORB_LATCH_K2NN.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ORB_LATCH_K2NN.dir/build: ORB_LATCH_K2NN

.PHONY : CMakeFiles/ORB_LATCH_K2NN.dir/build

CMakeFiles/ORB_LATCH_K2NN.dir/requires: CMakeFiles/ORB_LATCH_K2NN.dir/main.cpp.o.requires

.PHONY : CMakeFiles/ORB_LATCH_K2NN.dir/requires

CMakeFiles/ORB_LATCH_K2NN.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ORB_LATCH_K2NN.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ORB_LATCH_K2NN.dir/clean

CMakeFiles/ORB_LATCH_K2NN.dir/depend:
	cd /tmp/KORAL/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/KORAL /tmp/KORAL /tmp/KORAL/cmake-build-debug /tmp/KORAL/cmake-build-debug /tmp/KORAL/cmake-build-debug/CMakeFiles/ORB_LATCH_K2NN.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ORB_LATCH_K2NN.dir/depend

