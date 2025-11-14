#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
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
	} else {
		// Parent goes down this path (main)
		int rc_wait = wait(NULL);
		printf("Parent of %d (rc_wait:%d) (pid: %d)\n", rc,rc_wait,  (int) getpid());
	}
	return 0;
}
