cmake_minimum_required(VERSION 3.10)

# Déclaration du projet
project(tp1)
set(EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE})
include_directories(include)

# Déclaration de l'exécutable
add_executable(hello src/hello.cpp)

# Configuration de l'édition de liens
target_link_libraries(hello pthread X11)
