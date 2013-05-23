#ifndef BINARY_H_
#define BINARY_H_

#include<iostream>
#include<fstream>
#include <string.h>
using namespace std;

int binary(int argc,char *argv[])
{
  int i,c,power;
  string buf,s;
//  char ch;
  if(argc < 3)//validation of arguments 
  {
    cerr<<"Syntax : ./a.out <input_file> <output_file>"<<endl;
    return 0;
  }
  ofstream fout;
  ifstream fin;
  fin.open(argv[1]);
  fout.open(argv[2]);
  //get input
  if (fin.is_open()) 
  {
    while(getline(fin, buf))
    {
       s = buf ;
       s += "\n";
       //for each character, print it's binary output
       for( i=0 ; s[i]!='\0' ; i++ )
       {
         //c holds the character being converted
         c = s[i];
         //for each binary value below 256 (because ascii values < 256)
         for( power=7 ; power+1 ; power-- )
         //if c is greater than or equal to it, it is a 1
         if( c >= (1<<power) )
         {
	    c -= (1<<power); //subtract that binary value
	    fout<<"1";
	 }
         //otherwise, it is a zero
         else
         fout<<"0";
      }
    }
  }
return 0;
}

#endif
