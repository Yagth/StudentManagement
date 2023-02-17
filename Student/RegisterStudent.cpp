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



