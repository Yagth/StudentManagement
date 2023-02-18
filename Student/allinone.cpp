

int main()
{
    // registerStudent();
    registerStudent();
    registerStudent();
    registerStudent();

    student *temp = SHead;

    deleteStudentById(temp->id);
    displayAllStudents();

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

void student::gradeStudent(string courseNo, float grade)
{
    studentCourse *courseInfo = findStudentCourse(courseNo);
    courseInfo->grade = grade;
}

void student::displayStudentInfo()
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
    {
        cout << "\tCourseNo: " << temp->courseNo;
        cout << "\tGrade: ";

        if (temp->grade == -1.0)
            cout << "Not determined" << endl;
        else
            cout << temp->grade << endl;
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