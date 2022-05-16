cmake_minimum_required(VERSION 2.6)
project(concurrency)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(main ${SOURCES})

set_property(TARGET main PROPERTY CXX_STANDARD 17)
# target_link_libraries(main)
# TODO: Run -Werror in CI.
target_compile_options(main PRIVATE -Wall -Wextra)
