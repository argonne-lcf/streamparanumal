project(streamp-bs8)

add_executable(BS8
  bs8Main.cpp
  src/bs8Run.cpp
  src/bs8Settings.cpp
  src/bs8Setup.cpp
)

target_include_directories(BS8 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(BS8 PUBLIC mesh ogs core)

target_compile_definitions(BS8 
  PUBLIC 
    "DBS8=\"${CMAKE_INSTALL_PREFIX}\""
)

install(TARGETS BS8)
