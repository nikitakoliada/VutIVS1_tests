# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/user/Desktop/ivs_project_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/user/Desktop/ivs_project_1/build

# Include any dependencies generated for this target.
include CMakeFiles/white_box_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/white_box_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/white_box_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/white_box_test.dir/flags.make

CMakeFiles/white_box_test.dir/white_box_tests.cpp.o: CMakeFiles/white_box_test.dir/flags.make
CMakeFiles/white_box_test.dir/white_box_tests.cpp.o: ../white_box_tests.cpp
CMakeFiles/white_box_test.dir/white_box_tests.cpp.o: CMakeFiles/white_box_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/user/Desktop/ivs_project_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/white_box_test.dir/white_box_tests.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/white_box_test.dir/white_box_tests.cpp.o -MF CMakeFiles/white_box_test.dir/white_box_tests.cpp.o.d -o CMakeFiles/white_box_test.dir/white_box_tests.cpp.o -c /mnt/c/Users/user/Desktop/ivs_project_1/white_box_tests.cpp

CMakeFiles/white_box_test.dir/white_box_tests.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/white_box_test.dir/white_box_tests.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/user/Desktop/ivs_project_1/white_box_tests.cpp > CMakeFiles/white_box_test.dir/white_box_tests.cpp.i

CMakeFiles/white_box_test.dir/white_box_tests.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/white_box_test.dir/white_box_tests.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/user/Desktop/ivs_project_1/white_box_tests.cpp -o CMakeFiles/white_box_test.dir/white_box_tests.cpp.s

CMakeFiles/white_box_test.dir/white_box_code.cpp.o: CMakeFiles/white_box_test.dir/flags.make
CMakeFiles/white_box_test.dir/white_box_code.cpp.o: ../white_box_code.cpp
CMakeFiles/white_box_test.dir/white_box_code.cpp.o: CMakeFiles/white_box_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/user/Desktop/ivs_project_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/white_box_test.dir/white_box_code.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/white_box_test.dir/white_box_code.cpp.o -MF CMakeFiles/white_box_test.dir/white_box_code.cpp.o.d -o CMakeFiles/white_box_test.dir/white_box_code.cpp.o -c /mnt/c/Users/user/Desktop/ivs_project_1/white_box_code.cpp

CMakeFiles/white_box_test.dir/white_box_code.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/white_box_test.dir/white_box_code.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/user/Desktop/ivs_project_1/white_box_code.cpp > CMakeFiles/white_box_test.dir/white_box_code.cpp.i

CMakeFiles/white_box_test.dir/white_box_code.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/white_box_test.dir/white_box_code.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/user/Desktop/ivs_project_1/white_box_code.cpp -o CMakeFiles/white_box_test.dir/white_box_code.cpp.s

# Object files for target white_box_test
white_box_test_OBJECTS = \
"CMakeFiles/white_box_test.dir/white_box_tests.cpp.o" \
"CMakeFiles/white_box_test.dir/white_box_code.cpp.o"

# External object files for target white_box_test
white_box_test_EXTERNAL_OBJECTS =

white_box_test: CMakeFiles/white_box_test.dir/white_box_tests.cpp.o
white_box_test: CMakeFiles/white_box_test.dir/white_box_code.cpp.o
white_box_test: CMakeFiles/white_box_test.dir/build.make
white_box_test: lib/libgtest_main.a
white_box_test: lib/libgmock_main.a
white_box_test: lib/libgmock.a
white_box_test: lib/libgtest.a
white_box_test: CMakeFiles/white_box_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/user/Desktop/ivs_project_1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable white_box_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/white_box_test.dir/link.txt --verbose=$(VERBOSE)
	/usr/bin/cmake -D TEST_TARGET=white_box_test -D TEST_EXECUTABLE=/mnt/c/Users/user/Desktop/ivs_project_1/build/white_box_test -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/mnt/c/Users/user/Desktop/ivs_project_1/build -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=white_box_test_TESTS -D CTEST_FILE=/mnt/c/Users/user/Desktop/ivs_project_1/build/white_box_test[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /usr/share/cmake-3.22/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
CMakeFiles/white_box_test.dir/build: white_box_test
.PHONY : CMakeFiles/white_box_test.dir/build

CMakeFiles/white_box_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/white_box_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/white_box_test.dir/clean

CMakeFiles/white_box_test.dir/depend:
	cd /mnt/c/Users/user/Desktop/ivs_project_1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/user/Desktop/ivs_project_1 /mnt/c/Users/user/Desktop/ivs_project_1 /mnt/c/Users/user/Desktop/ivs_project_1/build /mnt/c/Users/user/Desktop/ivs_project_1/build /mnt/c/Users/user/Desktop/ivs_project_1/build/CMakeFiles/white_box_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/white_box_test.dir/depend
