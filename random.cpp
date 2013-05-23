#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <cmath>
#include <time.h>
#include <algorithm>
#include <cstring>

#define nob 7								 //Number of Bits (0-127 = 128 )
#define randomArray_nop 1024				//
#define nobf 3	


using namespace std;

	// Function returns the Boolean operator at the specified position
	char* tokenizeList(char list[] , int pos)
	{
		char *p =NULL;
	   	if (pos==0)
			p="||";
  	       else if (pos==1)
			p="&&";
		return (p);
	}//END:tokenizeList()

	// Function to generate a Random Number	
	int getRandomIndex(int *rA)
	{
		srand (time(NULL));
		for(int i=0;i<randomArray_nop;i++)
			// 1024 
			rA[i]=0+rand()%nobf;
	}//END:getRandomIndex()

	// Function to generate random sequence of Boolean functions AND, OR, NOT 
	void generateRandomSequence(ofstream &fout,int NoBits)
	{
		//storing all boolean functions
		char list[]="|| && ^";		      		      
		int Rnum=0;
		//for storing the randomly returned boolean Functions();
		string res;			
		string rest;
		//Create an array of random generated 
		//1024

		int *randomArray=new int [randomArray_nop];
		
		for(int i=0;i<NoBits;i++)
		{
			getRandomIndex(randomArray);
		
			srand(time(NULL));
			//128 bits ; 1024 - 4 =  1020
			Rnum=1+rand()% (randomArray_nop-NoBits);
		 	 //cout <<"Value of Rnum " << Rnum;
		 	for( int j=Rnum;j<(Rnum+NoBits)-2;j++ )
			{// j = 860 ; j < 862;i 861
				
			 	int a=randomArray[j];
			//	 cout << " Value of a " << a <<endl;	
				res=tokenizeList(list,a);
			
				//Creating a list of boolean fuctions 
				//if part for the first boolean fun and the else part for the rest of the fun();
				if(j==Rnum)
				{
					rest =res; 
					rest+=" ";
				}
				else
				{
					
					rest+=res;
					rest+=" ";
					
					if(res=="~")
					{
						a=0+rand()%2;
						if(a%2==0)
							rest+="||";
						else
							rest+="&&";
						
						rest+=" ";	
					}	
					
				}//END:else
		       			
			
			}//END:for
				
				cout<<"\nEquation ["<<i<<"]  = "<<rest;	
				fout<<rest<<endl;
			       //Sleep to generate unique number			
				sleep(1);
		}
	}//END:generateRandomSequence()

int main(){
ofstream fout("dEQU.txt");
		if(!fout)
		{
			cout<<"Error in opening file.............";
		}
	
		//generating boolean functions for 2 sets of equations.........
		//Generation of functions for the set one of equations.
		int NoBits = 4;	
		generateRandomSequence(fout,NoBits);	

}
