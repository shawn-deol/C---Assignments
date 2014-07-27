//Question 3

#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>
using namespace std;
double distance(double x1, double y1,double x2,double y2)
{
  return  sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));     
}
       
void converter (int latD,int latM, int longD, int longM, double & x, double & y)
//double &lat, double minute,double &longt, double minute2)
{
      y= 111*(latD+latM/60.0);
      latD *= M_PI/180;
      x= 111*(longD+longM/60.0)*cos(latD);
}

void closestInd(int numOfShops,double x[], double y[],int &index1, int &index2)
{
     double best=10000;
     for(int j=0;j<numOfShops;j++)
     {
        for(int k=0;k<numOfShops;k++)
        { 
           if (j != k)
           {
              double d = distance(x[j],y[j],x[k],y[k]);
              if (d<best)
              {
                  best = d;
                  index1 = j;
                  index2 = k;                                                     
               }
           }
        }
     }
}

int main ()
{
    string name;
    string names[15];
    double xCoord[15];
    double yCoord[15];
    int i=0;
    string ShopName;
    int degree1,min1,degree2,min2;
    double x,y;
    int a=0,b=0;
    
     ifstream infile;
     infile.open("coffee.txt"); 
     if(!infile)
     {
        cout << " File error.\n";
        system("PAUSE");
        return 0;  
     }
     while (infile>>name>>degree1>>min1>>degree2>>min2)
     {
           names[i]=name;
           converter(degree1,min1,degree2,min2,x,y);
           xCoord[i]=x;
           yCoord[i]=y;
           i++;
     }
    closestInd(i,xCoord,yCoord,a,b);
    cout<<names[a]<<names[b]<<endl;
    system("PAUSE");
    return 0;   
}

