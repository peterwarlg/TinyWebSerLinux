# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /home/wangzitu/webserver1/webserver2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/wangzitu/webserver1/webserver2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/webserver.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/webserver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/webserver.dir/flags.make

CMakeFiles/webserver.dir/src/http/HttpRequest.cpp.o: CMakeFiles/webserver.dir/flags.make
CMakeFiles/webserver.dir/src/http/HttpRequest.cpp.o: ../src/http/HttpRequest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wangzitu/webserver1/webserver2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/webserver.dir/src/http/HttpRequest.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webserver.dir/src/http/HttpRequest.cpp.o -c /home/wangzitu/webserver1/webserver2/src/http/HttpRequest.cpp

CMakeFiles/webserver.dir/src/http/HttpRequest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webserver.dir/src/http/HttpRequest.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wangzitu/webserver1/webserver2/src/http/HttpRequest.cpp > CMakeFiles/webserver.dir/src/http/HttpRequest.cpp.i

CMakeFiles/webserver.dir/src/http/HttpRequest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webserver.dir/src/http/HttpRequest.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wangzitu/webserver1/webserver2/src/http/HttpRequest.cpp -o CMakeFiles/webserver.dir/src/http/HttpRequest.cpp.s

CMakeFiles/webserver.dir/src/http/HttpData.cpp.o: CMakeFiles/webserver.dir/flags.make
CMakeFiles/webserver.dir/src/http/HttpData.cpp.o: ../src/http/HttpData.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wangzitu/webserver1/webserver2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/webserver.dir/src/http/HttpData.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webserver.dir/src/http/HttpData.cpp.o -c /home/wangzitu/webserver1/webserver2/src/http/HttpData.cpp

CMakeFiles/webserver.dir/src/http/HttpData.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webserver.dir/src/http/HttpData.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wangzitu/webserver1/webserver2/src/http/HttpData.cpp > CMakeFiles/webserver.dir/src/http/HttpData.cpp.i

CMakeFiles/webserver.dir/src/http/HttpData.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webserver.dir/src/http/HttpData.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wangzitu/webserver1/webserver2/src/http/HttpData.cpp -o CMakeFiles/webserver.dir/src/http/HttpData.cpp.s

CMakeFiles/webserver.dir/src/http/HttpParse.cpp.o: CMakeFiles/webserver.dir/flags.make
CMakeFiles/webserver.dir/src/http/HttpParse.cpp.o: ../src/http/HttpParse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wangzitu/webserver1/webserver2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/webserver.dir/src/http/HttpParse.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webserver.dir/src/http/HttpParse.cpp.o -c /home/wangzitu/webserver1/webserver2/src/http/HttpParse.cpp

CMakeFiles/webserver.dir/src/http/HttpParse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webserver.dir/src/http/HttpParse.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wangzitu/webserver1/webserver2/src/http/HttpParse.cpp > CMakeFiles/webserver.dir/src/http/HttpParse.cpp.i

CMakeFiles/webserver.dir/src/http/HttpParse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webserver.dir/src/http/HttpParse.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wangzitu/webserver1/webserver2/src/http/HttpParse.cpp -o CMakeFiles/webserver.dir/src/http/HttpParse.cpp.s

CMakeFiles/webserver.dir/src/http/HttpResponse.cpp.o: CMakeFiles/webserver.dir/flags.make
CMakeFiles/webserver.dir/src/http/HttpResponse.cpp.o: ../src/http/HttpResponse.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wangzitu/webserver1/webserver2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/webserver.dir/src/http/HttpResponse.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webserver.dir/src/http/HttpResponse.cpp.o -c /home/wangzitu/webserver1/webserver2/src/http/HttpResponse.cpp

CMakeFiles/webserver.dir/src/http/HttpResponse.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webserver.dir/src/http/HttpResponse.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wangzitu/webserver1/webserver2/src/http/HttpResponse.cpp > CMakeFiles/webserver.dir/src/http/HttpResponse.cpp.i

CMakeFiles/webserver.dir/src/http/HttpResponse.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webserver.dir/src/http/HttpResponse.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wangzitu/webserver1/webserver2/src/http/HttpResponse.cpp -o CMakeFiles/webserver.dir/src/http/HttpResponse.cpp.s

CMakeFiles/webserver.dir/src/http/Server.cpp.o: CMakeFiles/webserver.dir/flags.make
CMakeFiles/webserver.dir/src/http/Server.cpp.o: ../src/http/Server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wangzitu/webserver1/webserver2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/webserver.dir/src/http/Server.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webserver.dir/src/http/Server.cpp.o -c /home/wangzitu/webserver1/webserver2/src/http/Server.cpp

CMakeFiles/webserver.dir/src/http/Server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webserver.dir/src/http/Server.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wangzitu/webserver1/webserver2/src/http/Server.cpp > CMakeFiles/webserver.dir/src/http/Server.cpp.i

CMakeFiles/webserver.dir/src/http/Server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webserver.dir/src/http/Server.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wangzitu/webserver1/webserver2/src/http/Server.cpp -o CMakeFiles/webserver.dir/src/http/Server.cpp.s

CMakeFiles/webserver.dir/src/Socket.cpp.o: CMakeFiles/webserver.dir/flags.make
CMakeFiles/webserver.dir/src/Socket.cpp.o: ../src/Socket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wangzitu/webserver1/webserver2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/webserver.dir/src/Socket.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webserver.dir/src/Socket.cpp.o -c /home/wangzitu/webserver1/webserver2/src/Socket.cpp

CMakeFiles/webserver.dir/src/Socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webserver.dir/src/Socket.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wangzitu/webserver1/webserver2/src/Socket.cpp > CMakeFiles/webserver.dir/src/Socket.cpp.i

CMakeFiles/webserver.dir/src/Socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webserver.dir/src/Socket.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wangzitu/webserver1/webserver2/src/Socket.cpp -o CMakeFiles/webserver.dir/src/Socket.cpp.s

CMakeFiles/webserver.dir/src/ThreadPool.cpp.o: CMakeFiles/webserver.dir/flags.make
CMakeFiles/webserver.dir/src/ThreadPool.cpp.o: ../src/ThreadPool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wangzitu/webserver1/webserver2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/webserver.dir/src/ThreadPool.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webserver.dir/src/ThreadPool.cpp.o -c /home/wangzitu/webserver1/webserver2/src/ThreadPool.cpp

CMakeFiles/webserver.dir/src/ThreadPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webserver.dir/src/ThreadPool.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wangzitu/webserver1/webserver2/src/ThreadPool.cpp > CMakeFiles/webserver.dir/src/ThreadPool.cpp.i

CMakeFiles/webserver.dir/src/ThreadPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webserver.dir/src/ThreadPool.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wangzitu/webserver1/webserver2/src/ThreadPool.cpp -o CMakeFiles/webserver.dir/src/ThreadPool.cpp.s

CMakeFiles/webserver.dir/src/Timer.cpp.o: CMakeFiles/webserver.dir/flags.make
CMakeFiles/webserver.dir/src/Timer.cpp.o: ../src/Timer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wangzitu/webserver1/webserver2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/webserver.dir/src/Timer.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webserver.dir/src/Timer.cpp.o -c /home/wangzitu/webserver1/webserver2/src/Timer.cpp

CMakeFiles/webserver.dir/src/Timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webserver.dir/src/Timer.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wangzitu/webserver1/webserver2/src/Timer.cpp > CMakeFiles/webserver.dir/src/Timer.cpp.i

CMakeFiles/webserver.dir/src/Timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webserver.dir/src/Timer.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wangzitu/webserver1/webserver2/src/Timer.cpp -o CMakeFiles/webserver.dir/src/Timer.cpp.s

CMakeFiles/webserver.dir/src/Util.cpp.o: CMakeFiles/webserver.dir/flags.make
CMakeFiles/webserver.dir/src/Util.cpp.o: ../src/Util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wangzitu/webserver1/webserver2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/webserver.dir/src/Util.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webserver.dir/src/Util.cpp.o -c /home/wangzitu/webserver1/webserver2/src/Util.cpp

CMakeFiles/webserver.dir/src/Util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webserver.dir/src/Util.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wangzitu/webserver1/webserver2/src/Util.cpp > CMakeFiles/webserver.dir/src/Util.cpp.i

CMakeFiles/webserver.dir/src/Util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webserver.dir/src/Util.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wangzitu/webserver1/webserver2/src/Util.cpp -o CMakeFiles/webserver.dir/src/Util.cpp.s

CMakeFiles/webserver.dir/src/Epoll.cpp.o: CMakeFiles/webserver.dir/flags.make
CMakeFiles/webserver.dir/src/Epoll.cpp.o: ../src/Epoll.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wangzitu/webserver1/webserver2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/webserver.dir/src/Epoll.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webserver.dir/src/Epoll.cpp.o -c /home/wangzitu/webserver1/webserver2/src/Epoll.cpp

CMakeFiles/webserver.dir/src/Epoll.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webserver.dir/src/Epoll.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wangzitu/webserver1/webserver2/src/Epoll.cpp > CMakeFiles/webserver.dir/src/Epoll.cpp.i

CMakeFiles/webserver.dir/src/Epoll.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webserver.dir/src/Epoll.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wangzitu/webserver1/webserver2/src/Epoll.cpp -o CMakeFiles/webserver.dir/src/Epoll.cpp.s

CMakeFiles/webserver.dir/src/main.cpp.o: CMakeFiles/webserver.dir/flags.make
CMakeFiles/webserver.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/wangzitu/webserver1/webserver2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/webserver.dir/src/main.cpp.o"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/webserver.dir/src/main.cpp.o -c /home/wangzitu/webserver1/webserver2/src/main.cpp

CMakeFiles/webserver.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/webserver.dir/src/main.cpp.i"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/wangzitu/webserver1/webserver2/src/main.cpp > CMakeFiles/webserver.dir/src/main.cpp.i

CMakeFiles/webserver.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/webserver.dir/src/main.cpp.s"
	g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/wangzitu/webserver1/webserver2/src/main.cpp -o CMakeFiles/webserver.dir/src/main.cpp.s

# Object files for target webserver
webserver_OBJECTS = \
"CMakeFiles/webserver.dir/src/http/HttpRequest.cpp.o" \
"CMakeFiles/webserver.dir/src/http/HttpData.cpp.o" \
"CMakeFiles/webserver.dir/src/http/HttpParse.cpp.o" \
"CMakeFiles/webserver.dir/src/http/HttpResponse.cpp.o" \
"CMakeFiles/webserver.dir/src/http/Server.cpp.o" \
"CMakeFiles/webserver.dir/src/Socket.cpp.o" \
"CMakeFiles/webserver.dir/src/ThreadPool.cpp.o" \
"CMakeFiles/webserver.dir/src/Timer.cpp.o" \
"CMakeFiles/webserver.dir/src/Util.cpp.o" \
"CMakeFiles/webserver.dir/src/Epoll.cpp.o" \
"CMakeFiles/webserver.dir/src/main.cpp.o"

# External object files for target webserver
webserver_EXTERNAL_OBJECTS =

webserver: CMakeFiles/webserver.dir/src/http/HttpRequest.cpp.o
webserver: CMakeFiles/webserver.dir/src/http/HttpData.cpp.o
webserver: CMakeFiles/webserver.dir/src/http/HttpParse.cpp.o
webserver: CMakeFiles/webserver.dir/src/http/HttpResponse.cpp.o
webserver: CMakeFiles/webserver.dir/src/http/Server.cpp.o
webserver: CMakeFiles/webserver.dir/src/Socket.cpp.o
webserver: CMakeFiles/webserver.dir/src/ThreadPool.cpp.o
webserver: CMakeFiles/webserver.dir/src/Timer.cpp.o
webserver: CMakeFiles/webserver.dir/src/Util.cpp.o
webserver: CMakeFiles/webserver.dir/src/Epoll.cpp.o
webserver: CMakeFiles/webserver.dir/src/main.cpp.o
webserver: CMakeFiles/webserver.dir/build.make
webserver: CMakeFiles/webserver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/wangzitu/webserver1/webserver2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX executable webserver"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/webserver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/webserver.dir/build: webserver

.PHONY : CMakeFiles/webserver.dir/build

CMakeFiles/webserver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/webserver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/webserver.dir/clean

CMakeFiles/webserver.dir/depend:
	cd /home/wangzitu/webserver1/webserver2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/wangzitu/webserver1/webserver2 /home/wangzitu/webserver1/webserver2 /home/wangzitu/webserver1/webserver2/cmake-build-debug /home/wangzitu/webserver1/webserver2/cmake-build-debug /home/wangzitu/webserver1/webserver2/cmake-build-debug/CMakeFiles/webserver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/webserver.dir/depend

