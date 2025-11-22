#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
    int rc = fork();
    if (rc < 0){ // Fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) { // Child: redirect standard output to a file
        close(STDOUT_FILENO);
        open("./p4.output", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);

        // Now exec "wc"
        char *myargs[3];
        myargs[0] = strdup("wc"); // program: "wc" (word count)
        myargs[1] = strdup("p4.c"); // Argument: file to count
        myargs[2] = NULL; // End of array
        execvp(myargs[0], myargs); // Runs word count

    } else { // Parent goes down this path (main)
        int wc = wait(NULL);

    }
    return 0;

}