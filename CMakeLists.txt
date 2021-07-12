cmake_minimum_required(VERSION 3.19)
project(PolarizedSave)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost COMPONENTS filesystem REQUIRED)
include_directories("/opt/spinnaker/include")
include_directories ( ${Boost_INCLUDE_DIR})

link_directories("/opt/spinnaker/lib")
link_libraries(Spinnaker)

add_library(PolarizedSave_lib_shared SHARED main.cpp Polarization.cpp Polarization.h util.cpp util.h)
add_executable(PolarizedSave main.cpp Polarization.cpp Polarization.h util.cpp util.h)

target_link_libraries(PolarizedSave_lib_shared  ${Boost_LIBRARIES} )
target_link_libraries(PolarizedSave  ${Boost_LIBRARIES} PolarizedSave_lib_shared)