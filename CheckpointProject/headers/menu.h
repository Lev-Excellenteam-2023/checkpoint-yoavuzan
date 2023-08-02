#ifndef MENU_H
#define MENU_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
struct inputData {
    char name[50];
    char lastName[50];
    char phoneNumber[15];
	int grade[10];
	int level;
	int classes;
}typedef inputData;
void menu();
bool checkClass(int tempClasses);
bool checkLevel(int _level);
bool checkGrade(int _grade);
bool checkPhone(char _phoneNumber[15]);
void input(inputData * cur_data);
void insertNewStudent();
void deleteStudentByPhone(const char* number,const int level,const int classes);
void deleteStudent();
void editStudentGrade();
void searchStudent();
void printAllStudents();

#endif // MENU_H
