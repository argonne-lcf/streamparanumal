project(bs0)

add_executable(BS0
               bs0Main.cpp
               src/bs0Run.cpp
               src/bs0Settings.cpp
               src/bs0Setup.cpp
)


target_include_directories(BS0 PUBLIC 
                           ${CMAKE_SOURCE_DIR}/BS/BS0 
                           ${CMAKE_SOURCE_DIR}/include
                           ${MKL_INCLUDE}
                           ${OCCA_INCLUDE_PATH})

target_link_libraries(BS0 
      PUBLIC
      linAlg
      core
      libocca
)    

target_compile_definitions(BS0 PUBLIC
                           -DCEED_DIR="${CMAKE_SOURCE_DIR}"
                           -DMKL_ILP64)

install(TARGETS BS0 RUNTIME DESTINATION ".")
install(DIRECTORY okl/ DESTINATION okl)                          
