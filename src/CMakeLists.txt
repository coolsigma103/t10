add_executable(t3 t3/t3.cpp)
target_include_directories(t3 PRIVATE 
    ../include
    ${CMAKE_CURRENT_SOURCE_DIR}
)

add_executable(t3c t3c/t3c.cpp)
target_include_directories(t3c PRIVATE  
    ../include 
    ${CMAKE_CURRENT_SOURCE_DIR}
)