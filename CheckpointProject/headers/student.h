#ifndef STUDENT_H
#define STUDENT_H
struct Node
{
    char _name[50];
    char _lastName[50];
    char _phoneNumber[15];
    int grade[10];
    struct Node* next; // Pointer to the next student in the list
}typedef Node;
struct Students
{
    struct Node* head; // Pointer to the first node in the list
}typedef Students;

#endif // STUDENT_H