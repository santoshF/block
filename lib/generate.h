/*
 * =====================================================================================
 *
 *       Filename:  generate.cpp
 *
 *    Description:  To generate random sequence of and ,or and not
 *
 *        Version:  1.0
 *        Created:  Wednesday 08 May 2013 11:00:31  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Santosh Fernandes (), s.is.santosh@gmail.com
 *   Organization:  ISSC
 *
 * =====================================================================================
 */
#ifndef GENERATE_H_
#define GENERATE_H_

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "binary.h" 	

using namespace std;


void randomBit(int * randomArray,int numBits){
	for(int i = 0 ; i < numBits ; i++) {
		randomArray[i] = rand()%2 + 0;
//		cout << randomArray[i]; //0001 
	}
}
string  boolExp(int a) {
      string  es;      
 	   if( a == 0 )
	      es += " &&  "; 
	   else if( a == 1)
	      es += " || ";
  return es;	
}


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
generate ( int numBits )
{
//	int numBits = 128;
//    binary(argc,argv);
//	char ch;
	int i = 0;
     
	
    ofstream  fout("generate.txt"); 
	// Seed for random function is time i
//	int numBits = 64;
//     cout << time(NULL) <<endl;
     srand( time(NULL) );
	// Position of value
  	int *randomArray = new int [numBits];
	string res,es;
	string rest;
	int a;
	int j;
//Number of Bit equals Number of Expressions
	for(j =0 ; j < numBits; j++)
       {
//Number of Boolean Expression  is n -2 
	for(i = 0 ; i < numBits-2 ; i++)
	{
	//Create Random bit array with numbits
              randomBit(randomArray,numBits);  
 	      a =  randomArray[i] ;
//	     cout << a <<endl;
	//Choose Random bool expression
	      es =  boolExp(a);	
//             cout << es;  
	    	
            res += es; 
	    rest = res;
	   
	}	
	fout <<rest << endl;
//	fout  <<rest << endl;
	  res= " ";
	}
	return EXIT_SUCCESS;
}

#endif				/* ----------  end of function main  ---------- */
