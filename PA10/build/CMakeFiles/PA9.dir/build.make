# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xiaolong/cs480Park/PA10

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xiaolong/cs480Park/PA10/build

# Include any dependencies generated for this target.
include CMakeFiles/PA9.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PA9.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PA9.dir/flags.make

CMakeFiles/PA9.dir/src/camera.cpp.o: CMakeFiles/PA9.dir/flags.make
CMakeFiles/PA9.dir/src/camera.cpp.o: ../src/camera.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xiaolong/cs480Park/PA10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PA9.dir/src/camera.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PA9.dir/src/camera.cpp.o -c /home/xiaolong/cs480Park/PA10/src/camera.cpp

CMakeFiles/PA9.dir/src/camera.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PA9.dir/src/camera.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xiaolong/cs480Park/PA10/src/camera.cpp > CMakeFiles/PA9.dir/src/camera.cpp.i

CMakeFiles/PA9.dir/src/camera.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PA9.dir/src/camera.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xiaolong/cs480Park/PA10/src/camera.cpp -o CMakeFiles/PA9.dir/src/camera.cpp.s

CMakeFiles/PA9.dir/src/engine.cpp.o: CMakeFiles/PA9.dir/flags.make
CMakeFiles/PA9.dir/src/engine.cpp.o: ../src/engine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xiaolong/cs480Park/PA10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/PA9.dir/src/engine.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PA9.dir/src/engine.cpp.o -c /home/xiaolong/cs480Park/PA10/src/engine.cpp

CMakeFiles/PA9.dir/src/engine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PA9.dir/src/engine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xiaolong/cs480Park/PA10/src/engine.cpp > CMakeFiles/PA9.dir/src/engine.cpp.i

CMakeFiles/PA9.dir/src/engine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PA9.dir/src/engine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xiaolong/cs480Park/PA10/src/engine.cpp -o CMakeFiles/PA9.dir/src/engine.cpp.s

CMakeFiles/PA9.dir/src/graphics.cpp.o: CMakeFiles/PA9.dir/flags.make
CMakeFiles/PA9.dir/src/graphics.cpp.o: ../src/graphics.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xiaolong/cs480Park/PA10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/PA9.dir/src/graphics.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PA9.dir/src/graphics.cpp.o -c /home/xiaolong/cs480Park/PA10/src/graphics.cpp

CMakeFiles/PA9.dir/src/graphics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PA9.dir/src/graphics.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xiaolong/cs480Park/PA10/src/graphics.cpp > CMakeFiles/PA9.dir/src/graphics.cpp.i

CMakeFiles/PA9.dir/src/graphics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PA9.dir/src/graphics.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xiaolong/cs480Park/PA10/src/graphics.cpp -o CMakeFiles/PA9.dir/src/graphics.cpp.s

CMakeFiles/PA9.dir/src/main.cpp.o: CMakeFiles/PA9.dir/flags.make
CMakeFiles/PA9.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xiaolong/cs480Park/PA10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/PA9.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PA9.dir/src/main.cpp.o -c /home/xiaolong/cs480Park/PA10/src/main.cpp

CMakeFiles/PA9.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PA9.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xiaolong/cs480Park/PA10/src/main.cpp > CMakeFiles/PA9.dir/src/main.cpp.i

CMakeFiles/PA9.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PA9.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xiaolong/cs480Park/PA10/src/main.cpp -o CMakeFiles/PA9.dir/src/main.cpp.s

CMakeFiles/PA9.dir/src/mesh.cpp.o: CMakeFiles/PA9.dir/flags.make
CMakeFiles/PA9.dir/src/mesh.cpp.o: ../src/mesh.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xiaolong/cs480Park/PA10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/PA9.dir/src/mesh.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PA9.dir/src/mesh.cpp.o -c /home/xiaolong/cs480Park/PA10/src/mesh.cpp

CMakeFiles/PA9.dir/src/mesh.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PA9.dir/src/mesh.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xiaolong/cs480Park/PA10/src/mesh.cpp > CMakeFiles/PA9.dir/src/mesh.cpp.i

CMakeFiles/PA9.dir/src/mesh.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PA9.dir/src/mesh.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xiaolong/cs480Park/PA10/src/mesh.cpp -o CMakeFiles/PA9.dir/src/mesh.cpp.s

CMakeFiles/PA9.dir/src/object.cpp.o: CMakeFiles/PA9.dir/flags.make
CMakeFiles/PA9.dir/src/object.cpp.o: ../src/object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xiaolong/cs480Park/PA10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/PA9.dir/src/object.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PA9.dir/src/object.cpp.o -c /home/xiaolong/cs480Park/PA10/src/object.cpp

CMakeFiles/PA9.dir/src/object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PA9.dir/src/object.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xiaolong/cs480Park/PA10/src/object.cpp > CMakeFiles/PA9.dir/src/object.cpp.i

CMakeFiles/PA9.dir/src/object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PA9.dir/src/object.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xiaolong/cs480Park/PA10/src/object.cpp -o CMakeFiles/PA9.dir/src/object.cpp.s

CMakeFiles/PA9.dir/src/shader.cpp.o: CMakeFiles/PA9.dir/flags.make
CMakeFiles/PA9.dir/src/shader.cpp.o: ../src/shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xiaolong/cs480Park/PA10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/PA9.dir/src/shader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PA9.dir/src/shader.cpp.o -c /home/xiaolong/cs480Park/PA10/src/shader.cpp

CMakeFiles/PA9.dir/src/shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PA9.dir/src/shader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xiaolong/cs480Park/PA10/src/shader.cpp > CMakeFiles/PA9.dir/src/shader.cpp.i

CMakeFiles/PA9.dir/src/shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PA9.dir/src/shader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xiaolong/cs480Park/PA10/src/shader.cpp -o CMakeFiles/PA9.dir/src/shader.cpp.s

CMakeFiles/PA9.dir/src/window.cpp.o: CMakeFiles/PA9.dir/flags.make
CMakeFiles/PA9.dir/src/window.cpp.o: ../src/window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xiaolong/cs480Park/PA10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/PA9.dir/src/window.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PA9.dir/src/window.cpp.o -c /home/xiaolong/cs480Park/PA10/src/window.cpp

CMakeFiles/PA9.dir/src/window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PA9.dir/src/window.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/xiaolong/cs480Park/PA10/src/window.cpp > CMakeFiles/PA9.dir/src/window.cpp.i

CMakeFiles/PA9.dir/src/window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PA9.dir/src/window.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/xiaolong/cs480Park/PA10/src/window.cpp -o CMakeFiles/PA9.dir/src/window.cpp.s

# Object files for target PA9
PA9_OBJECTS = \
"CMakeFiles/PA9.dir/src/camera.cpp.o" \
"CMakeFiles/PA9.dir/src/engine.cpp.o" \
"CMakeFiles/PA9.dir/src/graphics.cpp.o" \
"CMakeFiles/PA9.dir/src/main.cpp.o" \
"CMakeFiles/PA9.dir/src/mesh.cpp.o" \
"CMakeFiles/PA9.dir/src/object.cpp.o" \
"CMakeFiles/PA9.dir/src/shader.cpp.o" \
"CMakeFiles/PA9.dir/src/window.cpp.o"

# External object files for target PA9
PA9_EXTERNAL_OBJECTS =

PA9: CMakeFiles/PA9.dir/src/camera.cpp.o
PA9: CMakeFiles/PA9.dir/src/engine.cpp.o
PA9: CMakeFiles/PA9.dir/src/graphics.cpp.o
PA9: CMakeFiles/PA9.dir/src/main.cpp.o
PA9: CMakeFiles/PA9.dir/src/mesh.cpp.o
PA9: CMakeFiles/PA9.dir/src/object.cpp.o
PA9: CMakeFiles/PA9.dir/src/shader.cpp.o
PA9: CMakeFiles/PA9.dir/src/window.cpp.o
PA9: CMakeFiles/PA9.dir/build.make
PA9: /usr/lib/x86_64-linux-gnu/libGLEW.so
PA9: /usr/lib/x86_64-linux-gnu/libGL.so
PA9: /usr/lib/x86_64-linux-gnu/libGLU.so
PA9: /usr/lib/x86_64-linux-gnu/libSDL2main.a
PA9: /usr/lib/x86_64-linux-gnu/libSDL2.so
PA9: /usr/lib/x86_64-linux-gnu/libMagick++-6.Q16.so
PA9: /usr/lib/x86_64-linux-gnu/libBulletDynamics.so
PA9: /usr/lib/x86_64-linux-gnu/libBulletCollision.so
PA9: /usr/lib/x86_64-linux-gnu/libLinearMath.so
PA9: /usr/lib/x86_64-linux-gnu/libBulletSoftBody.so
PA9: CMakeFiles/PA9.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xiaolong/cs480Park/PA10/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable PA9"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PA9.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PA9.dir/build: PA9

.PHONY : CMakeFiles/PA9.dir/build

CMakeFiles/PA9.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PA9.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PA9.dir/clean

CMakeFiles/PA9.dir/depend:
	cd /home/xiaolong/cs480Park/PA10/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xiaolong/cs480Park/PA10 /home/xiaolong/cs480Park/PA10 /home/xiaolong/cs480Park/PA10/build /home/xiaolong/cs480Park/PA10/build /home/xiaolong/cs480Park/PA10/build/CMakeFiles/PA9.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PA9.dir/depend

