#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void intro();
void addtask(char *filename);
void deletetasks(char *filename);
void viewtask(char *filename);

int main() {
    char filename[50];
    printf("Enter the filename: ");
    fgets(filename, sizeof(filename), stdin);
    filename[strcspn(filename, "\n")] = 0;
    while (1) 
    {
        intro();
        int ch;
        printf("Enter your choice: ");
        scanf("%d", &ch);
        getchar();

        switch (ch) {
            case 1:
                addtask(filename);
                break;
            case 2:
                deletetasks(filename);
                break;
            case 3:
                viewtask(filename);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid operation.\n");
                break;
        }
    }
    return 0;
}

void intro() {
    printf("\n\n\nTo-Do List Menu:\n");
    printf("1. Add task\n");
    printf("2. Delete all tasks\n");
    printf("3. View all tasks\n");
    printf("4. Exit\n");
}

void addtask(char *filename) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    char data[100];
    printf("Enter a task: ");
    fgets(data, sizeof(data), stdin);
    data[strcspn(data, "\n")] = 0;
    fprintf(file, "%s\n", data);
    fclose(file);
    printf("Task added.\n");
}

void deletetasks(char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    fclose(file);
    printf("All tasks deleted.\n");
}

void viewtask(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }
    char data[100];
    int i = 0;
    printf("To-Do List:\n");
    while (fgets(data, sizeof(data), file) != NULL) {
        i++;
        printf("%d. %s", i, data);
    }
    if (i == 0) {
        printf("No tasks found.\n");
    }
    fclose(file);
}
