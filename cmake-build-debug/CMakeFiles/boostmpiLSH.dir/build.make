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
CMAKE_COMMAND = /home/peter/clion-2016.3.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/peter/clion-2016.3.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/peter/FYP/FastLSH

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/peter/FYP/FastLSH/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/boostmpiLSH.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/boostmpiLSH.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/boostmpiLSH.dir/flags.make

CMakeFiles/boostmpiLSH.dir/src/clusterCompute/boostmpiCompute.cpp.o: CMakeFiles/boostmpiLSH.dir/flags.make
CMakeFiles/boostmpiLSH.dir/src/clusterCompute/boostmpiCompute.cpp.o: ../src/clusterCompute/boostmpiCompute.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/peter/FYP/FastLSH/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/boostmpiLSH.dir/src/clusterCompute/boostmpiCompute.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/boostmpiLSH.dir/src/clusterCompute/boostmpiCompute.cpp.o -c /home/peter/FYP/FastLSH/src/clusterCompute/boostmpiCompute.cpp

CMakeFiles/boostmpiLSH.dir/src/clusterCompute/boostmpiCompute.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boostmpiLSH.dir/src/clusterCompute/boostmpiCompute.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/peter/FYP/FastLSH/src/clusterCompute/boostmpiCompute.cpp > CMakeFiles/boostmpiLSH.dir/src/clusterCompute/boostmpiCompute.cpp.i

CMakeFiles/boostmpiLSH.dir/src/clusterCompute/boostmpiCompute.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boostmpiLSH.dir/src/clusterCompute/boostmpiCompute.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/peter/FYP/FastLSH/src/clusterCompute/boostmpiCompute.cpp -o CMakeFiles/boostmpiLSH.dir/src/clusterCompute/boostmpiCompute.cpp.s

CMakeFiles/boostmpiLSH.dir/src/clusterCompute/boostmpiCompute.cpp.o.requires:

.PHONY : CMakeFiles/boostmpiLSH.dir/src/clusterCompute/boostmpiCompute.cpp.o.requires

CMakeFiles/boostmpiLSH.dir/src/clusterCompute/boostmpiCompute.cpp.o.provides: CMakeFiles/boostmpiLSH.dir/src/clusterCompute/boostmpiCompute.cpp.o.requires
	$(MAKE) -f CMakeFiles/boostmpiLSH.dir/build.make CMakeFiles/boostmpiLSH.dir/src/clusterCompute/boostmpiCompute.cpp.o.provides.build
.PHONY : CMakeFiles/boostmpiLSH.dir/src/clusterCompute/boostmpiCompute.cpp.o.provides

CMakeFiles/boostmpiLSH.dir/src/clusterCompute/boostmpiCompute.cpp.o.provides.build: CMakeFiles/boostmpiLSH.dir/src/clusterCompute/boostmpiCompute.cpp.o


# Object files for target boostmpiLSH
boostmpiLSH_OBJECTS = \
"CMakeFiles/boostmpiLSH.dir/src/clusterCompute/boostmpiCompute.cpp.o"

# External object files for target boostmpiLSH
boostmpiLSH_EXTERNAL_OBJECTS =

boostmpiLSH: CMakeFiles/boostmpiLSH.dir/src/clusterCompute/boostmpiCompute.cpp.o
boostmpiLSH: CMakeFiles/boostmpiLSH.dir/build.make
boostmpiLSH: /usr/lib/x86_64-linux-gnu/libboost_system.so
boostmpiLSH: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
boostmpiLSH: /usr/lib/x86_64-linux-gnu/libboost_mpi.so
boostmpiLSH: /usr/lib/x86_64-linux-gnu/libboost_serialization.so
boostmpiLSH: /usr/lib/openmpi/lib/libmpi_cxx.so
boostmpiLSH: /usr/lib/openmpi/lib/libmpi.so
boostmpiLSH: CMakeFiles/boostmpiLSH.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/peter/FYP/FastLSH/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable boostmpiLSH"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/boostmpiLSH.dir/link.txt --verbose=$(VERBOSE)
	/usr/bin/mpiexec -np 4 boostmpiLSH

# Rule to build all files generated by this target.
CMakeFiles/boostmpiLSH.dir/build: boostmpiLSH

.PHONY : CMakeFiles/boostmpiLSH.dir/build

CMakeFiles/boostmpiLSH.dir/requires: CMakeFiles/boostmpiLSH.dir/src/clusterCompute/boostmpiCompute.cpp.o.requires

.PHONY : CMakeFiles/boostmpiLSH.dir/requires

CMakeFiles/boostmpiLSH.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/boostmpiLSH.dir/cmake_clean.cmake
.PHONY : CMakeFiles/boostmpiLSH.dir/clean

CMakeFiles/boostmpiLSH.dir/depend:
	cd /home/peter/FYP/FastLSH/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/peter/FYP/FastLSH /home/peter/FYP/FastLSH /home/peter/FYP/FastLSH/cmake-build-debug /home/peter/FYP/FastLSH/cmake-build-debug /home/peter/FYP/FastLSH/cmake-build-debug/CMakeFiles/boostmpiLSH.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/boostmpiLSH.dir/depend

