#include <stdio.h>

int convert_all(char * word ) 
{
    int val = 0;
    for (int u =0; u<6; u++)
    {   
       val = val + word[u];
    }
    return val;
}
int  main()
{
    char blah[5] = "42069";
    int wow = convert_all(blah);
    printf("%d\n",wow);
    return 0;
}

