# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "E:\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "E:\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "P:\visual studio\CourseProjects\CourseProject9"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "P:\visual studio\CourseProjects\CourseProject9\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/CourseProject9.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/CourseProject9.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CourseProject9.dir/flags.make

CMakeFiles/CourseProject9.dir/main.cpp.obj: CMakeFiles/CourseProject9.dir/flags.make
CMakeFiles/CourseProject9.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="P:\visual studio\CourseProjects\CourseProject9\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CourseProject9.dir/main.cpp.obj"
	E:\compilers\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\CourseProject9.dir\main.cpp.obj -c "P:\visual studio\CourseProjects\CourseProject9\main.cpp"

CMakeFiles/CourseProject9.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CourseProject9.dir/main.cpp.i"
	E:\compilers\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "P:\visual studio\CourseProjects\CourseProject9\main.cpp" > CMakeFiles\CourseProject9.dir\main.cpp.i

CMakeFiles/CourseProject9.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CourseProject9.dir/main.cpp.s"
	E:\compilers\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "P:\visual studio\CourseProjects\CourseProject9\main.cpp" -o CMakeFiles\CourseProject9.dir\main.cpp.s

# Object files for target CourseProject9
CourseProject9_OBJECTS = \
"CMakeFiles/CourseProject9.dir/main.cpp.obj"

# External object files for target CourseProject9
CourseProject9_EXTERNAL_OBJECTS =

CourseProject9.exe: CMakeFiles/CourseProject9.dir/main.cpp.obj
CourseProject9.exe: CMakeFiles/CourseProject9.dir/build.make
CourseProject9.exe: CMakeFiles/CourseProject9.dir/linklibs.rsp
CourseProject9.exe: CMakeFiles/CourseProject9.dir/objects1.rsp
CourseProject9.exe: CMakeFiles/CourseProject9.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="P:\visual studio\CourseProjects\CourseProject9\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable CourseProject9.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\CourseProject9.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CourseProject9.dir/build: CourseProject9.exe
.PHONY : CMakeFiles/CourseProject9.dir/build

CMakeFiles/CourseProject9.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\CourseProject9.dir\cmake_clean.cmake
.PHONY : CMakeFiles/CourseProject9.dir/clean

CMakeFiles/CourseProject9.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "P:\visual studio\CourseProjects\CourseProject9" "P:\visual studio\CourseProjects\CourseProject9" "P:\visual studio\CourseProjects\CourseProject9\cmake-build-debug" "P:\visual studio\CourseProjects\CourseProject9\cmake-build-debug" "P:\visual studio\CourseProjects\CourseProject9\cmake-build-debug\CMakeFiles\CourseProject9.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/CourseProject9.dir/depend
