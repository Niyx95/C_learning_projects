#include <stdio.h>

//prototype of function
int swap(int *a, int *b);

int main(void)
{
    //define 2 int
    int x = 13;
    int y = 43;

    //print, swap values and reprint
    printf("x is %i, y is %i\n", x, y);
    swap(&x, &y);
    printf("y is %i, x is %i\n", y, x );
}

//swap function 
int swap(int *a, int *b)
{
    // set a temporary variable to point to a
    int tmp = *a;
    //swap a to b pointers
    *a = *b;
    //set the temporary value which is a to b
    *b = tmp;
}
