#include "docopt/docopt.h"

static const char USAGE[] =
R"(Program.

    Usage:
      program [-hv] [--flag flag] <pos_arg>

    Options:
      -h --help         Show this message.
      -v --version      Show version.
         --flag=flag    Optional flag [default 1]
      <pos_arg>         Mandatory positional arg
)";

#include <iostream>
#include <string>
#include "src/functions.h"

int main(int argc, const char** argv) {
    std::map<std::string, docopt::value> args
        = docopt::docopt(USAGE,
                         { argv + 1, argv + argc},
                         true,    // show help if requested
                         "0.1");  // version string
     for(auto const& arg : args) {
         std::cout << arg.first << " => " << arg.second << std::endl;
     }

     std::cout << "a is of type: " << typeid(args["--flag"].asString()).name() << std::endl;
     std::string s = "10";
     int val = std::stoi(args["--flag"].asString());
     int sum = f::add(val, val);
     std::cout << sum << std::endl;
//    std::cout << "--flag => " << args["--flag"] << std::endl;
//    std::cout << "<pos_arg> => " << args["<pos_arg>"] << std::endl;

     return 0;
}