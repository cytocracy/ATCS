# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Theo\Development\ATCS\Quadratic

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Theo\Development\ATCS\Quadratic\build

# Include any dependencies generated for this target.
include CMakeFiles/Quadratic.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Quadratic.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Quadratic.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Quadratic.dir/flags.make

CMakeFiles/Quadratic.dir/main.cpp.obj: CMakeFiles/Quadratic.dir/flags.make
CMakeFiles/Quadratic.dir/main.cpp.obj: C:/Theo/Development/ATCS/Quadratic/main.cpp
CMakeFiles/Quadratic.dir/main.cpp.obj: CMakeFiles/Quadratic.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Theo\Development\ATCS\Quadratic\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Quadratic.dir/main.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Quadratic.dir/main.cpp.obj -MF CMakeFiles\Quadratic.dir\main.cpp.obj.d -o CMakeFiles\Quadratic.dir\main.cpp.obj -c C:\Theo\Development\ATCS\Quadratic\main.cpp

CMakeFiles/Quadratic.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Quadratic.dir/main.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Theo\Development\ATCS\Quadratic\main.cpp > CMakeFiles\Quadratic.dir\main.cpp.i

CMakeFiles/Quadratic.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Quadratic.dir/main.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Theo\Development\ATCS\Quadratic\main.cpp -o CMakeFiles\Quadratic.dir\main.cpp.s

# Object files for target Quadratic
Quadratic_OBJECTS = \
"CMakeFiles/Quadratic.dir/main.cpp.obj"

# External object files for target Quadratic
Quadratic_EXTERNAL_OBJECTS =

Quadratic.exe: CMakeFiles/Quadratic.dir/main.cpp.obj
Quadratic.exe: CMakeFiles/Quadratic.dir/build.make
Quadratic.exe: CMakeFiles/Quadratic.dir/linklibs.rsp
Quadratic.exe: CMakeFiles/Quadratic.dir/objects1.rsp
Quadratic.exe: CMakeFiles/Quadratic.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Theo\Development\ATCS\Quadratic\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Quadratic.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Quadratic.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Quadratic.dir/build: Quadratic.exe
.PHONY : CMakeFiles/Quadratic.dir/build

CMakeFiles/Quadratic.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Quadratic.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Quadratic.dir/clean

CMakeFiles/Quadratic.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Theo\Development\ATCS\Quadratic C:\Theo\Development\ATCS\Quadratic C:\Theo\Development\ATCS\Quadratic\build C:\Theo\Development\ATCS\Quadratic\build C:\Theo\Development\ATCS\Quadratic\build\CMakeFiles\Quadratic.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Quadratic.dir/depend

