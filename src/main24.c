#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main( int argc, const char *argv[] ) {
	pid_t pids[2];

	puts("\033[3m\033[2mstarter start.. xD\033[0m");

	for (int i = 0; i < 2; ++i) {
		int pid = fork();
		if (i == 0) {
			if (pid == 0) {
				printf(" CHILD MAIN: PID %d : PARENT PID  %d\n", getpid(), getppid());
				execl("program_v-0.0.0.1", "-a", NULL);
				exit(0);
			} else {
				pids[i] = pid;
			}
		}
		if (i == 1) {
			if (pid == 0) {
				printf(" CHILD TEST: PID %d : PARENT PID  %d\n", getpid(), getppid());
				execl("test_2_program", "none.", NULL);
				exit(0);
			} else {
				pids[i] = pid;
			}
		}
    	}

    	puts("\033[3m\033[2mstarter wait..\033[0m");

    	for (int i = 0; i < 2; ++i) {
		if (pids[i] > 0) {
			waitpid(pids[i], NULL, 0);
    	    }
    	}

    	puts("\033[3m\033[2mstarter stop.\033[0m");
/*
    	pid_t pid_main;
	pid_t pid_test_test;

	pid_main = fork();
	pid_test_test = fork();

	if (pid_main == -1) {
		perror("fork");
		exit(1);
	}
	if (pid_main == 0) {
		int main_return_value;
          	printf(" CHILD MAIN: PID %d : PARENT PID  %d\n", getpid(), getppid());
		//std::cout << " CHILD: PID " << getpid() << " : PARENT PID " << getppid() << "\n";
		//std::cout << " CHILD: запуск другого исполняемого файла\n";
  		//main_return_value = execl("program_v-0.0.0.1", "-a", NULL);
  		//main_return_value = execl("test_program", "none.", NULL);
		exit(main_return_value);
	}
	if (pid_test_test == -1) {
		perror("fork");
		exit(1);
	}
	if (pid_test_test == 0) {
		int test_return_value;
          	printf(" CHILD TEST: PID %d : PARENT PID  %d\n", getpid(), getppid());
		//std::cout << " CHILD: PID " << getpid() << " : PARENT PID " << getppid() << "\n";
		//std::cout << " CHILD: запуск другого исполняемого файла\n";
  		//test_return_value = execl("test_test2_program", "none.", NULL);
		exit(test_return_value);
	}

	int status_main;
	int status_test_test;
	waitpid(pid_main, &status_main, 0);
	waitpid(pid_test_test, &status_test_test, 0);
*/
	return 0;
}
