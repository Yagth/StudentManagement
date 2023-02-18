#include <iostream>
#include "C:\p1\StudentManagement\Student\dataStructures.h";
using namespace std;

void deleteStudentById(student *SHead, string id)
{
    student *current = SHead;

    // Traverse the list to find the student to be deleted
    while (current != NULL && current->id != id)
    {
        current = current->next;
    }

    // If the student is not found, return
    if (current == NULL)
    {
        return;
    }

    // If the student to be deleted is the head student, update the head pointer
    if (SHead == current)
    {
        SHead = current->next;
        if (SHead != NULL)
        {
            SHead->prev = NULL;
        }
    }
    else
    {
        // Update the next pointer of the previous student
        current->prev->next = current->next;

        // Update the previous pointer of the next student
        if (current->next != NULL)
        {
            current->next->prev = current->prev;
        }
    }

    // Free the memory of the student to be deleted
    delete current;
}

void deleteCourseByCourseNumber(course *CHead, int courseNo)
{
    course *current = CHead;

    // Traverse the list to find the Course Number to be deleted
    while (current != NULL && current->courseNo != courseNo)
    {
        current = current->next;
    }

    // If the Course Numbert is not found, return
    if (current == NULL)
    {
        return;
    }

    // If the Course Number to be deleted is in head , update the head pointer
    if (CHead == current)
    {
        CHead = current->next;
        if (CHead != NULL)
        {
            CHead->prev = NULL;
        }
    }
    else
    {
        // Update the next pointer of the previous Course
        current->prev->next = current->next;

        // Update the previous pointer of the next course
        if (current->next != NULL)
        {
            current->next->prev = current->prev;
        }
    }

    // Free the memory of the course to be deleted
    delete current;
}
