//Question 3
using namespace std;
#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <string>

void fileReader(ifstream & infile, string firstArray[],bool secondArray[]){
     bool ID;
     string name;
     int parkingSpot;
     while (infile>>ID>>name>>parkingSpot){
            firstArray[parkingSpot]=name;
            secondArray[parkingSpot]=ID;
           }
     }


void addOrRemove(ifstream & infile,string firstArray[],bool secondArray[] ){
     bool ID;
     string name;
     int i=0;
     while (infile>>ID>>name){
            firstArray[i]=name;
            secondArray[i]=ID;
            i++;
           }
     }

void deleteAndFree(string name,string firstArray[],bool secondArray[],bool ID ){

for (int i=0;i<50;i++){
    if (firstArray[i]==name){
      firstArray[i]=="empty";                     
      }
     }
    }
     

int main ()
{
    string masterNames[50]={0};
    bool masterIDs[50]={0};
    string names[10]={0};
    bool IDs[10]={0};
    
    ifstream fin ("parkingF13.txt");
    ofstream fout ("report.txt");

    fin.close();
    system("PAUSE");
    return 0;   
}


