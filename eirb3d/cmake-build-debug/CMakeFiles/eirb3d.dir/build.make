# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2017.1.1\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2017.1.1\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Anthony\Documents\Cours\Inge\S8\EN212\EN212\eirb3d

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Anthony\Documents\Cours\Inge\S8\EN212\EN212\eirb3d\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/eirb3d.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/eirb3d.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/eirb3d.dir/flags.make

CMakeFiles/eirb3d.dir/src/geometry.c.obj: CMakeFiles/eirb3d.dir/flags.make
CMakeFiles/eirb3d.dir/src/geometry.c.obj: CMakeFiles/eirb3d.dir/includes_C.rsp
CMakeFiles/eirb3d.dir/src/geometry.c.obj: ../src/geometry.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Anthony\Documents\Cours\Inge\S8\EN212\EN212\eirb3d\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/eirb3d.dir/src/geometry.c.obj"
	C:\MinGw\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\eirb3d.dir\src\geometry.c.obj   -c C:\Users\Anthony\Documents\Cours\Inge\S8\EN212\EN212\eirb3d\src\geometry.c

CMakeFiles/eirb3d.dir/src/geometry.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/eirb3d.dir/src/geometry.c.i"
	C:\MinGw\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Anthony\Documents\Cours\Inge\S8\EN212\EN212\eirb3d\src\geometry.c > CMakeFiles\eirb3d.dir\src\geometry.c.i

CMakeFiles/eirb3d.dir/src/geometry.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/eirb3d.dir/src/geometry.c.s"
	C:\MinGw\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Anthony\Documents\Cours\Inge\S8\EN212\EN212\eirb3d\src\geometry.c -o CMakeFiles\eirb3d.dir\src\geometry.c.s

CMakeFiles/eirb3d.dir/src/geometry.c.obj.requires:

.PHONY : CMakeFiles/eirb3d.dir/src/geometry.c.obj.requires

CMakeFiles/eirb3d.dir/src/geometry.c.obj.provides: CMakeFiles/eirb3d.dir/src/geometry.c.obj.requires
	$(MAKE) -f CMakeFiles\eirb3d.dir\build.make CMakeFiles/eirb3d.dir/src/geometry.c.obj.provides.build
.PHONY : CMakeFiles/eirb3d.dir/src/geometry.c.obj.provides

CMakeFiles/eirb3d.dir/src/geometry.c.obj.provides.build: CMakeFiles/eirb3d.dir/src/geometry.c.obj


CMakeFiles/eirb3d.dir/src/events.c.obj: CMakeFiles/eirb3d.dir/flags.make
CMakeFiles/eirb3d.dir/src/events.c.obj: CMakeFiles/eirb3d.dir/includes_C.rsp
CMakeFiles/eirb3d.dir/src/events.c.obj: ../src/events.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Anthony\Documents\Cours\Inge\S8\EN212\EN212\eirb3d\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/eirb3d.dir/src/events.c.obj"
	C:\MinGw\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\eirb3d.dir\src\events.c.obj   -c C:\Users\Anthony\Documents\Cours\Inge\S8\EN212\EN212\eirb3d\src\events.c

CMakeFiles/eirb3d.dir/src/events.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/eirb3d.dir/src/events.c.i"
	C:\MinGw\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Anthony\Documents\Cours\Inge\S8\EN212\EN212\eirb3d\src\events.c > CMakeFiles\eirb3d.dir\src\events.c.i

CMakeFiles/eirb3d.dir/src/events.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/eirb3d.dir/src/events.c.s"
	C:\MinGw\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Anthony\Documents\Cours\Inge\S8\EN212\EN212\eirb3d\src\events.c -o CMakeFiles\eirb3d.dir\src\events.c.s

CMakeFiles/eirb3d.dir/src/events.c.obj.requires:

.PHONY : CMakeFiles/eirb3d.dir/src/events.c.obj.requires

CMakeFiles/eirb3d.dir/src/events.c.obj.provides: CMakeFiles/eirb3d.dir/src/events.c.obj.requires
	$(MAKE) -f CMakeFiles\eirb3d.dir\build.make CMakeFiles/eirb3d.dir/src/events.c.obj.provides.build
.PHONY : CMakeFiles/eirb3d.dir/src/events.c.obj.provides

CMakeFiles/eirb3d.dir/src/events.c.obj.provides.build: CMakeFiles/eirb3d.dir/src/events.c.obj


CMakeFiles/eirb3d.dir/src/model.c.obj: CMakeFiles/eirb3d.dir/flags.make
CMakeFiles/eirb3d.dir/src/model.c.obj: CMakeFiles/eirb3d.dir/includes_C.rsp
CMakeFiles/eirb3d.dir/src/model.c.obj: ../src/model.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Anthony\Documents\Cours\Inge\S8\EN212\EN212\eirb3d\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/eirb3d.dir/src/model.c.obj"
	C:\MinGw\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\eirb3d.dir\src\model.c.obj   -c C:\Users\Anthony\Documents\Cours\Inge\S8\EN212\EN212\eirb3d\src\model.c

CMakeFiles/eirb3d.dir/src/model.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/eirb3d.dir/src/model.c.i"
	C:\MinGw\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Anthony\Documents\Cours\Inge\S8\EN212\EN212\eirb3d\src\model.c > CMakeFiles\eirb3d.dir\src\model.c.i

CMakeFiles/eirb3d.dir/src/model.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/eirb3d.dir/src/model.c.s"
	C:\MinGw\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Anthony\Documents\Cours\Inge\S8\EN212\EN212\eirb3d\src\model.c -o CMakeFiles\eirb3d.dir\src\model.c.s

CMakeFiles/eirb3d.dir/src/model.c.obj.requires:

.PHONY : CMakeFiles/eirb3d.dir/src/model.c.obj.requires

CMakeFiles/eirb3d.dir/src/model.c.obj.provides: CMakeFiles/eirb3d.dir/src/model.c.obj.requires
	$(MAKE) -f CMakeFiles\eirb3d.dir\build.make CMakeFiles/eirb3d.dir/src/model.c.obj.provides.build
.PHONY : CMakeFiles/eirb3d.dir/src/model.c.obj.provides

CMakeFiles/eirb3d.dir/src/model.c.obj.provides.build: CMakeFiles/eirb3d.dir/src/model.c.obj


CMakeFiles/eirb3d.dir/src/vector.c.obj: CMakeFiles/eirb3d.dir/flags.make
CMakeFiles/eirb3d.dir/src/vector.c.obj: CMakeFiles/eirb3d.dir/includes_C.rsp
CMakeFiles/eirb3d.dir/src/vector.c.obj: ../src/vector.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Anthony\Documents\Cours\Inge\S8\EN212\EN212\eirb3d\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/eirb3d.dir/src/vector.c.obj"
	C:\MinGw\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\eirb3d.dir\src\vector.c.obj   -c C:\Users\Anthony\Documents\Cours\Inge\S8\EN212\EN212\eirb3d\src\vector.c

CMakeFiles/eirb3d.dir/src/vector.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/eirb3d.dir/src/vector.c.i"
	C:\MinGw\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Anthony\Documents\Cours\Inge\S8\EN212\EN212\eirb3d\src\vector.c > CMakeFiles\eirb3d.dir\src\vector.c.i

CMakeFiles/eirb3d.dir/src/vector.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/eirb3d.dir/src/vector.c.s"
	C:\MinGw\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Anthony\Documents\Cours\Inge\S8\EN212\EN212\eirb3d\src\vector.c -o CMakeFiles\eirb3d.dir\src\vector.c.s

CMakeFiles/eirb3d.dir/src/vector.c.obj.requires:

.PHONY : CMakeFiles/eirb3d.dir/src/vector.c.obj.requires

CMakeFiles/eirb3d.dir/src/vector.c.obj.provides: CMakeFiles/eirb3d.dir/src/vector.c.obj.requires
	$(MAKE) -f CMakeFiles\eirb3d.dir\build.make CMakeFiles/eirb3d.dir/src/vector.c.obj.provides.build
.PHONY : CMakeFiles/eirb3d.dir/src/vector.c.obj.provides

CMakeFiles/eirb3d.dir/src/vector.c.obj.provides.build: CMakeFiles/eirb3d.dir/src/vector.c.obj


CMakeFiles/eirb3d.dir/src/window.c.obj: CMakeFiles/eirb3d.dir/flags.make
CMakeFiles/eirb3d.dir/src/window.c.obj: CMakeFiles/eirb3d.dir/includes_C.rsp
CMakeFiles/eirb3d.dir/src/window.c.obj: ../src/window.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Anthony\Documents\Cours\Inge\S8\EN212\EN212\eirb3d\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/eirb3d.dir/src/window.c.obj"
	C:\MinGw\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\eirb3d.dir\src\window.c.obj   -c C:\Users\Anthony\Documents\Cours\Inge\S8\EN212\EN212\eirb3d\src\window.c

CMakeFiles/eirb3d.dir/src/window.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/eirb3d.dir/src/window.c.i"
	C:\MinGw\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Anthony\Documents\Cours\Inge\S8\EN212\EN212\eirb3d\src\window.c > CMakeFiles\eirb3d.dir\src\window.c.i

CMakeFiles/eirb3d.dir/src/window.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/eirb3d.dir/src/window.c.s"
	C:\MinGw\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Anthony\Documents\Cours\Inge\S8\EN212\EN212\eirb3d\src\window.c -o CMakeFiles\eirb3d.dir\src\window.c.s

CMakeFiles/eirb3d.dir/src/window.c.obj.requires:

.PHONY : CMakeFiles/eirb3d.dir/src/window.c.obj.requires

CMakeFiles/eirb3d.dir/src/window.c.obj.provides: CMakeFiles/eirb3d.dir/src/window.c.obj.requires
	$(MAKE) -f CMakeFiles\eirb3d.dir\build.make CMakeFiles/eirb3d.dir/src/window.c.obj.provides.build
.PHONY : CMakeFiles/eirb3d.dir/src/window.c.obj.provides

CMakeFiles/eirb3d.dir/src/window.c.obj.provides.build: CMakeFiles/eirb3d.dir/src/window.c.obj


CMakeFiles/eirb3d.dir/src/main.c.obj: CMakeFiles/eirb3d.dir/flags.make
CMakeFiles/eirb3d.dir/src/main.c.obj: CMakeFiles/eirb3d.dir/includes_C.rsp
CMakeFiles/eirb3d.dir/src/main.c.obj: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Anthony\Documents\Cours\Inge\S8\EN212\EN212\eirb3d\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/eirb3d.dir/src/main.c.obj"
	C:\MinGw\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\eirb3d.dir\src\main.c.obj   -c C:\Users\Anthony\Documents\Cours\Inge\S8\EN212\EN212\eirb3d\src\main.c

CMakeFiles/eirb3d.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/eirb3d.dir/src/main.c.i"
	C:\MinGw\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Anthony\Documents\Cours\Inge\S8\EN212\EN212\eirb3d\src\main.c > CMakeFiles\eirb3d.dir\src\main.c.i

CMakeFiles/eirb3d.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/eirb3d.dir/src/main.c.s"
	C:\MinGw\bin\gcc.exe  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Anthony\Documents\Cours\Inge\S8\EN212\EN212\eirb3d\src\main.c -o CMakeFiles\eirb3d.dir\src\main.c.s

CMakeFiles/eirb3d.dir/src/main.c.obj.requires:

.PHONY : CMakeFiles/eirb3d.dir/src/main.c.obj.requires

CMakeFiles/eirb3d.dir/src/main.c.obj.provides: CMakeFiles/eirb3d.dir/src/main.c.obj.requires
	$(MAKE) -f CMakeFiles\eirb3d.dir\build.make CMakeFiles/eirb3d.dir/src/main.c.obj.provides.build
.PHONY : CMakeFiles/eirb3d.dir/src/main.c.obj.provides

CMakeFiles/eirb3d.dir/src/main.c.obj.provides.build: CMakeFiles/eirb3d.dir/src/main.c.obj


# Object files for target eirb3d
eirb3d_OBJECTS = \
"CMakeFiles/eirb3d.dir/src/geometry.c.obj" \
"CMakeFiles/eirb3d.dir/src/events.c.obj" \
"CMakeFiles/eirb3d.dir/src/model.c.obj" \
"CMakeFiles/eirb3d.dir/src/vector.c.obj" \
"CMakeFiles/eirb3d.dir/src/window.c.obj" \
"CMakeFiles/eirb3d.dir/src/main.c.obj"

# External object files for target eirb3d
eirb3d_EXTERNAL_OBJECTS =

eirb3d.exe: CMakeFiles/eirb3d.dir/src/geometry.c.obj
eirb3d.exe: CMakeFiles/eirb3d.dir/src/events.c.obj
eirb3d.exe: CMakeFiles/eirb3d.dir/src/model.c.obj
eirb3d.exe: CMakeFiles/eirb3d.dir/src/vector.c.obj
eirb3d.exe: CMakeFiles/eirb3d.dir/src/window.c.obj
eirb3d.exe: CMakeFiles/eirb3d.dir/src/main.c.obj
eirb3d.exe: CMakeFiles/eirb3d.dir/build.make
eirb3d.exe: CMakeFiles/eirb3d.dir/linklibs.rsp
eirb3d.exe: CMakeFiles/eirb3d.dir/objects1.rsp
eirb3d.exe: CMakeFiles/eirb3d.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Anthony\Documents\Cours\Inge\S8\EN212\EN212\eirb3d\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable eirb3d.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\eirb3d.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/eirb3d.dir/build: eirb3d.exe

.PHONY : CMakeFiles/eirb3d.dir/build

CMakeFiles/eirb3d.dir/requires: CMakeFiles/eirb3d.dir/src/geometry.c.obj.requires
CMakeFiles/eirb3d.dir/requires: CMakeFiles/eirb3d.dir/src/events.c.obj.requires
CMakeFiles/eirb3d.dir/requires: CMakeFiles/eirb3d.dir/src/model.c.obj.requires
CMakeFiles/eirb3d.dir/requires: CMakeFiles/eirb3d.dir/src/vector.c.obj.requires
CMakeFiles/eirb3d.dir/requires: CMakeFiles/eirb3d.dir/src/window.c.obj.requires
CMakeFiles/eirb3d.dir/requires: CMakeFiles/eirb3d.dir/src/main.c.obj.requires

.PHONY : CMakeFiles/eirb3d.dir/requires

CMakeFiles/eirb3d.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\eirb3d.dir\cmake_clean.cmake
.PHONY : CMakeFiles/eirb3d.dir/clean

CMakeFiles/eirb3d.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Anthony\Documents\Cours\Inge\S8\EN212\EN212\eirb3d C:\Users\Anthony\Documents\Cours\Inge\S8\EN212\EN212\eirb3d C:\Users\Anthony\Documents\Cours\Inge\S8\EN212\EN212\eirb3d\cmake-build-debug C:\Users\Anthony\Documents\Cours\Inge\S8\EN212\EN212\eirb3d\cmake-build-debug C:\Users\Anthony\Documents\Cours\Inge\S8\EN212\EN212\eirb3d\cmake-build-debug\CMakeFiles\eirb3d.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/eirb3d.dir/depend
