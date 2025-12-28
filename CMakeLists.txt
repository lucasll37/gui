cmake_minimum_required(VERSION 3.20)
project(meu_app VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ========================================
# Configuração de Build Type
# ========================================
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Tipo de build (Debug ou Release)" FORCE)
endif()

message(STATUS "========================================")
message(STATUS "Projeto: ${PROJECT_NAME} v${PROJECT_VERSION}")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Compilador: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "========================================")

# ========================================
# Flags de Compilação
# ========================================
if(MINGW OR CMAKE_COMPILER_IS_GNUCXX)
    # Flags comuns
    add_compile_options(-Wall -Wextra -Wpedantic)
    
    # Flags específicas de Debug
    set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -DDEBUG -D_DEBUG")
    
    # Flags específicas de Release
    set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")
    
elseif(MSVC)
    # Flags comuns
    add_compile_options(/W4)
    
    # Flags específicas de Debug
    set(CMAKE_CXX_FLAGS_DEBUG "/Zi /Od /DEBUG /D_DEBUG")
    
    # Flags específicas de Release
    set(CMAKE_CXX_FLAGS_RELEASE "/O2 /DNDEBUG")
endif()

# ========================================
# Biblioteca Core
# ========================================
add_library(meu_app_core
  src/core/core.cpp
)

target_include_directories(meu_app_core
  PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

# ========================================
# GUI Application
# ========================================
add_subdirectory(apps/gui)

# ========================================
# Informações Finais
# ========================================
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "🔧 Modo DEBUG ativado")
    message(STATUS "   - Símbolos de debug: Sim")
    message(STATUS "   - Otimização: Desativada")
    message(STATUS "   - Console: Ativado (apps/gui)")
else()
    message(STATUS "🚀 Modo RELEASE ativado")
    message(STATUS "   - Símbolos de debug: Não")
    message(STATUS "   - Otimização: Máxima")
    message(STATUS "   - Console: Desativado (apps/gui)")
endif()
message(STATUS "========================================")

# cmake_minimum_required(VERSION 3.20)
# project(meu_app VERSION 0.1.0 LANGUAGES CXX)

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_EXTENSIONS OFF)

# # Biblioteca core
# add_library(meu_app_core
#   src/core/core.cpp
# )

# target_include_directories(meu_app_core
#   PUBLIC
#     ${PROJECT_SOURCE_DIR}/include
# )

# # warnings
# if (MSVC)
#   target_compile_options(meu_app_core PRIVATE /W4)
# else()
#   target_compile_options(meu_app_core PRIVATE -Wall -Wextra -Wpedantic)
# endif()

# add_subdirectory(apps/gui)
