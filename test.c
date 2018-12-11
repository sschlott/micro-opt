#include <stdio.h>
#include <math.h>
const int TENS = 10;
const int HUNDREDS = 100; 
const int THOUSANDS = 1000;
const int TTHOUS = 10000;
int convert_all(char * word ) 
{
    int val = ((word[0]-48)<<13)+((word[0]-48)<<10) + ((word[0]-48)<<9)+((word[0]-48)<<8)+((word[0]-48)<<4) + ( (word[1]-48)<<9)+( (word[1]-48)<<8)+( (word[1]-48)<<7)+( (word[1]-48)<<6)+( (word[1]-48)<<5)+( (word[1]-48)<<3) + ((word[2]-48)<<6)+((word[2]-48)<<5)+((word[2]-48)<<2) + ((word[3]-48)<<3) +((word[3]-48)<<1)  +(word[4]-48);
    //Each index of the word is converted from ascii int to the number it reps (-48)
    //Then scaled depending on its actual magnitude in the given number
    return val;
}
int  main()
{
    char quote[5] = "12345";
    int numeric = convert_all(quote);
    printf("%d\n",numeric);
    return 0;
}

