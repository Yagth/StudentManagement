#include <bits/stdc++.h>

using namespace std;

struct course
{
    string courseNo;
    string courseTitle;
    int creditHour;
    course *next;

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

    studentCourse *getStudentCourse(string courseNo)
    {
        studentCourse *temp = new studentCourse();
        temp->courseNo = courseNo;
        temp->grade = -1.0;
        temp->next = NULL;

        return temp;
    }

    void addCourse(string courseNo)
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

    studentCourse *findStudentCourse(string courseNo)
    {
        studentCourse *current = this->head;

        if (current == NULL)
        {
            cout << "No registred Course" << endl;
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

    void gradeStudent(string courseNo, float grade)
    {
        studentCourse *courseInfo = findStudentCourse(courseNo);
        courseInfo->grade = grade;
    }

    void displayStudentInfo()
    {
        cout << "ID: " << this->id << endl;
        cout << "First name: " << this->firstName << endl;
        cout << "Last name: " << this->lastName << endl;
        cout << "Age: " << this->age << endl;
        cout << "Sex: " << this->sex << endl;

        cout << "Registered courses" << endl;

        studentCourse *temp = this->head;

        if (temp == NULL)
        {
            cout << "No registered courses" << endl;
            return;
        }

        while (temp != NULL)
            cout << "\tCourseNo: " << temp->courseNo;
        cout << "\tGrade: ";

        if (temp->grade == -1.0)
            cout << "Not determined" << endl;
        else
            cout << temp->grade << endl;
    }

} *SHead = NULL;

student *findStudentById(string id)
{
    student *current = SHead;

    if (current == NULL)
    {
        cout << "List is empty" << endl;
    }
    else
    {
        while (current != NULL)
        {
            if (current->id == id)
                return current;
            current = current->next;
        }
        cout << "Student not found" << endl;
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

course *getCourse()
{
    course *newcourse = new course();
    cout << "Enter Course number ";
    cin >> newcourse->courseNo;

    cout << "Enter Course Title ";
    getline(cin, newcourse->courseTitle);
    cin >> newcourse->courseTitle;
    cout << "Enter Course Credit Hour ";
    cin >> newcourse->creditHour;
    newcourse->next = NULL;

    return newcourse;
}
void recordCourse()
{
    course *newCourse = getCourse();
    if (CHead == NULL)
    {
        CHead = newCourse;
        return;
    }
    else
    {
        course *temp = CHead;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newCourse;
    }
}

void display(course *n)
{
    while (n != NULL)
    {
        cout << "course Number " << n->courseNo << endl;
        cout << "course Title " << n->courseTitle << endl;
        cout << "course credit Hour " << n->creditHour << endl;
        cout << endl;
        n = n->next;
    }
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
                if (current->firstName > index->firstName)
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

void registerStudent()
{
    student *curr = SHead;

    // Check if List is not empty
    while (SHead != NULL && curr->next != NULL)
    {
        curr = curr->next;
    }
    student *st = new student();
    cout << "Enter ID : ";
    cin.ignore(); // To Clear the buffer memory before the next input
    cin >> st->id;
    cout << "Enter First name : ";
    cin.ignore();
    cin >> st->firstName;
    cout << "Enter Last name : ";
    cin.ignore();
    cin >> st->lastName;
    cout << "Enter Age : ";
    cin.ignore();
    cin >> st->age;
    cout << "Enter Sex : ";
    cin.ignore();
    cin >> st->sex;

    st->next = NULL;
    st->prev = NULL;

    if (SHead == NULL)
        SHead = st;
    else
    {
        curr->next = st;
        st->prev = curr;
    }
}

int main()
{
    registerStudent();
    recordCourse();
    student *temp = SHead;
    course *tempCourse = CHead;
    // temp->addCourse(tempCourse->courseNo);

    // temp->displayStudentInfo();
    // registerStudent();
    // registerStudent();

    // recordCourse();
    // recordCourse();
    // display(CHead);
}