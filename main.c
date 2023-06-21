#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGS 10

int execute_command(char *command) {
    char *args[MAX_ARGS];
    int argc = 0;

    // Separate command and arguments
    char *token = strtok(command, " ");
    while (token != NULL && argc < MAX_ARGS) {
        args[argc++] = token;
        token = strtok(NULL, " ");
    }
    args[argc] = NULL;

    if (argc == 0) {
        // No command entered
        return 0;
    }

    if (strcmp(args[0], "ls") == 0) {
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
    } else if (strcmp(args[0], "cat") == 0) {
        // Implementation cat
        pid_t pid = fork();
        if (pid == 0) {
            execvp("cat", args);
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
        // پیاده سازی cd
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
        
        // Remove the newline character from the end of the string and replace 
        // it with the end of string pointer
        
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
