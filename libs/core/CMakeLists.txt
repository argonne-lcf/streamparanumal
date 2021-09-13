project(core)

set(core-src
    settings.cpp
    matrixEig.cpp
    matrixConditionNumber.cpp
    matrixInverse.cpp
    matrixRightSolve.cpp
    matrixTranspose.cpp
    parallelSort.cpp
    platformBuildKernel.cpp
    platformSettings.cpp
    platformProperties.cpp
    platformDeviceConfig.cpp
    platformBuildKernel.cpp
    parallelSort.cpp
)

add_library(core STATIC ${core-src})
target_include_directories(core PUBLIC 
                           ${CMAKE_SOURCE_DIR}/include
                           ${MKL_INCLUDE}
                           ${OCCA_INCLUDE_PATH})

target_compile_definitions(core PUBLIC
                           -DCEED_DIR="${CMAKE_SOURCE_DIR}"
                           -DMKL_ILP64)                           
