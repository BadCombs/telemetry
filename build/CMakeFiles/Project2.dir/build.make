# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/cmake/1156/bin/cmake

# The command to remove a file.
RM = /snap/cmake/1156/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/badcombs/Uni/Eagle/telemetry

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/badcombs/Uni/Eagle/telemetry/build

# Include any dependencies generated for this target.
include CMakeFiles/Project2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Project2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Project2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Project2.dir/flags.make

CMakeFiles/Project2.dir/sources/fake_receiver.c.o: CMakeFiles/Project2.dir/flags.make
CMakeFiles/Project2.dir/sources/fake_receiver.c.o: /home/badcombs/Uni/Eagle/telemetry/sources/fake_receiver.c
CMakeFiles/Project2.dir/sources/fake_receiver.c.o: CMakeFiles/Project2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/badcombs/Uni/Eagle/telemetry/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Project2.dir/sources/fake_receiver.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Project2.dir/sources/fake_receiver.c.o -MF CMakeFiles/Project2.dir/sources/fake_receiver.c.o.d -o CMakeFiles/Project2.dir/sources/fake_receiver.c.o -c /home/badcombs/Uni/Eagle/telemetry/sources/fake_receiver.c

CMakeFiles/Project2.dir/sources/fake_receiver.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Project2.dir/sources/fake_receiver.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/badcombs/Uni/Eagle/telemetry/sources/fake_receiver.c > CMakeFiles/Project2.dir/sources/fake_receiver.c.i

CMakeFiles/Project2.dir/sources/fake_receiver.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Project2.dir/sources/fake_receiver.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/badcombs/Uni/Eagle/telemetry/sources/fake_receiver.c -o CMakeFiles/Project2.dir/sources/fake_receiver.c.s

CMakeFiles/Project2.dir/sources/fsm.cpp.o: CMakeFiles/Project2.dir/flags.make
CMakeFiles/Project2.dir/sources/fsm.cpp.o: /home/badcombs/Uni/Eagle/telemetry/sources/fsm.cpp
CMakeFiles/Project2.dir/sources/fsm.cpp.o: CMakeFiles/Project2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/badcombs/Uni/Eagle/telemetry/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Project2.dir/sources/fsm.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project2.dir/sources/fsm.cpp.o -MF CMakeFiles/Project2.dir/sources/fsm.cpp.o.d -o CMakeFiles/Project2.dir/sources/fsm.cpp.o -c /home/badcombs/Uni/Eagle/telemetry/sources/fsm.cpp

CMakeFiles/Project2.dir/sources/fsm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project2.dir/sources/fsm.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/badcombs/Uni/Eagle/telemetry/sources/fsm.cpp > CMakeFiles/Project2.dir/sources/fsm.cpp.i

CMakeFiles/Project2.dir/sources/fsm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project2.dir/sources/fsm.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/badcombs/Uni/Eagle/telemetry/sources/fsm.cpp -o CMakeFiles/Project2.dir/sources/fsm.cpp.s

CMakeFiles/Project2.dir/sources/message.cpp.o: CMakeFiles/Project2.dir/flags.make
CMakeFiles/Project2.dir/sources/message.cpp.o: /home/badcombs/Uni/Eagle/telemetry/sources/message.cpp
CMakeFiles/Project2.dir/sources/message.cpp.o: CMakeFiles/Project2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/badcombs/Uni/Eagle/telemetry/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Project2.dir/sources/message.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project2.dir/sources/message.cpp.o -MF CMakeFiles/Project2.dir/sources/message.cpp.o.d -o CMakeFiles/Project2.dir/sources/message.cpp.o -c /home/badcombs/Uni/Eagle/telemetry/sources/message.cpp

CMakeFiles/Project2.dir/sources/message.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project2.dir/sources/message.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/badcombs/Uni/Eagle/telemetry/sources/message.cpp > CMakeFiles/Project2.dir/sources/message.cpp.i

CMakeFiles/Project2.dir/sources/message.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project2.dir/sources/message.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/badcombs/Uni/Eagle/telemetry/sources/message.cpp -o CMakeFiles/Project2.dir/sources/message.cpp.s

CMakeFiles/Project2.dir/sources/id_info.cpp.o: CMakeFiles/Project2.dir/flags.make
CMakeFiles/Project2.dir/sources/id_info.cpp.o: /home/badcombs/Uni/Eagle/telemetry/sources/id_info.cpp
CMakeFiles/Project2.dir/sources/id_info.cpp.o: CMakeFiles/Project2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/badcombs/Uni/Eagle/telemetry/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Project2.dir/sources/id_info.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Project2.dir/sources/id_info.cpp.o -MF CMakeFiles/Project2.dir/sources/id_info.cpp.o.d -o CMakeFiles/Project2.dir/sources/id_info.cpp.o -c /home/badcombs/Uni/Eagle/telemetry/sources/id_info.cpp

CMakeFiles/Project2.dir/sources/id_info.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Project2.dir/sources/id_info.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/badcombs/Uni/Eagle/telemetry/sources/id_info.cpp > CMakeFiles/Project2.dir/sources/id_info.cpp.i

CMakeFiles/Project2.dir/sources/id_info.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Project2.dir/sources/id_info.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/badcombs/Uni/Eagle/telemetry/sources/id_info.cpp -o CMakeFiles/Project2.dir/sources/id_info.cpp.s

# Object files for target Project2
Project2_OBJECTS = \
"CMakeFiles/Project2.dir/sources/fake_receiver.c.o" \
"CMakeFiles/Project2.dir/sources/fsm.cpp.o" \
"CMakeFiles/Project2.dir/sources/message.cpp.o" \
"CMakeFiles/Project2.dir/sources/id_info.cpp.o"

# External object files for target Project2
Project2_EXTERNAL_OBJECTS =

libProject2.so: CMakeFiles/Project2.dir/sources/fake_receiver.c.o
libProject2.so: CMakeFiles/Project2.dir/sources/fsm.cpp.o
libProject2.so: CMakeFiles/Project2.dir/sources/message.cpp.o
libProject2.so: CMakeFiles/Project2.dir/sources/id_info.cpp.o
libProject2.so: CMakeFiles/Project2.dir/build.make
libProject2.so: CMakeFiles/Project2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/badcombs/Uni/Eagle/telemetry/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX shared library libProject2.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Project2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Project2.dir/build: libProject2.so
.PHONY : CMakeFiles/Project2.dir/build

CMakeFiles/Project2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Project2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Project2.dir/clean

CMakeFiles/Project2.dir/depend:
	cd /home/badcombs/Uni/Eagle/telemetry/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/badcombs/Uni/Eagle/telemetry /home/badcombs/Uni/Eagle/telemetry /home/badcombs/Uni/Eagle/telemetry/build /home/badcombs/Uni/Eagle/telemetry/build /home/badcombs/Uni/Eagle/telemetry/build/CMakeFiles/Project2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Project2.dir/depend

