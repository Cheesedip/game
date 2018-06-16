cmake_minimum_required(VERSION 2.8)

set (CMAKE_CXX_STANDARD 11)
set ( CMAKE_BUILD_TYPE Debug )

#find_package(SFML 2.5 REQUIRED)

project(engine)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    /usr/lib/x86_64-linux-gnu
    /usr/local/lib
    /usr/include
    )

file(GLOB SRCFILES
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
)


add_executable(${PROJECT_NAME} ${SRCFILES})

target_link_libraries(${PROJECT_NAME}
    sfml-window
    sfml-system
    sfml-graphics
    sfml-audio
    sfml-network
)
