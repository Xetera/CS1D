# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /home/xetera/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/192.6603.37/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/xetera/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/192.6603.37/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xetera/cs1d/LinkedList

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xetera/cs1d/LinkedList/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/linked_list.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/linked_list.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/linked_list.dir/flags.make

CMakeFiles/linked_list.dir/src/linked_list.cpp.o: CMakeFiles/linked_list.dir/flags.make
CMakeFiles/linked_list.dir/src/linked_list.cpp.o: ../src/linked_list.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xetera/cs1d/LinkedList/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/linked_list.dir/src/linked_list.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/linked_list.dir/src/linked_list.cpp.o -c /home/xetera/cs1d/LinkedList/src/linked_list.cpp

CMakeFiles/linked_list.dir/src/linked_list.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linked_list.dir/src/linked_list.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xetera/cs1d/LinkedList/src/linked_list.cpp > CMakeFiles/linked_list.dir/src/linked_list.cpp.i

CMakeFiles/linked_list.dir/src/linked_list.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linked_list.dir/src/linked_list.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xetera/cs1d/LinkedList/src/linked_list.cpp -o CMakeFiles/linked_list.dir/src/linked_list.cpp.s

CMakeFiles/linked_list.dir/src/main.cpp.o: CMakeFiles/linked_list.dir/flags.make
CMakeFiles/linked_list.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xetera/cs1d/LinkedList/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/linked_list.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/linked_list.dir/src/main.cpp.o -c /home/xetera/cs1d/LinkedList/src/main.cpp

CMakeFiles/linked_list.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/linked_list.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xetera/cs1d/LinkedList/src/main.cpp > CMakeFiles/linked_list.dir/src/main.cpp.i

CMakeFiles/linked_list.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/linked_list.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xetera/cs1d/LinkedList/src/main.cpp -o CMakeFiles/linked_list.dir/src/main.cpp.s

# Object files for target linked_list
linked_list_OBJECTS = \
"CMakeFiles/linked_list.dir/src/linked_list.cpp.o" \
"CMakeFiles/linked_list.dir/src/main.cpp.o"

# External object files for target linked_list
linked_list_EXTERNAL_OBJECTS =

linked_list: CMakeFiles/linked_list.dir/src/linked_list.cpp.o
linked_list: CMakeFiles/linked_list.dir/src/main.cpp.o
linked_list: CMakeFiles/linked_list.dir/build.make
linked_list: CMakeFiles/linked_list.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xetera/cs1d/LinkedList/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable linked_list"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/linked_list.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/linked_list.dir/build: linked_list

.PHONY : CMakeFiles/linked_list.dir/build

CMakeFiles/linked_list.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/linked_list.dir/cmake_clean.cmake
.PHONY : CMakeFiles/linked_list.dir/clean

CMakeFiles/linked_list.dir/depend:
	cd /home/xetera/cs1d/LinkedList/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xetera/cs1d/LinkedList /home/xetera/cs1d/LinkedList /home/xetera/cs1d/LinkedList/cmake-build-debug /home/xetera/cs1d/LinkedList/cmake-build-debug /home/xetera/cs1d/LinkedList/cmake-build-debug/CMakeFiles/linked_list.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/linked_list.dir/depend

