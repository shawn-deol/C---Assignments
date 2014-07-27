//Question 3
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;
int main ()

{
double width=0, length=0,  limitingValue=0,  maxVolume=10000000, volume=0;
for (int i=0; i<5; ){
       
do{
    cout << "Please enter a correct value for width and length" << endl;
    cin >> width >> length;
    }
       while(width<0||length<0);
    
    if (width>length)
    limitingValue=length;
    else
    limitingValue=width;
        
        for  (double j=0.1;j<limitingValue;j+=0.1){
         volume=(width-j)*(length-j)*j;
         if(volume>maxVolume){
         j=limitingValue;                    
                              }
         maxVolume=volume;
         
         }
       cout << "the max volume is " << volume << endl;
       
       
       
        i++;
   }
    
    system("PAUSE");
    return 0;   
    }
