cmake_minimum_required(VERSION 3.13)
set(CMAKE_VERBOSE_MAKEFILE on)

file(GLOB rnoh_search_bar_SRC CONFIGURE_DEPENDS *.cpp)
add_library(rnoh_search_bar SHARED ${rnoh_search_bar_SRC})
target_include_directories(rnoh_search_bar PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(rnoh_search_bar PUBLIC rnoh)