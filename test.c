#include <stdio.h>
#include <math.h>
const int ONES = 1;
const int TENS = 10;
const int HUNDREDS = 100; 
const int THOUSANDS = 1000;
const int TTHOUS = 10000;
int convert_all(char * word ) 
{
    int val = (word[0]-48)*TTHOUS + (word[1]-48)*THOUSANDS + (word[2]-48)*HUNDREDS + (word[3]-48)*TENS +(word[4]-48);

    return val;
}
int  main()
{
    char quote[5] = "12345";
    int numeric = convert_all(quote);
    printf("%d\n",numeric);
    return 0;
}

