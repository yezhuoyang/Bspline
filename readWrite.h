//
// Created by 叶卓杨 on 2021/5/8.
//

#pragma once


#include <string>
#include <vector>
#include <Eigen/Core>

using namespace std;




class readWrite {

    static bool readData(const string& filename, vector<Vector2d>& points);


    static bool writeDate(const string& filename,const vector<Vector2d>& points);



};
