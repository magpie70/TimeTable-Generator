#ifndef FACULTY_H_INCLUDED
#define FACULTY_H_INCLUDED
#include"courses.h"
#include<iostream>
#include<string>
using namespace std;
class faculty:public courses{//creating faculty class that is inheritor of courses class
private:
    string name;//name of the teacher
public:
    string getname(){//function to get the data about name of faculty
    return name;
    }
    faculty(){
    name="NIL";
    }
    faculty(string name, string coursecode,string coursetype, string coursename):courses(coursecode,coursetype,coursename){// constructor for the class
    this->name=name;
    }
};

#endif // FACULTY_H_INCLUDED
