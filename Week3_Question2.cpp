
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;
int main ()
{
double side1,side2,angle,square,rectangle,rhombus,parallelogram,shape;

cout << "Please input side length 1, side length 2 and the angle between" << endl;
cin >> side1 >> side2 >> angle;

if (side1<=0 || side2<=0 || angle<=0 || angle>=180) 
{
cout << "Invalid input please try again" << endl ;
system ("pause");
return 0;                     
}

if (90.5 >= angle && angle>=89.5){
if (fabs(side1-side2)<=0.1){
cout << "your shape is a square"<< endl;
}     
else  cout << "your shape is a rectangle"<< endl;    
     }
else if (fabs(side1-side2)<=0.1){
     cout << "your shape is a rhombus"<< endl;
     }
else cout << "your shape is a parelleogram"<< angle << endl; 

system ("pause");
return 0;    
}
