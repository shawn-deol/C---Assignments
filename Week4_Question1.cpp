//Question 3
using namespace std;
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>




int Decode(string colour)
{
string Colours[10]= {"black","brown","red","orange","yellow","green"
,"blue","violet","grey","white"};
for (int i=0;i<10;i++){      
if (Colours[i]==colour){     
return i;
         }
       }
}

int resistorValue(string firstColour,string secondColour,string thirdColour)
{
int a=Decode(firstColour);
int b=Decode(secondColour);
int c=Decode(thirdColour);
return ((a*10)+b)*pow(10.0,c)+0.1;

}



int main ()
{
    int numberOfResistors=0;
    int Resistors[10]={0,0,0,0,0,0,0,0,0,0};
    string a,b,c;

    ifstream infile;
    ofstream outfile ("report.txt");
    infile.open("resist.dat");
        while (infile >> numberOfResistors){
 
              for(int i=0;i<numberOfResistors;i++){
               infile >> a >> b >> c;
              Resistors[((resistorValue(a,b,c)/100)-1)]+=1; 

                                                                 
                    }
              }
              
         for (int i=0;i<10;i++){
             if ((250-Resistors[i])>0){
            outfile << "We need " << (250-Resistors[i])<<" "<< (i+1)*100
            << " Ohm Resistors" <<endl;
                                   }
          
            }     
    infile.close();
    system("PAUSE");
    return 0;   
    }

/*
We need 17 300 Ohm Resistors
We need 9 400 Ohm Resistors
We need 9 900 Ohm Resistors
*/
