#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main( int argc, const char *argv[] ) {
	pid_t pid;
	switch(pid=fork()) {
	case -1:
		perror("fork"); /* произошла ошибка */
		exit(1); /*выход из родительского процесса*/
	case 0:
		int return_value;
		std::cout << " CHILD: PID " << getpid() << " : PARENT PID " << getppid() << "\n";
		std::cout << " CHILD: запуск другого исполняемого файла\n";
  		return_value = execl("test_test2_program"," ","Hello", "World!", NULL);
		exit(return_value);
	default:
		std::cout << "PARENT: PID " << getpid() << " : CHILD: PID " << pid << "\n";
		int status;
		waitpid(pid, &status, 0);
		std::cout << "PARENT: child return value: " << WEXITSTATUS(status) << "\n";
		std::cout << "PARENT: exit\n";
		return WEXITSTATUS(status);
	}
	return 0;
}
