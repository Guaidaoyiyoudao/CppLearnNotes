#include "GradeBook.hpp"
#include <iostream>
#include <string>

GradeBook::GradeBook(std::string cn,std::string tn):courseName(cn),teacherName(tn)
{
}
void GradeBook::setCourseName(std::string cn)
{
    if(cn.size()>25){
        this->courseName = cn.substr(0,25);
    }else
    {
        this->courseName = cn;
    }
}
std::string GradeBook::getCourseName() const
{
    return this->courseName;
}
std::string GradeBook::getTeacherName() const
{
    return this->teacherName;
}
void GradeBook::setTeacherName(std::string tn)
{
    this->teacherName = tn;
}
void GradeBook::displayMessage() const
{
    std::cout<<"Welcome to the grade book for "<< this->getCourseName()<<\
    " by "<<this->getTeacherName()<<endl;
}