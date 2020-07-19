cmake_minimum_required(VERSION 3.5)
project(reunionesRemotas)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")


add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)

set(SOURCE_FILES_TEST
        main.cpp
        ejercicios.cpp
        ejercicios.h
        auxiliares.cpp
        auxiliares.h
        tests/ej1TEST.cpp
        tests/ej2TEST.cpp
        tests/ej3TEST.cpp
        tests/ej4TEST.cpp
        tests/ej5TEST.cpp
        tests/ej6TEST.cpp
        tests/ej7TEST.cpp
        tests/ej8TEST.cpp
        tests/ej9TEST.cpp
        tests/ej10TEST.cpp
        tests/ej11TEST.cpp
        )
add_executable(reunionesRemotas ${SOURCE_FILES_TEST})

target_link_libraries(reunionesRemotas gtest gtest_main)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

# -g: Hace que podamos debuggear el programa.
# --coverage: Hace que se pueda calcular el cubrimiento de los casos de test.
set(CMAKE_CXX_FLAGS "-g --coverage")
# Un temita de gcov que no se lleva tan bien con CMake,
# y entonces hay que poner esta línea.
# Para más información, ver https://texus.me/2015/09/06/cmake-and-gcov/.
set(CMAKE_CXX_OUTPUT_EXTENSION_REPLACE 1)
