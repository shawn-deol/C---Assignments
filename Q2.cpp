// Shawn Deol
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
double inputAngle,inputRadius,coneVolume,coneHeight;

cout << " Please input Angle" << endl;
cin >> inputAngle;

cout << " Please input radius " << endl;
cin >> inputRadius;

if ( inputRadius <= 0 ){
     cout << " Invalid radius size " << endl;
     system("PAUSE");
    return 0;
     } 

inputAngle = inputAngle*((M_PI)/180.0);
coneHeight = inputAngle*inputRadius;
coneVolume = (1.0/3.0)*M_PI*inputRadius*inputRadius*coneHeight;

cout << "your cone volume is " << coneVolume << endl;

    system("PAUSE");
    return 0;
}
/*
 Please input Angle
90
 Please input radius
1
your cone volume is 1.64493
Press any key to continue . . .

 Please input Angle
180
 Please input radius
0
 Invalid radius size
Press any key to continue . . .

*/




