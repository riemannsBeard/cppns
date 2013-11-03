set(CMAKE_CXX_FLAGS "-lmgl")

add_executable(${PROJECT_NAME} lin1d.cpp)
configure_file(lin1d.gp lin1d.gp COPYONLY)
