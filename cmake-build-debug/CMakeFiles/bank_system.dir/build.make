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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.1.3\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.1.3\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Projects\bank_system

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Projects\bank_system\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/bank_system.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/bank_system.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/bank_system.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bank_system.dir/flags.make

CMakeFiles/bank_system.dir/main.cpp.obj: CMakeFiles/bank_system.dir/flags.make
CMakeFiles/bank_system.dir/main.cpp.obj: D:/Projects/bank_system/main.cpp
CMakeFiles/bank_system.dir/main.cpp.obj: CMakeFiles/bank_system.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projects\bank_system\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/bank_system.dir/main.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/bank_system.dir/main.cpp.obj -MF CMakeFiles\bank_system.dir\main.cpp.obj.d -o CMakeFiles\bank_system.dir\main.cpp.obj -c D:\Projects\bank_system\main.cpp

CMakeFiles/bank_system.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bank_system.dir/main.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Projects\bank_system\main.cpp > CMakeFiles\bank_system.dir\main.cpp.i

CMakeFiles/bank_system.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bank_system.dir/main.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Projects\bank_system\main.cpp -o CMakeFiles\bank_system.dir\main.cpp.s

CMakeFiles/bank_system.dir/model/Person.cpp.obj: CMakeFiles/bank_system.dir/flags.make
CMakeFiles/bank_system.dir/model/Person.cpp.obj: D:/Projects/bank_system/model/Person.cpp
CMakeFiles/bank_system.dir/model/Person.cpp.obj: CMakeFiles/bank_system.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projects\bank_system\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/bank_system.dir/model/Person.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/bank_system.dir/model/Person.cpp.obj -MF CMakeFiles\bank_system.dir\model\Person.cpp.obj.d -o CMakeFiles\bank_system.dir\model\Person.cpp.obj -c D:\Projects\bank_system\model\Person.cpp

CMakeFiles/bank_system.dir/model/Person.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bank_system.dir/model/Person.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Projects\bank_system\model\Person.cpp > CMakeFiles\bank_system.dir\model\Person.cpp.i

CMakeFiles/bank_system.dir/model/Person.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bank_system.dir/model/Person.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Projects\bank_system\model\Person.cpp -o CMakeFiles\bank_system.dir\model\Person.cpp.s

CMakeFiles/bank_system.dir/model/Client.cpp.obj: CMakeFiles/bank_system.dir/flags.make
CMakeFiles/bank_system.dir/model/Client.cpp.obj: D:/Projects/bank_system/model/Client.cpp
CMakeFiles/bank_system.dir/model/Client.cpp.obj: CMakeFiles/bank_system.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projects\bank_system\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/bank_system.dir/model/Client.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/bank_system.dir/model/Client.cpp.obj -MF CMakeFiles\bank_system.dir\model\Client.cpp.obj.d -o CMakeFiles\bank_system.dir\model\Client.cpp.obj -c D:\Projects\bank_system\model\Client.cpp

CMakeFiles/bank_system.dir/model/Client.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bank_system.dir/model/Client.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Projects\bank_system\model\Client.cpp > CMakeFiles\bank_system.dir\model\Client.cpp.i

CMakeFiles/bank_system.dir/model/Client.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bank_system.dir/model/Client.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Projects\bank_system\model\Client.cpp -o CMakeFiles\bank_system.dir\model\Client.cpp.s

CMakeFiles/bank_system.dir/model/Employee.cpp.obj: CMakeFiles/bank_system.dir/flags.make
CMakeFiles/bank_system.dir/model/Employee.cpp.obj: D:/Projects/bank_system/model/Employee.cpp
CMakeFiles/bank_system.dir/model/Employee.cpp.obj: CMakeFiles/bank_system.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projects\bank_system\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/bank_system.dir/model/Employee.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/bank_system.dir/model/Employee.cpp.obj -MF CMakeFiles\bank_system.dir\model\Employee.cpp.obj.d -o CMakeFiles\bank_system.dir\model\Employee.cpp.obj -c D:\Projects\bank_system\model\Employee.cpp

CMakeFiles/bank_system.dir/model/Employee.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bank_system.dir/model/Employee.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Projects\bank_system\model\Employee.cpp > CMakeFiles\bank_system.dir\model\Employee.cpp.i

CMakeFiles/bank_system.dir/model/Employee.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bank_system.dir/model/Employee.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Projects\bank_system\model\Employee.cpp -o CMakeFiles\bank_system.dir\model\Employee.cpp.s

CMakeFiles/bank_system.dir/model/Admin.cpp.obj: CMakeFiles/bank_system.dir/flags.make
CMakeFiles/bank_system.dir/model/Admin.cpp.obj: D:/Projects/bank_system/model/Admin.cpp
CMakeFiles/bank_system.dir/model/Admin.cpp.obj: CMakeFiles/bank_system.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projects\bank_system\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/bank_system.dir/model/Admin.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/bank_system.dir/model/Admin.cpp.obj -MF CMakeFiles\bank_system.dir\model\Admin.cpp.obj.d -o CMakeFiles\bank_system.dir\model\Admin.cpp.obj -c D:\Projects\bank_system\model\Admin.cpp

CMakeFiles/bank_system.dir/model/Admin.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bank_system.dir/model/Admin.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Projects\bank_system\model\Admin.cpp > CMakeFiles\bank_system.dir\model\Admin.cpp.i

CMakeFiles/bank_system.dir/model/Admin.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bank_system.dir/model/Admin.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Projects\bank_system\model\Admin.cpp -o CMakeFiles\bank_system.dir\model\Admin.cpp.s

CMakeFiles/bank_system.dir/manger/ClientManger.cpp.obj: CMakeFiles/bank_system.dir/flags.make
CMakeFiles/bank_system.dir/manger/ClientManger.cpp.obj: D:/Projects/bank_system/manger/ClientManger.cpp
CMakeFiles/bank_system.dir/manger/ClientManger.cpp.obj: CMakeFiles/bank_system.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projects\bank_system\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/bank_system.dir/manger/ClientManger.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/bank_system.dir/manger/ClientManger.cpp.obj -MF CMakeFiles\bank_system.dir\manger\ClientManger.cpp.obj.d -o CMakeFiles\bank_system.dir\manger\ClientManger.cpp.obj -c D:\Projects\bank_system\manger\ClientManger.cpp

CMakeFiles/bank_system.dir/manger/ClientManger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bank_system.dir/manger/ClientManger.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Projects\bank_system\manger\ClientManger.cpp > CMakeFiles\bank_system.dir\manger\ClientManger.cpp.i

CMakeFiles/bank_system.dir/manger/ClientManger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bank_system.dir/manger/ClientManger.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Projects\bank_system\manger\ClientManger.cpp -o CMakeFiles\bank_system.dir\manger\ClientManger.cpp.s

CMakeFiles/bank_system.dir/Helper.cpp.obj: CMakeFiles/bank_system.dir/flags.make
CMakeFiles/bank_system.dir/Helper.cpp.obj: D:/Projects/bank_system/Helper.cpp
CMakeFiles/bank_system.dir/Helper.cpp.obj: CMakeFiles/bank_system.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Projects\bank_system\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/bank_system.dir/Helper.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/bank_system.dir/Helper.cpp.obj -MF CMakeFiles\bank_system.dir\Helper.cpp.obj.d -o CMakeFiles\bank_system.dir\Helper.cpp.obj -c D:\Projects\bank_system\Helper.cpp

CMakeFiles/bank_system.dir/Helper.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/bank_system.dir/Helper.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Projects\bank_system\Helper.cpp > CMakeFiles\bank_system.dir\Helper.cpp.i

CMakeFiles/bank_system.dir/Helper.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/bank_system.dir/Helper.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Projects\bank_system\Helper.cpp -o CMakeFiles\bank_system.dir\Helper.cpp.s

# Object files for target bank_system
bank_system_OBJECTS = \
"CMakeFiles/bank_system.dir/main.cpp.obj" \
"CMakeFiles/bank_system.dir/model/Person.cpp.obj" \
"CMakeFiles/bank_system.dir/model/Client.cpp.obj" \
"CMakeFiles/bank_system.dir/model/Employee.cpp.obj" \
"CMakeFiles/bank_system.dir/model/Admin.cpp.obj" \
"CMakeFiles/bank_system.dir/manger/ClientManger.cpp.obj" \
"CMakeFiles/bank_system.dir/Helper.cpp.obj"

# External object files for target bank_system
bank_system_EXTERNAL_OBJECTS =

bank_system.exe: CMakeFiles/bank_system.dir/main.cpp.obj
bank_system.exe: CMakeFiles/bank_system.dir/model/Person.cpp.obj
bank_system.exe: CMakeFiles/bank_system.dir/model/Client.cpp.obj
bank_system.exe: CMakeFiles/bank_system.dir/model/Employee.cpp.obj
bank_system.exe: CMakeFiles/bank_system.dir/model/Admin.cpp.obj
bank_system.exe: CMakeFiles/bank_system.dir/manger/ClientManger.cpp.obj
bank_system.exe: CMakeFiles/bank_system.dir/Helper.cpp.obj
bank_system.exe: CMakeFiles/bank_system.dir/build.make
bank_system.exe: CMakeFiles/bank_system.dir/linkLibs.rsp
bank_system.exe: CMakeFiles/bank_system.dir/objects1.rsp
bank_system.exe: CMakeFiles/bank_system.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Projects\bank_system\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable bank_system.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\bank_system.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bank_system.dir/build: bank_system.exe
.PHONY : CMakeFiles/bank_system.dir/build

CMakeFiles/bank_system.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\bank_system.dir\cmake_clean.cmake
.PHONY : CMakeFiles/bank_system.dir/clean

CMakeFiles/bank_system.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Projects\bank_system D:\Projects\bank_system D:\Projects\bank_system\cmake-build-debug D:\Projects\bank_system\cmake-build-debug D:\Projects\bank_system\cmake-build-debug\CMakeFiles\bank_system.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/bank_system.dir/depend

