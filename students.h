#ifndef STUDENTS_H_INCLUDED
#define STUDENTS_H_INCLUDED
#include<string>
#include"courses.h"
#include<iostream>
class students: public courses{
protected:
    string groupname;
    int numb;
public:
    string getgroupname(){
    return groupname;
    }
    int getnumb(){// number of students in each student group
    return numb;
    }
    students(){
    groupname="NIL";
    numb=0;
    }
    students(string coursecode,string coursetype, string groupname ,int numb, string coursename):courses(coursecode,coursetype, coursename){//constructor
    this->groupname=groupname;
    this->numb=numb;
    }
};

#endif // STUDENTS_H_INCLUDED
