#include <cs50.h>
#include <stdio.h>

const int total_n = 7;

int main(void)
{
    //create array and get user input
    int numbers[] = {1, 45, 32, 11, 65, 120, 71};
    int n = get_int("plase enter a number. >");

    //loop trought numbers, if match - print and return
    for (int i=0; i<total_n; i++)
    {
        if (numbers[i] == n)
        {
            printf("True \n");
            return 1;
        }
    }
    printf("number not found\n");
    return false;
}
