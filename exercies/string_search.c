#include <stdio.h>
#include <cs50.h>
#include <string.h>


int main(void)
{
    string words[] = {"rainbow", "star", "thunder", "blitz"};

    string choice = get_string("please eneter a word. >");

    //loop trough
    for (int i=0; i<4; i++)
    {
        if (strcmp(words[i], choice) == 0)
        {
            printf("match found\n");
            return 1;
        }
    }
    printf("match not found\n");
    return 1;
}
