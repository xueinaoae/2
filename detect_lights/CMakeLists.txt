cmake_minimum_required(VERSION 3.16)
project(detect_lights)
file(GLOB_RECURSE SRC  ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_executable(${PROJECT_NAME} ${SRC})
target_include_directories(${PROJECT_NAME} PUBLIC  ${PROJECT_SOURCE_DIR}/src/detect_lights/include)
find_package(OpenCV REQUIRED)
find_package(fmt REQUIRED)
target_link_libraries(${PROJECT_NAME} PUBLIC ${OpenCV_LIBS}
                                              fmt::fmt)