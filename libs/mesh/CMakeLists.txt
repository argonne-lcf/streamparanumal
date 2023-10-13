project(meshlib)

set(meshlib-src
  meshBasis1D.cpp
  meshBasisHex3D.cpp
  meshBasisQuad2D.cpp
  meshBasisTet3D.cpp
  meshBasisTri2D.cpp
  meshConnect.cpp
  meshConnectFaceNodes.cpp
  meshConnectFaceVertices.cpp
  meshConnectNodes.cpp
  meshDeviceProperties.cpp
  meshGatherScatterSetup.cpp
  meshHaloSetup.cpp
  meshReferenceNodesHex3D.cpp
  meshReferenceNodesQuad2D.cpp
  meshReferenceNodesTet3D.cpp
  meshReferenceNodesTri2D.cpp
  meshSetElementType.cpp
  meshSettings.cpp
  meshSetupBoxHex3D.cpp
  meshSetupBoxQuad2D.cpp
  meshSetupBoxTet3D.cpp
  meshSetupBoxTri2D.cpp
  meshSetup.cpp
)

add_library(mesh STATIC ${meshlib-src})
target_include_directories(mesh
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include> 
)

target_link_libraries(mesh PUBLIC ogs core)
set_target_properties(mesh PROPERTIES PUBLIC_HEADER ${CMAKE_SOURCE_DIR}/include/mesh.hpp)

target_compile_definitions(mesh PUBLIC "MESH_DIR=\"${CMAKE_INSTALL_PREFIX}\"")

install(TARGETS mesh DESTINATION lib)
