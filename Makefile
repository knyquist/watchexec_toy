SHELL=/bin/bash

.DEFAULT_GOAL := compile


watch:
	watchexec --exts cpp make run

compile:
	clang++ -std=c++11 -I `cat include.txt` -L `cat lib.txt` program.cpp -o program

run: compile
	./program