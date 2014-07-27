
using namespace std;
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>


//inputs filestream data into master list arrays for name and ID

void winter2013Reader(string names[],bool IDS[],ifstream & fileInput)
{
     string name;
     bool id;
     int spot;
     while (fileInput >> id >> name >> spot)
     {
     names[spot]=name;
     IDS[spot]=id;
           
     }
}
//inputs filestream data into add array or remove array (same array)     
void addOrRemove(string names[],bool IDS[],ifstream & fileInput)
{
     string name;
     bool id;
     int spot=0;
     while (fileInput >> id >> name )
     {
         names[spot]=name;
         IDS[spot]=id;
         spot++;     
     }                 
}  
/*Takes master name array and replaces the 
name of those who want to be removed with "empty" 
*/      
void deleteSpot(string names[], string name)
{
 for (int i=0;i<50;i++)
 {
  if(names[i]==name)
  {
   names[i]="empty";                   
  }
 }
}     
//Loops through master name array and if an empty spot is found returns false
bool checkIfFull(string names[])
{
 for (int i=0;i<50;i++)
 {
  if(names[i]!="empty")
  {   
  }
  else
  return false;       
 }
}     

/* if lot is not full checks if input is student or faculty, if student
starts assigning parking spots starting at 25, otherwise starts at 0
only assigns spots if the name under the spot is "empty"
*/
void assignSpot(string names[],bool IDS[], string name,bool id )
{
 if(!checkIfFull(names))
 {
 int i=0;
 if (!id)
  {
   i=25;
  }
 for (;i<50;i++)
  {
   if(names[i]=="empty")
   {
       names[i]=name;
       IDS[i]=id;
       i=50;              
   }
  }
 }   
}
/*Moves faculty members between spots 25 and 50 to a spot under 25
moves students from spots 0-25 to spots over 25
*/   
void moveFaculty(string names[],bool IDS[])
{
 for (int i=25;i<50;i++)
 {
  if (IDS[i]&&names[i]!="empty")
  {
   assignSpot(names,IDS,names[i],IDS[i]);
   names[i]="empty";
  }
 }
 for (int i=0;i<25;i++)
 {
  if (!IDS[i]&&names[i]!="empty")
  {
   assignSpot(names,IDS,names[i],IDS[i]);
   names[i]="empty";
  }
 }
}
//Takes master name and id array and prints them to file, ignores empty spots   
void outToFile(ofstream & fileOutput,string names[],bool IDS[])
{
 for (int i=0;i<50;i++)
 {
  if (names[i]!="empty")
  {
   fileOutput << IDS[i]<<setw(20)<< names[i]<< " "   << i <<endl;   
  }               
 }
}
     
   
int main()
{
//4 arrays, 2 50 size master arrays for name and ID, 2 temp storage arrays for
// assigning names and ids and removing names and ids
    string  masterNames[50]={};
    bool  masterIDS[50]={};
    string  addRemoveNames[10]={};
    bool  addRemoveIDS[10]={};
//Creating 3 file readers and 1 file writer    
    ofstream fout("parkingS14.txt");
    ifstream fin;
    ifstream fin2;
    ifstream fin3;
//Opening the first 2 readers b/c program doesn't compile if all 3 are opened      
    fin.open("parkingF13.txt");
    fin2.open("removeW14.txt");
//Write into master ID array and master name array     
    winter2013Reader(masterNames,masterIDS,fin);  
//Write into temporary array with remove14 text file
    addOrRemove(addRemoveNames,addRemoveIDS,fin2);

//Deletes people from master name array   
    for (int i=0;i<10;i++)
    {
     deleteSpot(masterNames,addRemoveNames[i]);
    }
//Clears the temporary storage array
    for (int a=0;a<10;a++)
    {
    addRemoveNames[a].clear();
    addRemoveIDS[a]=0;
    }
//Open 3rd file reader b/c program is stupid
    fin3.open("assignW14.txt");
//Store values of assignW14.txt
    addOrRemove(addRemoveNames,addRemoveIDS,fin3);
    
//Assigns spots to the peopl on the assignW14 list
     for(int i=0;i<10;i++)
     {
      if (!(addRemoveNames[i].empty()))
      {
     assignSpot(masterNames,masterIDS,addRemoveNames[i],addRemoveIDS[i]);    
      }
     }
//Moves faculty to spots under 25, moves students to spots over 25
     moveFaculty(masterNames,masterIDS);
//outputs updated master name and master id arrays to a text file
     outToFile(fout,masterNames,masterIDS);
     
   return 0;
}

