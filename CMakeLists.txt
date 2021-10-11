cmake_minimum_required(VERSION 3.0)

project(WeightChecker VERSION 1.0)

file(GLOB SRC "src/*.cpp")

add_executable(${PROJECT_NAME} ${SRC})

find_package(wxWidgets REQUIRED gl core base OPTIONAL_COMPONENTS net)

include(${wxWidgets_USE_FILE})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})

install(TARGETS ${PROJECT_NAME} DESTINATION bin)