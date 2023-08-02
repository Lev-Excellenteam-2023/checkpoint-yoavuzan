#include "headers/globals.h"
#include "headers/menu.h"
/*struct inputData {
    char name[50];
    char lastName[50];
    char phoneNumber[15];
	int grade[10];
	int level;
	int classes;
}typedef inputData;
*/
enum menu_inputs {
    Insert = '0',
    Delete = '1',
    Edit = '2',
    Search = '3',
    Showall = '4',
    Top10 = '5',
    UnderperformedStudents = '6',
    Average = '7',
    Export = '8',
    Exit = '9'
};
bool checkClass(int tempClasses)
{
/*	if (tempClasses < 1 || tempClasses > 10)
	{
		printf("Invalid class!\n");
		return false;
	}
    */
	return true;
}
bool checkLevel(int _level)
{
	/*if (_level < 1 || _level > 12)
	{
		printf("Invalid level!\n");
		return false;
	}
    */
	return true;
}
bool checkGrade(int _grade)
{
	/*if (_grade < 0 || _grade > 100)
	{
		printf("Invalid grade!\n");
		return false;
	}
    */
	return true;
}
bool checkPhone(char _phoneNumber[15])
{
   /* if (_phoneNumber[0] != '0' || _phoneNumber[1] != '5' || strlen(_phoneNumber) != 10)
    {
        printf("Invalid phone number!\n");
        return false;
    }
    */
    return true;
}

void input(inputData * cur_data)
{
	printf("Enter student name: ");
	//scanf("%s", name);
    scanf("%s", cur_data->name);
	printf("Enter student last name: ");
	//scanf("%s", lastName);
    scanf("%s", cur_data->lastName);
	printf("Enter student phone number: ");
    char tempPhone[15];
	//scanf("%s", tempPhone);
	scanf("%s", tempPhone);
    if (checkPhone(tempPhone))
    {   
        strcpy(cur_data->phoneNumber, tempPhone);
    }
    else
        return;
	printf("Enter student grades: ");
    int tempGrade = 0;
	for(int i = 0; i < 10; i++)
	{
        scanf("%d", &tempGrade);
        if (checkGrade(tempGrade))
        {
            cur_data->grade[i] = tempGrade;
        }
        else
        {
        printf("Invalid grade entered. Please try again.\n");
        i--; // Decrement i to re-enter the invalid grade
        }
	}
    int tempLevel = 0;
    printf("Enter student level: ");
    scanf("%d", &tempLevel);
    if (checkLevel(tempLevel))
    {
        cur_data->level = tempLevel;
    }
    else
        return;
    int tempClasses=0;
    printf("Enter student classes: ");
    scanf("%d", &tempClasses);
    if (checkClass(tempClasses))
    {
    //    strcpy(&classes, tempClasses);
    cur_data->classes = tempClasses;
    }
	else
		return;

}
void insertNewStudent()
{
    inputData cur_data;
    input(&cur_data);
    printf("Name: %s\nLast name: %s\nPhone number: %s\n", cur_data.name, cur_data.lastName, cur_data.phoneNumber);
    addStudent(&(allStu[cur_data.level - 1][cur_data.classes - 1]).head, cur_data.name, cur_data.lastName, cur_data.phoneNumber, cur_data.grade);
}

void deleteStudentByPhone(const char* number,const int level,const int classes)
{
	struct Node* current = allStu[level - 1][classes - 1].head;
	struct Node* prev = NULL;
	if (current == NULL) {
		printf("No students to delete.\n");
		return;
	}
	else {
		// Find the last node in the linked list
		while (current != NULL) {
			if (strcmp(current->_phoneNumber, number) == 0)
			{
				if (prev == NULL)
				{
                    allStu[level - 1][classes - 1].head = current->next;
					free(current);
					return;
				}
				else
				{
					prev->next = current->next;
					free(current);
					return;
				}
			}
			prev = current;
			current = current->next;
		}
	}
	printf("No student with this phone number.\n");
}
void deleteStudent()
{
	char number[50];
    int level=0, classes=0;
	printf("Enter phone number: ");
    scanf("%s", number);
    printf("Enter level: ");
    scanf("%d", &level);
	printf("Enter classes: ");
    scanf("%d", &classes);
    //checkPhone(number);
	deleteStudentByPhone(number, level, classes);
}

void editStudentGrade()
{
    printf("Enter the index of number that you want to edit: ");
    int index = 0;
    scanf("%d", &index);
    int level = 0, classes = 0;
    printf("Enter level: ");
    scanf("%d", &level);
    printf("Enter classes: ");
    scanf("%d", &classes);
    printf("Enter new grade: ");
    scanf("%d", &allStu[level - 1][classes - 1].head->grade[index-1]);
}

void searchStudent()
{
	char number[50];
	int level = 0, classes = 0;
	printf("Enter phone number: ");
	scanf("%s", number);
	printf("Enter level: ");
	scanf("%d", &level);
	printf("Enter classes: ");
	scanf("%d", &classes);
	struct Node* current = allStu[level - 1][classes - 1].head;
	if (current == NULL) {
		printf("No students to search.\n");
		return;
	}
	else {
		// Find the last node in the linked list
		while (current != NULL) {
			if (strcmp(current->_phoneNumber, number) == 0)
			{
				printf("Name: %s\nLast name: %s\nPhone number: %s\n", current->_name, current->_lastName, current->_phoneNumber);
				return;
			}
			current = current->next;
		}
	}
	printf("No student with this phone number.\n");
}

void printAllStudents()
{
    printSchool();
}

void  exportDatabase()
{






}
void menu() {
    char input;
    // school.name = "schoolName";
    do {
        printf("\n|School Manager<::>Home|\n");
        printf("--------------------------------------------------------------------------------\n");
        //printf("Welcome to ( %s ) School!\nYou have inserted ( %zu ) students.\n\n", school.name, school.numOfStudents);
        printf("\t[0] |--> Insert\n");
        printf("\t[1] |--> Delete\n");
        printf("\t[2] |--> Edit\n");
        printf("\t[3] |--> Search\n");
        printf("\t[4] |--> Show All\n");
        printf("\t[5] |--> Top 10 students per course\n");
        printf("\t[6] |--> Underperformed students\n");
        printf("\t[7] |--> Average per course\n");
        printf("\t[8] |--> Export\n");
        printf("\t[9] |--> Exit\n");
        printf("\n\tPlease Enter Your Choice (0-9): ");
        input = getc(stdin);
        fflush(stdin);
        getc(stdin);
        switch (input) {
            case Insert:
                insertNewStudent(allStu);
                break;
            case Delete:
                deleteStudent(allStu);
                break;
            case Edit:
                editStudentGrade();
                break;
            case Search:
                searchStudent();
                break;
            case Showall:
                printAllStudents();
                break;
            case Top10:
                //printTopNStudentsPerCourse();
                break;
            case UnderperformedStudents:
                //printUnderperformedStudents();
                break;
            case Average:
                //printAverage();
                break;
            case Export:
                exportDatabase();
                break;
            case Exit:
                //handleClosing();
                break;
            default:
                printf("\nThere is no item with symbol \"%c\".Please enter a number between 1-10!\nPress any key to continue...",
                       input);
                getc(stdin);
                getc(stdin);
                break;
        }
    } while (input != Exit);
}

