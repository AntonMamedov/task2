# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /snap/clion/129/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/129/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/anton/dev/techno_park/cpp/task2/tf_idf_metric_nonthread

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anton/dev/techno_park/cpp/task2/tf_idf_metric_nonthread/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/tf_idf_metric_nonthread.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tf_idf_metric_nonthread.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tf_idf_metric_nonthread.dir/flags.make

CMakeFiles/tf_idf_metric_nonthread.dir/src/main.c.o: CMakeFiles/tf_idf_metric_nonthread.dir/flags.make
CMakeFiles/tf_idf_metric_nonthread.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anton/dev/techno_park/cpp/task2/tf_idf_metric_nonthread/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/tf_idf_metric_nonthread.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tf_idf_metric_nonthread.dir/src/main.c.o   -c /home/anton/dev/techno_park/cpp/task2/tf_idf_metric_nonthread/src/main.c

CMakeFiles/tf_idf_metric_nonthread.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tf_idf_metric_nonthread.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/anton/dev/techno_park/cpp/task2/tf_idf_metric_nonthread/src/main.c > CMakeFiles/tf_idf_metric_nonthread.dir/src/main.c.i

CMakeFiles/tf_idf_metric_nonthread.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tf_idf_metric_nonthread.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/anton/dev/techno_park/cpp/task2/tf_idf_metric_nonthread/src/main.c -o CMakeFiles/tf_idf_metric_nonthread.dir/src/main.c.s

CMakeFiles/tf_idf_metric_nonthread.dir/src/str.c.o: CMakeFiles/tf_idf_metric_nonthread.dir/flags.make
CMakeFiles/tf_idf_metric_nonthread.dir/src/str.c.o: ../src/str.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anton/dev/techno_park/cpp/task2/tf_idf_metric_nonthread/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/tf_idf_metric_nonthread.dir/src/str.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tf_idf_metric_nonthread.dir/src/str.c.o   -c /home/anton/dev/techno_park/cpp/task2/tf_idf_metric_nonthread/src/str.c

CMakeFiles/tf_idf_metric_nonthread.dir/src/str.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tf_idf_metric_nonthread.dir/src/str.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/anton/dev/techno_park/cpp/task2/tf_idf_metric_nonthread/src/str.c > CMakeFiles/tf_idf_metric_nonthread.dir/src/str.c.i

CMakeFiles/tf_idf_metric_nonthread.dir/src/str.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tf_idf_metric_nonthread.dir/src/str.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/anton/dev/techno_park/cpp/task2/tf_idf_metric_nonthread/src/str.c -o CMakeFiles/tf_idf_metric_nonthread.dir/src/str.c.s

CMakeFiles/tf_idf_metric_nonthread.dir/src/str_map.c.o: CMakeFiles/tf_idf_metric_nonthread.dir/flags.make
CMakeFiles/tf_idf_metric_nonthread.dir/src/str_map.c.o: ../src/str_map.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anton/dev/techno_park/cpp/task2/tf_idf_metric_nonthread/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/tf_idf_metric_nonthread.dir/src/str_map.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tf_idf_metric_nonthread.dir/src/str_map.c.o   -c /home/anton/dev/techno_park/cpp/task2/tf_idf_metric_nonthread/src/str_map.c

CMakeFiles/tf_idf_metric_nonthread.dir/src/str_map.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tf_idf_metric_nonthread.dir/src/str_map.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/anton/dev/techno_park/cpp/task2/tf_idf_metric_nonthread/src/str_map.c > CMakeFiles/tf_idf_metric_nonthread.dir/src/str_map.c.i

CMakeFiles/tf_idf_metric_nonthread.dir/src/str_map.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tf_idf_metric_nonthread.dir/src/str_map.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/anton/dev/techno_park/cpp/task2/tf_idf_metric_nonthread/src/str_map.c -o CMakeFiles/tf_idf_metric_nonthread.dir/src/str_map.c.s

CMakeFiles/tf_idf_metric_nonthread.dir/src/file_metric.c.o: CMakeFiles/tf_idf_metric_nonthread.dir/flags.make
CMakeFiles/tf_idf_metric_nonthread.dir/src/file_metric.c.o: ../src/file_metric.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anton/dev/techno_park/cpp/task2/tf_idf_metric_nonthread/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/tf_idf_metric_nonthread.dir/src/file_metric.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tf_idf_metric_nonthread.dir/src/file_metric.c.o   -c /home/anton/dev/techno_park/cpp/task2/tf_idf_metric_nonthread/src/file_metric.c

CMakeFiles/tf_idf_metric_nonthread.dir/src/file_metric.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tf_idf_metric_nonthread.dir/src/file_metric.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/anton/dev/techno_park/cpp/task2/tf_idf_metric_nonthread/src/file_metric.c > CMakeFiles/tf_idf_metric_nonthread.dir/src/file_metric.c.i

CMakeFiles/tf_idf_metric_nonthread.dir/src/file_metric.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tf_idf_metric_nonthread.dir/src/file_metric.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/anton/dev/techno_park/cpp/task2/tf_idf_metric_nonthread/src/file_metric.c -o CMakeFiles/tf_idf_metric_nonthread.dir/src/file_metric.c.s

CMakeFiles/tf_idf_metric_nonthread.dir/src/vec.c.o: CMakeFiles/tf_idf_metric_nonthread.dir/flags.make
CMakeFiles/tf_idf_metric_nonthread.dir/src/vec.c.o: ../src/vec.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anton/dev/techno_park/cpp/task2/tf_idf_metric_nonthread/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/tf_idf_metric_nonthread.dir/src/vec.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tf_idf_metric_nonthread.dir/src/vec.c.o   -c /home/anton/dev/techno_park/cpp/task2/tf_idf_metric_nonthread/src/vec.c

CMakeFiles/tf_idf_metric_nonthread.dir/src/vec.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tf_idf_metric_nonthread.dir/src/vec.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/anton/dev/techno_park/cpp/task2/tf_idf_metric_nonthread/src/vec.c > CMakeFiles/tf_idf_metric_nonthread.dir/src/vec.c.i

CMakeFiles/tf_idf_metric_nonthread.dir/src/vec.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tf_idf_metric_nonthread.dir/src/vec.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/anton/dev/techno_park/cpp/task2/tf_idf_metric_nonthread/src/vec.c -o CMakeFiles/tf_idf_metric_nonthread.dir/src/vec.c.s

CMakeFiles/tf_idf_metric_nonthread.dir/src/tf_idf_priority_queue.c.o: CMakeFiles/tf_idf_metric_nonthread.dir/flags.make
CMakeFiles/tf_idf_metric_nonthread.dir/src/tf_idf_priority_queue.c.o: ../src/tf_idf_priority_queue.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anton/dev/techno_park/cpp/task2/tf_idf_metric_nonthread/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/tf_idf_metric_nonthread.dir/src/tf_idf_priority_queue.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/tf_idf_metric_nonthread.dir/src/tf_idf_priority_queue.c.o   -c /home/anton/dev/techno_park/cpp/task2/tf_idf_metric_nonthread/src/tf_idf_priority_queue.c

CMakeFiles/tf_idf_metric_nonthread.dir/src/tf_idf_priority_queue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/tf_idf_metric_nonthread.dir/src/tf_idf_priority_queue.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/anton/dev/techno_park/cpp/task2/tf_idf_metric_nonthread/src/tf_idf_priority_queue.c > CMakeFiles/tf_idf_metric_nonthread.dir/src/tf_idf_priority_queue.c.i

CMakeFiles/tf_idf_metric_nonthread.dir/src/tf_idf_priority_queue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/tf_idf_metric_nonthread.dir/src/tf_idf_priority_queue.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/anton/dev/techno_park/cpp/task2/tf_idf_metric_nonthread/src/tf_idf_priority_queue.c -o CMakeFiles/tf_idf_metric_nonthread.dir/src/tf_idf_priority_queue.c.s

# Object files for target tf_idf_metric_nonthread
tf_idf_metric_nonthread_OBJECTS = \
"CMakeFiles/tf_idf_metric_nonthread.dir/src/main.c.o" \
"CMakeFiles/tf_idf_metric_nonthread.dir/src/str.c.o" \
"CMakeFiles/tf_idf_metric_nonthread.dir/src/str_map.c.o" \
"CMakeFiles/tf_idf_metric_nonthread.dir/src/file_metric.c.o" \
"CMakeFiles/tf_idf_metric_nonthread.dir/src/vec.c.o" \
"CMakeFiles/tf_idf_metric_nonthread.dir/src/tf_idf_priority_queue.c.o"

# External object files for target tf_idf_metric_nonthread
tf_idf_metric_nonthread_EXTERNAL_OBJECTS =

tf_idf_metric_nonthread: CMakeFiles/tf_idf_metric_nonthread.dir/src/main.c.o
tf_idf_metric_nonthread: CMakeFiles/tf_idf_metric_nonthread.dir/src/str.c.o
tf_idf_metric_nonthread: CMakeFiles/tf_idf_metric_nonthread.dir/src/str_map.c.o
tf_idf_metric_nonthread: CMakeFiles/tf_idf_metric_nonthread.dir/src/file_metric.c.o
tf_idf_metric_nonthread: CMakeFiles/tf_idf_metric_nonthread.dir/src/vec.c.o
tf_idf_metric_nonthread: CMakeFiles/tf_idf_metric_nonthread.dir/src/tf_idf_priority_queue.c.o
tf_idf_metric_nonthread: CMakeFiles/tf_idf_metric_nonthread.dir/build.make
tf_idf_metric_nonthread: CMakeFiles/tf_idf_metric_nonthread.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anton/dev/techno_park/cpp/task2/tf_idf_metric_nonthread/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable tf_idf_metric_nonthread"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tf_idf_metric_nonthread.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tf_idf_metric_nonthread.dir/build: tf_idf_metric_nonthread

.PHONY : CMakeFiles/tf_idf_metric_nonthread.dir/build

CMakeFiles/tf_idf_metric_nonthread.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tf_idf_metric_nonthread.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tf_idf_metric_nonthread.dir/clean

CMakeFiles/tf_idf_metric_nonthread.dir/depend:
	cd /home/anton/dev/techno_park/cpp/task2/tf_idf_metric_nonthread/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anton/dev/techno_park/cpp/task2/tf_idf_metric_nonthread /home/anton/dev/techno_park/cpp/task2/tf_idf_metric_nonthread /home/anton/dev/techno_park/cpp/task2/tf_idf_metric_nonthread/cmake-build-debug /home/anton/dev/techno_park/cpp/task2/tf_idf_metric_nonthread/cmake-build-debug /home/anton/dev/techno_park/cpp/task2/tf_idf_metric_nonthread/cmake-build-debug/CMakeFiles/tf_idf_metric_nonthread.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tf_idf_metric_nonthread.dir/depend

