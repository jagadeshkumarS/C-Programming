#if 0              //1 for Predefined Library
#include<stdio.h>
#else              //else for user defined library
#include"stdio.h"
#endif

#define PI 3.14

int main()
{
        #ifndef PI
        printf("%d\n",EOF);
        #else
        printf("%.2f\n",PI);
        #endif
}