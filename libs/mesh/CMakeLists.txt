project(mesh)

set(mesh-src
    mesh.cpp
    meshBasis1D.cpp
    meshBasisHex3D.cpp
    meshBasisQuad2D.cpp
    meshBasisTet3D.cpp
    meshBasisTri2D.cpp
    meshBoundarySetup.cpp
    meshConnect.cpp    
    meshConnectBoundary.cpp
    meshConnectFaceNodes2D.cpp
    meshConnectFaceNodes3D.cpp
    meshGeometricPartition2D.cpp
    meshGeometricPartition3D.cpp
    meshHaloSetup.cpp
    meshHaloTraceSetup.cpp
    meshOccaSetup.cpp
    meshOccaSetup2D.cpp
    meshOccaSetup3D.cpp
    meshOccaSetupHex3D.cpp
    meshOccaSetupQuad2D.cpp
    meshOccaSetupQuad3D.cpp
    meshOccaSetupTet3D.cpp
    meshOccaSetupTri2D.cpp
    meshOccaSetupTri3D.cpp
    meshParallelConnectNodes.cpp
    meshParallelConnectOpt.cpp
    meshParallelGatherScatterSetup.cpp
    meshParallelReaderHex3D.cpp
    meshParallelReaderQuad2D.cpp
    meshParallelReaderQuad3D.cpp
    meshParallelReaderTet3D.cpp
    meshParallelReaderTri2D.cpp
    meshParallelReaderTri3D.cpp 
    meshPartitionStatistics.cpp
    meshPhysicalNodesHex3D.cpp
    meshPhysicalNodesQuad2D.cpp
    meshPhysicalNodesQuad3D.cpp
    meshPhysicalNodesTet3D.cpp
    meshPhysicalNodesTri2D.cpp
    meshPhysicalNodesTri3D.cpp
    meshReferenceNodesHex3D.cpp
    meshReferenceNodesQuad2D.cpp    
    meshReferenceNodesTet3D.cpp
    meshReferenceNodesTri2D.cpp
    meshSettings.cpp
    meshSetup.cpp
    meshSetupBoxHex3D.cpp    
    meshSetupBoxQuad2D.cpp
    meshSetupBoxTet3D.cpp
    meshSetupBoxTri2D.cpp
)

add_library(mesh STATIC ${mesh-src})
target_include_directories(mesh PUBLIC 
                           ${CMAKE_SOURCE_DIR}/include
                           ${CMAKE_SOURCE_DIR}/include/mesh
                           ${CMAKE_SOURCE_DIR}/3rdParty/gslib/src
                           ${OCCA_INCLUDE_PATH})

target_compile_definitions(mesh PUBLIC
                           -DCEED_DIR="${CMAKE_SOURCE_DIR}"
                           -DMESH_DIR="${CMAKE_SOURCE_DIR}/libs/mesh"
			   -DMKL_ILP64)                           

target_link_libraries(mesh PUBLIC MPI::MPI_C libocca gs)
#set_target_properties(ogs PROPERTIES PUBLIC_HEADER ogs.hpp)
