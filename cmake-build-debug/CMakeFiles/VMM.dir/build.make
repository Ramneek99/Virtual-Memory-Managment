# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/rimmyaulakh/CLionProjects/VMM

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rimmyaulakh/CLionProjects/VMM/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/VMM.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/VMM.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/VMM.dir/flags.make

CMakeFiles/VMM.dir/main.cpp.o: CMakeFiles/VMM.dir/flags.make
CMakeFiles/VMM.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rimmyaulakh/CLionProjects/VMM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/VMM.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VMM.dir/main.cpp.o -c /Users/rimmyaulakh/CLionProjects/VMM/main.cpp

CMakeFiles/VMM.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VMM.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rimmyaulakh/CLionProjects/VMM/main.cpp > CMakeFiles/VMM.dir/main.cpp.i

CMakeFiles/VMM.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VMM.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rimmyaulakh/CLionProjects/VMM/main.cpp -o CMakeFiles/VMM.dir/main.cpp.s

CMakeFiles/VMM.dir/Process.cpp.o: CMakeFiles/VMM.dir/flags.make
CMakeFiles/VMM.dir/Process.cpp.o: ../Process.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rimmyaulakh/CLionProjects/VMM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/VMM.dir/Process.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VMM.dir/Process.cpp.o -c /Users/rimmyaulakh/CLionProjects/VMM/Process.cpp

CMakeFiles/VMM.dir/Process.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VMM.dir/Process.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rimmyaulakh/CLionProjects/VMM/Process.cpp > CMakeFiles/VMM.dir/Process.cpp.i

CMakeFiles/VMM.dir/Process.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VMM.dir/Process.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rimmyaulakh/CLionProjects/VMM/Process.cpp -o CMakeFiles/VMM.dir/Process.cpp.s

CMakeFiles/VMM.dir/Vmas.cpp.o: CMakeFiles/VMM.dir/flags.make
CMakeFiles/VMM.dir/Vmas.cpp.o: ../Vmas.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rimmyaulakh/CLionProjects/VMM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/VMM.dir/Vmas.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VMM.dir/Vmas.cpp.o -c /Users/rimmyaulakh/CLionProjects/VMM/Vmas.cpp

CMakeFiles/VMM.dir/Vmas.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VMM.dir/Vmas.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rimmyaulakh/CLionProjects/VMM/Vmas.cpp > CMakeFiles/VMM.dir/Vmas.cpp.i

CMakeFiles/VMM.dir/Vmas.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VMM.dir/Vmas.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rimmyaulakh/CLionProjects/VMM/Vmas.cpp -o CMakeFiles/VMM.dir/Vmas.cpp.s

CMakeFiles/VMM.dir/PageTable.cpp.o: CMakeFiles/VMM.dir/flags.make
CMakeFiles/VMM.dir/PageTable.cpp.o: ../PageTable.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rimmyaulakh/CLionProjects/VMM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/VMM.dir/PageTable.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VMM.dir/PageTable.cpp.o -c /Users/rimmyaulakh/CLionProjects/VMM/PageTable.cpp

CMakeFiles/VMM.dir/PageTable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VMM.dir/PageTable.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rimmyaulakh/CLionProjects/VMM/PageTable.cpp > CMakeFiles/VMM.dir/PageTable.cpp.i

CMakeFiles/VMM.dir/PageTable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VMM.dir/PageTable.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rimmyaulakh/CLionProjects/VMM/PageTable.cpp -o CMakeFiles/VMM.dir/PageTable.cpp.s

CMakeFiles/VMM.dir/Frame.cpp.o: CMakeFiles/VMM.dir/flags.make
CMakeFiles/VMM.dir/Frame.cpp.o: ../Frame.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rimmyaulakh/CLionProjects/VMM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/VMM.dir/Frame.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VMM.dir/Frame.cpp.o -c /Users/rimmyaulakh/CLionProjects/VMM/Frame.cpp

CMakeFiles/VMM.dir/Frame.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VMM.dir/Frame.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rimmyaulakh/CLionProjects/VMM/Frame.cpp > CMakeFiles/VMM.dir/Frame.cpp.i

CMakeFiles/VMM.dir/Frame.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VMM.dir/Frame.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rimmyaulakh/CLionProjects/VMM/Frame.cpp -o CMakeFiles/VMM.dir/Frame.cpp.s

CMakeFiles/VMM.dir/Pager.cpp.o: CMakeFiles/VMM.dir/flags.make
CMakeFiles/VMM.dir/Pager.cpp.o: ../Pager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rimmyaulakh/CLionProjects/VMM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/VMM.dir/Pager.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VMM.dir/Pager.cpp.o -c /Users/rimmyaulakh/CLionProjects/VMM/Pager.cpp

CMakeFiles/VMM.dir/Pager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VMM.dir/Pager.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rimmyaulakh/CLionProjects/VMM/Pager.cpp > CMakeFiles/VMM.dir/Pager.cpp.i

CMakeFiles/VMM.dir/Pager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VMM.dir/Pager.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rimmyaulakh/CLionProjects/VMM/Pager.cpp -o CMakeFiles/VMM.dir/Pager.cpp.s

CMakeFiles/VMM.dir/Fifo.cpp.o: CMakeFiles/VMM.dir/flags.make
CMakeFiles/VMM.dir/Fifo.cpp.o: ../Fifo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rimmyaulakh/CLionProjects/VMM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/VMM.dir/Fifo.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VMM.dir/Fifo.cpp.o -c /Users/rimmyaulakh/CLionProjects/VMM/Fifo.cpp

CMakeFiles/VMM.dir/Fifo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VMM.dir/Fifo.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rimmyaulakh/CLionProjects/VMM/Fifo.cpp > CMakeFiles/VMM.dir/Fifo.cpp.i

CMakeFiles/VMM.dir/Fifo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VMM.dir/Fifo.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rimmyaulakh/CLionProjects/VMM/Fifo.cpp -o CMakeFiles/VMM.dir/Fifo.cpp.s

CMakeFiles/VMM.dir/Random.cpp.o: CMakeFiles/VMM.dir/flags.make
CMakeFiles/VMM.dir/Random.cpp.o: ../Random.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rimmyaulakh/CLionProjects/VMM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/VMM.dir/Random.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VMM.dir/Random.cpp.o -c /Users/rimmyaulakh/CLionProjects/VMM/Random.cpp

CMakeFiles/VMM.dir/Random.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VMM.dir/Random.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rimmyaulakh/CLionProjects/VMM/Random.cpp > CMakeFiles/VMM.dir/Random.cpp.i

CMakeFiles/VMM.dir/Random.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VMM.dir/Random.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rimmyaulakh/CLionProjects/VMM/Random.cpp -o CMakeFiles/VMM.dir/Random.cpp.s

CMakeFiles/VMM.dir/Clock.cpp.o: CMakeFiles/VMM.dir/flags.make
CMakeFiles/VMM.dir/Clock.cpp.o: ../Clock.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rimmyaulakh/CLionProjects/VMM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/VMM.dir/Clock.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VMM.dir/Clock.cpp.o -c /Users/rimmyaulakh/CLionProjects/VMM/Clock.cpp

CMakeFiles/VMM.dir/Clock.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VMM.dir/Clock.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rimmyaulakh/CLionProjects/VMM/Clock.cpp > CMakeFiles/VMM.dir/Clock.cpp.i

CMakeFiles/VMM.dir/Clock.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VMM.dir/Clock.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rimmyaulakh/CLionProjects/VMM/Clock.cpp -o CMakeFiles/VMM.dir/Clock.cpp.s

CMakeFiles/VMM.dir/NRU.cpp.o: CMakeFiles/VMM.dir/flags.make
CMakeFiles/VMM.dir/NRU.cpp.o: ../NRU.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rimmyaulakh/CLionProjects/VMM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/VMM.dir/NRU.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VMM.dir/NRU.cpp.o -c /Users/rimmyaulakh/CLionProjects/VMM/NRU.cpp

CMakeFiles/VMM.dir/NRU.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VMM.dir/NRU.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rimmyaulakh/CLionProjects/VMM/NRU.cpp > CMakeFiles/VMM.dir/NRU.cpp.i

CMakeFiles/VMM.dir/NRU.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VMM.dir/NRU.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rimmyaulakh/CLionProjects/VMM/NRU.cpp -o CMakeFiles/VMM.dir/NRU.cpp.s

CMakeFiles/VMM.dir/Aging.cpp.o: CMakeFiles/VMM.dir/flags.make
CMakeFiles/VMM.dir/Aging.cpp.o: ../Aging.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rimmyaulakh/CLionProjects/VMM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/VMM.dir/Aging.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VMM.dir/Aging.cpp.o -c /Users/rimmyaulakh/CLionProjects/VMM/Aging.cpp

CMakeFiles/VMM.dir/Aging.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VMM.dir/Aging.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rimmyaulakh/CLionProjects/VMM/Aging.cpp > CMakeFiles/VMM.dir/Aging.cpp.i

CMakeFiles/VMM.dir/Aging.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VMM.dir/Aging.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rimmyaulakh/CLionProjects/VMM/Aging.cpp -o CMakeFiles/VMM.dir/Aging.cpp.s

CMakeFiles/VMM.dir/WorkingSet.cpp.o: CMakeFiles/VMM.dir/flags.make
CMakeFiles/VMM.dir/WorkingSet.cpp.o: ../WorkingSet.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rimmyaulakh/CLionProjects/VMM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/VMM.dir/WorkingSet.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VMM.dir/WorkingSet.cpp.o -c /Users/rimmyaulakh/CLionProjects/VMM/WorkingSet.cpp

CMakeFiles/VMM.dir/WorkingSet.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VMM.dir/WorkingSet.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rimmyaulakh/CLionProjects/VMM/WorkingSet.cpp > CMakeFiles/VMM.dir/WorkingSet.cpp.i

CMakeFiles/VMM.dir/WorkingSet.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VMM.dir/WorkingSet.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rimmyaulakh/CLionProjects/VMM/WorkingSet.cpp -o CMakeFiles/VMM.dir/WorkingSet.cpp.s

# Object files for target VMM
VMM_OBJECTS = \
"CMakeFiles/VMM.dir/main.cpp.o" \
"CMakeFiles/VMM.dir/Process.cpp.o" \
"CMakeFiles/VMM.dir/Vmas.cpp.o" \
"CMakeFiles/VMM.dir/PageTable.cpp.o" \
"CMakeFiles/VMM.dir/Frame.cpp.o" \
"CMakeFiles/VMM.dir/Pager.cpp.o" \
"CMakeFiles/VMM.dir/Fifo.cpp.o" \
"CMakeFiles/VMM.dir/Random.cpp.o" \
"CMakeFiles/VMM.dir/Clock.cpp.o" \
"CMakeFiles/VMM.dir/NRU.cpp.o" \
"CMakeFiles/VMM.dir/Aging.cpp.o" \
"CMakeFiles/VMM.dir/WorkingSet.cpp.o"

# External object files for target VMM
VMM_EXTERNAL_OBJECTS =

VMM: CMakeFiles/VMM.dir/main.cpp.o
VMM: CMakeFiles/VMM.dir/Process.cpp.o
VMM: CMakeFiles/VMM.dir/Vmas.cpp.o
VMM: CMakeFiles/VMM.dir/PageTable.cpp.o
VMM: CMakeFiles/VMM.dir/Frame.cpp.o
VMM: CMakeFiles/VMM.dir/Pager.cpp.o
VMM: CMakeFiles/VMM.dir/Fifo.cpp.o
VMM: CMakeFiles/VMM.dir/Random.cpp.o
VMM: CMakeFiles/VMM.dir/Clock.cpp.o
VMM: CMakeFiles/VMM.dir/NRU.cpp.o
VMM: CMakeFiles/VMM.dir/Aging.cpp.o
VMM: CMakeFiles/VMM.dir/WorkingSet.cpp.o
VMM: CMakeFiles/VMM.dir/build.make
VMM: CMakeFiles/VMM.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/rimmyaulakh/CLionProjects/VMM/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable VMM"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/VMM.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/VMM.dir/build: VMM

.PHONY : CMakeFiles/VMM.dir/build

CMakeFiles/VMM.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/VMM.dir/cmake_clean.cmake
.PHONY : CMakeFiles/VMM.dir/clean

CMakeFiles/VMM.dir/depend:
	cd /Users/rimmyaulakh/CLionProjects/VMM/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rimmyaulakh/CLionProjects/VMM /Users/rimmyaulakh/CLionProjects/VMM /Users/rimmyaulakh/CLionProjects/VMM/cmake-build-debug /Users/rimmyaulakh/CLionProjects/VMM/cmake-build-debug /Users/rimmyaulakh/CLionProjects/VMM/cmake-build-debug/CMakeFiles/VMM.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/VMM.dir/depend

