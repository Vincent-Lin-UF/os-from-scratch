#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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
	} else {
		// Parent goes down this path (main)
		printf("Parent of %d (pid: %d)\n", rc, (int) getpid());
	}
	return 0;
}
