project(bs5)

add_executable(BS5
               bs5Main.cpp
               src/bs5Run.cpp
               src/bs5Settings.cpp
               src/bs5Setup.cpp
)


target_include_directories(BS5 PUBLIC 
                           ${CMAKE_SOURCE_DIR}/BS/BS5 
                           ${CMAKE_SOURCE_DIR}/include
                           ${MKL_INCLUDE}
                           ${OCCA_INCLUDE_PATH})

target_link_libraries(BS5 
      PUBLIC
      linAlg
      core
      libocca
)    

target_compile_definitions(BS5 PUBLIC
                           -DCEED_DIR="${CMAKE_SOURCE_DIR}"
                           -DMKL_ILP64)

install(TARGETS BS5 RUNTIME DESTINATION ".")
install(DIRECTORY okl/ DESTINATION okl)                          
