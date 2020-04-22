SHELL=/bin/bash

.DEFAULT_GOAL := compile

dylib_path = DYLD_LIBRARY_PATH=`cat lib.txt`:$$DYLD_LIBRARY_PATH

watch:
	watchexec --exts cpp make run

compile:
	$(dylib_path); \
	clang++ --stdlib=libc++ --std=c++11 -I`cat include.txt` -L`cat lib.txt` program.cpp -ldocopt -o program

run: compile
	$(dylib_path) ./program --help