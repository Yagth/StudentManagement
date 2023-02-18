#include <cstdlib>
#include <fstream>
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
#ifdef _WIN32
    system("pause");
#else
    system("bash -c 'read -n1 -r -p \"Press any key to continue...\" key'");
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
    waitForUser();
    dispMenu();
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
    }
    else
    {
        cout << "Enter course number: ";
        cin >> courseNo;
        course *course = findCourseByNo(courseNo);
        if (course == NULL)
        {
            cout << "Course with courseNo: " << courseNo << " is not found" << endl;
        }
        else
        {
            st->addCourse(courseNo);
            cout << "Registered student to course succefully!!" << endl;
        }
    }
    waitForUser();
    dispMenu();
}

void gradeStudentD()
{
    string id, courseNo;
    float grade;
    clearScreen();
    cout << "===================================================================" << endl;
    cout << "\t\t\t--Grading Student--" << endl;
    cout << "===================================================================" << endl
         << endl;

    cout << "Enter Id: ";
    cin >> id;

    student *st = findStudentById(id);
    if (st == NULL)
    {
        cout << "Student with id: " << id << " is not found" << endl;
    }
    else
    {
        cout << "Enter courseNo: ";
        cin >> courseNo;

        student::studentCourse *course = st->findStudentCourse(courseNo);
        if (course == NULL)
        {
            cout << "Student is not registred to course with courseNo: " << courseNo << endl;
        }
        else
        {
            cout << "Enter grade: ";
            while (!(cin >> grade) || !(grade <= 4.0 && grade >= 0))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "\t Please make sure you entered a grade between 0.0 - 4.0" << endl;
                cout << "Enter grade: ";
            }

            st->gradeStudent(courseNo, grade);
            cout << "Student graded successfully" << endl;
        }
    }
    waitForUser();
    dispMenu();
}

void searchStudentD()
{
    string id;
    clearScreen();
    cout << "===================================================================" << endl;
    cout << "\t\t\t--Search Student--" << endl;
    cout << "===================================================================" << endl
         << endl;
    cout << "Enter id: ";
    cin >> id;

    student *st = findStudentById(id);
    if (st == NULL)
    {
        cout << "Student with id: " << id << " couldn't be found" << endl;
    }
    else
    {
        cout << "Student found!!" << endl
             << endl;
        st->displayStudentInfo();
    }
    waitForUser();
    dispMenu();
}

void searchCourseD()
{
    string courseNo;
    clearScreen();
    cout << "===================================================================" << endl;
    cout << "\t\t\t--Search  Course--" << endl;
    cout << "===================================================================" << endl
         << endl;
    cout << "Enter courseNo: ";
    cin >> courseNo;

    course *course = findCourseByNo(courseNo);
    if (course == NULL)
    {
        cout << "Course with courseNo: " << courseNo << " couldn't be found" << endl;
    }
    else
    {
        cout << "Course found!!" << endl
             << endl;
        course->displayCourseInfo();
    }
    waitForUser();
    dispMenu();
}

void displayAllStudentsD()
{
    clearScreen();
    cout << "===================================================================" << endl;
    cout << "\t\t\t--List of Students--" << endl;
    cout << "===================================================================" << endl
         << endl;
    displayAllStudents();
    waitForUser();
    dispMenu();
}

void displayAllCoursesD()
{
    clearScreen();
    cout << "===================================================================" << endl;
    cout << "\t\t\t--List of Courses--" << endl;
    cout << "===================================================================" << endl
         << endl;
    displayAllCourses();
    waitForUser();
    dispMenu();
}

void sortD()
{
    cout << "Sorting..." << endl;
    sortStudentByName();
    cout << "Sort finished!!" << endl;
    clearScreen();
    cout << "===================================================================" << endl;
    cout << "\t\t\t--Sorted list of students--" << endl;
    cout << "===================================================================" << endl
         << endl;
    displayAllStudents();
    waitForUser();
    dispMenu();
}

void deleteStudentD()
{
    string id;
    clearScreen();
    cout << "===================================================================" << endl;
    cout << "\t\t\t--Delete student--" << endl;
    cout << "===================================================================" << endl
         << endl;
    cout << "Enter id: ";
    cin >> id;

    deleteStudentById(id);
    waitForUser();
    dispMenu();
}

void deleteCourseD()
{
    string courseNo;
    clearScreen();
    cout << "===================================================================" << endl;
    cout << "\t\t\t--Delete Course--" << endl;
    cout << "===================================================================" << endl
         << endl;
    cout << "Enter courseNo: ";
    cin >> courseNo;

    deleteCourseByCourseNumber(courseNo);
    waitForUser();
    dispMenu();
}

void dispMenu()
{
    // choice input of user
    int choice;
    bool saved;

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
        cout << "9. Sort Students by FirstName" << endl;
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
            cout << "Exiting..." << endl;
            return;
        case 1:
            registerStudentD();
            break;
        case 2:
            registerCourseD();
            break;
        case 3:
            registerStudentToCourse();
            break;
        case 4:
            gradeStudentD();
            break;
        case 5:
            searchStudentD();
            break;
        case 6:
            searchCourseD();
            break;
        case 7:
            displayAllStudentsD();
            break;
        case 8:
            displayAllCoursesD();
            break;
        case 9:
            sortD();
            break;
        case 10:
            deleteStudentD();
            break;
        case 11:
            deleteCourseD();
            break;
        case 12:
            saved = saveLinkedList("students");
            if (saved)
                cout << "Save successfull" << endl;
            else
                cout << "saving failed" << endl;
            waitForUser();
            break;
        default:
            cout << "invalid input, please try again!" << endl;
        }
        clearScreen();
    }
}

bool saveLinkedList(const char *filename)
{
    ofstream fout(filename);

    if (!fout)
    {
        cerr << "Error: failed to open file " << filename << " for writing." << endl;
        return false;
    }

    // write the number of nodes in the list as first line
    int count = 0;
    student *current = SHead;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    fout << count << endl;

    // write each node's data and linked list attribute
    current = SHead;
    while (current != NULL)
    {
        // write student data
        fout << current->id << "," << current->firstName << "," << current->lastName << ","
             << current->age << "," << current->sex;

        // write linked list attribute
        if (current->head != NULL)
        { // check if student has courses
            student::studentCourse *courseCurrent = current->head;
            while (courseCurrent != NULL)
            {
                fout << "," << courseCurrent->courseNo << ":" << courseCurrent->grade;
                courseCurrent = courseCurrent->next;
            }
        }

        fout << endl;

        current = current->next;
    }

    fout.close();
    return true;
}

bool loadLinkedList(const char *filename)
{
    ifstream fin(filename);

    if (!fin)
    {
        cerr << "Error: failed to open file " << filename << " for reading." << endl;
        return false;
    }

    // read the number of nodes in the list from the first line
    int count;
    fin >> count;
    string line;
    getline(fin, line);

    // read each node's data and linked list attribute
    for (int i = 0; i < count; i++)
    {
        student *current = new student();
        getline(fin, line);

        // tokenize the line by ","
        stringstream ss(line);
        string token;
        getline(ss, token, ',');
        current->id = token;
        getline(ss, current->firstName, ',');
        getline(ss, current->lastName, ',');
        getline(ss, token, ',');
        current->age = stoi(token);
        getline(ss, current->sex, ',');
        // read linked list attribute
        getline(ss, token, ',');
        while (getline(ss, token, ','))
        {
            if (token.find(":") != string::npos)
            { // check if token is a course string
                // tokenize the course string by ":"
                stringstream courseSS(token);
                string courseNoStr, gradeStr;
                getline(courseSS, courseNoStr, ':');
                getline(courseSS, gradeStr, ':');
                string courseNo = courseNoStr;
                float grade = stof(gradeStr);

                // add course to student's course linked list
                student::studentCourse *courseNode = new student::studentCourse();
                courseNode->courseNo = courseNo;
                courseNode->grade = grade;
                current->addCourse(courseNode->courseNo);
            }
        }

        if (SHead == NULL)
        {
            SHead = current;
        }
        else
        {
            student *curr = SHead;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->next = current;
        }
    }

    fin.close();
    return true;
}
