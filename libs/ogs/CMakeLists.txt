project(ogslib)

option(GPU_AWARE_MPI "Using a GPU aware MPI implementation" OFF)

set(ogslib-src
  ogsAllToAll.cpp
  ogsAuto.cpp
  ogs.cpp
  ogsCrystalRouter.cpp
  ogsHalo.cpp
  ogsOperator.cpp
  ogsPairwise.cpp
  ogsSetup.cpp
  ogsUtils.cpp
)

add_library(ogs STATIC ${ogslib-src})

target_include_directories(ogs 
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include> 
)

target_link_libraries(ogs PUBLIC core)
set_target_properties(ogs PROPERTIES PUBLIC_HEADER ${CMAKE_SOURCE_DIR}/include/ogs.hpp)

target_compile_definitions(ogs 
  PUBLIC 
    "LIBP_DIR=\"${CMAKE_INSTALL_PREFIX}\""
    "OGS_DIR=\"${CMAKE_INSTALL_PREFIX}\""
)

if(GPU_AWARE_MPI)
  message("--- Building libogs with GPU aware mpi")
  target_compile_definitions(ogs PUBLIC "GPU_AWARE_MPI")
endif()

install(TARGETS ogs DESTINATION lib)
install(DIRECTORY okl/ DESTINATION okl)
