#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
# define MAX_ARGS 10

void execute_ssh(char * args[]) {
    pid_t pid = fork();
    if (pid == 0) {
        execvp("ssh", args);
        exit(1);
    } else {
        wait(NULL);
    }
}

void execute_sudo_apt_get(char * args[]) {
    pid_t pid = fork();
    if (pid == 0) {
        execvp("sudo", args);
        exit(1);
    } else {
        wait(NULL);
    }
}

int execute_command(char * command) {
    char * args[MAX_ARGS];
    int argc = 0;

    char * saveptr;

    // Separate command and arguments
    char * token = strtok_r(command, " ;", & saveptr);
    while (token != NULL && argc < MAX_ARGS) {
        args[argc++] = token;
        token = strtok_r(NULL, " ;", & saveptr);
    }
    args[argc] = NULL;

    if (argc == 0) {
        // No command entered
        return 0;
    }

    if (strcmp(args[0], "ssh") == 0) {
        execute_ssh(args);
    }

    if (strcmp(args[0], "sudo") == 0 && strcmp(args[1], "apt-get") == 0) {
        execute_sudo_apt_get(args);
    } else if (strcmp(args[0], "ls") == 0) {
        // Implementation ls
        pid_t pid = fork();
        if (pid == 0) {
            execvp("ls", args);
            exit(1);
        } else {
            wait(NULL);
        }
    } else if (strcmp(args[0], "mkdir") == 0) {
        // Implementation mkdir
        pid_t pid = fork();
        if (pid == 0) {
            execvp("mkdir", args);
            exit(1);
        } else {
            wait(NULL);
        }
    } else if (strcmp(args[0], "rm") == 0) {
        // Implementation rm
        pid_t pid = fork();
        if (pid == 0) {
            execvp("rm", args);
            exit(1);
        } else {
            wait(NULL);
        }
    } else if (strcmp(args[0], "cat") == 0) {
        // Implementation cat
        pid_t pid = fork();
        if (pid == 0) {
            execvp("cat", args);
            exit(1);
        } else {
            wait(NULL);
        }
    } else if (strcmp(args[0], "cp") == 0) {
        // Implementation cp
        pid_t pid = fork();
        if (pid == 0) {
            execvp("cp", args);
            exit(1);
        } else {
            wait(NULL);
        }
    } else if (strcmp(args[0], "cd") == 0) {
        // Implementation cd
        if (argc > 1) {
            if (chdir(args[1]) != 0) {
                printf("cd: No such directory: %s\n", args[1]);
            }
        } else {
            printf("cd: Missing directory name\n");
        }
    } else if (strcmp(args[0], "pwd") == 0) {
        // Implementation pwd
        char cwd[1024];
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            printf("Current directory: %s\n", cwd);
        } else {
            printf("Error getting current directory\n");
        }
    } else if (strcmp(args[0], "echo") == 0) {
        // Implementation echo
        for (int i = 1; i < argc; i++) {
            printf("%s ", args[i]);
        }
        printf("\n");
    } else if (strcmp(args[0], "wget") == 0) {
        // Implementation wget
        pid_t pid = fork();
        if (pid == 0) {
            execvp("wget", args);
            exit(1);
        } else {
            wait(NULL);
        }
    } else if (strcmp(args[0], "head") == 0) {
        // Implementation head
        pid_t pid = fork();
        if (pid == 0) {
            execvp("head", args);
            exit(1);
        } else {
            wait(NULL);
        }
    } else if (strcmp(args[0], "tail") == 0) {
        // Implementation tail
        pid_t pid = fork();
        if (pid == 0) {
            execvp("tail", args);
            exit(1);
        } else {
            wait(NULL);
        }
    } else if (strcmp(args[0], "scp") == 0) {
        // Implementation scp
        pid_t pid = fork();
        if (pid == 0) {
            execvp("scp", args);
            exit(1);
        } else {
            wait(NULL);
        }
    } else if (strcmp(args[0], "find") == 0) {
        // Implementation find
        pid_t pid = fork();
        if (pid == 0) {
            execvp("find", args);
            exit(1);
        } else {
            wait(NULL);
        }
    } else if (strcmp(args[0], "ping") == 0) {
        // Implementation ping
        pid_t pid = fork();
        if (pid == 0) {
            execvp("ping", args);
            exit(1);
        } else {
            wait(NULL);
        }
    } else if (strcmp(args[0], "top") == 0) {
        // Implementation top
        pid_t pid = fork();
        if (pid == 0) {
            execvp("top", args);
            exit(1);
        } else {
            wait(NULL);
        }
    } else if (strcmp(args[0], "rpm") == 0) {
        // Implementation rpm
        pid_t pid = fork();
        if (pid == 0) {
            execvp("rpm", args);
            exit(1);
        } else {
            wait(NULL);
        }
    } else if (strcmp(args[0], "mv") == 0) {
        // Implementation mv
        pid_t pid = fork();
        if (pid == 0) {
            execvp("mv", args);
            exit(1);
        } else {
            wait(NULL);
        }
    } else if (strcmp(args[0], "grep") == 0) {
        // Implementation grep
        pid_t pid = fork();
        if (pid == 0) {
            execvp("grep", args);
            exit(1);
        } else {
            wait(NULL);
        }
    } else if (strcmp(args[0], "chmod") == 0) {
        // Implementation chmod
        pid_t pid = fork();
        if (pid == 0) {
            execvp("chmod", args);
            exit(1);
        } else {
            wait(NULL);
        }
    } else if (strcmp(args[0], "chown") == 0) {
        // Implementation chown
        pid_t pid = fork();
        if (pid == 0) {
            execvp("chown", args);
            exit(1);
        } else {
            wait(NULL);
        }
    } else if (strcmp(args[0], "touch") == 0) {
        // Implementation touch
        pid_t pid = fork();
        if (pid == 0) {
            execvp("touch", args);
            exit(1);
        } else {
            wait(NULL);
        }
    } else if (strcmp(args[0], "tar") == 0) {
        // Implementation tar
        pid_t pid = fork();
        if (pid == 0) {
            execvp("tar", args);
            exit(1);
        } else {
            wait(NULL);
        }
    } else if (strcmp(args[0], "gzip") == 0) {
        // Implementation gzip
        pid_t pid = fork();
        if (pid == 0) {
            execvp("gzip", args);
            exit(1);
        } else {
            wait(NULL);
        }
    } else if (strcmp(args[0], "exit") == 0) {
        // Terminate the program
        exit(0);
    } else {
        // Invalid command

        printf("Invalid command: %s\n", args[0]);
    }

    return 1;
}

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        printf("Enter a command: ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        size_t command_length = strlen(command);
        if (command[command_length - 1] == '\n') {
            command[command_length - 1] = '\0';
        }

        if (strcmp(command, "exit") == 0) {
            break;
        }

        execute_command(command);
    }

    return 0;
}