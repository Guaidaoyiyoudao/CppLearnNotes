#include "GradeBook.hpp"
#include<iostream>
#include <string>


int main()
{

    string courseName,teacherName;
    cout<<"Please enter the course name:";
    cin>>courseName;
    cout<<"Please enter the teacher name:";
    cin>>teacherName;
    GradeBook myGradeBook(courseName,teacherName);
    myGradeBook.displayMessage();
    return 0;
}