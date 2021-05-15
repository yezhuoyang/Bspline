//
// Created by 叶卓杨 on 2021/4/19.
//

#include "BSpline.h"
#include <fstream>

#include <ANN/ANN.h>


void BSplineCurve::setNewControl(const vector<Vector2d> &controlPs) {





}


Vector2d BSplineCurve::getPos(const Parameter &para) const {




}



Vector2d BSplineCurve::getFirstDiff(const Parameter &para) const {




}

Vector2d BSplineCurve::getSecondDiff(const Parameter &para) const {


}

double BSplineCurve::getCurvature(const Parameter &para) const {


}

Vector2d BSplineCurve::getTangent(const Parameter &para) const {

}

Vector2d BSplineCurve::getNormal(const Parameter &para) const {

}

Vector2d BSplineCurve::getCurvCenter(const Parameter &para) const {

}

double BSplineCurve::findFootPrint(const vector<Vector2d> &givepoints, vector<Parameter> &footPrints) const {

}

BSplineCurve::Parameter BSplineCurve::getPara(int index) const {

}

VectorXd BSplineCurve::getCoffe(const Parameter &para) const {

}

bool BSplineCurve::checkSameSide(Vector2d p1, Vector2d p2, Vector2d neip) {

}

bool BSplineCurve::checkInside(Vector2d p) {

}

int BSplineCurve::isLeft(Vector2d p0, Vector2d p1, Vector2d p2) {

}

MatrixXd BSplineCurve::getSIntegralSq() {

}

MatrixXd BSplineCurve::getFIntegralSq() {

}