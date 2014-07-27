//Question 1
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

//Created perimeter and area functions


double perimeterTri(double S1, double S2, double S3){
    return S1+S2+S3;        
}

double perimeterQuad(double S1, double S2, double S3, double S4){
    return S1+S2+S3+S4;        
}

double perimeterSector(double radius, double angle){
    return (radius*2)+radius*(angle/360)*2*M_PI;        
}

double areaSector(double radius, double angle){
    return ceil((angle/360.0)*radius*radius*M_PI);        
}

double areaTri(double S1, double S2, double S3)
{
    double area;
    double s;
    s=(perimeterTri(S1,S2,S3)/2.0);
    area=sqrt(s*(s-S1)*(s-S2)*(s-S3));   
    return (area);       
}

double areaQuad(double S1, double S2, double Diagonal, double S3, double S4)
{      
    return areaTri(S1,S2,Diagonal)+areaTri(Diagonal,S3,S4);       
}

//Created Cost and discount checking functions

bool discountCheck(double mowCost,double weedCost)
{
        return((mowCost>50.0)||((mowCost>40.0)&&(weedCost>10.0)));
     
        }

double mowCost(double area){
       return ceil(area)*0.07;     
       }
       
double trimCost(double perimeter){
       return ceil((perimeter))*0.15;     
       }
       
double taxes(double cost ){
       return cost*.13;
       }

//Console writer function       
using namespace std;       
void consoleWriter( int jobNumber,bool trim,double actualPerim,double mowedArea)
     {
double weedCost=0;
double totalCost=0;
double untaxedTotal=0;
double mowingCost=0;

mowingCost=(mowCost(mowedArea));
             
      if(trim)
      {
      weedCost=trimCost(actualPerim);         
      }      
        if (discountCheck(mowingCost,weedCost))
        {
        untaxedTotal-=10.0;                   
        }      
        untaxedTotal+=(weedCost+mowingCost+12.0);
        totalCost=untaxedTotal+taxes(untaxedTotal);
          
    cout <<setprecision(2)<<fixed
    << jobNumber << setw(9)<< ceil(mowedArea) << setw(11)<< mowingCost 
    << setw(10)<< actualPerim<< setw(11) << weedCost<< setw(9) <<
    discountCheck(mowingCost,weedCost)<< setw(9)
    << taxes(untaxedTotal)<< setw(10) << totalCost<< endl;
    
    
    return;                                                              
     }
          
int main ()
{ 
    //Declare variables and create input reader
    int jobNumber;
    bool trim;
    double mowedArea,actualPerim;
    double s1,s2,s3,s4,diagonal,angle;
    
    string shape;
    ifstream infile;
    
    infile.open("jobs.txt");    
      //print headers              
    cout << "job # " << "Mowed Area " << "Mow Cost "<<"Actual Perim  "
            << "Weed Cost " << "Discount " << "Taxes "  
             << "Total Cost " <<endl;  

     //Determine shape type and therefore which input is required
    while (infile >> jobNumber)
    {
        infile >> trim >> shape;

        if (shape=="tri")
        {
            infile >> s1 >> s2 >> s3;
            mowedArea=areaTri(s1,s2,s3);
            actualPerim=perimeterTri(s1,s2,s3);

        }
                          
        else if(shape=="quad")
        {
            infile >> s1 >> s2 >> diagonal >> s3 >> s4;    
            mowedArea=areaQuad(s1,s2,diagonal,s3,s4);
            actualPerim=perimeterQuad(s1,s2,s3,s4);
        }  
        
        else 
        {
            infile >> s1 >> angle;
            mowedArea=areaSector(s1,angle);
            actualPerim=perimeterSector(s1, angle);
        }
    
      //Call console writer to write the next line of code              
        consoleWriter( jobNumber, trim,actualPerim,mowedArea);
    
    }
    
  
system("PAUSE");
    return 0;      

    }
/*
job # Mowed Area Mow Cost Actual Perim  Weed Cost Discount Taxes Total Cost
7100   600.00      42.00    120.00      18.00        1     8.06     70.06
7101     9.00       0.63     12.00       0.00        0     1.64     14.27
7102     3.00       0.21      7.57       0.00        0     1.59     13.80
7103   784.00      54.88    112.00      16.80        1     9.58     83.26
7104   158.00      11.06     51.42       7.80        0     4.01     34.87
7105    71.00       4.97     34.40       0.00        0     2.21     19.18
7106  2324.00     162.68    192.80      28.95        1    25.17    218.80
7107   198.00      13.86     57.59       0.00        0     3.36     29.22
7108   502.00      35.14     89.60       0.00        0     6.13     53.27
7109    90.00       6.30     38.21       5.85        0     3.14     27.29
7110     9.00       0.63     11.80       0.00        0     1.64     14.27
7111     4.00       0.28      9.00       1.35        0     1.77     15.40
7112    71.00       4.97     33.60       5.10        0     2.87     24.94
Press any key to continue . . .
*/
