
using namespace std;
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>



void winter2013Reader(string names[],bool IDS[],ifstream & fileInput){
     string name;
     bool id;
     int spot;
     while (fileInput >> id >> name >> spot){
           names[spot]=name;
           IDS[spot]=id;
           
           }
     }
     
void addOrRemove(string names[],bool IDS[],ifstream & fileInput){
     string name;
     bool id;
     int spot=0;
     while (fileInput >> id >> name ){
           names[spot]=name;
           IDS[spot]=id;
           spot++;

           
           }
           
           
     }  
        
void deleteSpot(string names[], string name){
     for (int i=0;i<50;i++){
           if(names[i]==name){
           names[i]="empty";                   
           }
           }
     }     

bool checkIfFull(string names[]){
     for (int i=0;i<50;i++){
           if(names[i]=="empty"){
           return true;                   
           }
     }
     }     
     
  void assignSpot(string names[],bool IDS[], string name,bool id )
  {
     if(!checkIfFull(names))
    
     for (int i=0;i<50;i++)
     {
             if (!id)
             {
             i=25;
             }
           if(names[i]=="empty")
          {
          names[i]=name;
          IDS[i]=id;                   
          }
     }
     }   
   
   
   void moveFaculty(string names[],bool IDS[]){
     for (int i=25;i<50;i++){
           if(IDS[i]){
           assignSpot(names,IDS,names[i],IDS[i]);                   
           }
     }
     }  
   
    void outToFile(ofstream & fileOutput,string names[],bool IDS[]){
     for (int i=0;i<50;i++){
           fileOutput << IDS[i] << names[i] << i <<endl;                  
           }
     }
     
   
int main()
{
    string  masterNames[50]={};
    bool  masterIDS[50]={};
    string  addRemoveNames[10]={};
    bool  addRemoveIDS[10]={};
    
    ofstream fout("parkingS14.txt");
    ifstream fin;
    ifstream fin2;
    ifstream fin3;
      
    fin.open("parkingF13.txt");
    fin2.open("removeW14.txt");
    
    winter2013Reader(masterNames,masterIDS,fin);  
    addOrRemove(addRemoveNames,addRemoveIDS,fin2);
     
    for (int i=0;i<10;i++)
    {
    deleteSpot(masterNames,addRemoveNames[i]);
    }
    
    for (int a=0;a<10;a++)
    {
    addRemoveNames[a].clear();
    addRemoveIDS[a]=0;
    }
    
    fin3.open("assignW14.txt");
     addOrRemove(addRemoveNames,addRemoveIDS,fin3);
     for(int i=0;i<10;i++){
     cout << masterNames[i]<< endl;         
    system("pause");                 
    }
     
     for(int i=0;i<10;i++)
     {
     if (!(masterNames[i].empty())){
     assignSpot(masterNames,masterIDS,addRemoveNames[i],addRemoveIDS[i]);
     }
     }
     
     
     moveFaculty(masterNames,masterIDS);
     
     outToFile(fout,masterNames,masterIDS);
   system("pause");
   return 0;
}

