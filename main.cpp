//
// Created by 叶卓杨 on 2021/5/8.
//

#include "Spline_curve_fitting.h"
#include "readWrite.h"

#include <iostream>



int main(int argc, char *argv[]){
    char inpf[200],*input;
    argc--;
    argv++;					//Skip program name arg

    if(argc<1)
    {
        cout<<"Input file:"<<endl;
        cin>>inpf;
        input = inpf;
    }
    else input    = argv[0];

    string inFileName( input );
    string outFileName1 = inFileName + "_controls.txt";
    string outFileName2 = inFileName + "_spline.txt";

    BSplineCurve curve(0.002);
    Spline_curve_fitting scf;


    std::vector<Vector2d> points;
    readWrite::readData( inFileName, points );

    scf.apply(points, curve, 28, 50, 0.005, 0.005, 0.0001, SPHERE_INIT);

//	CReadWriteAsc::writeAsc( inFileName, points);
    readWrite::writeDate( outFileName1, curve.getControls());
    readWrite::writeDate( outFileName2, curve.getSamples() );








}
