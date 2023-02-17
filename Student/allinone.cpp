#include <bits/stdc++.h>

using namespace std;

struct course{
    int courseNo;
    string courseTitle;
    int creditHour;
    course* next;
}*CHead=NULL;

struct student {
    string id;
    string firstName;
    string lastName;
    int age;
    string sex;
    student* next;
}* SHead=NULL;

course* getCourse(){
    course* newcourse = new course();
    cout << "Enter Course number ";
    cin >> newcourse->courseNo;
    cout << "Enter Course Title ";
    cin >> newcourse->courseTitle;
    cout << "Enter Course Credit Hour ";
    cin >> newcourse->creditHour;
    newcourse->next = NULL;
    newcourse->prev = NULL;
    return newcourse;
}
void insertCourse(){
    course* newCourse = getCourse();
    if(CHead==NULL){
        CHead = newCourse;
        return;
    }
    else{
       course* temp = CHead;
       while(temp->next != NULL){
        temp = temp->next;
       }
       temp->next = newCourse;
       newCourse->prev = temp;
    }
}

void display(course* n){
  while(n != NULL){
    cout << "course Number " << n->courseNo << endl;
    cout << "course Title " << n->courseTitle << endl;
    cout << "course credit Hour " << n->creditHour << endl;
    cout << endl;
    n = n->next;
  }
}

void sortStudentByName(){

    if (SHead == NULL) {
        return;
    }else {
        student* current = SHead, *prev = NULL, *next = NULL;
        while(current != NULL){
            if(current->firstName > current->next->firstName){
                if(current == SHead){
                    prev = current->
                }
            }
            prev = current;
            current = current->next;
            next = current->next;
        }
    }
}

void display() {
    student* current = SHead;

    if (SHead == NULL) {
        cout << "List is empty." << endl;
        return;
    }
    while (current != NULL) {
        cout << "ID: " << current->id << endl;
        cout << "First name: " << current->firstName << endl;
        cout << "Last name: " << current->lastName << endl;
        cout << "Age: " << current->age << endl;
        cout << "Sex: " << current->sex << endl;

        current = current->next;
    }
}

void registerStudent(){
        student * curr = SHead;
        cout << "registerStudent";

        //Check if List is not empty
        while(SHead != NULL && curr->next != NULL){
            curr = curr->next;
        }
        student *st = new student();
        cout << "Enter ID : ";
        cin.ignore();//To Clear the buffer memory before the next input
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
        
        if(SHead == NULL) SHead = st;
        else{
            curr->next = st;
            st->prev = curr->prev;
        }
}

int main(){
    registerStudent();
    registerStudent();
    registerStudent();

    sortStudentByName();
    
    display();

    // insertCourse();
    // insertCourse();
    // insertCourse();
    // display(CHead);
}