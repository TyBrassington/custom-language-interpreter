# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.31

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
CMAKE_SOURCE_DIR = "C:\Users\Ty\Documents\Custom Language Interpreter"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\Ty\Documents\Custom Language Interpreter\build"

# Include any dependencies generated for this target.
include CMakeFiles/Custom_Language_Interpreter.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Custom_Language_Interpreter.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Custom_Language_Interpreter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Custom_Language_Interpreter.dir/flags.make

CMakeFiles/Custom_Language_Interpreter.dir/codegen:
.PHONY : CMakeFiles/Custom_Language_Interpreter.dir/codegen

CMakeFiles/Custom_Language_Interpreter.dir/src/lexer.cpp.obj: CMakeFiles/Custom_Language_Interpreter.dir/flags.make
CMakeFiles/Custom_Language_Interpreter.dir/src/lexer.cpp.obj: CMakeFiles/Custom_Language_Interpreter.dir/includes_CXX.rsp
CMakeFiles/Custom_Language_Interpreter.dir/src/lexer.cpp.obj: C:/Users/Ty/Documents/Custom\ Language\ Interpreter/src/lexer.cpp
CMakeFiles/Custom_Language_Interpreter.dir/src/lexer.cpp.obj: CMakeFiles/Custom_Language_Interpreter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\Ty\Documents\Custom Language Interpreter\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Custom_Language_Interpreter.dir/src/lexer.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Custom_Language_Interpreter.dir/src/lexer.cpp.obj -MF CMakeFiles\Custom_Language_Interpreter.dir\src\lexer.cpp.obj.d -o CMakeFiles\Custom_Language_Interpreter.dir\src\lexer.cpp.obj -c "C:\Users\Ty\Documents\Custom Language Interpreter\src\lexer.cpp"

CMakeFiles/Custom_Language_Interpreter.dir/src/lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Custom_Language_Interpreter.dir/src/lexer.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Ty\Documents\Custom Language Interpreter\src\lexer.cpp" > CMakeFiles\Custom_Language_Interpreter.dir\src\lexer.cpp.i

CMakeFiles/Custom_Language_Interpreter.dir/src/lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Custom_Language_Interpreter.dir/src/lexer.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Ty\Documents\Custom Language Interpreter\src\lexer.cpp" -o CMakeFiles\Custom_Language_Interpreter.dir\src\lexer.cpp.s

CMakeFiles/Custom_Language_Interpreter.dir/src/main.cpp.obj: CMakeFiles/Custom_Language_Interpreter.dir/flags.make
CMakeFiles/Custom_Language_Interpreter.dir/src/main.cpp.obj: CMakeFiles/Custom_Language_Interpreter.dir/includes_CXX.rsp
CMakeFiles/Custom_Language_Interpreter.dir/src/main.cpp.obj: C:/Users/Ty/Documents/Custom\ Language\ Interpreter/src/main.cpp
CMakeFiles/Custom_Language_Interpreter.dir/src/main.cpp.obj: CMakeFiles/Custom_Language_Interpreter.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="C:\Users\Ty\Documents\Custom Language Interpreter\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Custom_Language_Interpreter.dir/src/main.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Custom_Language_Interpreter.dir/src/main.cpp.obj -MF CMakeFiles\Custom_Language_Interpreter.dir\src\main.cpp.obj.d -o CMakeFiles\Custom_Language_Interpreter.dir\src\main.cpp.obj -c "C:\Users\Ty\Documents\Custom Language Interpreter\src\main.cpp"

CMakeFiles/Custom_Language_Interpreter.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/Custom_Language_Interpreter.dir/src/main.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\Ty\Documents\Custom Language Interpreter\src\main.cpp" > CMakeFiles\Custom_Language_Interpreter.dir\src\main.cpp.i

CMakeFiles/Custom_Language_Interpreter.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/Custom_Language_Interpreter.dir/src/main.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\Ty\Documents\Custom Language Interpreter\src\main.cpp" -o CMakeFiles\Custom_Language_Interpreter.dir\src\main.cpp.s

# Object files for target Custom_Language_Interpreter
Custom_Language_Interpreter_OBJECTS = \
"CMakeFiles/Custom_Language_Interpreter.dir/src/lexer.cpp.obj" \
"CMakeFiles/Custom_Language_Interpreter.dir/src/main.cpp.obj"

# External object files for target Custom_Language_Interpreter
Custom_Language_Interpreter_EXTERNAL_OBJECTS =

Custom_Language_Interpreter.exe: CMakeFiles/Custom_Language_Interpreter.dir/src/lexer.cpp.obj
Custom_Language_Interpreter.exe: CMakeFiles/Custom_Language_Interpreter.dir/src/main.cpp.obj
Custom_Language_Interpreter.exe: CMakeFiles/Custom_Language_Interpreter.dir/build.make
Custom_Language_Interpreter.exe: CMakeFiles/Custom_Language_Interpreter.dir/linkLibs.rsp
Custom_Language_Interpreter.exe: CMakeFiles/Custom_Language_Interpreter.dir/objects1.rsp
Custom_Language_Interpreter.exe: CMakeFiles/Custom_Language_Interpreter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="C:\Users\Ty\Documents\Custom Language Interpreter\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Custom_Language_Interpreter.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Custom_Language_Interpreter.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Custom_Language_Interpreter.dir/build: Custom_Language_Interpreter.exe
.PHONY : CMakeFiles/Custom_Language_Interpreter.dir/build

CMakeFiles/Custom_Language_Interpreter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Custom_Language_Interpreter.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Custom_Language_Interpreter.dir/clean

CMakeFiles/Custom_Language_Interpreter.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\Ty\Documents\Custom Language Interpreter" "C:\Users\Ty\Documents\Custom Language Interpreter" "C:\Users\Ty\Documents\Custom Language Interpreter\build" "C:\Users\Ty\Documents\Custom Language Interpreter\build" "C:\Users\Ty\Documents\Custom Language Interpreter\build\CMakeFiles\Custom_Language_Interpreter.dir\DependInfo.cmake" "--color=$(COLOR)"
.PHONY : CMakeFiles/Custom_Language_Interpreter.dir/depend

