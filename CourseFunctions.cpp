#include "dataStructures.h"
course *findCourseByNo(string courseNo)
{
    course *current = CHead;

    if (current == NULL)
    {
        return NULL;
    }
    else
    {
        while (current != NULL)
        {
            if (current->courseNo == courseNo)
                return current;
            current = current->next;
        }
    }
    return NULL;
}

void displayAllStudents()
{
    student *current = SHead;

    if (SHead == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    while (current != NULL)
    {
        cout << "ID: " << current->id << endl;
        cout << "First name: " << current->firstName << endl;
        cout << "Last name: " << current->lastName << endl;
        cout << "Age: " << current->age << endl;
        cout << "Sex: " << current->sex << endl;

        current = current->next;
    }
}

void deleteStudentById(string id)
{
    student *current = findStudentById(id);

    // If the student is not found, return
    if (current == NULL)
    {
        cout << "\tStudent not found." << endl;
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

    cout << "Student deleted sucessfully" << endl;
}

void deleteCourseByCourseNumber(string courseNo)
{
    course *current = findCourseByNo(courseNo);

    // If the Course Numbert is not found, return
    if (current == NULL)
    {
        cout << "\tCourse not found!" << endl;
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
    cout << "Course deleted sucessfully" << endl;
}

course *getCourse()
{
    course *newcourse = new course();
    cout << "Enter Course No ";
    cin >> newcourse->courseNo;

    course *temp = findCourseByNo(newcourse->courseNo);

    if (temp != NULL)
    {
        cout << "Course with number: " << newcourse->courseNo << " already exists." << endl;
        return NULL;
    }

    cout << "Enter Course Credit Hour ";
    while (!(cin >> newcourse->creditHour))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\t!!Please Make sure the credit hour is integer!!" << endl;
        cout << "Enter Course Credit Hour ";
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter Course Title ";
    getline(cin, newcourse->courseTitle);

    newcourse->next = NULL;
    newcourse->prev = NULL;

    return newcourse;
}

void recordCourse()
{
    course *newCourse = getCourse();
    if (CHead == NULL)
    {
        CHead = newCourse;
    }
    else
    {
        course *temp = CHead;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newCourse;
        newCourse->prev = temp;
    }
    cout << "Course Successfully added to list" << endl;
}

void displayAllCourses()
{
    course *current = CHead;
    while (current != NULL)
    {
        cout << "course Number " << current->courseNo << endl;
        cout << "course Title " << current->courseTitle << endl;
        cout << "course credit Hour " << current->creditHour << endl;
        cout << endl;
        current = current->next;
    }
}
