
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
using namespace std;
int main()
{
int inputNumber, part1, part2;

cout << " Please enter input" << endl;

cin >> inputNumber; 
part1=inputNumber/1000;
part2=inputNumber%1000;
cout << part1 << ",";

 if (abs(inputNumber)%1000<10) 
{
     cout<< "00" << abs(part2) <<  endl;
     }
 else if (abs(inputNumber)%1000<100) 
 {                       
       cout<< '0' << abs(part2) <<  endl;                 
}           
 else {
      cout<< abs(part2) <<  endl;
      }                         
    system("PAUSE");
    return 0;
}

/*
 Please enter input
101010
101,010
Press any key to continue . . .

 Please enter input
-101010
-101,010
Press any key to continue . . .

 Please enter input
000001000
1,000
Press any key to continue . . .

 Please enter input
-000000101010
-101,010
Press any key to continue . . .

*/
