cmake_minimum_required( VERSION  3.0 )
project( simple_argv_parser )

set (CMAKE_CXX_STANDARD 14)

add_library( simple_argv_parser parser.cpp )
include_directories( simple_arbv_parser ${CMAKE_CURRENT_SOURCE_DIR} )

if (BUILD_TESTS)
    add_executable( parser_test test.cpp )
    include_directories( parser_test ${CMAKE_CURRENT_SOURCE_DIR} )
    target_link_libraries( parser_test simple_argv_parser )
endif()
