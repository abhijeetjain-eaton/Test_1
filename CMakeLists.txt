cmake_minimum_required(VERSION 3.20)
project(FileReaderApp VERSION 1.0.0 LANGUAGES CXX)

# ---- C++20 standard ----
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# ---- Sources ----
set(SOURCES
    src/TextFileReader.cpp
    src/LineCountProcessor.cpp
    src/WordCountProcessor.cpp
    src/FileReaderService.cpp
    src/main.cpp
)

# ---- Executable ----
add_executable(file_reader ${SOURCES})
target_include_directories(file_reader PRIVATE ${CMAKE_SOURCE_DIR}/include)

# ---- Compiler warnings ----
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(file_reader PRIVATE -Wall -Wextra -Wpedantic)
elseif(MSVC)
    target_compile_options(file_reader PRIVATE /W4)
endif()
