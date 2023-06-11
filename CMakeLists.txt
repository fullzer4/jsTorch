include_directories(/usr/include/node)

cmake_minimum_required(VERSION 3.2)

project(torchtest)

set(CMAKE_PREFIX_PATH ./libtorch/)

find_package(Torch REQUIRED)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

add_executable(${PROJECT_NAME} ./lib/main.cpp)

target_link_libraries(${PROJECT_NAME} "${TORCH_LIBRARIES}")

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 14)
