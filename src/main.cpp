#include <iostream>
#include <boost/program_options.hpp>

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

    unsigned int num_of_threads;
    if (vm.count("threads")) {
        num_of_threads = vm["threads"].as<unsigned int>();
    }

    return 0;
}
