cmake_minimum_required(VERSION 3.19)
project(spline_fitting)


SET(CMAKE_C_COMPILER mingw32-gcc)
SET(CMAKE_CXX_COMPILER mingw32-g++)

set(EIGEN_DIR  /Users/lez/Desktop/CGCourse/Bspline-main/eigen-3.3.9)

include_directories(${EIGEN_DIR})


set(ANN_DIR  /Users/yezhuoyang/Desktop/ann_1.1.2)

include_directories(${ANN_DIR}/include)

link_directories(${ANN_DIR}/lib)

find_library(ANN
        libANN.a
        ${ANN_DIR}/lib)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/core)

set(incs
        core/BSpline.h
        core/Spline_curve_fitting.h
        )

set(srcs
        core/BSpline.cpp
        core/Spline_curve_fitting.cpp
        )


add_executable(spline_fitting_test ${incs} ${srcs} readWrite.h  readWrite.cpp main.cpp )


target_link_libraries(
        spline_fitting_test
        ${ANN_DIR}/lib/libANN.a
)