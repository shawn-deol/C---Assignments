// Shawn Deol
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;


const int NSIZE = 10;

void countFreq(ifstream & fin, int freq[]){
int mark;
    while (fin>> mark) {
    freq[(mark/10)]+=1;
          }
          
}    
   
void draw(ofstream & fout, int n){
        for (int i=0; i<n; i++){
            fout << "*" ;
            }
            fout << endl;
     }


int main()
{
    ifstream fin;
    ofstream fout ("results.txt");
    fin.open("midterm.dat");
    int freq[NSIZE]={0};
    countFreq(fin, freq);
    
          for (int a=0; a<NSIZE; a++){
          
          draw(fout, freq[a]);
          }
system("pause");
return 0; 
}

