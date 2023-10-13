project(streamp-bs7)

add_executable(BS7
  bs7Main.cpp
  src/bs7Run.cpp
  src/bs7Settings.cpp
  src/bs7Setup.cpp
)

target_include_directories(BS7 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(BS7 PUBLIC mesh ogs core)

target_compile_definitions(BS7 
  PUBLIC 
    "DBS7=\"${CMAKE_INSTALL_PREFIX}\""
)

install(TARGETS BS7)
