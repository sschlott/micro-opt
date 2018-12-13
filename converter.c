//3's: 136300, 4's: 2232595, 5's: 82585
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
	if (word[4]) //Same as if word[4]!='\0' which is to say, "If our word isn't a 4 character number"
	{
		if (word[3])
		{
		    //5 character string
		    nums[i]= ((((word[0]-48)*TENS + (word[1]-48))*TENS + (word[2]-48))*TENS +(word[3]-48))*TENS + (word[4]-48);
		    //"Magic"  -48 is conversion from '0' to int 0, '1' to int 1, etc. 
		    //TENS multiplies the last calculated amount by 10 so the decimal places of int are conserved
		}
		else 
		{
		    //3 character string
		    nums[i]= ((word[0]-48)*TENS + (word[1]-48))*TENS +(word[2]-48);
		}
	}
	else 
	{
		//4 character string
		nums[i]= (((word[0]-48)*TENS + (word[1]-48))*TENS + (word[2]-48))*TENS +(word[3]-48);
	}
    }
}
