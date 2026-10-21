cmake_minimum_required(VERSION 3.10)

# Déclaration du projet
project(tp2)
set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})
add_compile_options(-std=c++11)
include_directories(include)

# Dépendance OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Déclaration de l'exécutable
add_executable(hello src/hello.cpp)
add_executable(capt src/capture.cpp)

# Configuration de l'édition de liens
target_link_libraries(hello ${OpenCV_LIBS})
target_link_libraries(capt ${OpenCV_LIBS})