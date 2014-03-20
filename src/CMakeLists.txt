

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
    )

set(core_source_files
    main.cpp)
    
include_directories(/usr/include/eigen3/)
add_executable(cppns ${core_source_files} ${oned_source_files})
add_subdirectory(util)
target_link_libraries(cppns util)