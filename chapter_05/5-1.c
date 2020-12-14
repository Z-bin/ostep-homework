#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int x = 100;
    int rc = fork();

    if (rc < 0) {
        // 创建进程失败
        fprintf(stderr, "fork failed\n");
        exit(EXIT_FAILURE);        
    } else if (rc == 0) {
        x = 101;
        printf("x in child process is %d\n", x);
    } else {
        x = 102;
        printf("x in process process is %d\n", x);
    }
    return 0;
}