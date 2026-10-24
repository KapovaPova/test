cmake_minimum_required(VERSION 3.5)
project(main)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Boost REQUIRED COMPONENTS program_options)

add_executable(main
    src/main.cpp
)

target_link_libraries(main PRIVATE
    Boost::program_options
)
