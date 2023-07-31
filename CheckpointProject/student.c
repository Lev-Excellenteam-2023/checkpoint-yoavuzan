#include <stdio.h>
#include <stdlib.h>
struct Node
{
    char _name[50];
    char _lastName[50];
    char _phoneNumber[15];
    int grade[10];
    struct Node* next; // Pointer to the next student in the list
};
struct Students
{
    
    struct Node* head; // Pointer to the first node in the list
};



void addStudent(struct Node** allStudents, const char name[50], const char lastName[50], const char* phoneNumber[15], const int* grades) {
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
void printSchool(const struct Students allStu[10][12]) {
    for (int layer = 0; layer < 10; layer++) {
        for (int classNum = 0; classNum < 12; classNum++) {
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


#define MAX_LINE_LENGTH 1000000 // Define a maximum line length to read

int main() 
{
    struct Students allStu[12][10];
for (int layer = 0; layer < 12; layer++) {
		for (int classNum = 0; classNum < 10; classNum++) {
			allStu[layer][classNum].head = NULL;
		}
	}
    FILE* file;
    errno_t err;
    //read the data from a file
    err = fopen_s(&file, "students_with_class.txt", "r");
   
    if (err != 0) {
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

        int n = sscanf_s(buffer, "%s %s %s %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
            name, sizeof(name), lastName, sizeof(lastName), phoneNumber, sizeof(phoneNumber),
            &layer, &classNum, &grades[0], &grades[1], &grades[2], &grades[3], &grades[4],
            &grades[5], &grades[6], &grades[7], &grades[8], &grades[9]);

        // Check if all values were successfully parsed
        if (n != 15) {
            printf("Invalid data format: %s\n", buffer);
            continue; // Skip this line and proceed to the next one
        }

        // Add the student to the class
        addStudent(&allStu[layer-1][classNum-1].head, name, lastName, phoneNumber, grades);
    }
    printSchool(allStu);
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

