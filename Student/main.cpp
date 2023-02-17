#include <bits/stdc++.h>

using namespace std;

struct student {
    string id;
    string firstName;
    string lastName;
    int age;
    string sex;
    student *next;
    student *prev;
}* head = NULL;

struct course{
    int courseNo;
    string courseTitle;
    int creditHour;
    course* next;
    course* prev;
};

course* head = NULL;

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
    if(head==NULL){
        head = newCourse;
        return;
    }
    else{
       course* temp = head;
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


void registerStudent(){
        student * temp = head;
        cout << "registerStudent";
        while(temp != NULL){
            temp = temp->next;
        }
        student *temp1 = new student();
        cout << "Enter ID : ";
        cin.ignore();
        cin >> temp1->id;
        cout << "Enter First name : ";
        cin >> temp1->firstName;
        cout << "Enter Last name : ";
        cin >> temp1->lastName;
        cout << "Enter Age : ";
        cin >> temp1->age;
        cout << "Enter Sex : ";
        cin >> temp1->sex;
    
        temp->next = temp1;
        temp1->next = NULL;
        temp1->prev = temp;
}

void sortByName(){
    student* tempFirstName;

    if (Head == NULL) {
        return;
    }else {
        for (student *current = Head; current != NULL; current = current->next) {
            for (student *index = current->next; index != NULL; index = index->next) {
                if (current->firstName > index->firstName) {
                    tempFirstName = current;
                    current = index;
                    index= tempFirstName;
                }
            }
        }
    }
}

void display() {
    if (Head == NULL) {
        cout << "List is empty." << endl;
        return;
    }

    student* current = Head;

    while (current != NULL) {
        cout << "ID: " << current->id << endl;
        cout << "First name: " << current->firstName << endl;
        cout << "Last name: " << current->lastName << endl;
        cout << "Age: " << current->age << endl;
        cout << "Sex: " << current->sex << endl;

        current = current->next;
    }
}



int main(){
    insertCourse();
    display();
}




