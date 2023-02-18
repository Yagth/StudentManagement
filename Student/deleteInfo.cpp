#include <iostream>
#include "C:\p1\StudentManagement\Student\DataStrucutres.h";
using namespace std;

void delete_student_by_id(student** head_ref, string id) {
    student* current = *head_ref;

    // Traverse the list to find the student to be deleted
    while (current != nullptr && current->id != id) {
        current = current->next;
    }

    // If the student is not found, return
    if (current == nullptr) {
        return;
    }

    // If the student to be deleted is the head student, update the head pointer
    if (*head_ref == current) {
        *head_ref = current->next;
        if (*head_ref != nullptr) {
            (*head_ref)->prev = nullptr;
        }
    }
    else {
        // Update the next pointer of the previous student
        current->prev->next = current->next;

        // Update the previous pointer of the next student
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }
    }

    // Free the memory of the student to be deleted
    delete current;
}

void deleteCourseByCourseNumber(course** head_ref, int courseNo) {
    course* current = *head_ref;

    // Traverse the list to find the Course Number to be deleted
    while (current != nullptr && current->courseNo != courseNo) {
        current = current->next;
    }

    // If the Course Numbert is not found, return
    if (current == nullptr) {
        return;
    }

    // If the Course Number to be deleted is in head , update the head pointer
    if (*head_ref == current) {
        *head_ref = current->next;
        if (*head_ref != nullptr) {
            (*head_ref)->prev = nullptr;
        }
    }
    else {
        // Update the next pointer of the previous Course
        current->prev->next = current->next;

        // Update the previous pointer of the next course
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }
    }

    // Free the memory of the course to be deleted
    delete current;
}


