/*
 * =====================================================================================
 *
 *       Filename:  string2int.cpp
 *
 *    Description:  to convert from string to int
 *
 *        Version:  1.0
 *        Created:  Thursday 23 May 2013 03:04:56  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Santosh Fernandes (), s.is.santosh@gmail.com
 *   Organization:  ISSC
 *
 * =====================================================================================
 */

#include 	<cstring>
#include	<stdlib.h>
#include	<sstream>
#include	<iostream>
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
 string  T = "abc";
 cout << T;
	
// stringstream s(T);
  int i[T.length()];
  
 for(unsigned int j = 0 ; j < T.length() ; j++  )	
{
   i[j] = T[i] - 48;
  cout << i[j]  <<endl;
}
//  s >> i;
 
// cout << s;		
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
