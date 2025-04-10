#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdint.h>

int main( uint16_t argc, const char *argv[] ) {
	pid_t pids[2];
	int status_main;
	int status_test;

	puts("\033[3m\033[2mstarter start.. xD\033[0m");

	for (uint8_t i = 0; i < 2; ++i) {
		int pid = fork();
		if (i == 0) {
			if (pid == 0) {
				int main_return_value;
				printf(" CHILD MAIN: PID %d : PARENT PID  %d\n", getpid(), getppid());
				main_return_value = execl("program_v-0.0.0.1", "program_v-0.0.0.1", NULL);
				exit(main_return_value);
			} else {
				pids[i] = pid;
			}
		}
		if (i == 1) {
			if (pid == 0) {
				int test_return_value;
				printf(" CHILD MAIN: PID %d : PARENT PID  %d\n", getpid(), getppid());
				printf(" CHILD TEST: PID %d : PARENT PID  %d\n", getpid(), getppid());
				test_return_value = execl("test_2_program", "test_2_program", NULL);
				exit(test_return_value);
			} else {
				pids[i] = pid;
			}
		}
    	}

    	puts("\033[3m\033[2mstarter wait..\033[0m");

    	for (uint8_t i = 0; i < 2; ++i) {
		if (i == 0) {
			waitpid(pids[i], &status_main, 0);
			printf("MAIN RETURN VALUE: %d\n", WEXITSTATUS(status_main));
		}
		if (i == 1) {
			waitpid(pids[i], &status_test, 0);
			printf("TEST RETURN VALUE: %d\n", WEXITSTATUS(status_test));
		}
    	}

	if (status_main != 0 || status_main != 0) {
		puts("\033[31mstart failed, starting last stable version..\033[0m");
		execl("program_v-0.0.0.1_static", "program_v-0.0.0.1_static", NULL);
	}

    	puts("\033[3m\033[2mstarter stop.\033[0m");

	return 0;
}
