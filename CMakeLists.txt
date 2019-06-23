cmake_minimum_required(VERSION 2.8)
project(starkit_geometry)

find_package(catkin REQUIRED COMPONENTS
  starkit_utils
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES starkit_geometry
  CATKIN_DEPENDS starkit_utils
)

include_directories(include ${catkin_INCLUDE_DIRS})

#Enable C++17
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra")

#Enable Weird option linker
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")

#List Sources sub source directories
set(SOURCES_DIRECTORIES
  src/starkit_geometry
  src/starkit_geometry/3d
)

#Include Sources sub sources
foreach (DIRECTORY ${SOURCES_DIRECTORIES})
    message(STATUS "-- Sources: Adding ${DIRECTORY}/")
    include (${DIRECTORY}/Sources.cmake)
    set (PREFIXED_SOURCES)
    foreach (SOURCE ${SOURCES})
        set (PREFIXED_SOURCES ${PREFIXED_SOURCES} ${DIRECTORY}/${SOURCE})
    endforeach (SOURCE)
    set (ALL_SOURCES ${ALL_SOURCES} ${PREFIXED_SOURCES})
endforeach (DIRECTORY)

add_library (starkit_geometry ${ALL_SOURCES})
target_link_libraries(starkit_geometry ${catkin_LIBRARIES})

