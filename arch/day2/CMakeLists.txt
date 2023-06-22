cmake_minimum_required(VERSION 3.0)
project(aoc)

# Set the C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)

# Add the executable target
add_executable(main main.cpp)

# Copy the input.txt file to the build directory
configure_file(input.txt input.txt COPYONLY)
configure_file(simple.txt simple.txt COPYONLY)