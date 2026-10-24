#include <iostream>
#include <boost/program_options.hpp>
#include <thread>

namespace po = boost::program_options;

int main(int argc, char** argv) {
    po::options_description desc("super program");

    desc.add_options()
        ("help,h", "Show this help message")
        ("threads,t", po::value<unsigned int>(), "Number of threads")
        ("path,p", po::value<std::string>()->required(), "Path for hashes");

    po::variables_map vm;

    po::store(
        po::parse_command_line(argc, argv, desc),
        vm
    );

    if (vm.count("help")) {
        std::cout << desc << std::endl;
        return 0;
    }

    po::notify(vm);

    unsigned int num_of_threads = 4;
    if (vm.count("threads")) {
        num_of_threads = vm["threads"].as<unsigned int>();
        if (num_of_threads == 0 || num_of_threads > std::thread::hardware_concurrency()) {
            num_of_threads = 4;
            std::cout << "bro, u dont have brain :)" << std::endl;
        } else {
            std::cout << "thread count set to " << vm["threads"].as<unsigned int>() << std::endl;
        }
    }

    return 0;
}
