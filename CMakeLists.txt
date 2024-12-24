cmake_minimum_required(VERSION 3.27)
project(gm-quiz C)
set(CMAKE_C_STANDARD 99)

set(CMAKE_C_FLAGS -O2)
if(CFLAGS_EX)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${CFLAGS_EX}")
endif()

set(SRCDIR src)
set(BUILDDIR build)

file(GLOB SRC "${SRCDIR}/*.c")

set(RAYLIB_VERSION 5.5)
find_package(raylib ${RAYLIB_VERSION} QUIET)
if (NOT raylib_FOUND)
  include(FetchContent)
  FetchContent_Declare(
    raylib
    DOWNLOAD_EXTRACT_TIMESTAMP OFF
    URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
  )
  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED)
    set(FETCHCONTENT_QUIET NO)
    FetchContent_MakeAvailable(raylib)
    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
  endif()
endif()

add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} raylib)
if(UNIX)
    target_link_libraries(${PROJECT_NAME} m)
endif()

set(CMAKE_BUILD_TYPE Release)
