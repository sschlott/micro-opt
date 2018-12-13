//3's: 136300, 4's: 2232595, 5's: 82585
//Found little change/slightly worse performance with word[4]=='\0' arrangement
//took significantly longer using strlen()
//Pretty similar using define or just putting constants in (going to keep prettiest version here)
//Best run time overall: 0.004024s as of 12/11 at 1am
//Bitwise conversions consistently slower. Tried with just on len 3, 4, 5 etc., always lost .001s+ 
//i declared outside the loop harms performance (.002s slower)
//Couldn't get cases to work in the manner I use if/else right now
//Best run time overall: 0.003686s after changing multiplication process to smaller amounts at a time
#include "converter.h"
#include <stdlib.h>
#include <stdio.h>
const int TENS = 10;
void convert_all(unsigned nlines, char *lines[], quote_t nums[])
{
    for (unsigned i = 0; i < nlines; ++i) 
    {    
	char * word = lines[i];
	if (word[4])
	{
		if (word[3])
		{
		    
		    nums[i]= ((((word[0]-48)*TENS + (word[1]-48))*TENS + (word[2]-48))*TENS +(word[3]-48))*TENS + (word[4]-48);
		}
		else 
		{

		    nums[i]= ((word[0]-48)*TENS + (word[1]-48))*TENS +(word[2]-48);
		}
	}
	else 
	{
		
		nums[i]= (((word[0]-48)*TENS + (word[1]-48))*TENS + (word[2]-48))*TENS +(word[3]-48);
	}
    }
}
