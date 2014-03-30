

#add_subdirectory(utils)

set(oned_source_files
    lin1d.cpp
    lin1d.h
    nonlin1d.cpp
    nonlin1d.h
    diffusion1d.cpp
    diffusion1d.h
    burgers.cpp
    burgers.h
    arrayops.cpp
    arrayops.h
    lin2d.cpp
    lin2d.h
    nonlin2d.cpp
    nonlin2d.h
    diffusion2d.cpp
    diffusion2d.h
    burgers2d.cpp
    burgers2d.h
    laplace2d.cpp
    laplace2d.h
    poisson2d.cpp
    poisson2d.h
    cavityns.cpp
    cavityns.h
    )

set(core_source_files
    main.cpp)
file(COPY step1 DESTINATION ${CMAKE_BINARY_DIR})
file(COPY step2 DESTINATION ${CMAKE_BINARY_DIR})
file(COPY step3 DESTINATION ${CMAKE_BINARY_DIR})
file(COPY step4 DESTINATION ${CMAKE_BINARY_DIR})
file(COPY step5 DESTINATION ${CMAKE_BINARY_DIR})
file(COPY step6 DESTINATION ${CMAKE_BINARY_DIR})
file(COPY step7 DESTINATION ${CMAKE_BINARY_DIR})
file(COPY step8 DESTINATION ${CMAKE_BINARY_DIR})
file(COPY step9 DESTINATION ${CMAKE_BINARY_DIR})
file(COPY step10 DESTINATION ${CMAKE_BINARY_DIR})
file(COPY step11 DESTINATION ${CMAKE_BINARY_DIR})
file(COPY step12 DESTINATION ${CMAKE_BINARY_DIR})
include_directories(/usr/include/eigen3/)
add_executable(cppns ${core_source_files} ${oned_source_files})
add_subdirectory(util)
target_link_libraries(cppns util)
