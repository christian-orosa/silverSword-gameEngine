cmake_minimum_required(VERSION 3.15)
project(Graphics LANGUAGES CXX)

# Headers
set(GRAPHICS_HEADERS
    ${CMAKE_CURRENT_SOURCE_DIR}/Rendering.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Camera.h
    ${CMAKE_CURRENT_SOURCE_DIR}/Frustum.h
    # añade más headers aquí si tienes
)

# Sources
set(GRAPHICS_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/Rendering.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Camera.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/Frustum.cpp
    # añade más cpp aquí si tienes
)

# Crear librería estática
add_library(silverGraphics STATIC ${GRAPHICS_SOURCES} ${GRAPHICS_HEADERS})

# Incluir directorio de headers
target_include_directories(silverGraphics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Estándar de C++
target_compile_features(silverGraphics PUBLIC cxx_std_17)

# Dependencia con silverMaths (ejemplo: Camera usa Vector3D)
target_link_libraries(silverGraphics PUBLIC silverMaths)
