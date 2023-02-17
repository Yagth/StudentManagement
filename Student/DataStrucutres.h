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