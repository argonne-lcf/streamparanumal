project(streamp-bs1)

add_executable(BS1
  bs1Main.cpp
  src/bs1Run.cpp
  src/bs1Settings.cpp
  src/bs1Setup.cpp
)

target_include_directories(BS1 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(BS1 PUBLIC mesh ogs core)

target_compile_definitions(BS1 
  PUBLIC 
    "DBS1=\"${CMAKE_INSTALL_PREFIX}\""
)

install(TARGETS BS1)
install(DIRECTORY okl/ DESTINATION okl)
