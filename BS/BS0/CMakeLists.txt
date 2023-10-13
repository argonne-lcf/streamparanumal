project(streamp-bs0)

add_executable(BS0
  bs0Main.cpp
  src/bs0Run.cpp
  src/bs0Settings.cpp
  src/bs0Setup.cpp
)

target_include_directories(BS0 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(BS0 PUBLIC mesh ogs core)

target_compile_definitions(BS0 
  PUBLIC 
    "DBS0=\"${CMAKE_INSTALL_PREFIX}\""
)

install(TARGETS BS0)
install(DIRECTORY okl/ DESTINATION okl)
