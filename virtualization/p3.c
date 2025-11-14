#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
	printf("hello (pid: %d)\n", (int) getpid());
	int rc = fork();
	if (rc < 0) {
		// Fork failed
		fprintf(stderr, "Fork Failed\n");
		exit(1);
	} else if (rc == 0) {
		// Child (new process)
		printf("Child (pid: %d)\n", (int) getpid());
		char *myargs[3];
		myargs[0] = strdup("wc"); // Program: "wc"
		myargs[1] = strdup("p3.c"); // arg: input file
		myargs[2] = NULL; // Mark end of array
		execvp(myargs[0], myargs); // Runs word count
		printf("This shouldn't print out");
	} else {
		// Parent goes down this path (main)
		int rc_wait = wait(NULL);
		printf("Parent of %d (rc_wait:%d) (pid: %d)\n", rc,rc_wait,  (int) getpid());
	}
	return 0;
}
