# Micro Optimization
Code for Sierra Schlott's Micro-Optimization of an atoi converter 
Important files: 
* `converter.c` my implementation of converter
* `old_converter.c` some person on stack exchange's fast_atoi
* `converter_original.c` The orignal converter (only uses atoi library call)

#### Best run time overall for converter_original.c: 0.059506s
#### Best run time overall for converter.c: 0.003674s(My implemetation)  
Final: About 16.2 times faster than the orinigan implementation. 
Recorded on laptop's VM, 10000 iters, with minimal interruptions

To start, I wanted my code to implement atoi since making library calls can be expensive in terms of time. Admittedly, I did look up an implementation of atoi by some person on stack overflow, but realized it wouldn’t be in the spirit of the assignment and abandoned it. This is located in my `old_converter.c`. After this, I stopped looking at the implementation this person had used and worked through the process of finding what worked best for myself.

The main change I started with was trying my own atoi. I looked up the corresponding integer values on an ascii table and found ‘0’ started at int 48. So, for any index in a string of number chars, I knew I would only have to subtract 48 in order to get the actual value. I started off using this as a function that was written outside of convert_all, but eventually brought it into my main function. 

Next, I took a closer look at the actual workload that was expected of the convert_all function by having a quick loop count the number of instances of 3-character, 4-character, and 5-character strings. I kept this tally in mind and used it to order my if/else statements so that 4-character strings, which occur the most by quite a bit, would immediately move on to the else statement. I followed similarly for the 3 and 5 character strings. 
This brought me down to about two times as fast as the fast_atoi that I’d tested on stack overflow. 

Some things I tried were less useful.

* I tried using bitwise shifts instead of multiplication by powers of 10 to assemble the final integer values, but found the gcc optimization was faster than what I could accomplish.
* I tried declaring the I iterator outside of the for loop, but this ended up being slightly slower.
* I couldn’t get branch prediction to operate faster than my initial arrangement of nested if/else statements
* I found little change with using just `if(word[i])` as opposed to `if (word[i]!=’\0’)`
* I found little change in using the actual integer values as opposed to declaring const ints `TENS`, `HUNDREDS`, `THOUSANDS`,... for multiplying by powers of ten

The final change I found to make a difference was altering my multiplication process so the program had smaller amounts to multiply by in any given instance.
For example, this is how I replaced the lines in my conversion for a three character integer: 
  
`nums[i]= (word[0]-48)*TTHOUS + (word[1]-48)*THOUSANDS + (word[2]-48)*HUNDREDS +(word[3]-48)*TENS + (word[4]-48);`

I started using:

` nums[i]= ((word[0]-48)*TENS + (word[1]-48))*TENS +(word[2]-48);`

This cut off about .0006 seconds, taking me from 14.8x faster to 16.2x faster.  

## Some Cool Bug I encountered
This doesn't work on my desktop computer, where the clock would only measure the 
