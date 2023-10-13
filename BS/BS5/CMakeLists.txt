project(streamp-bs5)

add_executable(BS5
  bs5Main.cpp
  src/bs5Run.cpp
  src/bs5Settings.cpp
  src/bs5Setup.cpp
)

target_include_directories(BS5 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(BS5 PUBLIC mesh ogs core)

target_compile_definitions(BS5 
  PUBLIC 
    "DBS5=\"${CMAKE_INSTALL_PREFIX}\""
)

install(TARGETS BS5)
install(DIRECTORY okl/ DESTINATION okl)
