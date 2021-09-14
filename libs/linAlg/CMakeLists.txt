project(linAlg)

set(linAlg-src
    linAlg.cpp
    linAlgSetup.cpp
)

add_library(linAlg STATIC ${linAlg-src})
target_include_directories(linAlg PUBLIC 
                           ${CMAKE_SOURCE_DIR}/include
                           ${OCCA_INCLUDE_PATH})

target_compile_definitions(linAlg PUBLIC
                           -DCEED_DIR="${CMAKE_SOURCE_DIR}"
                           -DLINALG_DIR="${CMAKE_SOURCE_DIR}/libs/linAlg"
			   -DMKL_ILP64)                           

target_link_libraries(linAlg PUBLIC libocca)
#set_target_properties(ogs PROPERTIES PUBLIC_HEADER ogs.hpp)
set_target_properties(linAlg PROPERTIES PUBLIC_HEADER linAlg.hpp)

install(DIRECTORY okl/ DESTINATION okl)
