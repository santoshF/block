/*
 * =====================================================================================
 *
 *       Filename:  binary.c
 *
 *    Description:  to convert number to bin
 *
 *        Version:  1.0
 *        Created:  Friday 03 May 2013 02:24:04  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Santosh Fernandes (), s.is.santosh@gmail.com
 *   Organization:  ISSC
 *
 * =====================================================================================
 */

#include	<stdio.h>
#include	<stdlib.h>

/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  main
 *  Description:  call num to bin function
		  65/2 c
 * =====================================================================================
 */

void num2bin(unsigned int a){
int temp[8] = { };
int i = 0;
  while(a != 0){
	temp[i] = a % 2;
	 a = a /2;
	i++;
	}
	printf("Binary \t");
	for(i = 8 ; i >= 0 ;i-- ){
	if(temp[i] == 8)
		;
	else
	  printf("%d",  temp[i]);
	}
}

	int
main ( int argc, char *argv[] )
{
	unsigned int a = 128;
	num2bin(a);
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
