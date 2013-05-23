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
#define nobf 3							   //number of binary functions

using namespace std;
char msg[]="msg_s.txt";
char eEQU[]=".temp.txt";
char dEQU[]=".txt";


int getLength(string s)
	{
			int i=0;
			while(1)
			{
				if(s[i]!=NULL)
					i++;
				else
					break;
			}
			return i;
	}



void Encrypt(ifstream &fin,int *T,int NoBits)
	{
	//input stream , binary array , number of bits.

		int ans=0;
		string seq;
		int cnt=0;
		int first=1;
		int i;

		int flag=0;
		int k=0;
		while(!fin.eof())
		{
			getline(fin,seq);
			string op;
			string op1;
			ans=0;
			int first=1;
			int length=getLength(seq);
			if(length==0)
				break;

			i=0;
		
				if(seq=="#")
				{	
					flag=1;
					cnt=0;
					k=0;
					continue;
				}
	
				if(flag==0)
				{	
					for(int j=0; i<length ; j++ )
					{
					
						if(cnt!=j)
						{
							op=seq[i];
							i++;
										
							if(first==1)
							{
								if(op=="|" || op=="&")
								{
									op+=seq[i];
									i+=2;
								}
					
								if(op=="||")
								{
										int a=T[j];
										int b;
										if( (j+1)== cnt)
										{
											b=T[j+2];
											j+=2;
										}
										else
											b=T[++j];	
							
										ans=a || b;
							
								}
								else if(op=="&&")
								{
										int a =T[j];
										int b;
										if( (j+1)== cnt)
										{
											b=T[j+2];
											j+=2;
										}
										else
											b=T[++j];	
										ans=a && b;	
						
								}
								first=0;
							}
							else					
							{
								if(op=="|" || op=="&")
								{
										op+=seq[i];
										i+=2;
								}			
					
								if(op=="||")
								{
									int a =T[j];
									ans = ans || a;
									//cout<<op<<a;
								}
								else if(op=="&&")
								{
									int b=T[j];
									ans = ans && b;
									//cout<<op<<b;						
								}
							}
						}
					}//END:for
		
					T[k]=T[k]^ ans;

					k++;
					cnt++;
				}else if (flag==1)
				{
					for(int j=0; i<length ; j++ )
					{
						if(cnt!=j)
						{
							op=seq[i];
							i++;
										
							if(first==1)
							{
								if(op=="|" || op=="&")
								{
									op+=seq[i];
									i+=2;
								}
					
								if(op=="||")
								{
										int a=T[j];
										int b;
										if( (j+1)== cnt)
										{
											b=T[j+2];
											j+=2;
										}
										else
											b=T[++j];	
							
										ans=a || b;
								
								}
								else if(op=="&&")
								{
										int a =T[j];
										int b;
										if( (j+1)== cnt)
										{
											b=T[j+2];
											j+=2;
										}
										else
											b=T[++j];	
										ans=a && b;	
						
								}
								first=0;
							}
							else					
							{
								if(op=="|" || op=="&")
								{
										op+=seq[i];
										i+=2;
								}			
					
								if(op=="||")
								{
									int a =T[j];
									ans = ans || a;
									
								}
								else if(op=="&&")
								{
									int b=T[j];
									ans = ans && b;
												
								}
							}
						}
					}//END:for
		
					T[k]=T[k]^ ans;
			
					k++;
					cnt++;
			}
			
	
	}

	return;	
	}//END:Encrypt()



#include	<stdlib.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	int key = 1024;
	

	ifstream fin1("blocks.txt");
	ifstream fin("generate.txt");

//	char *  T;
	int i = 0;	
	if(fin1.is_open()) {

        while(getline(fin1, T)){
	 i++;
         fin1 >> T;
	
	 cout << T <<endl <<endl;     
	
	if( i == 1024 ) {
            break; 

          }    
 
//	Encrypt(fin,T ,key ) ;

//	for(int i =0 ; i < 1024 ; i++)
//	   Tr[i] = T[i];

//	Encrypt(fin,Tr ,key ) ;
        
//	for(int i =0 ; i < 1024 ; i++)
//	  cout <<  Tr[i];

  	
	}
	}
//	int * T = new  int [1024];
//	ifstream fin("generate.txt");
//	Encrypt(fin,T ,1024 ) ;
//	for(int i =0 ; i < 1024 ; i++)
//	  cout  << T[i] ;
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
