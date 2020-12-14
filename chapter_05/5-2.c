#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int fd = open("./2.txt", O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
    int rc = fork();
    write(fd, "Fist Line.\n", strlen("Fist Line.\n"));

    // 创建进程失败
    if (rc < 0) {
        fprintf(stderr, "fork failed\n");
        exit(EXIT_FAILURE);
    } else if (rc == 0) {
        write(fd, "child writes a line.\n", strlen("child writes a line.\n"));
        printf("file descriptor in child process: %d\n", fd);
    } else {
        write(fd, "parent writes a line.\n", strlen("parent writes a line.\n"));
        printf("file descriptor in parent process: %d\n", fd);

        if (wait(NULL) == -1) {
            fprintf(stderr, "wait failed\n");
            exit(EXIT_FAILURE);            
        }

        FILE *fp;
        fp = fopen("./2.txt", "r");
        int ch;
        printf("\nfile contents: \n");
        while ((ch = fgetc(fp)) != EOF){
            printf("%c",ch);
        }
        fclose(fp);    
    }
    close(fd);
    return 0;
}