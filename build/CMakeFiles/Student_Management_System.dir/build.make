# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = E:\cmake-3.26.0-rc1-windows-x86_64\cmake-3.26.0-rc1-windows-x86_64\bin\cmake.exe

# The command to remove a file.
RM = E:\cmake-3.26.0-rc1-windows-x86_64\cmake-3.26.0-rc1-windows-x86_64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = G:\c_cpp_projectfile\cpp_project\practise\chapter_07_SMS

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = G:\c_cpp_projectfile\build

# Include any dependencies generated for this target.
include CMakeFiles/Student_Management_System.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Student_Management_System.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Student_Management_System.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Student_Management_System.dir/flags.make

CMakeFiles/Student_Management_System.dir/main.cpp.obj: CMakeFiles/Student_Management_System.dir/flags.make
CMakeFiles/Student_Management_System.dir/main.cpp.obj: G:/c_cpp_projectfile/cpp_project/practise/chapter_07_SMS/main.cpp
CMakeFiles/Student_Management_System.dir/main.cpp.obj: CMakeFiles/Student_Management_System.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\c_cpp_projectfile\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Student_Management_System.dir/main.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Student_Management_System.dir/main.cpp.obj -MF CMakeFiles\Student_Management_System.dir\main.cpp.obj.d -o CMakeFiles\Student_Management_System.dir\main.cpp.obj -c G:\c_cpp_projectfile\cpp_project\practise\chapter_07_SMS\main.cpp

CMakeFiles/Student_Management_System.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Student_Management_System.dir/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\c_cpp_projectfile\cpp_project\practise\chapter_07_SMS\main.cpp > CMakeFiles\Student_Management_System.dir\main.cpp.i

CMakeFiles/Student_Management_System.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Student_Management_System.dir/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\c_cpp_projectfile\cpp_project\practise\chapter_07_SMS\main.cpp -o CMakeFiles\Student_Management_System.dir\main.cpp.s

CMakeFiles/Student_Management_System.dir/function.cpp.obj: CMakeFiles/Student_Management_System.dir/flags.make
CMakeFiles/Student_Management_System.dir/function.cpp.obj: G:/c_cpp_projectfile/cpp_project/practise/chapter_07_SMS/function.cpp
CMakeFiles/Student_Management_System.dir/function.cpp.obj: CMakeFiles/Student_Management_System.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\c_cpp_projectfile\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Student_Management_System.dir/function.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Student_Management_System.dir/function.cpp.obj -MF CMakeFiles\Student_Management_System.dir\function.cpp.obj.d -o CMakeFiles\Student_Management_System.dir\function.cpp.obj -c G:\c_cpp_projectfile\cpp_project\practise\chapter_07_SMS\function.cpp

CMakeFiles/Student_Management_System.dir/function.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Student_Management_System.dir/function.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\c_cpp_projectfile\cpp_project\practise\chapter_07_SMS\function.cpp > CMakeFiles\Student_Management_System.dir\function.cpp.i

CMakeFiles/Student_Management_System.dir/function.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Student_Management_System.dir/function.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\c_cpp_projectfile\cpp_project\practise\chapter_07_SMS\function.cpp -o CMakeFiles\Student_Management_System.dir\function.cpp.s

CMakeFiles/Student_Management_System.dir/student.cpp.obj: CMakeFiles/Student_Management_System.dir/flags.make
CMakeFiles/Student_Management_System.dir/student.cpp.obj: G:/c_cpp_projectfile/cpp_project/practise/chapter_07_SMS/student.cpp
CMakeFiles/Student_Management_System.dir/student.cpp.obj: CMakeFiles/Student_Management_System.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=G:\c_cpp_projectfile\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Student_Management_System.dir/student.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Student_Management_System.dir/student.cpp.obj -MF CMakeFiles\Student_Management_System.dir\student.cpp.obj.d -o CMakeFiles\Student_Management_System.dir\student.cpp.obj -c G:\c_cpp_projectfile\cpp_project\practise\chapter_07_SMS\student.cpp

CMakeFiles/Student_Management_System.dir/student.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Student_Management_System.dir/student.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E G:\c_cpp_projectfile\cpp_project\practise\chapter_07_SMS\student.cpp > CMakeFiles\Student_Management_System.dir\student.cpp.i

CMakeFiles/Student_Management_System.dir/student.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Student_Management_System.dir/student.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S G:\c_cpp_projectfile\cpp_project\practise\chapter_07_SMS\student.cpp -o CMakeFiles\Student_Management_System.dir\student.cpp.s

# Object files for target Student_Management_System
Student_Management_System_OBJECTS = \
"CMakeFiles/Student_Management_System.dir/main.cpp.obj" \
"CMakeFiles/Student_Management_System.dir/function.cpp.obj" \
"CMakeFiles/Student_Management_System.dir/student.cpp.obj"

# External object files for target Student_Management_System
Student_Management_System_EXTERNAL_OBJECTS =

Student_Management_System.exe: CMakeFiles/Student_Management_System.dir/main.cpp.obj
Student_Management_System.exe: CMakeFiles/Student_Management_System.dir/function.cpp.obj
Student_Management_System.exe: CMakeFiles/Student_Management_System.dir/student.cpp.obj
Student_Management_System.exe: CMakeFiles/Student_Management_System.dir/build.make
Student_Management_System.exe: CMakeFiles/Student_Management_System.dir/linkLibs.rsp
Student_Management_System.exe: CMakeFiles/Student_Management_System.dir/objects1.rsp
Student_Management_System.exe: CMakeFiles/Student_Management_System.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=G:\c_cpp_projectfile\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Student_Management_System.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Student_Management_System.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Student_Management_System.dir/build: Student_Management_System.exe
.PHONY : CMakeFiles/Student_Management_System.dir/build

CMakeFiles/Student_Management_System.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Student_Management_System.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Student_Management_System.dir/clean

CMakeFiles/Student_Management_System.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" G:\c_cpp_projectfile\cpp_project\practise\chapter_07_SMS G:\c_cpp_projectfile\cpp_project\practise\chapter_07_SMS G:\c_cpp_projectfile\build G:\c_cpp_projectfile\build G:\c_cpp_projectfile\build\CMakeFiles\Student_Management_System.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Student_Management_System.dir/depend

