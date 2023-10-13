project(streamp-bs6)

add_executable(BS6
  bs6Main.cpp
  src/bs6Run.cpp
  src/bs6Settings.cpp
  src/bs6Setup.cpp
)

target_include_directories(BS6 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(BS6 PUBLIC mesh ogs core)

target_compile_definitions(BS6 
  PUBLIC 
    "DBS6=\"${CMAKE_INSTALL_PREFIX}\""
)

install(TARGETS BS6)
