cmake_minimum_required(VERSION 3.5)

project(Snake)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_BUILD_TYPE Debug)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

file(GLOB Snake_SRC
  "src/*.cpp"
)

add_executable(${PROJECT_NAME} ${Snake_SRC})
target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARY})
