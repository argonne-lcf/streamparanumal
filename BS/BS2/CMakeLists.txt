project(streamp-bs2)

add_executable(BS2
  bs2Main.cpp
  src/bs2Run.cpp
  src/bs2Settings.cpp
  src/bs2Setup.cpp
)

target_include_directories(BS2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(BS2 PUBLIC mesh ogs core)

target_compile_definitions(BS2 
  PUBLIC 
    "DBS2=\"${CMAKE_INSTALL_PREFIX}\""
)

install(TARGETS BS2)
install(DIRECTORY okl/ DESTINATION okl)
