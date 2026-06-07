cmake_minimum_required(VERSION 3.28)

project(T10-SDK VERSION 0.0.1 LANGUAGES C CXX)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)

install(DIRECTORY include/
    DESTINATION include
)

install(TARGETS
    t3 
    t3c

    RUNTIME DESTINATION bin    
)