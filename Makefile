SHELL=/bin/bash

.DEFAULT_GOAL := compile

include_path = `cat include.txt`
lib_path = `cat lib.txt`

watch:
	watchexec --exts cpp make run

compile:
	clang++ --stdlib=libc++ --std=c++11 -I$(include_path) -L$(lib_path) program.cpp \
	$(lib_path)/libdocopt.a \
	-o program

run: compile
	./program --help