cmake_minimum_required(VERSION 3.10 FATAL_ERROR)
project(effective_cpp LANGUAGES C CXX)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE RelWithDebInfo)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS FALSE)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

message(STATUS "CMAKE_C_FLAGS : " ${CMAKE_C_FLAGS})
message(STATUS "CMAKE_C_FLAGS_DEBUG : " ${CMAKE_C_FLAGS_DEBUG})
message(STATUS "CMAKE_C_FLAGS_RELWITHDEBINFO : " ${CMAKE_C_FLAGS_RELWITHDEBINFO})
message(STATUS "CMAKE_C_FLAGS_RELEASE : " ${CMAKE_C_FLAGS_RELEASE})

message(STATUS "CMAKE_CXX_FLAGS : " ${CMAKE_CXX_FLAGS})
message(STATUS "CMAKE_CXX_FLAGS_DEBUG : " ${CMAKE_CXX_FLAGS_DEBUG})
message(STATUS "CMAKE_CXX_FLAGS_RELWITHDEBINFO : " ${CMAKE_CXX_FLAGS_RELWITHDEBINFO})
message(STATUS "CMAKE_CXX_FLAGS_RELEASE : " ${CMAKE_CXX_FLAGS_RELEASE})

add_subdirectory(Chapter01)
add_subdirectory(Chapter02)
add_subdirectory(Chapter03)
add_subdirectory(Chapter05)
add_subdirectory(Chapter06)
add_subdirectory(Chapter07)
add_subdirectory(Chapter08)
