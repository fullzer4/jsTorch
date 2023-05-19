cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(jstorch-lib)

find_package(Torch REQUIRED)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${TORCH_CXX_FLAGS}")

add_definitions(-DNAPI_VERSION=3)

add_executable(jstorch-lib ./lib/tensor.cc)
target_link_libraries(jstorch-lib "${TORCH_LIBRARIES}")
set_property(TARGET jstorch-lib PROPERTY CXX_STANDARD 14)

if (MSVC)
  file(GLOB TORCH_DLLS "./lib/${TORCH_INSTALL_PREFIX}/lib/*.dll")
  add_custom_command(TARGET jstorch-lib
                     POST_BUILD
                     COMMAND ${CMAKE_COMMAND} -E copy_if_different
                     ${TORCH_DLLS}
                     $<TARGET_FILE_DIR:jstorch-lib>)
endif (MSVC)