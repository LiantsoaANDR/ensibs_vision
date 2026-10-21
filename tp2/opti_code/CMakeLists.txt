cmake_minimum_required(VERSION 3.10)

# Déclaration du projet
project(tp2)
set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})
include_directories(include)

# Dépendance OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Déclaration de l'exécutable
add_executable(hello src/hello.cpp)

# Configuration de l'édition de liens
target_link_libraries(hello pthread X11 ${OpenCV_LIBS})