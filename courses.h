#ifndef COURSES_H_INCLUDED
#define COURSES_H_INCLUDED
#include<string>
#include<sstream>
#include<iostream>
using namespace std;
class courses {  //Creating class
protected:
    string coursecode;// we made it protected in order to have an access to that variables in student and faculty classes
    string coursetype;
    string coursename;
public:
    string getcoursecode(){ //Function to get the information in any moment using getwhatever()
    return coursecode;
    }
    string getcoursetype(){
    return coursetype;
    }
    string getcoursename(){
    return coursename;
    }
    courses(){
    coursecode="NIL";
    coursename="NIL";
    coursetype="NIL";
    }
    courses(string coursecode,string coursetype, string coursename){// creating constructor for class
        this->coursecode=coursecode;
        this->coursetype=coursetype;
        this->coursename=coursename;
    }
};


#endif // COURSES_H_INCLUDED
