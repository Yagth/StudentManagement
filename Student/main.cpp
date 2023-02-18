#include "dataStructures.h"
#include "StudentFunctions.cpp"
#include "CourseFunctions.cpp"

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void dispMenu()
{
    int choice;
    do
    {
        clearScreen();

        cout << "STUDENT MANAGEMENT MENU" << endl;
        cout << "-----------------------" << endl;
        cout << "1. Register Student" << endl;
        cout << "2. Register Course" << endl;
        cout << "3. Register Student to Course" << endl;
        cout << "4. Grade Student" << endl;
        cout << "5. Search Student" << endl;
        cout << "6. Search Course" << endl;
        cout << "7. Display All Students" << endl;
        cout << "8. Display All Courses" << endl;
        cout << "9. Sort Students" << endl;
        cout << "10. Sort Students" << endl;
        cout << "11. Delete Student" << endl;
        cout << "12. Delete Course" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Exiting program..." << endl;
            break;
        case 1:
            // Register Student
            break;
        case 2:
            // Register Course
            break;
        case 3:
            // Register Student to Course
            break;
        case 4:
            // Grade Student
            break;
        case 5:
            // Search Student
            break;
        case 6:
            // Search Course
            break;
        case 7:
            // Display All Students
            break;
        case 8:
            // Display All Courses
            break;
        case 9:
            // Sort Students
            break;
        case 10:
            // Sort Students
            break;
        case 11:
            // Delete Student
            break;
        case 12:
            // Delete Course
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

        cout << endl;
        system("pause");
    } while (choice != 0);
}

int main()
{
    dispMenu();
    // registerStudent();
    // registerStudent();
    // registerStudent();
    // registerStudent();

    // student *temp = SHead;

    // deleteStudentById(temp->id);
    // displayAllStudents();

    // recordCourse();
    // recordCourse();

    // student *temp = SHead;
    // course *tempCourse = CHead;
    // temp->addCourse(tempCourse->courseNo);
    // temp->addCourse(tempCourse->next->courseNo);

    // temp->displayStudentInfo();
    // temp->next->displayStudentInfo();
    // cout << endl;
    // display(CHead);
}
