/*
 * =====================================================================================
 *
 *       Filename:  input.cpp
 *
 *    Description:  to scan input and convert text to binary
 *
 *        Version:  1.0
 *        Created:  Thursday 02 May 2013 11:06:39  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Santosh Fernandes (), s.is.santosh@gmail.com
 *   Organization:  ISSC
 *
 * =====================================================================================
 */




#include	<vector>
#include	<iostream>
#include	<fstream>
#include	<stdlib.h>
#define 	iFile  in.txt
#define 	oFile out.txt
using namespace std;
/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  
 * =====================================================================================
 */
	int
main ( int argc, char *argv[] )
{
	char ch;
	int num=0;
//	ifstream fin(argv[1]);
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	if(fin == NULL )
	   cerr<<"File Not found ";
	cout <<"Input File " <<endl;

	while(!fin.eof()) {
	     fin.get(ch);
		if(ch == '\n')
		  ;
	        else {
		cout << ch <<"\t";
		num =(int) ch;
		fout << num << "\t ";  
		 }	
	}
	cout <<endl;
	fin.close();
	fout.close();
	cout << " Output file " <<endl;
	ifstream fin1("out.txt");
	vector <int>v;	
	if(fin1 == NULL)
	   cerr<<"File Not found ";
	while(!fin1.eof()) {
	   fin1>>num; 
	   v.push_back(num);	
//	   cout << num << endl;	
	}
	for(unsigned int i =0 ; i <  v.size() ;i++)
		cout << v[i];
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
