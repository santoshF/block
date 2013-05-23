/*
 * =====================================================================================
 *
 *       Filename:  block_cipher.cpp
 *
 *    Description:  to generate block cipher
 *
 *        Version:  1.0
 *        Created:  Friday 10 May 2013 10:51:48  IST
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Santosh Fernandes (), s.is.santosh@gmail.com
 *   Organization:  ISSC
 *
 * =====================================================================================
 */




#include	"lib/binary.h"
#include	"lib/generate.h" 

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
	int numBits = 1024;
	generate(numBits);
	binary(argc,argv);
	
	return EXIT_SUCCESS;
}				/* ----------  end of function main  ---------- */
