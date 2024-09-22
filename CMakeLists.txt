cmake_minimum_required(VERSION 3.30)

project(
    "cpp_imgui"
    VERSION 1.0.0
    LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_OSX_ARCHITECTURES "x86_64")
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/)

option(ENABLE_WARNINGS "Enable to add warnings to a target." ON)
option(ENABLE_WARNINGS_AS_ERRORS "Enable to treat warnings as errors." OFF)
option(ENABLE_CLANG_TIDY "Enable to add clang tidy." ON)
option(ENABLE_CLANG_FORMAT "Enable to add clang-format." ON)

include(Warnings)
#  include(Tools) # needs clang tidy and clang format
include(ConfigSafeGuards)

# add_clang_format_target() # needs python
message(STATUS ${CMAKE_SOURCE_DIR})

set (VCPKG_DIR ${CMAKE_SOURCE_DIR}/external/vcpkg)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE AND DEFINED ENV{CMAKE_TOOLCHAIN_FILE})
   set(CMAKE_TOOLCHAIN_FILE $ENV{CMAKE_TOOLCHAIN_FILE})
endif()

include(${VCPKG_DIR}/scripts/buildsystems/vcpkg.cmake)

find_package(fmt CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(implot CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

add_subdirectory(ImGuiHelloWorld)
add_subdirectory(FileExplorer)
