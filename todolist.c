/**
 * @file todo_list.c
 * @brief Simple to-do list management program.
 * @author Tadeas Novotny
 * @date 2024-04-19
 * TODO : Implementation of saving that todo list to a file
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TASKS 20
#define MAX_TASK_LENGTH 50

typedef struct {
    int priority; 
    char description[MAX_TASK_LENGTH]; 
} Task;

/**
 * @brief Displays the initial message for the to-do list.
 */
void start() {
    printf("            *THIS IS TO-DO LIST*\n");
    printf("*COMMANDS (ADD, COMPLETED, REMOVE, VIEW, HELP)*\n");
}

/**
 * @brief Prompts the user to enter the number of a completed task.
 * @param taskList The array of tasks
 * @param taskCount The number of tasks in the list
 * @return The number of the completed task
 */
int completed(Task taskList[], int taskCount) {
    int number;

    printf("Enter number of task you completed: ");
    if (scanf(" %d", &number) != 1 || number < 1 || number > taskCount) {
        printf("Invalid task number.\n");
        return 0;
    } else {
        return number;
    }
}

/**
 * @brief Displays the to-do list along with priorities and completed tasks.
 * @param taskList The array of tasks
 * @param taskCount The number of tasks in the list
 * @param completedTask The number of the completed task (0 if none)
 */
void toDoList(Task taskList[], int taskCount, int completedTask) {
    char prioritySymbol[4];
    
    printf("YOUR TODO LIST:\n");

    for (int count = 0; count < taskCount; count++) {
        switch (taskList[count].priority) {
            case 1:
                strcpy(prioritySymbol, "!");
                break;
            case 2:
                strcpy(prioritySymbol, "!!");
                break;
            case 3:
                strcpy(prioritySymbol, "!!!");
                break;
            default:
                break;
        }

        if (count + 1 == completedTask) {
            printf("[X] [%s] %s\n", prioritySymbol, taskList[count].description);
        } else {
            printf("[%d] [%s] %s\n", count + 1, prioritySymbol, taskList[count].description);
        }
    }
}

/**
 * @brief Removes a task from the to-do list.
 * @param taskList The array of tasks
 * @param taskCount Pointer to the number of tasks in the list
 * @param number The number of the task to remove
 */
void rem(Task taskList[], int *taskCount, int number) {
    if (number < 1 || number > *taskCount) {
        printf("Invalid task number.\n");
        return;
    }

    for (int index = number - 1; index < *taskCount; index++) {
        taskList[index] = taskList[index + 1];
    }

    (*taskCount)--;
}

/**
 * @brief Adds a new task to the to-do list.
 * @param taskList The array of tasks
 * @param taskCount Pointer to the number of tasks in the list
 */
void add(Task taskList[], int *taskCount) {
    printf("Enter task description: ");
    scanf(" %49[^\n]", taskList[*taskCount].description);

    do {
        printf("Enter priority level (1-3): ");
        if (scanf(" %d", &taskList[*taskCount].priority) != 1 || taskList[*taskCount].priority < 1 || taskList[*taskCount].priority > 3) {
            printf("Invalid priority level. Please enter a number between 1 and 3.\n");
        } else {
            break;
        }
    } while (1);

    (*taskCount)++;

    do {
        char action[10];
        printf("Enter action (add, completed, remove, view, end): ");
        scanf(" %9s", action);
        fflush(stdin);
        
        if (strcmp(action, "completed") == 0) {
            int completedTask = completed(taskList, *taskCount);
            toDoList(taskList, *taskCount, completedTask);
            rem(taskList, taskCount, completedTask);
        } else if (strcmp(action, "remove") == 0) {
            int number;
            printf("Enter number of task you want to remove: ");
            scanf(" %d", &number);
            rem(taskList, taskCount, number);
        } else if (strcmp(action, "add") == 0) {
            add(taskList, taskCount);
            break;
        } else if (strcmp(action, "view") == 0) {
            toDoList(taskList, *taskCount, 0); // 0 means no task is completed
        } else if (strcmp(action, "end") == 0) {
            exit(0); 
        } else {
            printf("Invalid action. Please try again.\n");
        }
    } while (1);
}

/**
 * @brief Displays the help message with available commands.
 */
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

/**
 * @brief Processes user commands for managing the to-do list.
 * @param command The user's command string
 * @param taskList The array of tasks
 * @param taskCount Pointer to the number of tasks in the list
 */
void commands(char command[10], Task taskList[], int *taskCount) {
    for (int index = 0; command[index] != '\0'; index++) {
        command[index] = tolower(command[index]);
    }

    switch (command[0]) {
        case 'a':
            if (strcmp(command, "add") == 0) {
                add(taskList, taskCount);
            } else {
                printf("Invalid command. Type 'HELP' for available commands.\n");
            }
            break;
        case 'c':
            if (strcmp(command, "completed") == 0) {
                int completedTask = completed(taskList, *taskCount);
                toDoList(taskList, *taskCount, completedTask);
                rem(taskList, taskCount, completedTask);
            } else {
                printf("Invalid command. Type 'HELP' for available commands.\n");
            }
            break;
        case 'r':
            if (strcmp(command, "remove") == 0) {
                int number;
                printf("Enter number of task you want to remove: ");
                scanf(" %d", &number);
                rem(taskList, taskCount, number);
            } else {
                printf("Invalid command. Type 'HELP' for available commands.\n");
            }
            break;
        case 'v':
            if (strcmp(command, "view") == 0) {
                toDoList(taskList, *taskCount, 0); 
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

/**
 * @brief The main function to run the to-do list program.
 * @return 0 on successful execution
 */
int main() {
    Task taskList[MAX_TASKS];
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

        commands(command, taskList, &taskCount);
    }

    return 0;
}
