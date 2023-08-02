
#include "headers/globals.h"
#include "headers/menu.h"
#define MAX_LINE_LENGTH 1000000 // Define a maximum line length to read
int main()
{
    for (int layer = 0; layer < 12; layer++) {
        for (int classNum = 0; classNum < 10; classNum++) {
            allStu[layer][classNum].head = NULL;
        }
    }
    

    //read the data from a file
    FILE* file = fopen("shortStu.txt", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }

    int i = 0;
    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, file) != NULL)
    {
        // Parse the data from the line
        char name[50], lastName[50], phoneNumber[50];
        int layer, classNum;
        int grades[10];

       int n = sscanf(buffer, "%s %s %s %d %d %d %d %d %d %d %d %d %d %d %d",
            name, lastName, phoneNumber,
            &layer, &classNum, &grades[0], &grades[1], &grades[2], &grades[3], &grades[4],
            &grades[5], &grades[6], &grades[7], &grades[8], &grades[9]);

        // Check if all values were successfully parsed
        if (n != 15) {
            printf("Invalid data format: %s\n", buffer);
            continue; // Skip this line and proceed to the next one
        }

        // Add the student to the class
        addStudent(&allStu[layer - 1][classNum - 1].head, name, lastName, phoneNumber, grades);
    }
    printSchool();
    menu();
    // Free memory for each student linked list
    for (int layer = 0; layer < 12; layer++) {
        for (int classNum = 0; classNum < 10; classNum++) {
            struct Node* current = allStu[layer][classNum].head;
            while (current != NULL) {
                struct Node* next = current->next;
                free(current);
                current = next;
            }
        }
    }


    fclose(file); // Close the file when you're done reading
    //free(allStu) and free(allStu->head) and free(current) and free(current->next)

    return 0;
}

