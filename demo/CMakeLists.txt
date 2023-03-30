cmake_minimum_required(VERSION 3.9.1)

set(CMAKE_TOOLCHAIN_FILE $ENV{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake)

project(demo)

add_executable(${PROJECT_NAME} demo.cpp)

set_target_properties(
  ${PROJECT_NAME}
  PROPERTIES 
  LINKER_LANGUAGE CXX
  CXX_STANDARD 17
)

find_package(tkutils CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE tkutils::tkutils)

find_package(tkgeometry CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE tkgeometry::tkgeometry)

find_package(GLEW REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE GLEW::GLEW)

find_package(glfw3 CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
