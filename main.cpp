#include "displayFunctions.cpp"

int main()
{
    bool loaded = loadFiles();
    if (loaded)
        cout << "Loaded" << endl;
    waitForUser();
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
