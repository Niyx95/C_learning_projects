#include <stdio.h>
#include <stdlib.h>


int main(void)
{
    //create a pointer 
    int *x;
    int *y;
    //create pointee
    x = malloc(sizeof(int));
    //set value of x 
    *x = 43;
    //point y to x 
    y = x;
    //set new value 
    *y = 13;
    y = malloc(sizeof(int)); *y = 99;

    printf("%p\n", x);
    printf("%p\n", y);

    free(x);
    free(y);
}