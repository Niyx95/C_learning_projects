#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

//max characters avaiable
const int MAX_CHAR = 100;

int main(void)
{
    char user_input[MAX_CHAR];
    //init while loop until true
    while (1){
        //print and flush to stdout    
        printf("nxsh>> ");
        fflush(stdout);
        
        //get user input
        if(fgets(user_input, MAX_CHAR, stdin) == NULL){
            perror("not a valid input");
            continue;
        }

        //compare newline with user input and point \0 to \n
        char *newline = strchr(user_input, '\n');
        if (newline != NULL){
            *newline = '\0';
        }

        //handle exit command 
        if(strcmp(user_input, "exit") == 0){
            printf("aborting...\n");
            sleep(1);
            return 0;
        }

        //create token and init an integer
        int i = 0;
        char *args[11];
        args[0] = NULL;
        char *token = strtok(user_input, " ");
        
        //loop trough the str and argvs
        while(token != NULL){
            if(i >= 10){
                printf("too many arguments, max 10\n");
                break;
            }
            args[i] = token;
            i++;
            args[i] = NULL;
            token = strtok(NULL, " ");
        }
            
        //fork process and execute it
        pid_t pid = fork();
        if (pid < 0){
            perror("fork failed..");
        } else if (pid == 0) {
            execvp(args[0], args);
            perror("error");
            exit(1);
        } else {
            waitpid(pid, NULL, 0);
        }  
    }
    return 0;
}
