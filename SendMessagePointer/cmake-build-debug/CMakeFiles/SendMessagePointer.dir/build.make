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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/diegovidal/CLionProjects/rev/SendMessagePointer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/diegovidal/CLionProjects/rev/SendMessagePointer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SendMessagePointer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SendMessagePointer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SendMessagePointer.dir/flags.make

CMakeFiles/SendMessagePointer.dir/main.c.o: CMakeFiles/SendMessagePointer.dir/flags.make
CMakeFiles/SendMessagePointer.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/diegovidal/CLionProjects/rev/SendMessagePointer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/SendMessagePointer.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SendMessagePointer.dir/main.c.o   -c /Users/diegovidal/CLionProjects/rev/SendMessagePointer/main.c

CMakeFiles/SendMessagePointer.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SendMessagePointer.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/diegovidal/CLionProjects/rev/SendMessagePointer/main.c > CMakeFiles/SendMessagePointer.dir/main.c.i

CMakeFiles/SendMessagePointer.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SendMessagePointer.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/diegovidal/CLionProjects/rev/SendMessagePointer/main.c -o CMakeFiles/SendMessagePointer.dir/main.c.s

CMakeFiles/SendMessagePointer.dir/main.c.o.requires:

.PHONY : CMakeFiles/SendMessagePointer.dir/main.c.o.requires

CMakeFiles/SendMessagePointer.dir/main.c.o.provides: CMakeFiles/SendMessagePointer.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/SendMessagePointer.dir/build.make CMakeFiles/SendMessagePointer.dir/main.c.o.provides.build
.PHONY : CMakeFiles/SendMessagePointer.dir/main.c.o.provides

CMakeFiles/SendMessagePointer.dir/main.c.o.provides.build: CMakeFiles/SendMessagePointer.dir/main.c.o


# Object files for target SendMessagePointer
SendMessagePointer_OBJECTS = \
"CMakeFiles/SendMessagePointer.dir/main.c.o"

# External object files for target SendMessagePointer
SendMessagePointer_EXTERNAL_OBJECTS =

SendMessagePointer: CMakeFiles/SendMessagePointer.dir/main.c.o
SendMessagePointer: CMakeFiles/SendMessagePointer.dir/build.make
SendMessagePointer: CMakeFiles/SendMessagePointer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/diegovidal/CLionProjects/rev/SendMessagePointer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable SendMessagePointer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SendMessagePointer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SendMessagePointer.dir/build: SendMessagePointer

.PHONY : CMakeFiles/SendMessagePointer.dir/build

CMakeFiles/SendMessagePointer.dir/requires: CMakeFiles/SendMessagePointer.dir/main.c.o.requires

.PHONY : CMakeFiles/SendMessagePointer.dir/requires

CMakeFiles/SendMessagePointer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SendMessagePointer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SendMessagePointer.dir/clean

CMakeFiles/SendMessagePointer.dir/depend:
	cd /Users/diegovidal/CLionProjects/rev/SendMessagePointer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/diegovidal/CLionProjects/rev/SendMessagePointer /Users/diegovidal/CLionProjects/rev/SendMessagePointer /Users/diegovidal/CLionProjects/rev/SendMessagePointer/cmake-build-debug /Users/diegovidal/CLionProjects/rev/SendMessagePointer/cmake-build-debug /Users/diegovidal/CLionProjects/rev/SendMessagePointer/cmake-build-debug/CMakeFiles/SendMessagePointer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SendMessagePointer.dir/depend
