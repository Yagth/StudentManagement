#include "dataStructures.h"
#include "StudentFunctions.cpp"
#include "CourseFunctions.cpp"

#ifdef _WIN32
#include <conio.h> // for _getch()
#else
#include <unistd.h>  // for STDIN_FILENO
#include <termios.h> // for tcgetattr(), tcsetattr(), struct termios
#endif

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void waitForUser()
{
#ifdef _WIN32
    _getch();
#else
    struct termios old_termios, new_termios;
    tcgetattr(STDIN_FILENO, &old_termios);
    new_termios = old_termios;
    new_termios.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
    getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &old_termios);
#endif
}

void dispMenu()
{
    // choice input of user
    int choice;

    while (true)
    {
        clearScreen();
        // display menu
        cout << "-----------------------------------------------------------------------" << endl;
        cout << "WELCOME TO STUDENT RECORD MANAGEMENT SYSTEM" << endl;
        cout << "-----------------------------------------------------------------------" << endl
             << endl;
        cout << "1. Register Student" << endl;
        cout << "2. Register Course" << endl;
        cout << "3. Register Student to Course" << endl;
        cout << "4. Grade Student" << endl;
        cout << "5. Search Student" << endl;
        cout << "6. Search Course" << endl;
        cout << "7. Display All Students" << endl;
        cout << "8. Display All Courses" << endl;
        cout << "9. Sort Students" << endl;
        cout << "10. Delete Student" << endl;
        cout << "11. Delete Course" << endl;
        cout << "12. Save Student information to file" << endl;
        cout << "0. Exit" << endl;
        cout << endl;
        cout << "Enter your choice(0-12): ";
        // enter choice
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (choice)
        {
        case 0:
            return;
        case 1:
            registerStudent();
            waitForUser();
            dispMenu();
            break;
        case 2:
            recordCourse();
            break;
        case 3:
            // maintainGrades();
            break;
        case 4:
            // searchStudents();
            break;
        case 5:
            // searchCourses();
            break;
        case 6:
            // sortStudents();
            break;
        case 7:
            displayAllStudents();
            break;
        case 8:
            displayAllCourses();
            break;
        case 9:
            // deleteCourses();
            break;
        case 10:
            // writeToFile();
            break;
        default:
            cout << "invalid input, please try again!" << endl;
        }
        clearScreen();
    }
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
