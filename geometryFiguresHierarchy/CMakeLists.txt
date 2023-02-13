cmake_minimum_required(VERSION 3.20)
project(lab)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab main.cpp point.h point.cpp segment.h segment.cpp shape.h shape.cpp polygon.h polygon.cpp circle.h circle.cpp triangle.h triangle.cpp ellipse.h ellipse.cpp quadrangle.h quadrangle.cpp)
if (MSVC)
    target_compile_options(lab
            PRIVATE /W4          # warnings level
            PRIVATE /WX          # treat all warnings as errors
            )
else ()
    target_compile_options(lab
            PRIVATE -Wall        # basic set of warnings
            PRIVATE -pedantic    # modern C++ inspections
            PRIVATE -Werror      # treat all warnings as errors
            )
endif ()
