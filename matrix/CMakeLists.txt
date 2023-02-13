cmake_minimum_required(VERSION 3.20)
project(lab)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab main.cpp matrix.h matrix.cpp)
if (MSVC)
    target_compile_options(lab
            PRIVATE /W4          # warnings level
            PRIVATE /WX          # treat all warnings as errors
            )
else()
    target_compile_options(lab
            PRIVATE -Wall        # basic set of warnings
            PRIVATE -pedantic    # modern C++ inspections
            PRIVATE -Werror      # treat all warnings as errors
            )
endif()
