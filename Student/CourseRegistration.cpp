#include <iostream>
#include  <bits/stdc++.h>

using namespace std;

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



int main(){
    insertCourse();
    display(head);
}