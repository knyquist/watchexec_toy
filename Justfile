cmd := "--help"

# Watch for code changes and recompile/run automatically
watch:
    watchexec --exts cpp just "cmd={{cmd}}" run

# Compile the program
compile:
    clang++ --stdlib=libc++ --std=c++11 -I$INCLUDE_PATH -L$LIB_PATH program.cpp \
    `for LIB in $STATIC_LIB_NAMES; do echo $LIB_PATH/$LIB; done;` \
    -o program

# Run the program. Can inject custom command line args, i.e. cmd="--flag=100\ pos_arg"
run: compile
    ./program {{cmd}}