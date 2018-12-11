/*
 * Trivial implementation of converter function.
 * You may override this file or create your own.
 */
//3's: 136300, 4's: 2232595, 5's: 82585
//Found little change/slightly worse performance with word[4]=='\0' arrangement
//took significantly longer using strlen()
//Pretty similar using define or just putting constants in (going to keep pretties version here)
//Best run time overall: 0.004024s as of 12/11 at 1am
#include "converter.h"
#include <stdlib.h>
#include <stdio.h>
const int TENS = 10;
const int HUNDREDS = 100;
const int THOUSANDS = 1000;
const int TTHOUS = 10000;

void convert_all(unsigned nlines, char *lines[], quote_t nums[])
{
    for (unsigned i = 0; i < nlines; ++i) 
    {    
	char * word = lines[i];
	if (word[4] != '\0')
	{
		if (word[3]!= '\0')
		{
		    
		    nums[i]= (word[0]-48)*TTHOUS + (word[1]-48)*THOUSANDS + (word[2]-48)*HUNDREDS +(word[3]-48)*TENS + (word[4]-48);
		}
		else 
		{

		    nums[i]= (word[0]-48)*HUNDREDS + (word[1]-48)*TENS +(word[2]-48);
		}
	}
	else 
	{
		
		nums[i]= (word[0]-48)*THOUSANDS + (word[1]-48)*HUNDREDS + (word[2]-48)*TENS +(word[3]-48);
	}
    }
}
