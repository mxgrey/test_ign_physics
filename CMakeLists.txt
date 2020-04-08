cmake_minimum_required(VERSION 3.5)

project(test_phys)

find_package(ignition-plugin1 REQUIRED COMPONENTS loader)
find_package(ignition-physics2 REQUIRED)

add_executable(test_exec test_exec.cpp)

target_link_libraries(test_exec
  PRIVATE
    ignition-physics2::core
    ignition-plugin1::loader
)
