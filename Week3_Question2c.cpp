//Question 1
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>


double Dist(double dX0, double dY0, double dX1, double dY1)
{
    return sqrt((dX1 - dX0)*(dX1 - dX0) + (dY1 - dY0)*(dY1 - dY0));
}


using namespace std;
int main ()
{
    int numberOfTrips;
    double totalCost=0, x1, x2, y1, y2, dayDistance, dayCost, totalDistance=0;
    char dirX, dirY;
    
    //Create infile and open taxiDir.text, also declare all 3 variables
    ifstream infile;
    ofstream outfile ("taxiDir2.txt");
    infile.open("taxiDir.txt");
     
     outfile<< "# Stop   " << "  Distance  " << " Cost    "<<" Total Dist "
        << "Total Cost" <<endl;
    while (infile >> numberOfTrips){
       dayDistance=0.0;
        dayCost=numberOfTrips*15.0;
        x1=0.0;
        y1=0.0;
        
        for (int j=0; j<numberOfTrips; j++){
            infile >> x2 >>dirX >> y2 >>dirY;
            
            if (dirX=='W')
            x2=x2*(-1.0);
            if (dirY=='S')
            y2=y2*(-1.0);
           
            dayDistance=dayDistance+Dist(x1,y1,x2,y2);
            //cout<<x2<<" "<<y2<<" "<<dayDistance<<" ";
            x1=x2;
            y1=y2;    
      
        }
        dayDistance=dayDistance+sqrt(x1*x1+y1*y1);
        //cout<<endl;        
        totalDistance+=dayDistance;
        dayCost=dayCost+dayDistance*2.10;
        totalCost+=dayCost;
            
        outfile <<setprecision(2)<<fixed << setw(5)<< numberOfTrips <<setw(11)
        << dayDistance <<setw(11)<< dayCost <<setw(11)<< totalDistance 
        <<setw(11)<< totalCost<<endl;

    }

    infile.close();
    system("PAUSE");
    return 0;   
    }


