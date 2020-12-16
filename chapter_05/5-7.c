#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main() {    
    __pid_t rc = fork();

    if (rc < 0) {
        // 创建进程失败
        fprintf(stderr, "fork failed\n");
        exit(EXIT_FAILURE);        
    } else if (rc == 0) {
        printf("Preparing to close standard output (STDOUT_FILENO)...\n\n");
        close(STDOUT_FILENO);
        printf("child calls printf().");
    } else {
        int wc = wait(NULL);
        printf("I am parent process\n");
    }
    return 0;
}