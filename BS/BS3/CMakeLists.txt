project(streamp-bs3)

add_executable(BS3
  bs3Main.cpp
  src/bs3Run.cpp
  src/bs3Settings.cpp
  src/bs3Setup.cpp
)

target_include_directories(BS3 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(BS3 PUBLIC mesh ogs core)

target_compile_definitions(BS3 
  PUBLIC 
    "DBS3=\"${CMAKE_INSTALL_PREFIX}\""
)

install(TARGETS BS3)
install(DIRECTORY okl/ DESTINATION okl)
