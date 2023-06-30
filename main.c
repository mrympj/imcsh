#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 1000
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

void execute_command_in_background(char * args[]) {
    pid_t pid = fork();
    if (pid == 0) {
        execvp(args[0], args);
        exit(1);
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

void execute_cd(char *directory) {
    if (chdir(directory) != 0) {
        perror("chdir");
    }
}


void execute_command(char * command) {
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
        return;
    }

    if (strcmp(args[0], "cd") == 0) {
        if (argc > 1) {
            execute_cd(args[1]);
        } else {
            printf("Missing directory argument for cd command\n");
        }
    }

    if (strcmp(args[0], "&") == 0) {
        argc--;
        args[argc] = NULL;
        execute_command_in_background(args);
    } else if (strcmp(args[0], "ssh") == 0) {
        execute_ssh(args);
    } else if (strcmp(args[0], "sudo") == 0 && strcmp(args[1], "apt-get") == 0) {
        execute_sudo_apt_get(args);
    } else {
        // Execute the command
        pid_t pid = fork();
        if (pid == 0) {
            execvp(args[0], args);
            exit(1);
        } else {
            wait(NULL);
        }
    }
}
int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        printf(">> ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);
        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "exit") == 0) {
            break;
        }

        execute_command(command);
    }

    return 0;
}