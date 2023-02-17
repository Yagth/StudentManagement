#include <bits/stdc++.h>

struct student {
    string id;
    string firstName;
    string lastName;
    int age;
    string sex;
    student* next;
    student* prev;
}* Head;

using namespace std;

void main(){
    
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
