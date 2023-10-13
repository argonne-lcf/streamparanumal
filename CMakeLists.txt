cmake_minimum_required(VERSION 3.0)
cmake_policy(SET CMP0074 NEW)

project(streamparanumal VERSION 1.0.0)

enable_language(C CXX)
enable_testing()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include(GNUInstallDirs)

find_package(MPI REQUIRED)
find_package(BLAS REQUIRED)
find_package(LAPACK REQUIRED)

option(EXTERNAL_OCCA "Use an external OCCA build" OFF)
if(EXTERNAL_OCCA)
  message(STATUS "Using an external OCCA build.")
  find_package(occa REQUIRED)
  set(OCCA_TARGET OCCA::libocca)
else()
  add_subdirectory(occa)
  set(OCCA_TARGET libocca)
endif()

add_subdirectory(libs)
add_subdirectory(BS)

install(DIRECTORY include/ DESTINATION include)
