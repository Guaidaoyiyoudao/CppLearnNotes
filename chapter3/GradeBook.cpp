#include<iostream>
#include <string>

using namespace std;

class GradeBook{

public:
    GradeBook()
    {
        this->courseName="Hello,world!";
    }
    GradeBook(string cn)
    {
        this->courseName = cn;
    }

    void setCourseName(string coursename)
    {
        this->courseName = coursename;
    }
    string getCourseName() const
    {
        return this->courseName;
    }
    void displayMessage() const
    {
        cout<<"welcome to the Grade Book for "<<this->courseName<<endl;
    }
    
private:
    string courseName;
};

int main()
{

    string courseName;
    GradeBook myGradeBook;
    cout<<"Please enter the course name:";
    cin>>courseName;
    myGradeBook.displayMessage();
    return 0;
}