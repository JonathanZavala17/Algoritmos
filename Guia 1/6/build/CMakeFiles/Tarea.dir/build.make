# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_SOURCE_DIR = "/home/rooster17/AlgoritmosEjercicios/Algoritmos Tarea/6"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/rooster17/AlgoritmosEjercicios/Algoritmos Tarea/6/build"

# Include any dependencies generated for this target.
include CMakeFiles/Tarea.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Tarea.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Tarea.dir/flags.make

CMakeFiles/Tarea.dir/E6.cpp.o: CMakeFiles/Tarea.dir/flags.make
CMakeFiles/Tarea.dir/E6.cpp.o: ../E6.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/rooster17/AlgoritmosEjercicios/Algoritmos Tarea/6/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Tarea.dir/E6.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Tarea.dir/E6.cpp.o -c "/home/rooster17/AlgoritmosEjercicios/Algoritmos Tarea/6/E6.cpp"

CMakeFiles/Tarea.dir/E6.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Tarea.dir/E6.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/rooster17/AlgoritmosEjercicios/Algoritmos Tarea/6/E6.cpp" > CMakeFiles/Tarea.dir/E6.cpp.i

CMakeFiles/Tarea.dir/E6.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Tarea.dir/E6.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/rooster17/AlgoritmosEjercicios/Algoritmos Tarea/6/E6.cpp" -o CMakeFiles/Tarea.dir/E6.cpp.s

CMakeFiles/Tarea.dir/E6.cpp.o.requires:

.PHONY : CMakeFiles/Tarea.dir/E6.cpp.o.requires

CMakeFiles/Tarea.dir/E6.cpp.o.provides: CMakeFiles/Tarea.dir/E6.cpp.o.requires
	$(MAKE) -f CMakeFiles/Tarea.dir/build.make CMakeFiles/Tarea.dir/E6.cpp.o.provides.build
.PHONY : CMakeFiles/Tarea.dir/E6.cpp.o.provides

CMakeFiles/Tarea.dir/E6.cpp.o.provides.build: CMakeFiles/Tarea.dir/E6.cpp.o


# Object files for target Tarea
Tarea_OBJECTS = \
"CMakeFiles/Tarea.dir/E6.cpp.o"

# External object files for target Tarea
Tarea_EXTERNAL_OBJECTS =

Tarea: CMakeFiles/Tarea.dir/E6.cpp.o
Tarea: CMakeFiles/Tarea.dir/build.make
Tarea: /usr/lib/x86_64-linux-gnu/libGLU.so
Tarea: /usr/lib/x86_64-linux-gnu/libGL.so
Tarea: /usr/lib/x86_64-linux-gnu/libglut.so
Tarea: /usr/lib/x86_64-linux-gnu/libXmu.so
Tarea: /usr/lib/x86_64-linux-gnu/libXi.so
Tarea: CMakeFiles/Tarea.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/rooster17/AlgoritmosEjercicios/Algoritmos Tarea/6/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Tarea"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Tarea.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Tarea.dir/build: Tarea

.PHONY : CMakeFiles/Tarea.dir/build

CMakeFiles/Tarea.dir/requires: CMakeFiles/Tarea.dir/E6.cpp.o.requires

.PHONY : CMakeFiles/Tarea.dir/requires

CMakeFiles/Tarea.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Tarea.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Tarea.dir/clean

CMakeFiles/Tarea.dir/depend:
	cd "/home/rooster17/AlgoritmosEjercicios/Algoritmos Tarea/6/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/rooster17/AlgoritmosEjercicios/Algoritmos Tarea/6" "/home/rooster17/AlgoritmosEjercicios/Algoritmos Tarea/6" "/home/rooster17/AlgoritmosEjercicios/Algoritmos Tarea/6/build" "/home/rooster17/AlgoritmosEjercicios/Algoritmos Tarea/6/build" "/home/rooster17/AlgoritmosEjercicios/Algoritmos Tarea/6/build/CMakeFiles/Tarea.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Tarea.dir/depend

