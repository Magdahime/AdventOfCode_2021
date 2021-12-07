cmake_minimum_required(VERSION 3.11)
project(aoc_magdy C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -g")

set(SOURCE_DIR ${CMAKE_CURRENT_LIST_DIR}/src/)
set(HEADER_DIR ${CMAKE_CURRENT_LIST_DIR}/include/)

set(PROJECT_SOURCES
    ${SOURCE_DIR}/main.cc
    ${SOURCE_DIR}/day1.cc
    ${SOURCE_DIR}/day2.cc
    ${SOURCE_DIR}/day3.cc
    ${SOURCE_DIR}/day4.cc
    ${SOURCE_DIR}/day5.cc
)


# set(TEST_SOURCES
#     ${SOURCE_DIR}/test.cc
# )

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${HEADER_DIR})

# add_executable(json_test ${TEST_SOURCES})
# target_include_directories(json_test PRIVATE ${HEADER_DIR})
