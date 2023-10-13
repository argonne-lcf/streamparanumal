project(streamp-bs4)

add_executable(BS4
  bs4Main.cpp
  src/bs4Run.cpp
  src/bs4Settings.cpp
  src/bs4Setup.cpp
)

target_include_directories(BS4 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(BS4 PUBLIC mesh ogs core)

target_compile_definitions(BS4 
  PUBLIC 
    "DBS4=\"${CMAKE_INSTALL_PREFIX}\""
)

install(TARGETS BS4)
install(DIRECTORY okl/ DESTINATION okl)
