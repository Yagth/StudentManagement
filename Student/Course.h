#include <bits/stdc++.h>

using namespace std;

struct course
{
    string courseNo;
    string courseTitle;
    int creditHour;
    course *next;
    course *prev;

} *CHead = NULL;

void deleteCourseByCourseNumber(string courseNo);
course *findCourseByNo(string courseNo);
void displayAllCourses();
void recordCourse();
course *getCourse();
