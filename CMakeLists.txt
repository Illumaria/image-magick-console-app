cmake_minimum_required(VERSION 3.16)
project(image_magick_test)

set(CMAKE_CXX_STANDARD 11)

set(SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/src/commands.cpp
            ${CMAKE_CURRENT_SOURCE_DIR}/src/tokenizer.cpp
        )

add_library(commands SHARED
            ${CMAKE_CURRENT_SOURCE_DIR}/include/commands.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/src/commands.cpp
        )
add_library(tokenizer SHARED
            ${CMAKE_CURRENT_SOURCE_DIR}/include/tokenizer.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/src/tokenizer.cpp
        )

target_include_directories(commands PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(tokenizer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

find_package(PkgConfig REQUIRED)

# Uncomment and specify the path to use custom PKG_CONFIG_PATH
#set(ENV{PKG_CONFIG_PATH} "$ENV{PKG_CONFIG_PATH}:/path/to/pkgconfig/directory")

pkg_check_modules(PKG_IMAGEMAGICK REQUIRED IMPORTED_TARGET Magick++>=6.9.0)

target_link_libraries(commands PUBLIC PkgConfig::PKG_IMAGEMAGICK)

add_executable(image_magick_test ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

target_link_libraries(image_magick_test PUBLIC PkgConfig::PKG_IMAGEMAGICK commands tokenizer)