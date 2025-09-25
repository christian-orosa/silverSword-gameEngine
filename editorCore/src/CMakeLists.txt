cmake_minimum_required(VERSION 3.15)
project(silverSword LANGUAGES CXX)

# Fuentes del ejecutable
set(SILVERSWORD_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
    # añade aquí más .cpp si tienes
)

# Crear ejecutable
add_executable(silverSword ${SILVERSWORD_SOURCES})

# Incluir headers propios
target_include_directories(silverSword PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Estándar de C++
target_compile_features(silverSword PUBLIC cxx_std_17)

# Linkear librerías internas del motor
target_link_libraries(silverSword
    PRIVATE
        Graphics      # usa Rendering, Camera, Frustum
        silverMaths   # depende de Vector3D, Matrix, Quaternion
)
