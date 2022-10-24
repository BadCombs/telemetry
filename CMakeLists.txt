cmake_minimum_required(VERSION 3.21)
project(Project2 VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-pthread -O0 -g -w")

include_directories(
    #${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/sources
)

add_library(
    ${PROJECT_NAME}
    SHARED
    
    # Sources
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/fake_receiver.c
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/fsm.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/message.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sources/id_info.cpp
)

target_link_libraries(${PROJECT_NAME}
    # Other librs
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

add_executable(project_2 sources/main.cpp)
target_link_libraries(project_2 ${PROJECT_NAME})
