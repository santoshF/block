/*
 * =====================================================================================
 *
 *       Filename:  test_encrypt.cpp
 *
 *    Description:  to encrypt
 *
 *        Version:  1.0
 *        Created:  Monday 20 May 2013 01:30:45  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Santosh Fernandes (), s.is.santosh@gmail.com
 *   Organization:  ISSC
 *
 * =====================================================================================
 */
#include	<cstring>
#include	<iostream>
#include	<stdlib.h>
#include	<fstream>
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
	//Read binary file
	ifstream fin("out.txt");
	//Expresssion generated
	ifstream fin1("generate.txt");
	int key = 15;
	char ch;
	int i = 0;
// 	 int * T = new  int[key];
	char buff[key];
  	while(fin.eof()) {
	 getline(fin,buff); 
	i++;  
//	fin >> ch;
//	  cout << ch ;
// 	 int * T = new  int[key];	
//	  T[i] = ch;
//	for(int j = 0 ; i < key ;i++)
	cout << buff<<endl;	  
	 if( i == key) {
	        break;
		cout << endl;	
		}

	}
	
	


	 cout << i <<endl;
	 i = 0;
	 while(!fin1.eof()){
	 i++;
	
	  fin1 >> ch ;
//	  cout << ch ;
	  if( i == key ) { break;
		cout << endl;	
		}
	}

	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
