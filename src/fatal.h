#ifndef __FLATAL_H
#define __FLATAL_H
#include <stdio.h>
#include <stdlib.h>
#define Error(Str)	FatalError(Str)
#define FatalError(Str) do{fprintf(stderr,"%s\n",Str),exit(1);}while(0)

#endif
