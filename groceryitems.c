# Grocery-list-in-C
#A simple C program to manage a grocery store list using dynamic memory allocation.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void displayList(char **list, int size) {
    printf("\nGrocery List:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s\n", i + 1, list[i]);
    }
}

int main() {
 int n;
    printf("Enter initial number of grocery items: ");
    scanf("%d", &n);

    char **list = (char **)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        list[i] = (char *)malloc(100 * sizeof(char));
        printf("Enter item %d: ", i + 1);
        scanf("%s", list[i]);
    }

    char choice;
        printf("\nChoose an option:\n");
        printf("a - Add item\n");
        printf("d - Delete item\n");
        printf("v - View list\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        if (choice == 'a') {
            n++;
            list = (char **)realloc(list, n * sizeof(char *));
            list[n - 1] = (char *)malloc(100 * sizeof(char));
             printf("Enter new item: ");
            scanf("%s", list[n - 1]);
        } else if (choice == 'd') {
            int index;
            displayList(list, n);
            printf("Enter item number to delete: ");
            scanf("%d", &index);
            index--; // to match 0-based indexing
            if (index >= 0 && index < n) {
                free(list[index]);
                for (int i = index; i < n - 1; i++) {
                    list[i] = list[i + 1];
                }
                 n--;
                list = (char **)realloc(list, n * sizeof(char *));
                printf("Item deleted.\n");
            } else {
                printf("Invalid item number.\n");
            }
        } 
        displayList(list,n);

    // Free memory
    for (int i = 0; i < n; i++) {
        free(list[i]);
    }
    free(list);

return 0;
}
        
