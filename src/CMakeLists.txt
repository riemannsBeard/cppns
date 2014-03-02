

#add_subdirectory(utils)

set(oned_source_files
    lin1d.cpp
    lin1d.h
    nonlin1d.cpp
    nonlin1d.h
    diffusion1d.cpp
    diffusion1d.h
    )
    
#add_library(oned %{oned_source_files}) # Might use this later...

set(core_source_files
    main.cpp)
add_subdirectory(utils)  
include_directories(/usr/include/eigen3/)
add_executable(cppns ${core_source_files} ${oned_source_files})
target_link_libraries(cppns utils)