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
CMAKE_SOURCE_DIR = /home/djia/cs480Park/PA10

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/djia/cs480Park/PA10/build

# Include any dependencies generated for this target.
include CMakeFiles/PA10.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PA10.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PA10.dir/flags.make

CMakeFiles/PA10.dir/src/camera.cpp.o: CMakeFiles/PA10.dir/flags.make
CMakeFiles/PA10.dir/src/camera.cpp.o: ../src/camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/djia/cs480Park/PA10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PA10.dir/src/camera.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PA10.dir/src/camera.cpp.o -c /home/djia/cs480Park/PA10/src/camera.cpp

CMakeFiles/PA10.dir/src/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PA10.dir/src/camera.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/djia/cs480Park/PA10/src/camera.cpp > CMakeFiles/PA10.dir/src/camera.cpp.i

CMakeFiles/PA10.dir/src/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PA10.dir/src/camera.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/djia/cs480Park/PA10/src/camera.cpp -o CMakeFiles/PA10.dir/src/camera.cpp.s

CMakeFiles/PA10.dir/src/camera.cpp.o.requires:

.PHONY : CMakeFiles/PA10.dir/src/camera.cpp.o.requires

CMakeFiles/PA10.dir/src/camera.cpp.o.provides: CMakeFiles/PA10.dir/src/camera.cpp.o.requires
	$(MAKE) -f CMakeFiles/PA10.dir/build.make CMakeFiles/PA10.dir/src/camera.cpp.o.provides.build
.PHONY : CMakeFiles/PA10.dir/src/camera.cpp.o.provides

CMakeFiles/PA10.dir/src/camera.cpp.o.provides.build: CMakeFiles/PA10.dir/src/camera.cpp.o


CMakeFiles/PA10.dir/src/engine.cpp.o: CMakeFiles/PA10.dir/flags.make
CMakeFiles/PA10.dir/src/engine.cpp.o: ../src/engine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/djia/cs480Park/PA10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PA10.dir/src/engine.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PA10.dir/src/engine.cpp.o -c /home/djia/cs480Park/PA10/src/engine.cpp

CMakeFiles/PA10.dir/src/engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PA10.dir/src/engine.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/djia/cs480Park/PA10/src/engine.cpp > CMakeFiles/PA10.dir/src/engine.cpp.i

CMakeFiles/PA10.dir/src/engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PA10.dir/src/engine.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/djia/cs480Park/PA10/src/engine.cpp -o CMakeFiles/PA10.dir/src/engine.cpp.s

CMakeFiles/PA10.dir/src/engine.cpp.o.requires:

.PHONY : CMakeFiles/PA10.dir/src/engine.cpp.o.requires

CMakeFiles/PA10.dir/src/engine.cpp.o.provides: CMakeFiles/PA10.dir/src/engine.cpp.o.requires
	$(MAKE) -f CMakeFiles/PA10.dir/build.make CMakeFiles/PA10.dir/src/engine.cpp.o.provides.build
.PHONY : CMakeFiles/PA10.dir/src/engine.cpp.o.provides

CMakeFiles/PA10.dir/src/engine.cpp.o.provides.build: CMakeFiles/PA10.dir/src/engine.cpp.o


CMakeFiles/PA10.dir/src/graphics.cpp.o: CMakeFiles/PA10.dir/flags.make
CMakeFiles/PA10.dir/src/graphics.cpp.o: ../src/graphics.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/djia/cs480Park/PA10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/PA10.dir/src/graphics.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PA10.dir/src/graphics.cpp.o -c /home/djia/cs480Park/PA10/src/graphics.cpp

CMakeFiles/PA10.dir/src/graphics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PA10.dir/src/graphics.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/djia/cs480Park/PA10/src/graphics.cpp > CMakeFiles/PA10.dir/src/graphics.cpp.i

CMakeFiles/PA10.dir/src/graphics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PA10.dir/src/graphics.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/djia/cs480Park/PA10/src/graphics.cpp -o CMakeFiles/PA10.dir/src/graphics.cpp.s

CMakeFiles/PA10.dir/src/graphics.cpp.o.requires:

.PHONY : CMakeFiles/PA10.dir/src/graphics.cpp.o.requires

CMakeFiles/PA10.dir/src/graphics.cpp.o.provides: CMakeFiles/PA10.dir/src/graphics.cpp.o.requires
	$(MAKE) -f CMakeFiles/PA10.dir/build.make CMakeFiles/PA10.dir/src/graphics.cpp.o.provides.build
.PHONY : CMakeFiles/PA10.dir/src/graphics.cpp.o.provides

CMakeFiles/PA10.dir/src/graphics.cpp.o.provides.build: CMakeFiles/PA10.dir/src/graphics.cpp.o


CMakeFiles/PA10.dir/src/main.cpp.o: CMakeFiles/PA10.dir/flags.make
CMakeFiles/PA10.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/djia/cs480Park/PA10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/PA10.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PA10.dir/src/main.cpp.o -c /home/djia/cs480Park/PA10/src/main.cpp

CMakeFiles/PA10.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PA10.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/djia/cs480Park/PA10/src/main.cpp > CMakeFiles/PA10.dir/src/main.cpp.i

CMakeFiles/PA10.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PA10.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/djia/cs480Park/PA10/src/main.cpp -o CMakeFiles/PA10.dir/src/main.cpp.s

CMakeFiles/PA10.dir/src/main.cpp.o.requires:

.PHONY : CMakeFiles/PA10.dir/src/main.cpp.o.requires

CMakeFiles/PA10.dir/src/main.cpp.o.provides: CMakeFiles/PA10.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/PA10.dir/build.make CMakeFiles/PA10.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/PA10.dir/src/main.cpp.o.provides

CMakeFiles/PA10.dir/src/main.cpp.o.provides.build: CMakeFiles/PA10.dir/src/main.cpp.o


CMakeFiles/PA10.dir/src/mesh.cpp.o: CMakeFiles/PA10.dir/flags.make
CMakeFiles/PA10.dir/src/mesh.cpp.o: ../src/mesh.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/djia/cs480Park/PA10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/PA10.dir/src/mesh.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PA10.dir/src/mesh.cpp.o -c /home/djia/cs480Park/PA10/src/mesh.cpp

CMakeFiles/PA10.dir/src/mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PA10.dir/src/mesh.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/djia/cs480Park/PA10/src/mesh.cpp > CMakeFiles/PA10.dir/src/mesh.cpp.i

CMakeFiles/PA10.dir/src/mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PA10.dir/src/mesh.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/djia/cs480Park/PA10/src/mesh.cpp -o CMakeFiles/PA10.dir/src/mesh.cpp.s

CMakeFiles/PA10.dir/src/mesh.cpp.o.requires:

.PHONY : CMakeFiles/PA10.dir/src/mesh.cpp.o.requires

CMakeFiles/PA10.dir/src/mesh.cpp.o.provides: CMakeFiles/PA10.dir/src/mesh.cpp.o.requires
	$(MAKE) -f CMakeFiles/PA10.dir/build.make CMakeFiles/PA10.dir/src/mesh.cpp.o.provides.build
.PHONY : CMakeFiles/PA10.dir/src/mesh.cpp.o.provides

CMakeFiles/PA10.dir/src/mesh.cpp.o.provides.build: CMakeFiles/PA10.dir/src/mesh.cpp.o


CMakeFiles/PA10.dir/src/object.cpp.o: CMakeFiles/PA10.dir/flags.make
CMakeFiles/PA10.dir/src/object.cpp.o: ../src/object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/djia/cs480Park/PA10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/PA10.dir/src/object.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PA10.dir/src/object.cpp.o -c /home/djia/cs480Park/PA10/src/object.cpp

CMakeFiles/PA10.dir/src/object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PA10.dir/src/object.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/djia/cs480Park/PA10/src/object.cpp > CMakeFiles/PA10.dir/src/object.cpp.i

CMakeFiles/PA10.dir/src/object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PA10.dir/src/object.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/djia/cs480Park/PA10/src/object.cpp -o CMakeFiles/PA10.dir/src/object.cpp.s

CMakeFiles/PA10.dir/src/object.cpp.o.requires:

.PHONY : CMakeFiles/PA10.dir/src/object.cpp.o.requires

CMakeFiles/PA10.dir/src/object.cpp.o.provides: CMakeFiles/PA10.dir/src/object.cpp.o.requires
	$(MAKE) -f CMakeFiles/PA10.dir/build.make CMakeFiles/PA10.dir/src/object.cpp.o.provides.build
.PHONY : CMakeFiles/PA10.dir/src/object.cpp.o.provides

CMakeFiles/PA10.dir/src/object.cpp.o.provides.build: CMakeFiles/PA10.dir/src/object.cpp.o


CMakeFiles/PA10.dir/src/shader.cpp.o: CMakeFiles/PA10.dir/flags.make
CMakeFiles/PA10.dir/src/shader.cpp.o: ../src/shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/djia/cs480Park/PA10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/PA10.dir/src/shader.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PA10.dir/src/shader.cpp.o -c /home/djia/cs480Park/PA10/src/shader.cpp

CMakeFiles/PA10.dir/src/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PA10.dir/src/shader.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/djia/cs480Park/PA10/src/shader.cpp > CMakeFiles/PA10.dir/src/shader.cpp.i

CMakeFiles/PA10.dir/src/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PA10.dir/src/shader.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/djia/cs480Park/PA10/src/shader.cpp -o CMakeFiles/PA10.dir/src/shader.cpp.s

CMakeFiles/PA10.dir/src/shader.cpp.o.requires:

.PHONY : CMakeFiles/PA10.dir/src/shader.cpp.o.requires

CMakeFiles/PA10.dir/src/shader.cpp.o.provides: CMakeFiles/PA10.dir/src/shader.cpp.o.requires
	$(MAKE) -f CMakeFiles/PA10.dir/build.make CMakeFiles/PA10.dir/src/shader.cpp.o.provides.build
.PHONY : CMakeFiles/PA10.dir/src/shader.cpp.o.provides

CMakeFiles/PA10.dir/src/shader.cpp.o.provides.build: CMakeFiles/PA10.dir/src/shader.cpp.o


CMakeFiles/PA10.dir/src/window.cpp.o: CMakeFiles/PA10.dir/flags.make
CMakeFiles/PA10.dir/src/window.cpp.o: ../src/window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/djia/cs480Park/PA10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/PA10.dir/src/window.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PA10.dir/src/window.cpp.o -c /home/djia/cs480Park/PA10/src/window.cpp

CMakeFiles/PA10.dir/src/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PA10.dir/src/window.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/djia/cs480Park/PA10/src/window.cpp > CMakeFiles/PA10.dir/src/window.cpp.i

CMakeFiles/PA10.dir/src/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PA10.dir/src/window.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/djia/cs480Park/PA10/src/window.cpp -o CMakeFiles/PA10.dir/src/window.cpp.s

CMakeFiles/PA10.dir/src/window.cpp.o.requires:

.PHONY : CMakeFiles/PA10.dir/src/window.cpp.o.requires

CMakeFiles/PA10.dir/src/window.cpp.o.provides: CMakeFiles/PA10.dir/src/window.cpp.o.requires
	$(MAKE) -f CMakeFiles/PA10.dir/build.make CMakeFiles/PA10.dir/src/window.cpp.o.provides.build
.PHONY : CMakeFiles/PA10.dir/src/window.cpp.o.provides

CMakeFiles/PA10.dir/src/window.cpp.o.provides.build: CMakeFiles/PA10.dir/src/window.cpp.o


# Object files for target PA10
PA10_OBJECTS = \
"CMakeFiles/PA10.dir/src/camera.cpp.o" \
"CMakeFiles/PA10.dir/src/engine.cpp.o" \
"CMakeFiles/PA10.dir/src/graphics.cpp.o" \
"CMakeFiles/PA10.dir/src/main.cpp.o" \
"CMakeFiles/PA10.dir/src/mesh.cpp.o" \
"CMakeFiles/PA10.dir/src/object.cpp.o" \
"CMakeFiles/PA10.dir/src/shader.cpp.o" \
"CMakeFiles/PA10.dir/src/window.cpp.o"

# External object files for target PA10
PA10_EXTERNAL_OBJECTS =

PA10: CMakeFiles/PA10.dir/src/camera.cpp.o
PA10: CMakeFiles/PA10.dir/src/engine.cpp.o
PA10: CMakeFiles/PA10.dir/src/graphics.cpp.o
PA10: CMakeFiles/PA10.dir/src/main.cpp.o
PA10: CMakeFiles/PA10.dir/src/mesh.cpp.o
PA10: CMakeFiles/PA10.dir/src/object.cpp.o
PA10: CMakeFiles/PA10.dir/src/shader.cpp.o
PA10: CMakeFiles/PA10.dir/src/window.cpp.o
PA10: CMakeFiles/PA10.dir/build.make
PA10: /usr/lib/x86_64-linux-gnu/libGLEW.so
PA10: /usr/lib/x86_64-linux-gnu/libGLU.so
PA10: /usr/lib/x86_64-linux-gnu/libGL.so
PA10: /usr/local/lib/libSDL2main.a
PA10: /usr/local/lib/libSDL2.so
PA10: /usr/lib/x86_64-linux-gnu/libMagick++-6.Q16.so
PA10: /usr/local/lib/libBulletDynamics.a
PA10: /usr/local/lib/libBulletCollision.a
PA10: /usr/local/lib/libLinearMath.a
PA10: /usr/local/lib/libBulletSoftBody.a
PA10: CMakeFiles/PA10.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/djia/cs480Park/PA10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable PA10"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PA10.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PA10.dir/build: PA10

.PHONY : CMakeFiles/PA10.dir/build

CMakeFiles/PA10.dir/requires: CMakeFiles/PA10.dir/src/camera.cpp.o.requires
CMakeFiles/PA10.dir/requires: CMakeFiles/PA10.dir/src/engine.cpp.o.requires
CMakeFiles/PA10.dir/requires: CMakeFiles/PA10.dir/src/graphics.cpp.o.requires
CMakeFiles/PA10.dir/requires: CMakeFiles/PA10.dir/src/main.cpp.o.requires
CMakeFiles/PA10.dir/requires: CMakeFiles/PA10.dir/src/mesh.cpp.o.requires
CMakeFiles/PA10.dir/requires: CMakeFiles/PA10.dir/src/object.cpp.o.requires
CMakeFiles/PA10.dir/requires: CMakeFiles/PA10.dir/src/shader.cpp.o.requires
CMakeFiles/PA10.dir/requires: CMakeFiles/PA10.dir/src/window.cpp.o.requires

.PHONY : CMakeFiles/PA10.dir/requires

CMakeFiles/PA10.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PA10.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PA10.dir/clean

CMakeFiles/PA10.dir/depend:
	cd /home/djia/cs480Park/PA10/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/djia/cs480Park/PA10 /home/djia/cs480Park/PA10 /home/djia/cs480Park/PA10/build /home/djia/cs480Park/PA10/build /home/djia/cs480Park/PA10/build/CMakeFiles/PA10.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PA10.dir/depend

