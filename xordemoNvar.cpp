//2 stage implementation n variables

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

char msg[]="msg_s.txt";
char eEQU[]=".temp.txt";
char dEQU[]="dEQU.txt";

using namespace std;

	// Function returns the Boolean operator at the specified position
	char* tokenizeList(char list[],int pos)
	{
		char *p ="\0";
	
		if (pos==0)
						p="||";
  	 else if (pos==1)
						p="&&";
						
	return (p);
	}//END:tokenizeList()

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

	// Function to generate a Random Number	
	int getRandomIndex(int *rA)
	{
		srand (time(NULL));
		
		for(int i=0;i<randomArray_nop;i++)
					rA[i]=0+rand()%nobf;
	}//END:getRandomIndex()

	// Function to generate random sequence of Boolean functions AND, OR, NOT 
	void generateRandomSequence(ofstream &fout,int NoBits)
	{
		//storing all boolena functions
		//char list[]="|| ~ &&";
		char list[]="|| && ^";		      		      
		int Rnum=0;
		//for storing the randomly returned boolean Fun();
		string res;			
		string rest;
		int *randomArray=new int [randomArray_nop];
		
		for(int i=0;i<NoBits;i++)
		{
			getRandomIndex(randomArray);
		
			srand(time(NULL));
			Rnum=1+rand()% (randomArray_nop-NoBits);
		 	
		 	for( int j=Rnum;j<(Rnum+NoBits)-2;j++ )
			{
			 	int a=randomArray[j];
				res=tokenizeList(list,a);
			
				//Creating a list of boolean fuctions 
				//if part for the first boolean fun and the else part for the rest of the fun();
				if(j==Rnum)
				{
					//strcpy(rest,res);
					rest =res; 
					rest+=" ";
					
				}
				else
				{
					//strcat(rest,res);
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
				sleep(1);
		}
	}//END:generateRandomSequence()
	
	//function converting the plain text to binary form
	void binary(int dec, int *T, int pos)
	{
		int temp_d=dec;
		int T1[nob];
		for(int i=0;i<nob;i++)
			T1[i]=0;
		int rem=0;
		int temp;
		int i=0;
		while(temp_d!=0)
		{
			temp=(temp_d%2);
			T1[i]=temp;
			i++;
			temp_d/=2;
		}
		int n_pos=pos+(nob-1);
		for(int j=0;j<i;j++)
		{
			T[n_pos]=T1[j];
			n_pos--;
		}
	return ;
	}//END:binary()

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
	
	void Decrypt(ifstream &fin,int *T, int NoBits)
	{
		int ans=0;
		string seq;

		int cnt=NoBits;
		int i;
		int flag=0;
		int k=NoBits;
	
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
					cnt=NoBits;
					k=NoBits;
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
										{
											b=T[++j];	
										}
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
										{
											b=T[++j];	
										}
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
						}//else
					}//END:for
					T[k]= T[k]^ ans;
			
					k--;
					cnt--;
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
										{
											b=T[++j];	
										}
										
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
										{
											b=T[++j];	
										}
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
					
					k--;
					cnt--;
			}
	}
	return;	
}//END:Decrypt()
	
void copy(ifstream & fin , ofstream &fout)
{
	string seq;
	string seq1;

	int length=0,length1;
	int q;
	while(!fin.eof())
	{
		getline(fin,seq);
		length=getLength(seq);
		if(length==0)
			break;
		length1=length;


		reverse(seq.begin(), seq.end());
		seq1+=seq+"\n";
	}
	
		seq1[(seq1.size()-1)]="";

		for(int i=seq1.size();i>=0;i--)
		{	
			int a=seq1[i];
			if(a>=0 && a<=127)
			{
				if(i==seq1.size())
					continue;
				
				fout<<seq1[i];
				cout<<seq1[i];
			}
		}
		fin.close();
		fout.close();
return ;
}//END:copy()

	//funciton for conversion from binary to decimal	
	int bin2dec(int *T, int pos)	
	{
	  int sum=0,rem,k=0;
	  for(int j=pos ; ;j--)
	  {
		  sum=sum+T[j]*pow(2,k);
		  k++;
		 if(k==7)
		 	break;
	  }
		return sum;
	}

	int getChar(int ch)
	{
			return (char)ch;
	}


//converting binary to decimal and from ascii to text from	
string binaryToText(int * T ,int size)
{
	int *dec=new int [size];
	int sum=0;
	int pos=0;
	
	for(int i=0;i<size;i++)
	{
		if(i==0)
			pos=6;
		else
		{
			pos+=7;
		}
			sum=bin2dec(T,pos);
			dec[i]=sum;
	}
		
	string dMsg;
	string temp;

	for(int i=0;i<size;i++)
	{
			int aaaa=dec[i];
			temp=getChar(aaaa);
			dMsg+=temp;
	}

	return dMsg;
}


int main()
{
system("clear");
cout<<"==========================[ Implementation of two Stage public key Algorithm ]==========================\n\n";

	ifstream fin(msg);
	if(!fin)
	{
		cout<<"Error in reading message ..................";
		exit(0);
	}
	
	//String to hold plain text
	string msg;							
	//Accept Plain text to be encrypted		 
	getline(fin,msg);					
	
	//closing file which was opned for readin Plain message;
	fin.close();
	
	//Display read message.
	cout<<"Plain Message : ";
	for(int i=0;i< msg.size() ;i++)
		cout<<msg[i];
		cout<<endl;

	//Array to hold the Plain text
	int *T;							
	//Creating an array of size of the number of bits required 
	T=new int [(msg.size()) *nob];
	
	//Initializing the Array to 0
	for(int i=0;i<((msg.size()) *nob);i++)
		T[i]=0;
	
	char a;
	int temp_a;
	int pos=0;
	for(int i=0;i<msg.size();i++)
	{
		a=msg[i];
		temp_a=(int)a;
		binary(temp_a,T,pos);
		pos+=nob;
	}
		//Displaying the bianry of the message.
		cout<<"The Bianry form of Message is :";
		for(int i=0;i<msg.size()*nob;i++)
					cout<<T[i]<<"";
	
	cout<<"\nNumber of Boolean equations Requried to encrypt the Message : "<<msg.size()*nob<<endl;
	int NoBits=msg.size()*nob;
	
	cout<<"\nDo you want to Generate a New Boolean Function sequence [y/n] : ";
	string ch;
	cin>>ch;
	if(ch=="y" || ch=="Y")
	{
		cout<<"\nGenerating New Sequence....";
		ofstream fout(eEQU);
		if(!fout)
		{
			cout<<"Error in opening file.............";
		}
	
		//generating boolean functions for 2 sets of equations.........
		//Generation of functions for the set one of equations.	
		generateRandomSequence(fout,NoBits);		
		fout<<"#\n";
		//Generation of functions for the set two of equations.
		generateRandomSequence(fout,NoBits);		

		//closing the file in which boolean sequence is written
		fout.close();
		
		
		
		fin.open(eEQU);
		if(!fin)
		{
			cout<<"Error in opening file.............";
		}
		fout.open(dEQU);
		
		if(!fout)
		{
			cout<<"Error in opening file.............";
		}
		
		copy(fin,fout);
	}
	else if(ch=="n" || ch=="N")
		cout<<"\nUsing Previously Generated Sequence....\n";
	
	//opening the file in which boolean sequence written in read mode.
	fin.open(eEQU);
	if(!fin)
	{
		cerr<<"Error in opening file to read the binary sequence.........";
		exit(0);
	}
//	cout<<"\n(n-1) = "<<NoBits-1<<endl;
	
	Encrypt(fin,T,NoBits-1);
	
	cout<<"\nEncrypted Text :\n";
	for(int i=0;i<NoBits;i++)
		cout<<T[i]<<"\t";

	fin.close();
	
	string eMsg=binaryToText(T , msg.size() );
	
	cout<<"\n\nThe Encrypted Message is : "<<eMsg;
	
	fin.open(dEQU,ios::in);
	if(!fin)
	{
		cout<<"ERROR111";
	}
		cout<<"\n------------------------------------------------------------";
			Decrypt(fin,T,NoBits-1);
			cout<<"\nDecrypted Text :\n";
			for(int i=0;i<NoBits;i++)
				cout<<T[i]<<"\t";
	
		fin.close();

		string dMsg=binaryToText(T , msg.size() );

	cout<<"\n\nThe Decrypted Message is : "<<dMsg;
	
//	remove("temp.txt");	
cout<<"\n\nBye !!!";
cout<<endl<<endl;
return 0;				// indicates successful termination
}
