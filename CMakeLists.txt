cmake_minimum_required(VERSION 3.19)
project(core)


set(EIGEN_DIR  /Users/yezhuoyang/Desktop/eigen)
include_directories(${EIGEN_DIR})


set(ANN_DIR  /Users/yezhuoyang/Desktop/ann_1.1.2)
include_directories(${ANN_DIR}/include)

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