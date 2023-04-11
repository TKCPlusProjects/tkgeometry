set(DEMO_NAME demo)
 
add_executable(${DEMO_NAME} demo.cpp)

find_package(GLEW REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(CGAL CONFIG REQUIRED)

target_link_libraries(${DEMO_NAME} ${PROJECT_NAME} GLEW::GLEW glfw CGAL::CGAL)

set_target_properties(
    ${DEMO_NAME}
    PROPERTIES 
    LINKER_LANGUAGE CXX
    CXX_STANDARD 17
)


