# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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

# Produce verbose output by default.
VERBOSE = 1

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/holo/git/Server_Framework

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/holo/git/Server_Framework

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/holo/git/Server_Framework/CMakeFiles /home/holo/git/Server_Framework//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/holo/git/Server_Framework/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named test_fiber

# Build rule for target.
test_fiber: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 test_fiber
.PHONY : test_fiber

# fast build rule for target.
test_fiber/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_fiber.dir/build.make CMakeFiles/test_fiber.dir/build
.PHONY : test_fiber/fast

#=============================================================================
# Target rules for targets named test_util

# Build rule for target.
test_util: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 test_util
.PHONY : test_util

# fast build rule for target.
test_util/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_util.dir/build.make CMakeFiles/test_util.dir/build
.PHONY : test_util/fast

#=============================================================================
# Target rules for targets named test_config

# Build rule for target.
test_config: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 test_config
.PHONY : test_config

# fast build rule for target.
test_config/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_config.dir/build.make CMakeFiles/test_config.dir/build
.PHONY : test_config/fast

#=============================================================================
# Target rules for targets named test_thread

# Build rule for target.
test_thread: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 test_thread
.PHONY : test_thread

# fast build rule for target.
test_thread/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_thread.dir/build.make CMakeFiles/test_thread.dir/build
.PHONY : test_thread/fast

#=============================================================================
# Target rules for targets named test

# Build rule for target.
test: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 test
.PHONY : test

# fast build rule for target.
test/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/build
.PHONY : test/fast

#=============================================================================
# Target rules for targets named test_scheduler

# Build rule for target.
test_scheduler: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 test_scheduler
.PHONY : test_scheduler

# fast build rule for target.
test_scheduler/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_scheduler.dir/build.make CMakeFiles/test_scheduler.dir/build
.PHONY : test_scheduler/fast

#=============================================================================
# Target rules for targets named MSF

# Build rule for target.
MSF: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 MSF
.PHONY : MSF

# fast build rule for target.
MSF/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MSF.dir/build.make CMakeFiles/MSF.dir/build
.PHONY : MSF/fast

MSF/config.o: MSF/config.cc.o
.PHONY : MSF/config.o

# target to build an object file
MSF/config.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MSF.dir/build.make CMakeFiles/MSF.dir/MSF/config.cc.o
.PHONY : MSF/config.cc.o

MSF/config.i: MSF/config.cc.i
.PHONY : MSF/config.i

# target to preprocess a source file
MSF/config.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MSF.dir/build.make CMakeFiles/MSF.dir/MSF/config.cc.i
.PHONY : MSF/config.cc.i

MSF/config.s: MSF/config.cc.s
.PHONY : MSF/config.s

# target to generate assembly for a file
MSF/config.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MSF.dir/build.make CMakeFiles/MSF.dir/MSF/config.cc.s
.PHONY : MSF/config.cc.s

MSF/fiber.o: MSF/fiber.cc.o
.PHONY : MSF/fiber.o

# target to build an object file
MSF/fiber.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MSF.dir/build.make CMakeFiles/MSF.dir/MSF/fiber.cc.o
.PHONY : MSF/fiber.cc.o

MSF/fiber.i: MSF/fiber.cc.i
.PHONY : MSF/fiber.i

# target to preprocess a source file
MSF/fiber.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MSF.dir/build.make CMakeFiles/MSF.dir/MSF/fiber.cc.i
.PHONY : MSF/fiber.cc.i

MSF/fiber.s: MSF/fiber.cc.s
.PHONY : MSF/fiber.s

# target to generate assembly for a file
MSF/fiber.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MSF.dir/build.make CMakeFiles/MSF.dir/MSF/fiber.cc.s
.PHONY : MSF/fiber.cc.s

MSF/log.o: MSF/log.cc.o
.PHONY : MSF/log.o

# target to build an object file
MSF/log.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MSF.dir/build.make CMakeFiles/MSF.dir/MSF/log.cc.o
.PHONY : MSF/log.cc.o

MSF/log.i: MSF/log.cc.i
.PHONY : MSF/log.i

# target to preprocess a source file
MSF/log.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MSF.dir/build.make CMakeFiles/MSF.dir/MSF/log.cc.i
.PHONY : MSF/log.cc.i

MSF/log.s: MSF/log.cc.s
.PHONY : MSF/log.s

# target to generate assembly for a file
MSF/log.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MSF.dir/build.make CMakeFiles/MSF.dir/MSF/log.cc.s
.PHONY : MSF/log.cc.s

MSF/scheduler.o: MSF/scheduler.cc.o
.PHONY : MSF/scheduler.o

# target to build an object file
MSF/scheduler.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MSF.dir/build.make CMakeFiles/MSF.dir/MSF/scheduler.cc.o
.PHONY : MSF/scheduler.cc.o

MSF/scheduler.i: MSF/scheduler.cc.i
.PHONY : MSF/scheduler.i

# target to preprocess a source file
MSF/scheduler.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MSF.dir/build.make CMakeFiles/MSF.dir/MSF/scheduler.cc.i
.PHONY : MSF/scheduler.cc.i

MSF/scheduler.s: MSF/scheduler.cc.s
.PHONY : MSF/scheduler.s

# target to generate assembly for a file
MSF/scheduler.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MSF.dir/build.make CMakeFiles/MSF.dir/MSF/scheduler.cc.s
.PHONY : MSF/scheduler.cc.s

MSF/thread.o: MSF/thread.cc.o
.PHONY : MSF/thread.o

# target to build an object file
MSF/thread.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MSF.dir/build.make CMakeFiles/MSF.dir/MSF/thread.cc.o
.PHONY : MSF/thread.cc.o

MSF/thread.i: MSF/thread.cc.i
.PHONY : MSF/thread.i

# target to preprocess a source file
MSF/thread.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MSF.dir/build.make CMakeFiles/MSF.dir/MSF/thread.cc.i
.PHONY : MSF/thread.cc.i

MSF/thread.s: MSF/thread.cc.s
.PHONY : MSF/thread.s

# target to generate assembly for a file
MSF/thread.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MSF.dir/build.make CMakeFiles/MSF.dir/MSF/thread.cc.s
.PHONY : MSF/thread.cc.s

MSF/util.o: MSF/util.cc.o
.PHONY : MSF/util.o

# target to build an object file
MSF/util.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MSF.dir/build.make CMakeFiles/MSF.dir/MSF/util.cc.o
.PHONY : MSF/util.cc.o

MSF/util.i: MSF/util.cc.i
.PHONY : MSF/util.i

# target to preprocess a source file
MSF/util.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MSF.dir/build.make CMakeFiles/MSF.dir/MSF/util.cc.i
.PHONY : MSF/util.cc.i

MSF/util.s: MSF/util.cc.s
.PHONY : MSF/util.s

# target to generate assembly for a file
MSF/util.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/MSF.dir/build.make CMakeFiles/MSF.dir/MSF/util.cc.s
.PHONY : MSF/util.cc.s

tests/test.o: tests/test.cc.o
.PHONY : tests/test.o

# target to build an object file
tests/test.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/tests/test.cc.o
.PHONY : tests/test.cc.o

tests/test.i: tests/test.cc.i
.PHONY : tests/test.i

# target to preprocess a source file
tests/test.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/tests/test.cc.i
.PHONY : tests/test.cc.i

tests/test.s: tests/test.cc.s
.PHONY : tests/test.s

# target to generate assembly for a file
tests/test.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/tests/test.cc.s
.PHONY : tests/test.cc.s

tests/test_config.o: tests/test_config.cc.o
.PHONY : tests/test_config.o

# target to build an object file
tests/test_config.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_config.dir/build.make CMakeFiles/test_config.dir/tests/test_config.cc.o
.PHONY : tests/test_config.cc.o

tests/test_config.i: tests/test_config.cc.i
.PHONY : tests/test_config.i

# target to preprocess a source file
tests/test_config.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_config.dir/build.make CMakeFiles/test_config.dir/tests/test_config.cc.i
.PHONY : tests/test_config.cc.i

tests/test_config.s: tests/test_config.cc.s
.PHONY : tests/test_config.s

# target to generate assembly for a file
tests/test_config.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_config.dir/build.make CMakeFiles/test_config.dir/tests/test_config.cc.s
.PHONY : tests/test_config.cc.s

tests/test_fiber.o: tests/test_fiber.cc.o
.PHONY : tests/test_fiber.o

# target to build an object file
tests/test_fiber.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_fiber.dir/build.make CMakeFiles/test_fiber.dir/tests/test_fiber.cc.o
.PHONY : tests/test_fiber.cc.o

tests/test_fiber.i: tests/test_fiber.cc.i
.PHONY : tests/test_fiber.i

# target to preprocess a source file
tests/test_fiber.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_fiber.dir/build.make CMakeFiles/test_fiber.dir/tests/test_fiber.cc.i
.PHONY : tests/test_fiber.cc.i

tests/test_fiber.s: tests/test_fiber.cc.s
.PHONY : tests/test_fiber.s

# target to generate assembly for a file
tests/test_fiber.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_fiber.dir/build.make CMakeFiles/test_fiber.dir/tests/test_fiber.cc.s
.PHONY : tests/test_fiber.cc.s

tests/test_scheduler.o: tests/test_scheduler.cc.o
.PHONY : tests/test_scheduler.o

# target to build an object file
tests/test_scheduler.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_scheduler.dir/build.make CMakeFiles/test_scheduler.dir/tests/test_scheduler.cc.o
.PHONY : tests/test_scheduler.cc.o

tests/test_scheduler.i: tests/test_scheduler.cc.i
.PHONY : tests/test_scheduler.i

# target to preprocess a source file
tests/test_scheduler.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_scheduler.dir/build.make CMakeFiles/test_scheduler.dir/tests/test_scheduler.cc.i
.PHONY : tests/test_scheduler.cc.i

tests/test_scheduler.s: tests/test_scheduler.cc.s
.PHONY : tests/test_scheduler.s

# target to generate assembly for a file
tests/test_scheduler.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_scheduler.dir/build.make CMakeFiles/test_scheduler.dir/tests/test_scheduler.cc.s
.PHONY : tests/test_scheduler.cc.s

tests/test_thread.o: tests/test_thread.cc.o
.PHONY : tests/test_thread.o

# target to build an object file
tests/test_thread.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_thread.dir/build.make CMakeFiles/test_thread.dir/tests/test_thread.cc.o
.PHONY : tests/test_thread.cc.o

tests/test_thread.i: tests/test_thread.cc.i
.PHONY : tests/test_thread.i

# target to preprocess a source file
tests/test_thread.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_thread.dir/build.make CMakeFiles/test_thread.dir/tests/test_thread.cc.i
.PHONY : tests/test_thread.cc.i

tests/test_thread.s: tests/test_thread.cc.s
.PHONY : tests/test_thread.s

# target to generate assembly for a file
tests/test_thread.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_thread.dir/build.make CMakeFiles/test_thread.dir/tests/test_thread.cc.s
.PHONY : tests/test_thread.cc.s

tests/test_util.o: tests/test_util.cc.o
.PHONY : tests/test_util.o

# target to build an object file
tests/test_util.cc.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_util.dir/build.make CMakeFiles/test_util.dir/tests/test_util.cc.o
.PHONY : tests/test_util.cc.o

tests/test_util.i: tests/test_util.cc.i
.PHONY : tests/test_util.i

# target to preprocess a source file
tests/test_util.cc.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_util.dir/build.make CMakeFiles/test_util.dir/tests/test_util.cc.i
.PHONY : tests/test_util.cc.i

tests/test_util.s: tests/test_util.cc.s
.PHONY : tests/test_util.s

# target to generate assembly for a file
tests/test_util.cc.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/test_util.dir/build.make CMakeFiles/test_util.dir/tests/test_util.cc.s
.PHONY : tests/test_util.cc.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... MSF"
	@echo "... test"
	@echo "... test_config"
	@echo "... test_fiber"
	@echo "... test_scheduler"
	@echo "... test_thread"
	@echo "... test_util"
	@echo "... MSF/config.o"
	@echo "... MSF/config.i"
	@echo "... MSF/config.s"
	@echo "... MSF/fiber.o"
	@echo "... MSF/fiber.i"
	@echo "... MSF/fiber.s"
	@echo "... MSF/log.o"
	@echo "... MSF/log.i"
	@echo "... MSF/log.s"
	@echo "... MSF/scheduler.o"
	@echo "... MSF/scheduler.i"
	@echo "... MSF/scheduler.s"
	@echo "... MSF/thread.o"
	@echo "... MSF/thread.i"
	@echo "... MSF/thread.s"
	@echo "... MSF/util.o"
	@echo "... MSF/util.i"
	@echo "... MSF/util.s"
	@echo "... tests/test.o"
	@echo "... tests/test.i"
	@echo "... tests/test.s"
	@echo "... tests/test_config.o"
	@echo "... tests/test_config.i"
	@echo "... tests/test_config.s"
	@echo "... tests/test_fiber.o"
	@echo "... tests/test_fiber.i"
	@echo "... tests/test_fiber.s"
	@echo "... tests/test_scheduler.o"
	@echo "... tests/test_scheduler.i"
	@echo "... tests/test_scheduler.s"
	@echo "... tests/test_thread.o"
	@echo "... tests/test_thread.i"
	@echo "... tests/test_thread.s"
	@echo "... tests/test_util.o"
	@echo "... tests/test_util.i"
	@echo "... tests/test_util.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

