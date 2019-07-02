#include<iostream>
#include <string>

using namespace std;

class GradeBook{

public:
    GradeBook() = default;
    explicit GradeBook(string cn,string teacherName);

    void setCourseName(string coursename);
    string getCourseName() const;
    void setTeacherName(string tn);
    string getTeacherName() const;

    void displayMessage() const;
 
    
private:
    string courseName;
    string teacherName;    
};