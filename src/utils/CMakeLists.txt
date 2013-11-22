# CMakeLists.txt for utils folder

set(utils_source_files
    plot1d.cpp
    plot1d.h
    mgleigen.cpp
    mgleigen.h
    )
    
add_library(utils ${utils_source_files})
