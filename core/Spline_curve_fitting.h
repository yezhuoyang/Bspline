//
// Created by 叶卓杨 on 2021/5/8.
//
#include "BSpline.h"

typedef enum {RECT_INIT, SPHERE_INIT} EInitType;

class Spline_curve_fitting
{
public:
    Spline_curve_fitting(void) {}
    ~Spline_curve_fitting(void){}


    /*
     * Fitting B-Spline Curves to point Clouds
     */
    double apply(const vector<Vector2d>& points,
                 BSplineCurve& curve,
                 int controlNum=28,
                 int maxIterNum=30,
                 double alpha=0.002,
                 double beta=0.005,
                 double epsilon=0.0001,
                 EInitType initType=SPHERE_INIT);

private:

    void initControlPoint(const vector<Vector2d>& points,
                          vector<Vector2d>& controlPs,
                          int controlNum,
                          EInitType initType);

};