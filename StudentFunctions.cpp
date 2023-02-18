#include "dataStructures.h"
// using namespace std;

student::studentCourse *student::getStudentCourse(string courseNo)
{
    studentCourse *temp = new studentCourse();
    temp->courseNo = courseNo;
    temp->grade = -1.0;
    temp->next = NULL;

    return temp;
}

void student::addCourse(string courseNo)
{
    studentCourse *temp = getStudentCourse(courseNo);

    if (this->head == NULL)
    {
        this->head = temp;
    }
    else
    {
        studentCourse *current = this->head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = temp;
    }
}

student::studentCourse *student::findStudentCourse(string courseNo)
{
    studentCourse *current = this->head;

    if (current == NULL)
    {
        return NULL;
    }
    else
    {
        while (current != NULL)
        {
            if (current->courseNo == courseNo)
            {
                return current;
            }
            current = current->next;
        }
    }
    return NULL;
}

void student::deleteStudentCourse(string courseNo)
{
    student::studentCourse *sCourse = student::findStudentCourse(courseNo);
    // if the list is empty, return
    if (this->head == NULL)
    {
        return;
    }

    // if the key is at the head of the list
    if (this->head->courseNo == courseNo)
    {
        student::studentCourse *temp = this->head;
        this->head = this->head->next;
        delete temp;
        return;
    }

    // search for the key while keeping track of the previous node
    student::studentCourse *prev = this->head;
    student::studentCourse *curr = this->head->next;
    while (curr != NULL && curr->courseNo != courseNo)
    {
        prev = curr;
        curr = curr->next;
    }

    // if the key is found, delete the node
    if (curr != NULL)
    {
        prev->next = curr->next;
        delete curr;
    }
}

void student::gradeStudent(string courseNo, float grade)
{
    studentCourse *courseInfo = findStudentCourse(courseNo);
    courseInfo->grade = grade;
}

void student::displayStudentInfo()
{
    cout << " ID: " << this->id << endl;
    cout << " First name: " << this->firstName << endl;
    cout << " Last name: " << this->lastName << endl;
    cout << " Age: " << this->age << endl;
    cout << " Sex: " << this->sex << endl
         << endl;

    cout << "   Registered courses" << endl;

    studentCourse *temp = this->head;

    if (temp == NULL)
    {
        cout << "\tNo registered courses" << endl;
        return;
    }
    while (temp != NULL)
    {
        course *stCourse = findCourseByNo(temp->courseNo);

        if (stCourse != NULL)
        {
            cout << "\tGrade: ";
            stCourse->displayCourseInfo();
            if (temp->grade == -1.0)
                cout << "\tNot determined" << endl;
            else
                cout << "\t" << temp->grade << endl;
            cout << endl;
        }

        temp = temp->next;
    }
}

student *findStudentById(string id)
{
    student *current = SHead;

    if (current == NULL)
    {
        return NULL;
    }
    else
    {
        while (current != NULL)
        {
            if (current->id == id)
                return current;
            current = current->next;
        }
    }
    return NULL;
}

void swapNodes(student *node1, student *node2)
{
    student *temp = new student();
    temp->firstName = node1->firstName;
    temp->id = node1->id;
    temp->lastName = node1->lastName;
    temp->age = node1->age;
    temp->sex = node1->sex;

    node1->firstName = node2->firstName;
    node1->lastName = node2->lastName;
    node1->id = node2->id;
    node1->age = node2->age;
    node1->sex = node2->sex;

    node2->id = temp->id;
    node2->firstName = temp->firstName;
    node2->lastName = temp->lastName;
    node2->age = temp->age;
    node2->sex = temp->sex;
}
void toLowerCase(string str){
    for(int i = 0;i < str.length();i++){
       str[i] = tolower(str[i]);
    }
}

void sortStudentByName()
{

    if (SHead == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }
    else
    {
        student *current = SHead, *index = NULL, *temp, *temp2;
        while (current != NULL)
        {
            index = current->next;
            while (index != NULL)
            {
                student *temp = new student();
                string fname = current->firstName;
                string lname = current->lastName;
                toLowerCase(fname);  toLowerCase(lname);
                if (fname > lname)
                {
                    // Swap the elements
                    swapNodes(current, index);
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

student *getStudent()
{
    student *st = new student();
    cout << "Enter ID : ";
    cin >> st->id;

    student *temp = findStudentById(st->id);

    if (temp != NULL)
    {
        cout << "Student with Id: " << st->id << " is already registered." << endl;
        return NULL;
    }
    cin.ignore();
    cout << "Enter First name : ";
    cin >> st->firstName;
    cin.ignore();
    cout << "Enter Last name : ";
    cin >> st->lastName;
    cout << "Enter Age : ";

    // To check if the user has submitted a valid age.
    while (!(cin >> st->age))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\t!!Invalid input. Enter positive Integer" << endl;
        cout << "Enter Age : ";
    }

    cout << "Enter Sex(Male/Female) : ";
    cin.ignore();
    cin >> st->sex;

    st->next = NULL;
    st->prev = NULL;

    return st;
}

void registerStudent()
{
    student *curr = SHead;
    student *st = getStudent();

    if (st == NULL)
    {
        cout << "Registration Not successful" << endl;
        return;
    }

    // Check if List is not empty
    while (SHead != NULL && curr->next != NULL)
    {
        curr = curr->next;
    }

    if (SHead == NULL)
        SHead = st;
    else
    {
        curr->next = st;
        st->prev = curr;
    }

    cout << "Student registration succesfull" << endl;
}
void displayAllStudents()
{
    student *current = SHead;
    int count = 0;

    if (SHead == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    while (current != NULL)
    {
        cout << ++count << ". ";
        current->displayStudentInfo();
        current = current->next;

        if (count % 15 == 0)
        {
            cout << "--more--" << endl;
            waitForUser();
            clearScreen();
        }
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