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
CMAKE_COMMAND = /Users/jbelless/.brew/Cellar/cmake/3.9.1/bin/cmake

# The command to remove a file.
RM = /Users/jbelless/.brew/Cellar/cmake/3.9.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jbelless/42run

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jbelless/42run

# Include any dependencies generated for this target.
include CMakeFiles/42run.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/42run.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/42run.dir/flags.make

CMakeFiles/42run.dir/src/main.cpp.o: CMakeFiles/42run.dir/flags.make
CMakeFiles/42run.dir/src/main.cpp.o: src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jbelless/42run/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/42run.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/42run.dir/src/main.cpp.o -c /Users/jbelless/42run/src/main.cpp

CMakeFiles/42run.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/42run.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jbelless/42run/src/main.cpp > CMakeFiles/42run.dir/src/main.cpp.i

CMakeFiles/42run.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/42run.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jbelless/42run/src/main.cpp -o CMakeFiles/42run.dir/src/main.cpp.s

CMakeFiles/42run.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/42run.dir/src/main.cpp.o.requires

CMakeFiles/42run.dir/src/main.cpp.o.provides: CMakeFiles/42run.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/42run.dir/build.make CMakeFiles/42run.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/42run.dir/src/main.cpp.o.provides

CMakeFiles/42run.dir/src/main.cpp.o.provides.build: CMakeFiles/42run.dir/src/main.cpp.o


CMakeFiles/42run.dir/Classes/Math/Vec2.class.cpp.o: CMakeFiles/42run.dir/flags.make
CMakeFiles/42run.dir/Classes/Math/Vec2.class.cpp.o: Classes/Math/Vec2.class.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jbelless/42run/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/42run.dir/Classes/Math/Vec2.class.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/42run.dir/Classes/Math/Vec2.class.cpp.o -c /Users/jbelless/42run/Classes/Math/Vec2.class.cpp

CMakeFiles/42run.dir/Classes/Math/Vec2.class.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/42run.dir/Classes/Math/Vec2.class.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jbelless/42run/Classes/Math/Vec2.class.cpp > CMakeFiles/42run.dir/Classes/Math/Vec2.class.cpp.i

CMakeFiles/42run.dir/Classes/Math/Vec2.class.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/42run.dir/Classes/Math/Vec2.class.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jbelless/42run/Classes/Math/Vec2.class.cpp -o CMakeFiles/42run.dir/Classes/Math/Vec2.class.cpp.s

CMakeFiles/42run.dir/Classes/Math/Vec2.class.cpp.o.requires:

.PHONY : CMakeFiles/42run.dir/Classes/Math/Vec2.class.cpp.o.requires

CMakeFiles/42run.dir/Classes/Math/Vec2.class.cpp.o.provides: CMakeFiles/42run.dir/Classes/Math/Vec2.class.cpp.o.requires
	$(MAKE) -f CMakeFiles/42run.dir/build.make CMakeFiles/42run.dir/Classes/Math/Vec2.class.cpp.o.provides.build
.PHONY : CMakeFiles/42run.dir/Classes/Math/Vec2.class.cpp.o.provides

CMakeFiles/42run.dir/Classes/Math/Vec2.class.cpp.o.provides.build: CMakeFiles/42run.dir/Classes/Math/Vec2.class.cpp.o


CMakeFiles/42run.dir/Classes/Math/Vec3.class.cpp.o: CMakeFiles/42run.dir/flags.make
CMakeFiles/42run.dir/Classes/Math/Vec3.class.cpp.o: Classes/Math/Vec3.class.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jbelless/42run/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/42run.dir/Classes/Math/Vec3.class.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/42run.dir/Classes/Math/Vec3.class.cpp.o -c /Users/jbelless/42run/Classes/Math/Vec3.class.cpp

CMakeFiles/42run.dir/Classes/Math/Vec3.class.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/42run.dir/Classes/Math/Vec3.class.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jbelless/42run/Classes/Math/Vec3.class.cpp > CMakeFiles/42run.dir/Classes/Math/Vec3.class.cpp.i

CMakeFiles/42run.dir/Classes/Math/Vec3.class.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/42run.dir/Classes/Math/Vec3.class.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jbelless/42run/Classes/Math/Vec3.class.cpp -o CMakeFiles/42run.dir/Classes/Math/Vec3.class.cpp.s

CMakeFiles/42run.dir/Classes/Math/Vec3.class.cpp.o.requires:

.PHONY : CMakeFiles/42run.dir/Classes/Math/Vec3.class.cpp.o.requires

CMakeFiles/42run.dir/Classes/Math/Vec3.class.cpp.o.provides: CMakeFiles/42run.dir/Classes/Math/Vec3.class.cpp.o.requires
	$(MAKE) -f CMakeFiles/42run.dir/build.make CMakeFiles/42run.dir/Classes/Math/Vec3.class.cpp.o.provides.build
.PHONY : CMakeFiles/42run.dir/Classes/Math/Vec3.class.cpp.o.provides

CMakeFiles/42run.dir/Classes/Math/Vec3.class.cpp.o.provides.build: CMakeFiles/42run.dir/Classes/Math/Vec3.class.cpp.o


CMakeFiles/42run.dir/Classes/Math/Vec4.class.cpp.o: CMakeFiles/42run.dir/flags.make
CMakeFiles/42run.dir/Classes/Math/Vec4.class.cpp.o: Classes/Math/Vec4.class.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jbelless/42run/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/42run.dir/Classes/Math/Vec4.class.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/42run.dir/Classes/Math/Vec4.class.cpp.o -c /Users/jbelless/42run/Classes/Math/Vec4.class.cpp

CMakeFiles/42run.dir/Classes/Math/Vec4.class.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/42run.dir/Classes/Math/Vec4.class.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jbelless/42run/Classes/Math/Vec4.class.cpp > CMakeFiles/42run.dir/Classes/Math/Vec4.class.cpp.i

CMakeFiles/42run.dir/Classes/Math/Vec4.class.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/42run.dir/Classes/Math/Vec4.class.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jbelless/42run/Classes/Math/Vec4.class.cpp -o CMakeFiles/42run.dir/Classes/Math/Vec4.class.cpp.s

CMakeFiles/42run.dir/Classes/Math/Vec4.class.cpp.o.requires:

.PHONY : CMakeFiles/42run.dir/Classes/Math/Vec4.class.cpp.o.requires

CMakeFiles/42run.dir/Classes/Math/Vec4.class.cpp.o.provides: CMakeFiles/42run.dir/Classes/Math/Vec4.class.cpp.o.requires
	$(MAKE) -f CMakeFiles/42run.dir/build.make CMakeFiles/42run.dir/Classes/Math/Vec4.class.cpp.o.provides.build
.PHONY : CMakeFiles/42run.dir/Classes/Math/Vec4.class.cpp.o.provides

CMakeFiles/42run.dir/Classes/Math/Vec4.class.cpp.o.provides.build: CMakeFiles/42run.dir/Classes/Math/Vec4.class.cpp.o


CMakeFiles/42run.dir/Classes/Math/Mat2.class.cpp.o: CMakeFiles/42run.dir/flags.make
CMakeFiles/42run.dir/Classes/Math/Mat2.class.cpp.o: Classes/Math/Mat2.class.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jbelless/42run/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/42run.dir/Classes/Math/Mat2.class.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/42run.dir/Classes/Math/Mat2.class.cpp.o -c /Users/jbelless/42run/Classes/Math/Mat2.class.cpp

CMakeFiles/42run.dir/Classes/Math/Mat2.class.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/42run.dir/Classes/Math/Mat2.class.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jbelless/42run/Classes/Math/Mat2.class.cpp > CMakeFiles/42run.dir/Classes/Math/Mat2.class.cpp.i

CMakeFiles/42run.dir/Classes/Math/Mat2.class.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/42run.dir/Classes/Math/Mat2.class.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jbelless/42run/Classes/Math/Mat2.class.cpp -o CMakeFiles/42run.dir/Classes/Math/Mat2.class.cpp.s

CMakeFiles/42run.dir/Classes/Math/Mat2.class.cpp.o.requires:

.PHONY : CMakeFiles/42run.dir/Classes/Math/Mat2.class.cpp.o.requires

CMakeFiles/42run.dir/Classes/Math/Mat2.class.cpp.o.provides: CMakeFiles/42run.dir/Classes/Math/Mat2.class.cpp.o.requires
	$(MAKE) -f CMakeFiles/42run.dir/build.make CMakeFiles/42run.dir/Classes/Math/Mat2.class.cpp.o.provides.build
.PHONY : CMakeFiles/42run.dir/Classes/Math/Mat2.class.cpp.o.provides

CMakeFiles/42run.dir/Classes/Math/Mat2.class.cpp.o.provides.build: CMakeFiles/42run.dir/Classes/Math/Mat2.class.cpp.o


CMakeFiles/42run.dir/Classes/Math/Mat3.class.cpp.o: CMakeFiles/42run.dir/flags.make
CMakeFiles/42run.dir/Classes/Math/Mat3.class.cpp.o: Classes/Math/Mat3.class.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jbelless/42run/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/42run.dir/Classes/Math/Mat3.class.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/42run.dir/Classes/Math/Mat3.class.cpp.o -c /Users/jbelless/42run/Classes/Math/Mat3.class.cpp

CMakeFiles/42run.dir/Classes/Math/Mat3.class.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/42run.dir/Classes/Math/Mat3.class.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jbelless/42run/Classes/Math/Mat3.class.cpp > CMakeFiles/42run.dir/Classes/Math/Mat3.class.cpp.i

CMakeFiles/42run.dir/Classes/Math/Mat3.class.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/42run.dir/Classes/Math/Mat3.class.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jbelless/42run/Classes/Math/Mat3.class.cpp -o CMakeFiles/42run.dir/Classes/Math/Mat3.class.cpp.s

CMakeFiles/42run.dir/Classes/Math/Mat3.class.cpp.o.requires:

.PHONY : CMakeFiles/42run.dir/Classes/Math/Mat3.class.cpp.o.requires

CMakeFiles/42run.dir/Classes/Math/Mat3.class.cpp.o.provides: CMakeFiles/42run.dir/Classes/Math/Mat3.class.cpp.o.requires
	$(MAKE) -f CMakeFiles/42run.dir/build.make CMakeFiles/42run.dir/Classes/Math/Mat3.class.cpp.o.provides.build
.PHONY : CMakeFiles/42run.dir/Classes/Math/Mat3.class.cpp.o.provides

CMakeFiles/42run.dir/Classes/Math/Mat3.class.cpp.o.provides.build: CMakeFiles/42run.dir/Classes/Math/Mat3.class.cpp.o


CMakeFiles/42run.dir/Classes/Math/Mat4.class.cpp.o: CMakeFiles/42run.dir/flags.make
CMakeFiles/42run.dir/Classes/Math/Mat4.class.cpp.o: Classes/Math/Mat4.class.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jbelless/42run/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/42run.dir/Classes/Math/Mat4.class.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/42run.dir/Classes/Math/Mat4.class.cpp.o -c /Users/jbelless/42run/Classes/Math/Mat4.class.cpp

CMakeFiles/42run.dir/Classes/Math/Mat4.class.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/42run.dir/Classes/Math/Mat4.class.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jbelless/42run/Classes/Math/Mat4.class.cpp > CMakeFiles/42run.dir/Classes/Math/Mat4.class.cpp.i

CMakeFiles/42run.dir/Classes/Math/Mat4.class.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/42run.dir/Classes/Math/Mat4.class.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jbelless/42run/Classes/Math/Mat4.class.cpp -o CMakeFiles/42run.dir/Classes/Math/Mat4.class.cpp.s

CMakeFiles/42run.dir/Classes/Math/Mat4.class.cpp.o.requires:

.PHONY : CMakeFiles/42run.dir/Classes/Math/Mat4.class.cpp.o.requires

CMakeFiles/42run.dir/Classes/Math/Mat4.class.cpp.o.provides: CMakeFiles/42run.dir/Classes/Math/Mat4.class.cpp.o.requires
	$(MAKE) -f CMakeFiles/42run.dir/build.make CMakeFiles/42run.dir/Classes/Math/Mat4.class.cpp.o.provides.build
.PHONY : CMakeFiles/42run.dir/Classes/Math/Mat4.class.cpp.o.provides

CMakeFiles/42run.dir/Classes/Math/Mat4.class.cpp.o.provides.build: CMakeFiles/42run.dir/Classes/Math/Mat4.class.cpp.o


CMakeFiles/42run.dir/Classes/Render/Camera.class.cpp.o: CMakeFiles/42run.dir/flags.make
CMakeFiles/42run.dir/Classes/Render/Camera.class.cpp.o: Classes/Render/Camera.class.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jbelless/42run/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/42run.dir/Classes/Render/Camera.class.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/42run.dir/Classes/Render/Camera.class.cpp.o -c /Users/jbelless/42run/Classes/Render/Camera.class.cpp

CMakeFiles/42run.dir/Classes/Render/Camera.class.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/42run.dir/Classes/Render/Camera.class.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jbelless/42run/Classes/Render/Camera.class.cpp > CMakeFiles/42run.dir/Classes/Render/Camera.class.cpp.i

CMakeFiles/42run.dir/Classes/Render/Camera.class.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/42run.dir/Classes/Render/Camera.class.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jbelless/42run/Classes/Render/Camera.class.cpp -o CMakeFiles/42run.dir/Classes/Render/Camera.class.cpp.s

CMakeFiles/42run.dir/Classes/Render/Camera.class.cpp.o.requires:

.PHONY : CMakeFiles/42run.dir/Classes/Render/Camera.class.cpp.o.requires

CMakeFiles/42run.dir/Classes/Render/Camera.class.cpp.o.provides: CMakeFiles/42run.dir/Classes/Render/Camera.class.cpp.o.requires
	$(MAKE) -f CMakeFiles/42run.dir/build.make CMakeFiles/42run.dir/Classes/Render/Camera.class.cpp.o.provides.build
.PHONY : CMakeFiles/42run.dir/Classes/Render/Camera.class.cpp.o.provides

CMakeFiles/42run.dir/Classes/Render/Camera.class.cpp.o.provides.build: CMakeFiles/42run.dir/Classes/Render/Camera.class.cpp.o


CMakeFiles/42run.dir/Classes/Transform.class.cpp.o: CMakeFiles/42run.dir/flags.make
CMakeFiles/42run.dir/Classes/Transform.class.cpp.o: Classes/Transform.class.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jbelless/42run/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/42run.dir/Classes/Transform.class.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/42run.dir/Classes/Transform.class.cpp.o -c /Users/jbelless/42run/Classes/Transform.class.cpp

CMakeFiles/42run.dir/Classes/Transform.class.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/42run.dir/Classes/Transform.class.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jbelless/42run/Classes/Transform.class.cpp > CMakeFiles/42run.dir/Classes/Transform.class.cpp.i

CMakeFiles/42run.dir/Classes/Transform.class.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/42run.dir/Classes/Transform.class.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jbelless/42run/Classes/Transform.class.cpp -o CMakeFiles/42run.dir/Classes/Transform.class.cpp.s

CMakeFiles/42run.dir/Classes/Transform.class.cpp.o.requires:

.PHONY : CMakeFiles/42run.dir/Classes/Transform.class.cpp.o.requires

CMakeFiles/42run.dir/Classes/Transform.class.cpp.o.provides: CMakeFiles/42run.dir/Classes/Transform.class.cpp.o.requires
	$(MAKE) -f CMakeFiles/42run.dir/build.make CMakeFiles/42run.dir/Classes/Transform.class.cpp.o.provides.build
.PHONY : CMakeFiles/42run.dir/Classes/Transform.class.cpp.o.provides

CMakeFiles/42run.dir/Classes/Transform.class.cpp.o.provides.build: CMakeFiles/42run.dir/Classes/Transform.class.cpp.o


# Object files for target 42run
42run_OBJECTS = \
"CMakeFiles/42run.dir/src/main.cpp.o" \
"CMakeFiles/42run.dir/Classes/Math/Vec2.class.cpp.o" \
"CMakeFiles/42run.dir/Classes/Math/Vec3.class.cpp.o" \
"CMakeFiles/42run.dir/Classes/Math/Vec4.class.cpp.o" \
"CMakeFiles/42run.dir/Classes/Math/Mat2.class.cpp.o" \
"CMakeFiles/42run.dir/Classes/Math/Mat3.class.cpp.o" \
"CMakeFiles/42run.dir/Classes/Math/Mat4.class.cpp.o" \
"CMakeFiles/42run.dir/Classes/Render/Camera.class.cpp.o" \
"CMakeFiles/42run.dir/Classes/Transform.class.cpp.o"

# External object files for target 42run
42run_EXTERNAL_OBJECTS =

42run: CMakeFiles/42run.dir/src/main.cpp.o
42run: CMakeFiles/42run.dir/Classes/Math/Vec2.class.cpp.o
42run: CMakeFiles/42run.dir/Classes/Math/Vec3.class.cpp.o
42run: CMakeFiles/42run.dir/Classes/Math/Vec4.class.cpp.o
42run: CMakeFiles/42run.dir/Classes/Math/Mat2.class.cpp.o
42run: CMakeFiles/42run.dir/Classes/Math/Mat3.class.cpp.o
42run: CMakeFiles/42run.dir/Classes/Math/Mat4.class.cpp.o
42run: CMakeFiles/42run.dir/Classes/Render/Camera.class.cpp.o
42run: CMakeFiles/42run.dir/Classes/Transform.class.cpp.o
42run: CMakeFiles/42run.dir/build.make
42run: CMakeFiles/42run.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jbelless/42run/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable 42run"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/42run.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/42run.dir/build: 42run

.PHONY : CMakeFiles/42run.dir/build

CMakeFiles/42run.dir/requires: CMakeFiles/42run.dir/src/main.cpp.o.requires
CMakeFiles/42run.dir/requires: CMakeFiles/42run.dir/Classes/Math/Vec2.class.cpp.o.requires
CMakeFiles/42run.dir/requires: CMakeFiles/42run.dir/Classes/Math/Vec3.class.cpp.o.requires
CMakeFiles/42run.dir/requires: CMakeFiles/42run.dir/Classes/Math/Vec4.class.cpp.o.requires
CMakeFiles/42run.dir/requires: CMakeFiles/42run.dir/Classes/Math/Mat2.class.cpp.o.requires
CMakeFiles/42run.dir/requires: CMakeFiles/42run.dir/Classes/Math/Mat3.class.cpp.o.requires
CMakeFiles/42run.dir/requires: CMakeFiles/42run.dir/Classes/Math/Mat4.class.cpp.o.requires
CMakeFiles/42run.dir/requires: CMakeFiles/42run.dir/Classes/Render/Camera.class.cpp.o.requires
CMakeFiles/42run.dir/requires: CMakeFiles/42run.dir/Classes/Transform.class.cpp.o.requires

.PHONY : CMakeFiles/42run.dir/requires

CMakeFiles/42run.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/42run.dir/cmake_clean.cmake
.PHONY : CMakeFiles/42run.dir/clean

CMakeFiles/42run.dir/depend:
	cd /Users/jbelless/42run && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jbelless/42run /Users/jbelless/42run /Users/jbelless/42run /Users/jbelless/42run /Users/jbelless/42run/CMakeFiles/42run.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/42run.dir/depend

