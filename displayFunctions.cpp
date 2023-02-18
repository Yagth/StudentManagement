#include "dataStructures.h"
#include "CourseFunctions.cpp"
#include "StudentFunctions.cpp"

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
    cout << "Press any key to go back to menu...\n";
#ifdef _WIN32
    _getch();
#else
    struct termios old_termios,
        new_termios;
    tcgetattr(STDIN_FILENO, &old_termios);
    new_termios = old_termios;
    new_termios.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
    getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &old_termios);
#endif
}

void registerStudentD()
{
    clearScreen();
    cout << "===================================================================" << endl;
    cout << "\t\t\t--Student Registration--" << endl;
    cout << "===================================================================" << endl
         << endl;
    registerStudent();
    waitForUser();
    dispMenu();
}

void registerCourseD()
{
    clearScreen();
    cout << "===================================================================" << endl;
    cout << "\t\t\t--Course Recording--" << endl;
    cout << "===================================================================" << endl
         << endl;
    recordCourse();
}

void registerStudentToCourse()
{
    string id, courseNo;

    clearScreen();
    cout << "===================================================================" << endl;
    cout << "\t\t\t--Registration Student to course--" << endl;
    cout << "===================================================================" << endl
         << endl;
    cout << "Enter student id: ";
    cin >> id;

    student *st = findStudentById(id);
    if (st == NULL)
    {
        cout << "Student with id: " << id << " is not registred" << endl;
        waitForUser();
        dispMenu();
    }
    cout << "Enter course number: ";
    cin >> courseNo;

    course *course = findCourseByNo(courseNo);
    if (course == NULL)
    {
        cout << "Course with courseNo: " << courseNo << " is not found" << endl;
        waitForUser();
        dispMenu();
    }

    st->addCourse(courseNo);
    cout << "Registered student to course succefully!!" << endl;
    waitForUser();
    dispMenu();
}

void dispMenu()
{
    // choice input of user
    int choice;

    while (true)
    {
        clearScreen();
        // display menu
        cout << "===================================================================" << endl;
        cout << "-----------WELCOME TO STUDENT MANAGEMENT SYSTEM--------------------" << endl;
        cout << "===================================================================" << endl
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