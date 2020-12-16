#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {    
    int rc = fork();

    if (rc < 0) {
        // 创建进程失败
        fprintf(stderr, "fork failed\n");
        exit(EXIT_FAILURE);        
    } else if (rc == 0) {        
        pid_t wait_return = wait(NULL);  // 返回-1
        printf("child wait return: %d\n", wait_return);
    } else {
        pid_t wait_return = wait(NULL);
        printf("parent wait return: %d\n", wait_return);
    }
    return 0;
}