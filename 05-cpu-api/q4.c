#include <unistd.h>
#include <stdio.h>

int main(int argc, char *argv[], char *envp[]) {
    int pid = fork();

    if(pid < 0) {
        fprintf(stderr, "fork failed");
    }
    else if(pid == 0) {
        char* cmd = "/bin/ls";
        char* args[] = {"ls", "-a", "NULL"};
        //execl(cmd, "ls", NULL);
        //execlp(cmd, "ls", NULL);
        //execve(cmd, args, NULL); // doesn't execute on macOS
        //execve(cmd, args, envp); // same as above
        //execv(cmd, args); // same as above
        //execvp(cmd, args); // same as above
        execle(cmd, "ls", NULL, envp);
        printf("child process pid=%d done\n", (int) getpid());
    }

    return 0;
}

