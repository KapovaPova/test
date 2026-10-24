#include <iostream>
#include <boost/program_options.hpp>

int main(int argc, char** argv) {
    boost::program_options::options_description desc("This program can't do anything!");
    std::cout << "Hello, world!" << std::endl;
    return 0;
}
