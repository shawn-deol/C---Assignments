//Kiarash Amini
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>

using namespace std;
int main ()
{
    ifstream infile;
    infile.open("etest.txt");

    int year,veh_year;
while (infile >> year >> veh_year)
{
int car_age= year - veh_year;

if (year > 1987 && car_age >= 7)
 {
 if( ( veh_year % 2 ==0 && year%2 == 1) || (veh_year %2==1 && year % 2==0) ) 
 cout<<" for the year " << year << " Your car needs a Drive Clean Exam"<<endl;   
 else
cout<<" for the year " << year << " your car is good, no drive 
clean exam is required until until next year"<<endl;
 }   
 else
 cout<< " for the year " << year << " your car does not require a Dr
 ive Clean exam"<<endl;
}
 system ("pause");
infile.close();
return 0;
}
/*
*/
