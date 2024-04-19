#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h> 

void guide(){
    printf("            *THIS IS TO-DO LIST*\n");
    printf("*COMMANDS (ADD, COMPLETED, REMOVE, VIEW, HELP)*\n");
}

void add(){
    printf("THIS IS FOR ADD\n");
}

void completed(){
    printf("THIS IS FOR COMPLETED\n");
}

void rem(){
    printf("THIS IS FOR REMOVE\n");
}

void view(){
    printf("THIS IS FOR VIEW\n");
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

void commands(char command[10]) {

    for (int index = 0; command[index] != '\0'; index++) {
        command[index] = tolower(command[index]);
    }

    switch (command[0]) {
        case 'a':
            if (strcmp(command, "add") == 0) {
                add();
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
                rem();
            } else {
                printf("Invalid command. Type 'HELP' for available commands.\n");
            }
            break;
        case 'v':
            if (strcmp(command, "view") == 0) {
                view();
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

    char command[10];

    guide();

    printf("Enter a command: ");
    scanf("%9s", command);

    if (strlen(command) > 0) {
        commands(command);
    } else{
        printf("Please provide some text.");
    }

    return 0;

}