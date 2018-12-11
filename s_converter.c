/*
 * Trivial implementation of converter function.
 * You may override this file or create your own.
 */
#include "converter.h"
#include <stdlib.h>
#include <stdio.h>
const int TENS = 10;
const int HUNDREDS = 100;
const int THOUSANDS = 1000;
const int TTHOUS = 10000;
int convert4(char * word ) 
{
    int val = (word[0]-48)*THOUSANDS + (word[1]-48)*HUNDREDS + (word[2]-48)*TENS +(word[3]-48);
    //Each index of the word is converted from ascii int to the number it reps (-48)
    //Then scaled depending on its actual magnitude in the given number
    return val;
}

int convert3(char * word ) 
{
    int val =  (word[0]-48)*HUNDREDS + (word[1]-48)*TENS +(word[2]-48);
    return val;
}

int convert5(char * word ) 
{
    int val = (word[0]-48)*TTHOUS + (word[1]-48)*THOUSANDS + (word[2]-48)*HUNDREDS +(word[3]-48)*TENS + (word[4]-48);
    return val;
}

void convert_all(unsigned nlines, char *lines[], quote_t nums[])
{
    for (unsigned i = 0; i < nlines; i++) 
    {    
	char * raw = lines[i];
	if (raw[4] != '\0')
	{
		if (raw[3]!= '\0')
		{
		    
//		    int test5 = convert5(raw);
//		    printf("%s, %d\n", raw,test5);
		    nums[i]=convert5(raw);
		}
		else 
		{

//		    int test3 = convert3(raw);
//		    printf("%s, %d\n", raw,test3);
		    nums[i]=convert3(raw);
		}
	}
	else 
	{
		
//		int test4 = convert4(raw);
//		printf("%s, %d\n", raw,test4);
		nums[i]=convert4(raw);
	}
    }
}
