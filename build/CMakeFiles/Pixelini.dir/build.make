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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.17.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.17.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/leilei/Documents/CPlus/Develop-branch/Pixelini

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/build

# Include any dependencies generated for this target.
include CMakeFiles/Pixelini.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Pixelini.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Pixelini.dir/flags.make

CMakeFiles/Pixelini.dir/src/bmp/bmp.cpp.o: CMakeFiles/Pixelini.dir/flags.make
CMakeFiles/Pixelini.dir/src/bmp/bmp.cpp.o: ../src/bmp/bmp.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/leilei/Documents/CPlus/Develop-branch/Pixelini/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Pixelini.dir/src/bmp/bmp.cpp.o"
	clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pixelini.dir/src/bmp/bmp.cpp.o -c /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/bmp/bmp.cpp

CMakeFiles/Pixelini.dir/src/bmp/bmp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pixelini.dir/src/bmp/bmp.cpp.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/bmp/bmp.cpp > CMakeFiles/Pixelini.dir/src/bmp/bmp.cpp.i

CMakeFiles/Pixelini.dir/src/bmp/bmp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pixelini.dir/src/bmp/bmp.cpp.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/bmp/bmp.cpp -o CMakeFiles/Pixelini.dir/src/bmp/bmp.cpp.s

CMakeFiles/Pixelini.dir/src/files/exception.cpp.o: CMakeFiles/Pixelini.dir/flags.make
CMakeFiles/Pixelini.dir/src/files/exception.cpp.o: ../src/files/exception.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/leilei/Documents/CPlus/Develop-branch/Pixelini/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Pixelini.dir/src/files/exception.cpp.o"
	clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pixelini.dir/src/files/exception.cpp.o -c /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/files/exception.cpp

CMakeFiles/Pixelini.dir/src/files/exception.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pixelini.dir/src/files/exception.cpp.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/files/exception.cpp > CMakeFiles/Pixelini.dir/src/files/exception.cpp.i

CMakeFiles/Pixelini.dir/src/files/exception.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pixelini.dir/src/files/exception.cpp.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/files/exception.cpp -o CMakeFiles/Pixelini.dir/src/files/exception.cpp.s

CMakeFiles/Pixelini.dir/src/files/loader.cpp.o: CMakeFiles/Pixelini.dir/flags.make
CMakeFiles/Pixelini.dir/src/files/loader.cpp.o: ../src/files/loader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/leilei/Documents/CPlus/Develop-branch/Pixelini/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Pixelini.dir/src/files/loader.cpp.o"
	clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pixelini.dir/src/files/loader.cpp.o -c /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/files/loader.cpp

CMakeFiles/Pixelini.dir/src/files/loader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pixelini.dir/src/files/loader.cpp.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/files/loader.cpp > CMakeFiles/Pixelini.dir/src/files/loader.cpp.i

CMakeFiles/Pixelini.dir/src/files/loader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pixelini.dir/src/files/loader.cpp.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/files/loader.cpp -o CMakeFiles/Pixelini.dir/src/files/loader.cpp.s

CMakeFiles/Pixelini.dir/src/files/writer.cpp.o: CMakeFiles/Pixelini.dir/flags.make
CMakeFiles/Pixelini.dir/src/files/writer.cpp.o: ../src/files/writer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/leilei/Documents/CPlus/Develop-branch/Pixelini/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Pixelini.dir/src/files/writer.cpp.o"
	clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pixelini.dir/src/files/writer.cpp.o -c /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/files/writer.cpp

CMakeFiles/Pixelini.dir/src/files/writer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pixelini.dir/src/files/writer.cpp.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/files/writer.cpp > CMakeFiles/Pixelini.dir/src/files/writer.cpp.i

CMakeFiles/Pixelini.dir/src/files/writer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pixelini.dir/src/files/writer.cpp.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/files/writer.cpp -o CMakeFiles/Pixelini.dir/src/files/writer.cpp.s

CMakeFiles/Pixelini.dir/src/filters/filter.cpp.o: CMakeFiles/Pixelini.dir/flags.make
CMakeFiles/Pixelini.dir/src/filters/filter.cpp.o: ../src/filters/filter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/leilei/Documents/CPlus/Develop-branch/Pixelini/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Pixelini.dir/src/filters/filter.cpp.o"
	clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pixelini.dir/src/filters/filter.cpp.o -c /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/filters/filter.cpp

CMakeFiles/Pixelini.dir/src/filters/filter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pixelini.dir/src/filters/filter.cpp.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/filters/filter.cpp > CMakeFiles/Pixelini.dir/src/filters/filter.cpp.i

CMakeFiles/Pixelini.dir/src/filters/filter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pixelini.dir/src/filters/filter.cpp.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/filters/filter.cpp -o CMakeFiles/Pixelini.dir/src/filters/filter.cpp.s

CMakeFiles/Pixelini.dir/src/filters/grayScale.cpp.o: CMakeFiles/Pixelini.dir/flags.make
CMakeFiles/Pixelini.dir/src/filters/grayScale.cpp.o: ../src/filters/grayScale.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/leilei/Documents/CPlus/Develop-branch/Pixelini/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Pixelini.dir/src/filters/grayScale.cpp.o"
	clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pixelini.dir/src/filters/grayScale.cpp.o -c /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/filters/grayScale.cpp

CMakeFiles/Pixelini.dir/src/filters/grayScale.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pixelini.dir/src/filters/grayScale.cpp.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/filters/grayScale.cpp > CMakeFiles/Pixelini.dir/src/filters/grayScale.cpp.i

CMakeFiles/Pixelini.dir/src/filters/grayScale.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pixelini.dir/src/filters/grayScale.cpp.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/filters/grayScale.cpp -o CMakeFiles/Pixelini.dir/src/filters/grayScale.cpp.s

CMakeFiles/Pixelini.dir/src/filters/histogram.cpp.o: CMakeFiles/Pixelini.dir/flags.make
CMakeFiles/Pixelini.dir/src/filters/histogram.cpp.o: ../src/filters/histogram.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/leilei/Documents/CPlus/Develop-branch/Pixelini/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Pixelini.dir/src/filters/histogram.cpp.o"
	clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pixelini.dir/src/filters/histogram.cpp.o -c /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/filters/histogram.cpp

CMakeFiles/Pixelini.dir/src/filters/histogram.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pixelini.dir/src/filters/histogram.cpp.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/filters/histogram.cpp > CMakeFiles/Pixelini.dir/src/filters/histogram.cpp.i

CMakeFiles/Pixelini.dir/src/filters/histogram.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pixelini.dir/src/filters/histogram.cpp.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/filters/histogram.cpp -o CMakeFiles/Pixelini.dir/src/filters/histogram.cpp.s

CMakeFiles/Pixelini.dir/src/filters/smoothing.cpp.o: CMakeFiles/Pixelini.dir/flags.make
CMakeFiles/Pixelini.dir/src/filters/smoothing.cpp.o: ../src/filters/smoothing.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/leilei/Documents/CPlus/Develop-branch/Pixelini/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Pixelini.dir/src/filters/smoothing.cpp.o"
	clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pixelini.dir/src/filters/smoothing.cpp.o -c /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/filters/smoothing.cpp

CMakeFiles/Pixelini.dir/src/filters/smoothing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pixelini.dir/src/filters/smoothing.cpp.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/filters/smoothing.cpp > CMakeFiles/Pixelini.dir/src/filters/smoothing.cpp.i

CMakeFiles/Pixelini.dir/src/filters/smoothing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pixelini.dir/src/filters/smoothing.cpp.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/filters/smoothing.cpp -o CMakeFiles/Pixelini.dir/src/filters/smoothing.cpp.s

CMakeFiles/Pixelini.dir/src/filters/sobel.cpp.o: CMakeFiles/Pixelini.dir/flags.make
CMakeFiles/Pixelini.dir/src/filters/sobel.cpp.o: ../src/filters/sobel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/leilei/Documents/CPlus/Develop-branch/Pixelini/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Pixelini.dir/src/filters/sobel.cpp.o"
	clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pixelini.dir/src/filters/sobel.cpp.o -c /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/filters/sobel.cpp

CMakeFiles/Pixelini.dir/src/filters/sobel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pixelini.dir/src/filters/sobel.cpp.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/filters/sobel.cpp > CMakeFiles/Pixelini.dir/src/filters/sobel.cpp.i

CMakeFiles/Pixelini.dir/src/filters/sobel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pixelini.dir/src/filters/sobel.cpp.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/filters/sobel.cpp -o CMakeFiles/Pixelini.dir/src/filters/sobel.cpp.s

CMakeFiles/Pixelini.dir/src/image/image.cpp.o: CMakeFiles/Pixelini.dir/flags.make
CMakeFiles/Pixelini.dir/src/image/image.cpp.o: ../src/image/image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/leilei/Documents/CPlus/Develop-branch/Pixelini/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Pixelini.dir/src/image/image.cpp.o"
	clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pixelini.dir/src/image/image.cpp.o -c /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/image/image.cpp

CMakeFiles/Pixelini.dir/src/image/image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pixelini.dir/src/image/image.cpp.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/image/image.cpp > CMakeFiles/Pixelini.dir/src/image/image.cpp.i

CMakeFiles/Pixelini.dir/src/image/image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pixelini.dir/src/image/image.cpp.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/image/image.cpp -o CMakeFiles/Pixelini.dir/src/image/image.cpp.s

CMakeFiles/Pixelini.dir/src/main.cpp.o: CMakeFiles/Pixelini.dir/flags.make
CMakeFiles/Pixelini.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/leilei/Documents/CPlus/Develop-branch/Pixelini/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Pixelini.dir/src/main.cpp.o"
	clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pixelini.dir/src/main.cpp.o -c /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/main.cpp

CMakeFiles/Pixelini.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pixelini.dir/src/main.cpp.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/main.cpp > CMakeFiles/Pixelini.dir/src/main.cpp.i

CMakeFiles/Pixelini.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pixelini.dir/src/main.cpp.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/main.cpp -o CMakeFiles/Pixelini.dir/src/main.cpp.s

CMakeFiles/Pixelini.dir/src/png/png.cpp.o: CMakeFiles/Pixelini.dir/flags.make
CMakeFiles/Pixelini.dir/src/png/png.cpp.o: ../src/png/png.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/leilei/Documents/CPlus/Develop-branch/Pixelini/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Pixelini.dir/src/png/png.cpp.o"
	clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Pixelini.dir/src/png/png.cpp.o -c /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/png/png.cpp

CMakeFiles/Pixelini.dir/src/png/png.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Pixelini.dir/src/png/png.cpp.i"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/png/png.cpp > CMakeFiles/Pixelini.dir/src/png/png.cpp.i

CMakeFiles/Pixelini.dir/src/png/png.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Pixelini.dir/src/png/png.cpp.s"
	clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/src/png/png.cpp -o CMakeFiles/Pixelini.dir/src/png/png.cpp.s

# Object files for target Pixelini
Pixelini_OBJECTS = \
"CMakeFiles/Pixelini.dir/src/bmp/bmp.cpp.o" \
"CMakeFiles/Pixelini.dir/src/files/exception.cpp.o" \
"CMakeFiles/Pixelini.dir/src/files/loader.cpp.o" \
"CMakeFiles/Pixelini.dir/src/files/writer.cpp.o" \
"CMakeFiles/Pixelini.dir/src/filters/filter.cpp.o" \
"CMakeFiles/Pixelini.dir/src/filters/grayScale.cpp.o" \
"CMakeFiles/Pixelini.dir/src/filters/histogram.cpp.o" \
"CMakeFiles/Pixelini.dir/src/filters/smoothing.cpp.o" \
"CMakeFiles/Pixelini.dir/src/filters/sobel.cpp.o" \
"CMakeFiles/Pixelini.dir/src/image/image.cpp.o" \
"CMakeFiles/Pixelini.dir/src/main.cpp.o" \
"CMakeFiles/Pixelini.dir/src/png/png.cpp.o"

# External object files for target Pixelini
Pixelini_EXTERNAL_OBJECTS =

Pixelini: CMakeFiles/Pixelini.dir/src/bmp/bmp.cpp.o
Pixelini: CMakeFiles/Pixelini.dir/src/files/exception.cpp.o
Pixelini: CMakeFiles/Pixelini.dir/src/files/loader.cpp.o
Pixelini: CMakeFiles/Pixelini.dir/src/files/writer.cpp.o
Pixelini: CMakeFiles/Pixelini.dir/src/filters/filter.cpp.o
Pixelini: CMakeFiles/Pixelini.dir/src/filters/grayScale.cpp.o
Pixelini: CMakeFiles/Pixelini.dir/src/filters/histogram.cpp.o
Pixelini: CMakeFiles/Pixelini.dir/src/filters/smoothing.cpp.o
Pixelini: CMakeFiles/Pixelini.dir/src/filters/sobel.cpp.o
Pixelini: CMakeFiles/Pixelini.dir/src/image/image.cpp.o
Pixelini: CMakeFiles/Pixelini.dir/src/main.cpp.o
Pixelini: CMakeFiles/Pixelini.dir/src/png/png.cpp.o
Pixelini: CMakeFiles/Pixelini.dir/build.make
Pixelini: CMakeFiles/Pixelini.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/leilei/Documents/CPlus/Develop-branch/Pixelini/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Linking CXX executable Pixelini"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Pixelini.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Pixelini.dir/build: Pixelini

.PHONY : CMakeFiles/Pixelini.dir/build

CMakeFiles/Pixelini.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Pixelini.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Pixelini.dir/clean

CMakeFiles/Pixelini.dir/depend:
	cd /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/leilei/Documents/CPlus/Develop-branch/Pixelini /Users/leilei/Documents/CPlus/Develop-branch/Pixelini /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/build /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/build /Users/leilei/Documents/CPlus/Develop-branch/Pixelini/build/CMakeFiles/Pixelini.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Pixelini.dir/depend

