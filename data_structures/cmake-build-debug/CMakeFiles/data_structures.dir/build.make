# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /home/kamil/Software/clion-2017.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/kamil/Software/clion-2017.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kamil/Documents/repositories/pamsi/data_structures

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kamil/Documents/repositories/pamsi/data_structures/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/data_structures.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/data_structures.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/data_structures.dir/flags.make

CMakeFiles/data_structures.dir/main.cpp.o: CMakeFiles/data_structures.dir/flags.make
CMakeFiles/data_structures.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kamil/Documents/repositories/pamsi/data_structures/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/data_structures.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/data_structures.dir/main.cpp.o -c /home/kamil/Documents/repositories/pamsi/data_structures/main.cpp

CMakeFiles/data_structures.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/data_structures.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kamil/Documents/repositories/pamsi/data_structures/main.cpp > CMakeFiles/data_structures.dir/main.cpp.i

CMakeFiles/data_structures.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/data_structures.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kamil/Documents/repositories/pamsi/data_structures/main.cpp -o CMakeFiles/data_structures.dir/main.cpp.s

CMakeFiles/data_structures.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/data_structures.dir/main.cpp.o.requires

CMakeFiles/data_structures.dir/main.cpp.o.provides: CMakeFiles/data_structures.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/data_structures.dir/build.make CMakeFiles/data_structures.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/data_structures.dir/main.cpp.o.provides

CMakeFiles/data_structures.dir/main.cpp.o.provides.build: CMakeFiles/data_structures.dir/main.cpp.o


# Object files for target data_structures
data_structures_OBJECTS = \
"CMakeFiles/data_structures.dir/main.cpp.o"

# External object files for target data_structures
data_structures_EXTERNAL_OBJECTS =

data_structures: CMakeFiles/data_structures.dir/main.cpp.o
data_structures: CMakeFiles/data_structures.dir/build.make
data_structures: CMakeFiles/data_structures.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kamil/Documents/repositories/pamsi/data_structures/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable data_structures"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/data_structures.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/data_structures.dir/build: data_structures

.PHONY : CMakeFiles/data_structures.dir/build

CMakeFiles/data_structures.dir/requires: CMakeFiles/data_structures.dir/main.cpp.o.requires

.PHONY : CMakeFiles/data_structures.dir/requires

CMakeFiles/data_structures.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/data_structures.dir/cmake_clean.cmake
.PHONY : CMakeFiles/data_structures.dir/clean

CMakeFiles/data_structures.dir/depend:
	cd /home/kamil/Documents/repositories/pamsi/data_structures/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kamil/Documents/repositories/pamsi/data_structures /home/kamil/Documents/repositories/pamsi/data_structures /home/kamil/Documents/repositories/pamsi/data_structures/cmake-build-debug /home/kamil/Documents/repositories/pamsi/data_structures/cmake-build-debug /home/kamil/Documents/repositories/pamsi/data_structures/cmake-build-debug/CMakeFiles/data_structures.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/data_structures.dir/depend

