#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TASKS 20
#define MAX_TASK_LENGTH 50

void start() {
    printf("            *THIS IS TO-DO LIST*\n");
    printf("*COMMANDS (ADD, COMPLETED, REMOVE, VIEW, HELP)*\n");
}

void toDoList(char task[MAX_TASKS][MAX_TASK_LENGTH], int taskCount) {
    printf("YOUR TODO LIST:\n");
    
    for (int count = 0; count < taskCount; count++) {
        printf("[%d] %s\n", count + 1, task[count]);
    }
}

void completed() {
    printf("THIS IS FOR COMPLETED\n");
}

void rem(char task[MAX_TASKS][MAX_TASK_LENGTH], int *taskCount) {
    int number;

    printf("Enter number of task you want to remove: ");
    if (scanf(" %d", &number) != 1 || number < 1 || number > *taskCount) {
        printf("Invalid task number.\n");
        return;
    }

    for (int index = number - 1; index < *taskCount; index++) {
        strcpy(task[index], task[index + 1]);
    }

    task[*taskCount - 1][0] = '\0';

    (*taskCount)--;
}
void add(char task[MAX_TASKS][MAX_TASK_LENGTH], int *taskCount) {
    char answer;

    printf("Enter task you want to add: ");
    scanf(" %49[^\n]", task[*taskCount]); 
    (*taskCount)++;

    do {
            char action[10];
            printf("Enter action (add, completed, remove, view, end): ");
            scanf(" %9s", action);
            fflush(stdin);
            
            if (strcmp(action, "completed") == 0) {
                completed();
            } else if (strcmp(action, "remove") == 0) {
                rem(task, taskCount);
            } else if (strcmp(action, "add") == 0) {
                add(task, taskCount);
                break;
            } else if (strcmp(action, "view") == 0) {
                toDoList(task, *taskCount);
            } else if (strcmp(action, "end") == 0) {
                exit(0); 
            } else {
                printf("Invalid action. Please try again.\n");
            }
        }
    while (1);
}


void help() {
    printf("*****************************************\n");
    printf("                COMMANDS:\n");
    printf("ADD - Add a new item to the to-do list.\n");
    printf("COMPLETED - Mark an item as completed.\n");
    printf("REMOVE - Remove an item from the list.\n");
    printf("VIEW - View the current to-do list.\n");
    printf("HELP - Display this help message.\n");
    printf("*****************************************\n");
}

void commands(char command[10], char task[MAX_TASKS][MAX_TASK_LENGTH], int *taskCount) {
    for (int index = 0; command[index] != '\0'; index++) {
        command[index] = tolower(command[index]);
    }

    switch (command[0]) {
        case 'a':
            if (strcmp(command, "add") == 0) {
                add(task, taskCount);
            } else {
                printf("Invalid command. Type 'HELP' for available commands.\n");
            }
            break;
        case 'c':
            if (strcmp(command, "completed") == 0) {
                completed();
            } else {
                printf("Invalid command. Type 'HELP' for available commands.\n");
            }
            break;
        case 'r':
            if (strcmp(command, "remove") == 0) {
                rem(task, taskCount);
            } else {
                printf("Invalid command. Type 'HELP' for available commands.\n");
            }
            break;
        case 'v':
            if (strcmp(command, "view") == 0) {
                toDoList(task, *taskCount);
            } else {
                printf("Invalid command. Type 'HELP' for available commands.\n");
            }
            break;
        case 'h':
            if (strcmp(command, "help") == 0) {
                help();
            } else {
                printf("Invalid command. Type 'HELP' for available commands.\n");
            }
            break;
        default:
            printf("Invalid command. Type 'HELP' for available commands.\n");
            break;
    }
}

int main() {
    char task[MAX_TASKS][MAX_TASK_LENGTH];
    int taskCount = 0;
    char command[10];

    start();

    while (1) {
        printf("Enter a command (or 'end' to exit): ");
        if (scanf("%9s", command) != 1) {
            printf("Error reading command input.\n");
            return 1; 
        }

        if (strcmp(command, "end") == 0) {
            break; 
        }

        commands(command, task, &taskCount);
    }

    return 0;
}
