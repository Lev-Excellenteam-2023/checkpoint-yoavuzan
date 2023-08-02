#include "headers/globals.h"
#include <stdlib.h>
Students allStu[12][10];
void printSchool() {
    for (int layer = 0; layer < 12; layer++) {
        for (int classNum = 0; classNum < 10; classNum++) {
            printf("Layer %d - Class %d:\n", layer + 1, classNum + 1);
            struct Node* current = allStu[layer][classNum].head;
            while (current != NULL) {
                printf("Name: %s %s\n", current->_name, current->_lastName);
                printf("Phone Number: %s\n", current->_phoneNumber);
                printf("Grades: ");
                for (int i = 0; i < 10; i++) {
                    printf("%d ", current->grade[i]);
                }
                printf("\n");
                current = current->next;
            }
            printf("\n");
        }
    }
}
void addStudent(struct Node** allStudents, const char name[50], const char lastName[50], const char phoneNumber[15], const int* grades)
{
    struct Node* current = *allStudents;
    if (current == NULL) {
        // If the list is empty, create the first node
        current = (struct Node*)malloc(sizeof(struct Node));
        if (current == NULL) {
            printf("Memory allocation failed for new student.\n");
            return;
        }
        *allStudents = current;
    }
    else {
        // Find the last node in the linked list
        while (current->next != NULL) {
            current = current->next;
        }

        // Create a new student node
        current->next = (struct Node*)malloc(sizeof(struct Node));
        if (current->next == NULL) {
            printf("Memory allocation failed for new student.\n");
            return;
        }
        current = current->next;
    }

    // Assign the values to the new student node
    
    strcpy(current->_name, name);
    strcpy(current->_lastName, lastName);
    strcpy(current->_phoneNumber, phoneNumber);
    
    for (int i = 0; i < 10; i++) {
        current->grade[i] = grades[i];
    }
    current->next = NULL;
}
