#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <semaphore.h>

void test()
{
	pid_t	forker;

	for (int i=0; i < 3; i++)
	{
		forker = fork();
		printf("%d - %d\n", forker, i);
		sleep(i);
	}
	if (forker)
		printf("Is parent PID %d - PPID %d\n", getpid(), getppid());
}

int main ()
{
	int i = 0;

	write(1, "HELLO\n", 6);
	test();
 	printf ("It s the parent...\n");
	//else
	// write (1, "Child\n", 6);
	return (0);
}

