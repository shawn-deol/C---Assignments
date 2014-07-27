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
cout<<" for the year " << year << "exam is required next year"<<endl;
 }   
 else
 cout<< " for the year " << year<<"does not require a Drive Clean exam"<<endl;
}
 system ("pause");
infile.close();
return 0;
}
/*
 for the year 2014 Your car needs a Drive Clean Exam
 for the year 1986 your car does not require a Drive Clean exam
 for the year 2013 Your car needs a Drive Clean Exam
 for the year 2000 your car does not require a Drive Clean exam
Press any key to continue . . .
*/
