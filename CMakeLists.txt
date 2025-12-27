cmake_minimum_required(VERSION 3.20)
project(meu_app VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Biblioteca core
add_library(meu_app_core
  src/core/core.cpp
)

target_include_directories(meu_app_core
  PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

# warnings
if (MSVC)
  target_compile_options(meu_app_core PRIVATE /W4)
else()
  target_compile_options(meu_app_core PRIVATE -Wall -Wextra -Wpedantic)
endif()

add_subdirectory(apps/gui)
