// Shawn Deol
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

using namespace std;

int read(ifstream & fin,string bookName[],int similarityScore[50][50])
{
     int numberOfBooks;
     fin >>numberOfBooks;
     for (int i=0;i>numberOfBooks;i++)
     {
     fin >> bookName[i];
     for (int j=0;j>numberOfBooks;j++)
         {
         fin >> similarityScore[i][j]; 
         }
     }
     return numberOfBooks;
}

void newNovel(string newTitle, int newSimilarity[],string titles[], int similarity[50][50],int & numB)
{
     numB+=1;
    titles[numB]=newTitle; 
    for(int i=0;i<numB;i++)
    {
    similarity[numB][i]=newSimilarity[i];    
    similarity[i][numB]=newSimilarity[i];
    }      
}

void mostSimilar(string title,int numberOfBooks,string titles[],int similarity[50][50], int & mostSimilarIndex, int & leastSimilarIndex)
{
     int titleIndex;
    for (int i=0;i<numberOfBooks;i++)
    {
        if (titles[i]==title)
        {
        titleIndex=i;
        i=numberOfBooks;
        }    
    }
    
     int mostSimilar=10;
     int leastSimilar=0;
     for(int i=0;i<numberOfBooks;i++)
     {
         if (similarity[titleIndex][i]<mostSimilar)
         {
          mostSimilar=similarity[titleIndex][i];                             
          mostSimilarIndex=i; 
         }
         else if(similarity[titleIndex][i]>leastSimilar && i>0)
         {
          leastSimilar=similarity[titleIndex][i];                             
          leastSimilarIndex=i; 
         }
     }
     
     
}

void printDB(ofstream & fout,string titles[],int similarity[50][50],int numB)
{
 for (int i=0;i<numB;i++)
 {
  fout << titles[i]<< "";    
      for (int j=0;j<numB;j++)
      {
       fout<< similarity [i][j]<< "";    
      }   
  fout << endl;
 }    
     
     
}
int main()
{
 ifstream fin;
 fin.open("similar.txt");
 ofstream fout;
 string books[50];
 int score[50][50];
 
 read(fin,books,score);
    system("PAUSE");
    return 0;
}

