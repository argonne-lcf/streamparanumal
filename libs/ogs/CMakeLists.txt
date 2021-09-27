project(ogslib)

set(ogslib-src
    gs.cpp
    hostGather.cpp
    hostScatter.cpp
    hostGatherScatter.cpp
    occaGather.cpp
    occaScatter.cpp
    occaGatherScatter.cpp
    occaGatheredHaloExchange.cpp
    ogs.cpp
    ogsKernels.cpp
    ogsSetup.cpp
)

add_library(ogs STATIC ${ogslib-src})
target_include_directories(ogs PUBLIC 
                           ${CMAKE_SOURCE_DIR}/include
                           ${CMAKE_SOURCE_DIR}/3rdParty/gslib/src
                           ${OCCA_INCLUDE_PATH})

target_compile_definitions(ogs PUBLIC
                           -DCEED_DIR="${CMAKE_SOURCE_DIR}"
                           -DOGS_DIR="${CMAKE_SOURCE_DIR}/libs/ogs"
                           "USE_NEW_PINNED_MALLOC=1"
                           "DOGS=\"${CMAKE_INSTALL_PREFIX}\""
			   -DMKL_ILP64)                           

target_link_libraries(ogs PUBLIC MPI::MPI_C libocca gs)
#set_target_properties(ogs PROPERTIES PUBLIC_HEADER ogs.hpp)

install(TARGETS ogs 
  LIBRARY DESTINATION lib
  PUBLIC_HEADER DESTINATION include
)
install(DIRECTORY okl/ DESTINATION okl)
