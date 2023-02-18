#include <bits/stdc++.h>

using namespace std;

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