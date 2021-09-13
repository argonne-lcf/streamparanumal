cmake_minimum_required(VERSION 3.0)
project(streamParanumal VERSION 1.0)

enable_language(C)
enable_language(CXX)
#enable_language(Fortran)
#enable_testing()

#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_EXTENSIONS OFF)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include(GNUInstallDirs)
#include(FortranCInterface)

set(dfloat "double")
set(dfloatString "\"double\"")
set(dfloatFormat "\"%lf\"")
set(dlong "long int")
set(dlongString "\"long int\"")
set(dlongFormat="\"%ld\"")
set(hlong "long long int")
set(hlongString "\"long long int\"")
set(hlongFormat "\"%lld\"")
set(MPI_DFLOAT "MPI_DOUBLE")
set(MPI_DLONG "MPI_LONG_INT")
set(MPI_HLONG "MPI_LONG_LONG_INT")
set(CMAKE_CXX_FLAGS "-cxx=icpx -O2 -fopenmp -g -Wall -Wshadow -Wno-unused-function -std=c++11 -funroll-loops -xHost")
set(CMAKE_MSVC_RUNTIME_LIBRARY "")


option(USE_MPI "Use the MPI library." ON)
if(USE_MPI)
    find_package(MPI)
endif()

option(MKL_BLASLAPACK "Use MKL-provided Blas/Lapack library" OFF)
if(MKL_BLASLAPACK)
  set(BLA_VENDOR Intel10_64ilp_seq)
  find_package(LAPACK)
endif()

set(MKL_INCLUDE $ENV{MKLROOT}/include)


message("-- MKL root dirs: "$ENV{MKLROOT}/include"")

option(EXTERNAL_OCCA "Use an external OCCA build" OFF)
if(EXTERNAL_OCCA)
  find_library(OCCA_LIBRARY_PATH NAMES occa libocca PATHS $ENV{OCCA_DIR}/lib)
  find_path(OCCA_INCLUDE_PATH NAMES occa.hpp occa.h PATHS $ENV{OCCA_DIR}/include)
  add_library(libocca UNKNOWN IMPORTED)
  set_target_properties(libocca PROPERTIES IMPORTED_LOCATION ${OCCA_LIBRARY_PATH})
  target_include_directories(libocca INTERFACE ${OCCA_INCLUDE_PATH})
endif()

add_compile_definitions(
    "USE_OCCA_MEM_BYTE_ALIGN=64"
    "dfloat=double"
    "dfloatString=\"double\""
    "dfloatFormat=\"%lf\""
    "MPI_DFLOAT=MPI_DOUBLE"
    "dlong=int"
    "dlongString=\"int\""
    "dlongFormat=\"%d\""
    "MPI_DLONG=MPI_INT"
    "hlong=long long int"
    "hlongString=\"long long int\""
    "hlongFormat=\"%lld\""
    "MPI_HLONG=MPI_LONG_LONG_INT"
) 

#add_subdirectory(3rdParty)
add_subdirectory(libs)
add_subdirectory(BS)
