project(cpp-ns) # cpp-ns = C++-NavierStokes
cmake_minimum_required(VERSION 2.8)


set(HEADER_FILES step1/lin1d.h step2/nonlinear-1d.h)

add_executable(cpp-ns cpp-navier-stokes-steps.cpp ${HEADER_FILES})
target_link_libraries(cpp-ns mgl)
