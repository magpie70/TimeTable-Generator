#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED
#include<iostream>
#include<string>
using namespace std;

class room{// creating class
protected:// could be private it will not change the output
    string roomname;
    int capacity;
public:
    string getroomname(){
    return roomname;
    }
    int getcapacity(){
    return capacity;
    }
    room(){
    roomname="NIL";
    capacity=0;
    }
    room(string roomname, int capacity){// creating constructor
    this->roomname=roomname;
    this->capacity=capacity;
    }
};


#endif // ROOM_H_INCLUDED
