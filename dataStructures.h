#ifndef DATA_STRUCUTRES
#define DATA_STRUCUTRES

#include <bits/stdc++.h>

#ifdef _WIN32
#include <conio.h> // for windows users
#else
#include <unistd.h>  // for Linux users
#include <termios.h> // for Linux users
#endif

using namespace std;

struct course
{
    string courseNo;
    string courseTitle;
    int creditHour;
    course *next;
    course *prev;

} *CHead = NULL;

struct student
{
    string id;
    string firstName;
    string lastName;
    int age;
    string sex;

    struct studentCourse
    {
        string courseNo;
        float grade;
        studentCourse *next;
    } *head;

    student *next;
    student *prev;

    studentCourse *getStudentCourse(string courseNo);
    void addCourse(string courseNo);
    studentCourse *findStudentCourse(string courseNo);
    void gradeStudent(string courseNo, float grade);
    void displayStudentInfo();

} *SHead = NULL;

student *findStudentById(string id);
void displayAllStudents();
void deleteStudentById(string id);
void swapNodes(student *node1, student *node2);
void sortStudentByName();
student *getStudent();
void registerStudent();

void deleteCourseByCourseNumber(string courseNo);
course *findCourseByNo(string courseNo);
void displayAllCourses();
void recordCourse();
course *getCourse();

void clearScreen();
void waitForUser();
void registerStudentToCourse();
void registerStudentD();
void dispMenu();

#endif