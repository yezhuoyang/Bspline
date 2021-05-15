//
// Created by 叶卓杨 on 2021/5/8.
//

#include "BSpline.h"
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










}
