# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/Users/jbelless/.brew/Cellar/cmake/3.9.1/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/Users/jbelless/.brew/Cellar/cmake/3.9.1/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/jbelless/42run/CMakeFiles /Users/jbelless/42run/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/jbelless/42run/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named 42run

# Build rule for target.
42run: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 42run
.PHONY : 42run

# fast build rule for target.
42run/fast:
	$(MAKE) -f CMakeFiles/42run.dir/build.make CMakeFiles/42run.dir/build
.PHONY : 42run/fast

Classes/Math/Vec2.class.o: Classes/Math/Vec2.class.cpp.o

.PHONY : Classes/Math/Vec2.class.o

# target to build an object file
Classes/Math/Vec2.class.cpp.o:
	$(MAKE) -f CMakeFiles/42run.dir/build.make CMakeFiles/42run.dir/Classes/Math/Vec2.class.cpp.o
.PHONY : Classes/Math/Vec2.class.cpp.o

Classes/Math/Vec2.class.i: Classes/Math/Vec2.class.cpp.i

.PHONY : Classes/Math/Vec2.class.i

# target to preprocess a source file
Classes/Math/Vec2.class.cpp.i:
	$(MAKE) -f CMakeFiles/42run.dir/build.make CMakeFiles/42run.dir/Classes/Math/Vec2.class.cpp.i
.PHONY : Classes/Math/Vec2.class.cpp.i

Classes/Math/Vec2.class.s: Classes/Math/Vec2.class.cpp.s

.PHONY : Classes/Math/Vec2.class.s

# target to generate assembly for a file
Classes/Math/Vec2.class.cpp.s:
	$(MAKE) -f CMakeFiles/42run.dir/build.make CMakeFiles/42run.dir/Classes/Math/Vec2.class.cpp.s
.PHONY : Classes/Math/Vec2.class.cpp.s

Classes/Math/Vec3.class.o: Classes/Math/Vec3.class.cpp.o

.PHONY : Classes/Math/Vec3.class.o

# target to build an object file
Classes/Math/Vec3.class.cpp.o:
	$(MAKE) -f CMakeFiles/42run.dir/build.make CMakeFiles/42run.dir/Classes/Math/Vec3.class.cpp.o
.PHONY : Classes/Math/Vec3.class.cpp.o

Classes/Math/Vec3.class.i: Classes/Math/Vec3.class.cpp.i

.PHONY : Classes/Math/Vec3.class.i

# target to preprocess a source file
Classes/Math/Vec3.class.cpp.i:
	$(MAKE) -f CMakeFiles/42run.dir/build.make CMakeFiles/42run.dir/Classes/Math/Vec3.class.cpp.i
.PHONY : Classes/Math/Vec3.class.cpp.i

Classes/Math/Vec3.class.s: Classes/Math/Vec3.class.cpp.s

.PHONY : Classes/Math/Vec3.class.s

# target to generate assembly for a file
Classes/Math/Vec3.class.cpp.s:
	$(MAKE) -f CMakeFiles/42run.dir/build.make CMakeFiles/42run.dir/Classes/Math/Vec3.class.cpp.s
.PHONY : Classes/Math/Vec3.class.cpp.s

Classes/Math/Vec4.class.o: Classes/Math/Vec4.class.cpp.o

.PHONY : Classes/Math/Vec4.class.o

# target to build an object file
Classes/Math/Vec4.class.cpp.o:
	$(MAKE) -f CMakeFiles/42run.dir/build.make CMakeFiles/42run.dir/Classes/Math/Vec4.class.cpp.o
.PHONY : Classes/Math/Vec4.class.cpp.o

Classes/Math/Vec4.class.i: Classes/Math/Vec4.class.cpp.i

.PHONY : Classes/Math/Vec4.class.i

# target to preprocess a source file
Classes/Math/Vec4.class.cpp.i:
	$(MAKE) -f CMakeFiles/42run.dir/build.make CMakeFiles/42run.dir/Classes/Math/Vec4.class.cpp.i
.PHONY : Classes/Math/Vec4.class.cpp.i

Classes/Math/Vec4.class.s: Classes/Math/Vec4.class.cpp.s

.PHONY : Classes/Math/Vec4.class.s

# target to generate assembly for a file
Classes/Math/Vec4.class.cpp.s:
	$(MAKE) -f CMakeFiles/42run.dir/build.make CMakeFiles/42run.dir/Classes/Math/Vec4.class.cpp.s
.PHONY : Classes/Math/Vec4.class.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/42run.dir/build.make CMakeFiles/42run.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/42run.dir/build.make CMakeFiles/42run.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/42run.dir/build.make CMakeFiles/42run.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... 42run"
	@echo "... Classes/Math/Vec2.class.o"
	@echo "... Classes/Math/Vec2.class.i"
	@echo "... Classes/Math/Vec2.class.s"
	@echo "... Classes/Math/Vec3.class.o"
	@echo "... Classes/Math/Vec3.class.i"
	@echo "... Classes/Math/Vec3.class.s"
	@echo "... Classes/Math/Vec4.class.o"
	@echo "... Classes/Math/Vec4.class.i"
	@echo "... Classes/Math/Vec4.class.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

