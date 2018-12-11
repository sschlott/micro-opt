/*
 * Trivial implementation of converter function.
 * You may override this file or create your own.
 */
#include "converter.h"

#include <stdlib.h>

void convert_all(unsigned nlines, char *lines[], quote_t nums[])
{
  for (unsigned i = 0; i < nlines; i=i+4) {
    nums[i] = atoi(lines[i]);
    nums[i+1] = atoi(lines[i+1]);
    nums[i+2] = atoi(lines[i+2]);
    nums[i+3] = atoi(lines[i+3]);
  }
}
