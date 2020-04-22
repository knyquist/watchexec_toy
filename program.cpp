#include "docopt/docopt.h"
static const char USAGE[] =
R"(Program.

    Usage:
      program [-hv] [--flag flag] <positional_arg>

    Options:
      -h --help         Show this message.
      -v --version      Show version.
         --flag=flag    Optional flag [default 1]
)";

#include <iostream>


int main(int argc, const char** argv) {
    std::map<std::string, docopt::value> args
        = docopt::docopt(USAGE,
                         { argv + 1, argv + argc},
                         true,    // show help if requested
                         "0.1");  // version string
     for(auto const& arg : args) {
         std::cout << arg.first << arg.second << std::endl;
     }

     return 0;
}