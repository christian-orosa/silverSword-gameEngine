cmake_minimum_required(VERSION 3.15)
project(silverMaths LANGUAGES CXX)

# Headers
set(SILVERMATHS_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/Defines.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Matrix.h
    ${CMAKE_CURRENT_SOURCE_DIR}/NameSpace.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Quaternion.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector3D.h
)

# Sources
set(SILVERMATHS_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Matrix.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Quaternion.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Vector3D.cpp
)

# Crear librería estática
add_library(silverMaths STATIC ${SILVERMATHS_SOURCES} ${SILVERMATHS_HEADERS})

# Incluir directorio de headers
target_include_directories(silverMaths PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Estándar de C++
target_compile_features(silverMaths PUBLIC cxx_std_17)
