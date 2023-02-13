cmake_minimum_required(VERSION 3.20)
project(lab1-ssharkov03)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab1-ssharkov03 main.cpp complexNumbers.h complexNumbers.cpp)
if (MSVC)
    target_compile_options(lab1-ssharkov03
            PRIVATE /W4          # warnings level
            PRIVATE /WX          # treat all warnings as errors
            )
else()
    target_compile_options(lab1-ssharkov03
            PRIVATE -Wall        # basic set of warnings
            PRIVATE -pedantic    # modern C++ inspections
            PRIVATE -Werror      # treat all warnings as errors
            )
endif()
