#ifndef GLOBALS_H
#define GLOBALS_H
#include <stdio.h>
#include <string.h>
#include "student.h"
extern Students allStu[12][10];
void printSchool() ;
void addStudent(struct Node** allStudents, const char name[50], const char lastName[50], const char phoneNumber[15], const int* grades);

// bool checkClass(int tempClasses);
// bool checkLevel(int _level);
// bool checkGrade(int _grade);
// bool checkPhone(char _phoneNumber[15]);
// void addStudent();
// void input();
// void insertNewStudent();
// void printSchool();
// void deleteStudentByPhone();
// void deleteStudent();
// void editStudentGrade();
// void searchStudent();
// void printAllStudents();
// void exportDatabase();

#endif//GLOBALS_H
