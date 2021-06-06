//
// Created by 叶卓杨 on 2021/5/8.
//

#include "core/BSpline.cpp"
#include "core/Spline_curve_fitting.cpp"
#include "readWrite.cpp"

#include <iostream>


/*
 * Main function for Spline curve fitting
 *
 */
int main(int argc, char *argv[]){

    char inpf[200],*input;
    argc--;
    argv++;					//Skip program name arg

    if(argc<1)
    {
        cout<<"Input file:"<<endl;
        //cin>>inpf;
        strcpy(inpf,"01.txt");
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
//    for(int i=0;i<points.size();i++)
//		printf("%f %f\n",points[i].x,points[i].y); 

    scf.apply(points, curve, 28, 50, 0.005, 0.005, 0.0001, SPHERE_INIT);

//	CReadWriteAsc::writeAsc( inFileName, points);
    readWrite::writeDate( outFileName1, curve.getControls());
    readWrite::writeDate( outFileName2, curve.getSamples() );



}
