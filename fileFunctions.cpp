#include "dataStructures.h"

bool saveStudents(const char *filename)
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
            fout << ",";
        }

        fout << endl;

        current = current->next;
    }

    fout.close();
    return true;
}

bool saveCourses(const char *filename)
{
    ofstream fout(filename);

    if (!fout)
    {
        cerr << "Error: failed to open file " << filename << " for writing." << endl;
        return false;
    }

    // write the number of nodes in the list as first line
    int count = 0;
    course *current = CHead;
    while (current != NULL)
    {
        count++;
        current = current->next;
    }
    fout << count << endl;

    // write each node's data
    current = CHead;
    while (current != NULL)
    {
        // write course data
        fout << current->courseNo << "," << current->courseTitle << "," << current->creditHour;

        fout << endl;

        current = current->next;
    }

    fout.close();
    return true;
}

bool saveFiles()
{
    bool saved;
    saved = saveStudents("files/Students.txt") && saveCourses("files/Courses.txt");
    return saved;
}

bool loadStudents(const char *filename)
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
        cout << "Line: " << line << endl;
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
        while (getline(ss, token, ','))
        {
            cout << "token: " << token << endl;
            if (token.find(":") != string::npos)
            { // check if token is a course string
                // tokenize the course string by ":"
                stringstream courseSS(token);
                string courseNoStr, gradeStr;
                getline(courseSS, courseNoStr, ':');
                getline(courseSS, gradeStr, ':');
                string courseNo = courseNoStr;
                float grade = stof(gradeStr);
                cout << "CourseNo: " << courseNo;
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

bool loadCourses(const char *filename)
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
        course *current = new course();
        getline(fin, line);

        // tokenize the line by ","
        stringstream ss(line);
        string token;
        getline(ss, token, ',');
        current->courseNo = token;
        getline(ss, current->courseTitle, ',');
        getline(ss, token, ',');
        current->creditHour = stoi(token);

        if (CHead == NULL)
        {
            CHead = current;
        }
        else
        {
            course *curr = CHead;
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

bool loadFiles()
{
    bool loaded;
    loaded = loadCourses("files/Courses.txt") && loadStudents("files/Students.txt");
    return loaded;
}