#include<iostream>
#include"courses.h"
#include"faculty.h"
#include"room.h"
#include"students.h"
#include<string>
#include<fstream>
#include<time.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
    int main(){
    courses course[200];//creating an array in order to store data
    string courseC,courseN,courseT;
    ifstream in2("course.txt");// gain data from the txt file and use it as the variables of class courses
    for (int i=0;i<200;i++){
        in2>>courseC>>courseT>>courseN;// order is the same as in txt file
        course[i]=courses(courseC,courseT,courseN);
        }
    room classrooms[200];//
    string roomN;
    int capacity;
    ifstream in3("room.txt");// gain data from the txt file and use it as the variables of class room
    for (int i=0;i<200;i++){
        in3>>roomN>>capacity;
        classrooms[i]=room(roomN,capacity);// inputing data into array
        }
    faculty teacher[200];
    string teacherN;
    ifstream in4("faculty.txt");// gain data from the txt file and use it as the variables of class faculty
    for(int i=0;i<200;i++){
        in4>>teacherN>>courseC>>courseT;
        teacher[i]=faculty(teacherN,courseC,courseT, courseN);
    }
    students group[200];
    string groupname;
    int numb;
    ifstream in1("students.txt");// gain data from the txt file and use it as the variables of class students
    for (int i=0;i<200;i++){
        in1>>courseC>>courseT>>groupname>>numb;
        group[i]=students(courseC,courseT,groupname,numb,courseN);
    }
    string times[4]={"9.00-10.50", "11.00-12.50","14.00-15.50","16.00-17.50"};
    string days[5]={"Monday","Tuesday","Wednesday","Thursday","Friday"};

    string c;
    int a,a2,a3,a4,p1,p2,p3,p4,p5,d1,d2,d3,d4,d5;
    int n2,n,n3,n4,r1,r2,r3,r4,x=0;
    int r[10]={1,1,1,1,1,1,1,1,1,1};
    int ece2[15],eche2[9],eee2[16],eme2[15],ece3[11],eche3[13],eee3[14],eme3[12],ece4[7],eche4[10],eee4[14],eme4[12];


    string cour1[5]={"BENG_1","BENG_2","BENG_3","BENG_4","BENG_5"};
    string cour2[7]={"ECE2_1","ECE2_2","ECHE2","EEE2_1","EEE2_2","EME2_1","EME2_2"};
    string cour3[7]={"ECE3_1","ECE3_2","ECHE3","EEE3_1","EEE3_2","EME3_1","EME3_2"};
    string cour4[7]={"ECE4_1","ECE4_2","ECHE4","EEE4_1","EEE4_2","EME4_1","EME4_2"};

    int tmonday[4][10];
    int ttuesday[4][10];
    int twednesday[4][10];
    int tthursday[4][10];
    int tfriday[4][10];

    int rmonday[4][29];
    int rtuesday[4][29];
    int rwednesday[4][29];
    int rthursday[4][29];
    int rfriday[4][29];
    for(int i=0;i<4;i++){
        for(int j=0;j<10;j++){
            tmonday[i][j]=1;
            ttuesday[i][j]=1;
            twednesday[i][j]=1;
            tthursday[i][j]=1;
            tfriday[i][j]=1;
        }
    }

    for(int i=0;i<4;i++){
        for(int j=1;j<29;j++){
            rmonday[i][j]=1;
            rtuesday[i][j]=1;
            rwednesday[i][j]=1;
            rthursday[i][j]=1;
            rfriday[i][j]=1;
        }
    }

    srand(static_cast<unsigned int> (time(0)));
    cout<<"To generate timetable for each student group, press enter and go to output.txt "<<endl<<endl;
    freopen("output.txt","w",stdout);

    {//I-course

        cout<<"BENG_1: "<<endl;
        while(x<5){//BENG!

            a=rand()%4;
            n=rand()%10;
            n2=rand()%10;
            a2=rand()%4;



            if(a2!=a && course[n].getcoursetype()=="L" &&
               (course[n2].getcoursetype()=="T" || course[n2].getcoursetype()=="LB" || course[n2].getcoursetype()=="CLB") &&
               r[n]==1 && r[n2]==1){
                r2=rand()%5;
                if((x==0 && tmonday[a2][n2]==1 && rmonday[a2][r2]==1) || (x==1 && ttuesday[a2][n2]==1 && rtuesday[a2][r2]==1) ||
                   (x==2 && twednesday[a2][n2]==1 && rwednesday[a2][r2]==1) || (x==3 && tthursday[a2][n2]==1 && rthursday[a2][r2]==1) ||
                   (x==4 && tfriday[a2][n2]==1) && rfriday[a2][r2]==1){

                    if(x==0){p1=a;d1=n;for(int i=0; i<10;i++){tmonday[a][i]=0;}}
                    if(x==1){p2=a;d2=n;for(int i=0; i<10;i++){ttuesday[a][i]=0;}}
                    if(x==2){p3=a;d3=n;for(int i=0; i<10;i++){twednesday[a][i]=0;}}
                    if(x==3){p4=a;d4=n;for(int i=0; i<10;i++){tthursday[a][i]=0;}}
                    if(x==4){p5=a;d5=n;for(int i=0; i<10;i++){tfriday[a][i]=0;}}
                    cout<<days[x]<<endl;
                    cout<<times[a]<<"    "<<course[n].getcoursename()<<"    "<<teacher[n].getname()<<"    "<<classrooms[0].getroomname()<<endl;
                    cout<<endl;

                    if(x==0){tmonday[a2][n2]=0;rmonday[a2][r2]=0;}
                    if(x==1){ttuesday[a2][n2]=0;rtuesday[a2][r2]=0;}
                    if(x==2){twednesday[a2][n2]=0;rwednesday[a2][r2]=0;}
                    if(x==3){tthursday[a2][n2]=0;rthursday[a2][r2]=0;}
                    if(x==4){tfriday[a2][n2]=0;rfriday[a2][r2]=0;}



                    cout<<times[a2]<<"    "<<course[n2].getcoursename()<<"    "<<teacher[n2].getname()<<"    "<<classrooms[r2].getroomname()<<endl;
                    cout<<endl;


                    x+=1;

                    r[n]=0;
                    r[n2]=0;


                }
            }

        }

        for(int i=1;i<5;i++){//BENG2-5
            int b2[10]={1,1,1,1,1,1,1,1,1,1};
            cout<<cour1[i]<<": "<<endl;
            int p[5]={p1,p2,p3,p4,p5};
            int d[5]={d1,d2,d3,d4,d5};

            x=0;
            while(x<5){

                a=p[x];
                n=d[x];
                n2=rand()%10;
                a2=rand()%4;
                if(a2!=a && course[n].getcoursetype()=="L" && (course[n2].getcoursetype()=="T" || course[n2].getcoursetype()=="LB" || course[n2].getcoursetype()=="CLB") && b2[n]==1 && b2[n2]==1){

                    r2=rand()%5;
                if((x==0 && tmonday[a2][n2]==1 && rmonday[a2][r2]==1) || (x==1 && ttuesday[a2][n2]==1 && rtuesday[a2][r2]==1) ||
                   (x==2 && twednesday[a2][n2]==1 && rwednesday[a2][r2]==1) || (x==3 && tthursday[a2][n2]==1 && rthursday[a2][r2]==1) ||
                   (x==4 && tfriday[a2][n2]==1) && rfriday[a2][r2]==1){
                        cout<<days[x]<<endl;
                        cout<<times[a]<<"    "<<course[n].getcoursename()<<"    "<<teacher[n].getname()<<"    "<<classrooms[0].getroomname()<<endl;
                        cout<<endl;

                        if(x==0){tmonday[a2][n2]=0;rmonday[a2][r2]=0;}
                        if(x==1){ttuesday[a2][n2]=0;rtuesday[a2][r2]=0;}
                        if(x==2){twednesday[a2][n2]=0;rwednesday[a2][r2]=0;}
                        if(x==3){tthursday[a2][n2]=0;rthursday[a2][r2]=0;}
                        if(x==4){tfriday[a2][n2]=0;rfriday[a2][r2]=0;}

                        cout<<times[a2]<<"    "<<course[n2].getcoursename()<<"    "<<teacher[n2].getname()<<"    "<<classrooms[r2].getroomname()<<endl;
                        cout<<endl;

                        x+=1;

                        b2[n]=0;
                        b2[n2]=0;
                    }
                }

            }
        }
    }



    {// II-course


        int tmonday[4][15],ttuesday[4][15],twednesday[4][15],tfriday[4][15],tthursday[4][15];
        for(int i=0;i<4;i++){
            for(int j=0;j<15;j++){
                tmonday[i][j]=1;
                ttuesday[i][j]=1;
                twednesday[i][j]=1;
                tfriday[i][j]=1;
                tthursday[i][j]=1;
            }
        }
        for(int k=0;k<2;k++){//ECE2
            cout<<cour2[k]<<": "<<endl;
            x=0;
            for(int i=13;i<28;i++){
                ece2[i-13]=i-1;
            }
            while(x<5){

                a=rand()%4;
                n=rand()%15;
                n2=rand()%15;
                a2=rand()%4;
                n3=rand()%15;
                a3=rand()%4;
                r1=rand()%29;
                r2=rand()%29;
                r3=rand()%29;


                if(a2!=a && a!=a3 && a2!=a3 && n!=n2 && n2!=n3 && n!=n3 &&  r1!=r2 && r2!=r3 && r1!=r3 && ece2[n]!=0 && ece2[n2]!=0 && ece2[n3]!=0){


                    if((x==0 && tmonday[a][n]==1 && rmonday[a][r1]==1 && tmonday[a2][n2]==1 && rmonday[a2][r2]==1 && tmonday[a3][n3]==1  && rmonday[a3][r3]==1) ||
                       (x==1 && ttuesday[a][n]==1 && rtuesday[a][r1]==1 && ttuesday[a2][n2]==1 && rtuesday[a2][r2]==1 && ttuesday[a3][n3]==1 && rtuesday[a3][r3]==1) ||
                       (x==2 && twednesday[a][n]==1 && rwednesday[a][r1]==1 && twednesday[a2][n2]==1 && rwednesday[a2][r2]==1 && twednesday[a3][n3]==1 && rwednesday[a3][r3]==1) ||
                       (x==3 &&  tthursday[a][n]==1 && rthursday[a][r1]==1 && tthursday[a2][n2]==1 && rthursday[a2][r2]==1 && tthursday[a3][n3]==1 && rthursday[a3][r3]==1) ||
                       (x==4 && tfriday[a][n]==1 && rfriday[a][r1]==1 && tfriday[a2][n2]==1 && rfriday[a2][r2]==1 && tfriday[a3][n3]==1 && rfriday[a3][r3]==1)){



                        if(x==0){tmonday[a][n]=0; tmonday[a2][n2]=0; tmonday[a3][n3]=0; rmonday[a][r1]=0; rmonday[a2][r2]=0; rmonday[a3][r3]=0;}
                        if(x==1){ttuesday[a][n]=0; ttuesday[a2][n2]=0; ttuesday[a3][n3]=0; rtuesday[a][r1]=0; rtuesday[a2][2]=0; rtuesday[a3][r3]=0;}
                        if(x==2){twednesday[a][n]=0; twednesday[a2][n2]=0; twednesday[a3][n3]=0; rwednesday[a][r1]=0; rwednesday[a2][r2]=0; rwednesday[a3][r3]=0;}
                        if(x==3){tthursday[a][n]=0; tthursday[a2][n2]=0; tthursday[a3][n3]=0; rthursday[a][r1]=0; rthursday[a2][r2]=0; rthursday[a3][r3]=0;}
                        if(x==4){tfriday[a][n]=0; tfriday[a2][n2]=0; tfriday[a3][n3]=0; rfriday[a][r1]=0; rfriday[a2][r2]=0; rfriday[a3][r3]=0;}
                        cout<<days[x]<<endl;
                        cout<<times[a]<<"    "<<course[ece2[n]].getcoursename()<<"    "<<teacher[ece2[n]].getname()<<"    "<<classrooms[r1].getroomname()<<endl;
                        cout<<endl;



                        cout<<times[a2]<<"    "<<course[ece2[n2]].getcoursename()<<"    "<<teacher[ece2[n2]].getname()<<"    "<<classrooms[r2].getroomname()<<endl;;
                        cout<<endl;



                        cout<<times[a3]<<"    "<<course[ece2[n3]].getcoursename()<<"    "<<teacher[ece2[n3]].getname()<<"    "<<classrooms[r3].getroomname()<<endl;;
                        cout<<endl;
                        x+=1;
                        ece2[n]=0;
                        ece2[n2]=0;
                        ece2[n3]=0;

                       }

                }

            }
        }

        for(int i=0;i<4;i++){
            for(int j=0;j<15;j++){
                tmonday[i][j]=1;
                ttuesday[i][j]=1;
                twednesday[i][j]=1;
                tfriday[i][j]=1;
                tthursday[i][j]=1;
            }
        }


        cout<<cour2[2]<<": "<<endl; //ECHE2
        x=0;
        eche2[0]=13; eche2[1]=14;
        for(int i=47;i<54;i++){//ECHE2
            eche2[i-45]=i-1;
        }
        while(x<4){//ECHE2

            a=rand()%4;
            n=rand()%9;
            n2=rand()%9;
            a2=rand()%4;
            r1=rand()%29;
            r2=rand()%29;

            if(a2!=a && n!=n2 && r1!=r2 && eche2[n]!=0 && eche2[n2]!=0 ){




                if((x==0 && tmonday[a][n]==1 && rmonday[a][r1]==1 && tmonday[a2][n2]==1 && rmonday[a2][r2]==1 ) ||
                   (x==1 && ttuesday[a][n]==1 && rtuesday[a][r1]==1 && ttuesday[a2][n2]==1 && rtuesday[a2][r2]==1 ) ||
                   (x==2 && twednesday[a][n]==1 && rwednesday[a][r1]==1 && twednesday[a2][n2]==1 && rwednesday[a2][r2]==1) ||
                   (x==3 &&  tthursday[a][n]==1 && rthursday[a][r1]==1 && tthursday[a2][n2]==1 && rthursday[a2][r2]==1 ) ||
                   (x==4 && tfriday[a][n]==1 && rfriday[a][r1]==1 && tfriday[a2][n2]==1 && rfriday[a2][r2]==1 )){



                    if(x==0){tmonday[a][n]=0; tmonday[a2][n2]=0;  rmonday[a][r1]=0; rmonday[a2][r2]=0; }
                    if(x==1){ttuesday[a][n]=0; ttuesday[a2][n2]=0;  rtuesday[a][r1]=0; rtuesday[a2][2]=0; }
                    if(x==2){twednesday[a][n]=0; twednesday[a2][n2]=0;  rwednesday[a][r1]=0; rwednesday[a2][r2]=0; }
                    if(x==3){tthursday[a][n]=0; tthursday[a2][n2]=0; rthursday[a][r1]=0; rthursday[a2][r2]=0; }
                    if(x==4){tfriday[a][n]=0; tfriday[a2][n2]=0; rfriday[a][r1]=0; rfriday[a2][r2]=0; }
                    cout<<days[x]<<endl;
                    cout<<times[a]<<"    "<<course[eche2[n]].getcoursename()<<"    "<<teacher[eche2[n]].getname()<<"    "<<classrooms[r1].getroomname()<<endl;
                    cout<<endl;



                    cout<<times[a2]<<"    "<<course[eche2[n2]].getcoursename()<<"    "<<teacher[eche2[n2]].getname()<<"    "<<classrooms[r2].getroomname()<<endl;;
                    cout<<endl;



                    x+=1;
                    eche2[n]=0;
                    eche2[n2]=0;


                   }

            }

        }
        while(x<5){//ECHE2
            a2=rand()%4;
            n2=rand()%9;
            r2=rand()%29;
            if(eche2[n2]!=0 && tfriday[a2][n2]==1 && rfriday[a2][r2]==1){
                cout<<days[x]<<endl;
                cout<<times[a]<<"    "<<course[eche2[n2]].getcoursename()<<"    "<<teacher[eche2[n2]].getname()<<"    "<<classrooms[r2].getroomname()<<endl;
                cout<<endl;
                x+=1;
                eche2[n2]=0;
                tfriday[a2][n2]=0;
                rfriday[a2][r2]=0;
            }
        }
        for(int i=0;i<4;i++){
            for(int j=0;j<15;j++){
                tmonday[i][j]=1;
                ttuesday[i][j]=1;
                twednesday[i][j]=1;
                tfriday[i][j]=1;
                tthursday[i][j]=1;
            }
        }

        for(int k=3; k<5;k++){//EEE@
            cout<<cour2[k]<<": "<<endl; //EEE2
            x=0;
            eee2[0]=10; eee2[1]=11; eee2[2]=12; eee2[3]=13; eee2[4]=14;
            for(int i=77;i<88;i++){
                eee2[i-72]=i-1;
            }
            while(x<4){// EEE2

                a=rand()%4;
                n=rand()%16;
                n2=rand()%16;
                a2=rand()%4;
                n3=rand()%16;
                a3=rand()%4;
                r1=rand()%29;
                r2=rand()%29;
                r3=rand()%29;

                if(a2!=a && a!=a3 && a2!=a3 && n!=n2 && n2!=n3 && n!=n3 &&  r1!=r2 && r2!=r3 && r1!=r3 && eee2[n]!=0 && eee2[n2]!=0 && eee2[n3]!=0){



                    if((x==0 && tmonday[a][n]==1 && rmonday[a][r1]==1 && tmonday[a2][n2]==1 && rmonday[a2][r2]==1 && tmonday[a3][n3]==1  && rmonday[a3][r3]==1) ||
                       (x==1 && ttuesday[a][n]==1 && rtuesday[a][r1]==1 && ttuesday[a2][n2]==1 && rtuesday[a2][r2]==1 && ttuesday[a3][n3]==1 && rtuesday[a3][r3]==1) ||
                       (x==2 && twednesday[a][n]==1 && rwednesday[a][r1]==1 && twednesday[a2][n2]==1 && rwednesday[a2][r2]==1 && twednesday[a3][n3]==1 && rwednesday[a3][r3]==1) ||
                       (x==3 &&  tthursday[a][n]==1 && rthursday[a][r1]==1 && tthursday[a2][n2]==1 && rthursday[a2][r2]==1 && tthursday[a3][n3]==1 && rthursday[a3][r3]==1) ||
                       (x==4 && tfriday[a][n]==1 && rfriday[a][r1]==1 && tfriday[a2][n2]==1 && rfriday[a2][r2]==1 && tfriday[a3][n3]==1 && rfriday[a3][r3]==1)){



                        if(x==0){tmonday[a][n]=0; tmonday[a2][n2]=0; tmonday[a3][n3]=0; rmonday[a][r1]=0; rmonday[a2][r2]=0; rmonday[a3][r3]=0;}
                        if(x==1){ttuesday[a][n]=0; ttuesday[a2][n2]=0; ttuesday[a3][n3]=0; rtuesday[a][r1]=0; rtuesday[a2][2]=0; rtuesday[a3][r3]=0;}
                        if(x==2){twednesday[a][n]=0; twednesday[a2][n2]=0; twednesday[a3][n3]=0; rwednesday[a][r1]=0; rwednesday[a2][r2]=0; rwednesday[a3][r3]=0;}
                        if(x==3){tthursday[a][n]=0; tthursday[a2][n2]=0; tthursday[a3][n3]=0; rthursday[a][r1]=0; rthursday[a2][r2]=0; rthursday[a3][r3]=0;}
                        if(x==4){tfriday[a][n]=0; tfriday[a2][n2]=0; tfriday[a3][n3]=0; rfriday[a][r1]=0; rfriday[a2][r2]=0; rfriday[a3][r3]=0;}
                        cout<<days[x]<<endl;
                        cout<<times[a]<<"    "<<course[eee2[n]].getcoursename()<<"    "<<teacher[eee2[n]].getname()<<"    "<<classrooms[r1].getroomname()<<endl;
                        cout<<endl;



                        cout<<times[a2]<<"    "<<course[eee2[n2]].getcoursename()<<"    "<<teacher[eee2[n2]].getname()<<"    "<<classrooms[r2].getroomname()<<endl;;
                        cout<<endl;



                        cout<<times[a3]<<"    "<<course[eee2[n3]].getcoursename()<<"    "<<teacher[eee2[n3]].getname()<<"    "<<classrooms[r3].getroomname()<<endl;;
                        cout<<endl;
                        x+=1;
                        eee2[n]=0;
                        eee2[n2]=0;
                        eee2[n3]=0;

                       }

                }

            }
            while(x<5){//EEE2
            a=rand()%4;
            n=rand()%16;
            n2=rand()%16;
            a2=rand()%4;
            n3=rand()%16;
            a3=rand()%4;
            r1=rand()%29;
            r2=rand()%29;
            r3=rand()%29;
            a4=rand()%4;
            n4=rand()%16;
            r4=rand()%29;
            if(a2!=a && a!=a3 && a2!=a3 && a!=a4 && a2!=a4 && a3!=a4 && n!=n2 && n2!=n3 && n!=n3 && n!=n4 && n2!=n4 && n3!=n4 && r1!=r2 && r2!=r3 && r1!=r3 && r1!=r4 && r2!=r4 && r3!=r4 && eee2[n]!=0 && eee2[n2]!=0 && eee2[n3]!=0 && eee2[n4]!=0 &&
               tfriday[a][n]==1 && rfriday[a][r1]==1 && tfriday[a2][n2]==1 && rfriday[a2][r2]==1 && tfriday[a3][n3]==1 && rfriday[a3][r3]==1){
                    cout<<days[x]<<endl;
                    cout<<times[a]<<"    "<<course[eee2[n]].getcoursename()<<"    "<<teacher[eee2[n]].getname()<<"    "<<classrooms[r1].getroomname()<<endl;
                    cout<<endl;
                    cout<<times[a2]<<"    "<<course[eee2[n2]].getcoursename()<<"    "<<teacher[eee2[n2]].getname()<<"    "<<classrooms[r2].getroomname()<<endl;
                    cout<<endl;
                    cout<<times[a3]<<"    "<<course[eee2[n3]].getcoursename()<<"    "<<teacher[eee2[n3]].getname()<<"    "<<classrooms[r3].getroomname()<<endl;
                    cout<<endl;
                    cout<<times[a4]<<"    "<<course[eee2[n4]].getcoursename()<<"    "<<teacher[eee2[n4]].getname()<<"    "<<classrooms[r4].getroomname()<<endl;
                    cout<<endl;
                    x+=1;
                    eee2[n]=0;
                    eee2[n2]=0;
                    eee2[n3]=0;
                    eee2[n4]=0;
                    tfriday[a][n]=0;
                    rfriday[a][r1]=0;
                    tfriday[a2][n2]=0;
                    rfriday[a2][r2]=0;
                    tfriday[a3][n3]=0;
                    rfriday[a3][r3]=0;
                    tfriday[a4][n4]=0;
                    rfriday[a4][r4]=0;
                }
            }
        }

        for(int i=0;i<4;i++){
            for(int j=0;j<15;j++){
                tmonday[i][j]=1;
                ttuesday[i][j]=1;
                twednesday[i][j]=1;
                tfriday[i][j]=1;
                tthursday[i][j]=1;
            }
        }
        for(int k=5;k<7;k++){//EME2
            cout<<cour2[k]<<": "<<endl;
            x=0;
            eme2[0]=10; eme2[1]=11; eme2[2]=12; eme2[3]=13; eme2[4]=14;
            for(int i=116;i<126;i++){
                eme2[i-111]=i-1;
            }
            while(x<5){

                a=rand()%4;
                n=rand()%15;
                n2=rand()%15;
                a2=rand()%4;
                n3=rand()%15;
                a3=rand()%4;
                r1=rand()%29;
                r2=rand()%29;
                r3=rand()%29;


                if(a2!=a && a!=a3 && a2!=a3 && n!=n2 && n2!=n3 && n!=n3 &&  r1!=r2 && r2!=r3 && r1!=r3 && eme2[n]!=0 && eme2[n2]!=0 && eme2[n3]!=0){


                    if((x==0 && tmonday[a][n]==1 && rmonday[a][r1]==1 && tmonday[a2][n2]==1 && rmonday[a2][r2]==1 && tmonday[a3][n3]==1  && rmonday[a3][r3]==1) ||
                       (x==1 && ttuesday[a][n]==1 && rtuesday[a][r1]==1 && ttuesday[a2][n2]==1 && rtuesday[a2][r2]==1 && ttuesday[a3][n3]==1 && rtuesday[a3][r3]==1) ||
                       (x==2 && twednesday[a][n]==1 && rwednesday[a][r1]==1 && twednesday[a2][n2]==1 && rwednesday[a2][r2]==1 && twednesday[a3][n3]==1 && rwednesday[a3][r3]==1) ||
                       (x==3 &&  tthursday[a][n]==1 && rthursday[a][r1]==1 && tthursday[a2][n2]==1 && rthursday[a2][r2]==1 && tthursday[a3][n3]==1 && rthursday[a3][r3]==1) ||
                       (x==4 && tfriday[a][n]==1 && rfriday[a][r1]==1 && tfriday[a2][n2]==1 && rfriday[a2][r2]==1 && tfriday[a3][n3]==1 && rfriday[a3][r3]==1)){



                        if(x==0){tmonday[a][n]=0; tmonday[a2][n2]=0; tmonday[a3][n3]=0; rmonday[a][r1]=0; rmonday[a2][r2]=0; rmonday[a3][r3]=0;}
                        if(x==1){ttuesday[a][n]=0; ttuesday[a2][n2]=0; ttuesday[a3][n3]=0; rtuesday[a][r1]=0; rtuesday[a2][2]=0; rtuesday[a3][r3]=0;}
                        if(x==2){twednesday[a][n]=0; twednesday[a2][n2]=0; twednesday[a3][n3]=0; rwednesday[a][r1]=0; rwednesday[a2][r2]=0; rwednesday[a3][r3]=0;}
                        if(x==3){tthursday[a][n]=0; tthursday[a2][n2]=0; tthursday[a3][n3]=0; rthursday[a][r1]=0; rthursday[a2][r2]=0; rthursday[a3][r3]=0;}
                        if(x==4){tfriday[a][n]=0; tfriday[a2][n2]=0; tfriday[a3][n3]=0; rfriday[a][r1]=0; rfriday[a2][r2]=0; rfriday[a3][r3]=0;}
                        cout<<days[x]<<endl;
                        cout<<times[a]<<"    "<<course[eme2[n]].getcoursename()<<"    "<<teacher[eme2[n]].getname()<<"    "<<classrooms[r1].getroomname()<<endl;
                        cout<<endl;



                        cout<<times[a2]<<"    "<<course[eme2[n2]].getcoursename()<<"    "<<teacher[eme2[n2]].getname()<<"    "<<classrooms[r2].getroomname()<<endl;;
                        cout<<endl;



                        cout<<times[a3]<<"    "<<course[eme2[n3]].getcoursename()<<"    "<<teacher[eme2[n3]].getname()<<"    "<<classrooms[r3].getroomname()<<endl;;
                        cout<<endl;
                        x+=1;
                        eme2[n]=0;
                        eme2[n2]=0;
                        eme2[n3]=0;

                       }

                }

            }
        }
    }


    {// III-course


        int tmonday[4][15],ttuesday[4][15],twednesday[4][15],tfriday[4][15],tthursday[4][15];
        for(int i=0;i<4;i++){
            for(int j=0;j<15;j++){
                tmonday[i][j]=1;
                ttuesday[i][j]=1;
                twednesday[i][j]=1;
                tfriday[i][j]=1;
                tthursday[i][j]=1;
            }
        }
        for(int k=0;k<2;k++){//ECE3
            cout<<cour3[k]<<": "<<endl;
            x=0;
            for(int i=29; i<40;i++){
                ece3[i-29]=i-1;
            }
            while(x<4){

                a=rand()%4;
                n=rand()%11;
                n2=rand()%11;
                a2=rand()%4;


                r1=rand()%29;
                r2=rand()%29;



                if(a2!=a  && n!=n2  &&  r1!=r2 && ece3[n]!=0 && ece3[n2]!=0 ){


                    if((x==0 && tmonday[a][n]==1 && rmonday[a][r1]==1 && tmonday[a2][n2]==1 && rmonday[a2][r2]==1 ) ||
                       (x==1 && ttuesday[a][n]==1 && rtuesday[a][r1]==1 && ttuesday[a2][n2]==1 && rtuesday[a2][r2]==1 ) ||
                       (x==2 && twednesday[a][n]==1 && rwednesday[a][r1]==1 && twednesday[a2][n2]==1 && rwednesday[a2][r2]==1 ) ||
                       (x==3 &&  tthursday[a][n]==1 && rthursday[a][r1]==1 && tthursday[a2][n2]==1 && rthursday[a2][r2]==1 ) ||
                       (x==4 && tfriday[a][n]==1 && rfriday[a][r1]==1 && tfriday[a2][n2]==1 && rfriday[a2][r2]==1 )){



                        if(x==0){tmonday[a][n]=0; tmonday[a2][n2]=0; rmonday[a][r1]=0; rmonday[a2][r2]=0; }
                        if(x==1){ttuesday[a][n]=0; ttuesday[a2][n2]=0;  rtuesday[a][r1]=0; rtuesday[a2][2]=0;}
                        if(x==2){twednesday[a][n]=0; twednesday[a2][n2]=0;  rwednesday[a][r1]=0; rwednesday[a2][r2]=0; }
                        if(x==3){tthursday[a][n]=0; tthursday[a2][n2]=0;  rthursday[a][r1]=0; rthursday[a2][r2]=0; }
                        if(x==4){tfriday[a][n]=0; tfriday[a2][n2]=0; rfriday[a][r1]=0; rfriday[a2][r2]=0; }
                        cout<<days[x]<<endl;
                        cout<<times[a]<<"    "<<course[ece3[n]].getcoursename()<<"    "<<teacher[ece3[n]].getname()<<"    "<<classrooms[r1].getroomname()<<endl;
                        cout<<endl;



                        cout<<times[a2]<<"    "<<course[ece3[n2]].getcoursename()<<"    "<<teacher[ece3[n2]].getname()<<"    "<<classrooms[r2].getroomname()<<endl;;
                        cout<<endl;




                        x+=1;
                        ece3[n]=0;
                        ece3[n2]=0;


                       }

                }

            }
            while(x<5){//ECE3
                a2=rand()%4;
                n2=rand()%11;
                r2=rand()%29;
                a=rand()%4;
                n=rand()%11;
                r1=rand()%29;
                a3=rand()%4;
                n3=rand()%11;
                r3=rand()%29;

                if(a!=a2 && a!=a3 && a2!=a3 && n!=n2 && n!=n3 && n2!=n3 && r1!=r2 && r1!=r3 && r2!=r3 && ece3[n2]!=0 && ece3[n3]!=0 && ece3[n]!=0  && tfriday[a][n]==1 && rfriday[a][r1]==1 && tfriday[a2][n2]==1 && rfriday[a2][r2]==1 && tfriday[a3][n3]==1 && rfriday[a3][r3]==1){
                    cout<<days[x]<<endl;
                    cout<<times[a]<<"    "<<course[ece3[n]].getcoursename()<<"    "<<teacher[ece3[n]].getname()<<"    "<<classrooms[r1].getroomname()<<endl;
                    cout<<endl;

                    cout<<times[a2]<<"    "<<course[ece3[n2]].getcoursename()<<"    "<<teacher[ece3[n2]].getname()<<"    "<<classrooms[r2].getroomname()<<endl;
                    cout<<endl;

                    cout<<times[a3]<<"    "<<course[ece3[n3]].getcoursename()<<"    "<<teacher[ece3[n3]].getname()<<"    "<<classrooms[r3].getroomname()<<endl;
                    cout<<endl;
                    x+=1;
                    ece3[n2]=0;
                    ece3[n]=0;
                    ece3[n3]=0;
                    tfriday[a2][n2]=0;
                    rfriday[a2][r2]=0;
                    tfriday[a][n]=0;
                    rfriday[a][r1]=0;
                    tfriday[a3][n3]=0;
                    rfriday[a3][r3]=0;
                }
            }
        }

        for(int i=0;i<4;i++){
            for(int j=0;j<15;j++){
                tmonday[i][j]=1;
                ttuesday[i][j]=1;
                twednesday[i][j]=1;
                tfriday[i][j]=1;
                tthursday[i][j]=1;
            }
        }


        cout<<cour3[2]<<": "<<endl; //ECHE3
        x=0;

        for(int i=54;i<67;i++){//ECHE3
            eche3[i-54]=i-1;
        }
        while(x<4){// ECHE3

                a=rand()%4;
                n=rand()%13;
                n2=rand()%13;
                a2=rand()%4;
                n3=rand()%13;
                a3=rand()%4;
                r1=rand()%29;
                r2=rand()%29;
                r3=rand()%29;

                if(a2!=a && a!=a3 && a2!=a3 && n!=n2 && n2!=n3 && n!=n3 &&  r1!=r2 && r2!=r3 && r1!=r3 && eche3[n]!=0 && eche3[n2]!=0 && eche3[n3]!=0){



                    if((x==0 && tmonday[a][n]==1 && rmonday[a][r1]==1 && tmonday[a2][n2]==1 && rmonday[a2][r2]==1 && tmonday[a3][n3]==1  && rmonday[a3][r3]==1) ||
                       (x==1 && ttuesday[a][n]==1 && rtuesday[a][r1]==1 && ttuesday[a2][n2]==1 && rtuesday[a2][r2]==1 && ttuesday[a3][n3]==1 && rtuesday[a3][r3]==1) ||
                       (x==2 && twednesday[a][n]==1 && rwednesday[a][r1]==1 && twednesday[a2][n2]==1 && rwednesday[a2][r2]==1 && twednesday[a3][n3]==1 && rwednesday[a3][r3]==1) ||
                       (x==3 &&  tthursday[a][n]==1 && rthursday[a][r1]==1 && tthursday[a2][n2]==1 && rthursday[a2][r2]==1 && tthursday[a3][n3]==1 && rthursday[a3][r3]==1) ||
                       (x==4 && tfriday[a][n]==1 && rfriday[a][r1]==1 && tfriday[a2][n2]==1 && rfriday[a2][r2]==1 && tfriday[a3][n3]==1 && rfriday[a3][r3]==1)){



                        if(x==0){tmonday[a][n]=0; tmonday[a2][n2]=0; tmonday[a3][n3]=0; rmonday[a][r1]=0; rmonday[a2][r2]=0; rmonday[a3][r3]=0;}
                        if(x==1){ttuesday[a][n]=0; ttuesday[a2][n2]=0; ttuesday[a3][n3]=0; rtuesday[a][r1]=0; rtuesday[a2][2]=0; rtuesday[a3][r3]=0;}
                        if(x==2){twednesday[a][n]=0; twednesday[a2][n2]=0; twednesday[a3][n3]=0; rwednesday[a][r1]=0; rwednesday[a2][r2]=0; rwednesday[a3][r3]=0;}
                        if(x==3){tthursday[a][n]=0; tthursday[a2][n2]=0; tthursday[a3][n3]=0; rthursday[a][r1]=0; rthursday[a2][r2]=0; rthursday[a3][r3]=0;}
                        if(x==4){tfriday[a][n]=0; tfriday[a2][n2]=0; tfriday[a3][n3]=0; rfriday[a][r1]=0; rfriday[a2][r2]=0; rfriday[a3][r3]=0;}
                        cout<<days[x]<<endl;
                        cout<<times[a]<<"    "<<course[eche3[n]].getcoursename()<<"    "<<teacher[eche3[n]].getname()<<"    "<<classrooms[r1].getroomname()<<endl;
                        cout<<endl;



                        cout<<times[a2]<<"    "<<course[eche3[n2]].getcoursename()<<"    "<<teacher[eche3[n2]].getname()<<"    "<<classrooms[r2].getroomname()<<endl;;
                        cout<<endl;



                        cout<<times[a3]<<"    "<<course[eche3[n3]].getcoursename()<<"    "<<teacher[eche3[n3]].getname()<<"    "<<classrooms[r3].getroomname()<<endl;;
                        cout<<endl;
                        x+=1;
                        eche3[n]=0;
                        eche3[n2]=0;
                        eche3[n3]=0;

                       }

                }

        }
        while(x<5){//eche3
            a2=rand()%4;
            n2=rand()%13;
            r2=rand()%29;
            if(eche3[n2]!=0 && tfriday[a2][n2]==1 && rfriday[a2][r2]==1){
                cout<<days[x]<<endl;
                cout<<times[a2]<<"    "<<course[eche3[n2]].getcoursename()<<"    "<<teacher[eche3[n2]].getname()<<"    "<<classrooms[r2].getroomname()<<endl;
                cout<<endl;
                x+=1;
                eche3[n2]=0;
                tfriday[a2][n2]=0;
                rfriday[a2][r2]=0;
            }
        }




        for(int i=0;i<4;i++){
            for(int j=0;j<15;j++){
                tmonday[i][j]=1;
                ttuesday[i][j]=1;
                twednesday[i][j]=1;
                tfriday[i][j]=1;
                tthursday[i][j]=1;
            }
        }
        for(int k=3;k<5;k++){//EEE3
            cout<<cour3[k]<<": "<<endl; //EEE3
            x=0;

            for(int i=88;i<102;i++){//EEE3
                eee3[i-88]=i-1;
            }
            while(x<4){// EEE3

                    a=rand()%4;
                    n=rand()%14;
                    n2=rand()%14;
                    a2=rand()%4;
                    n3=rand()%14;
                    a3=rand()%4;
                    r1=rand()%29;
                    r2=rand()%29;
                    r3=rand()%29;

                    if(a2!=a && a!=a3 && a2!=a3 && n!=n2 && n2!=n3 && n!=n3 &&  r1!=r2 && r2!=r3 && r1!=r3 && eee3[n]!=0 && eee3[n2]!=0 && eee3[n3]!=0){



                        if((x==0 && tmonday[a][n]==1 && rmonday[a][r1]==1 && tmonday[a2][n2]==1 && rmonday[a2][r2]==1 && tmonday[a3][n3]==1  && rmonday[a3][r3]==1) ||
                           (x==1 && ttuesday[a][n]==1 && rtuesday[a][r1]==1 && ttuesday[a2][n2]==1 && rtuesday[a2][r2]==1 && ttuesday[a3][n3]==1 && rtuesday[a3][r3]==1) ||
                           (x==2 && twednesday[a][n]==1 && rwednesday[a][r1]==1 && twednesday[a2][n2]==1 && rwednesday[a2][r2]==1 && twednesday[a3][n3]==1 && rwednesday[a3][r3]==1) ||
                           (x==3 &&  tthursday[a][n]==1 && rthursday[a][r1]==1 && tthursday[a2][n2]==1 && rthursday[a2][r2]==1 && tthursday[a3][n3]==1 && rthursday[a3][r3]==1) ||
                           (x==4 && tfriday[a][n]==1 && rfriday[a][r1]==1 && tfriday[a2][n2]==1 && rfriday[a2][r2]==1 && tfriday[a3][n3]==1 && rfriday[a3][r3]==1)){



                            if(x==0){tmonday[a][n]=0; tmonday[a2][n2]=0; tmonday[a3][n3]=0; rmonday[a][r1]=0; rmonday[a2][r2]=0; rmonday[a3][r3]=0;}
                            if(x==1){ttuesday[a][n]=0; ttuesday[a2][n2]=0; ttuesday[a3][n3]=0; rtuesday[a][r1]=0; rtuesday[a2][2]=0; rtuesday[a3][r3]=0;}
                            if(x==2){twednesday[a][n]=0; twednesday[a2][n2]=0; twednesday[a3][n3]=0; rwednesday[a][r1]=0; rwednesday[a2][r2]=0; rwednesday[a3][r3]=0;}
                            if(x==3){tthursday[a][n]=0; tthursday[a2][n2]=0; tthursday[a3][n3]=0; rthursday[a][r1]=0; rthursday[a2][r2]=0; rthursday[a3][r3]=0;}
                            if(x==4){tfriday[a][n]=0; tfriday[a2][n2]=0; tfriday[a3][n3]=0; rfriday[a][r1]=0; rfriday[a2][r2]=0; rfriday[a3][r3]=0;}
                            cout<<days[x]<<endl;
                            cout<<times[a]<<"    "<<course[eee3[n]].getcoursename()<<"    "<<teacher[eee3[n]].getname()<<"    "<<classrooms[r1].getroomname()<<endl;
                            cout<<endl;



                            cout<<times[a2]<<"    "<<course[eee3[n2]].getcoursename()<<"    "<<teacher[eee3[n2]].getname()<<"    "<<classrooms[r2].getroomname()<<endl;;
                            cout<<endl;



                            cout<<times[a3]<<"    "<<course[eee3[n3]].getcoursename()<<"    "<<teacher[eee3[n3]].getname()<<"    "<<classrooms[r3].getroomname()<<endl;;
                            cout<<endl;
                            x+=1;
                            eee3[n]=0;
                            eee3[n2]=0;
                            eee3[n3]=0;

                           }

                    }

            }
            while(x<5){//EEE3
                a=rand()%4;
                n=rand()%14;
                r1=rand()%29;
                a2=rand()%4;
                n2=rand()%14;
                r2=rand()%29;
                if(a!=a2 && n!=n2 && r1!=r2 && eee3[n]!=0 && eee3[n2]!=0 &&  tfriday[a][n]==1 && rfriday[a][r1]==1 && tfriday[a2][n2]==1 && rfriday[a2][r2]==1){
                    cout<<days[x]<<endl;
                    cout<<times[a]<<"    "<<course[eee3[n]].getcoursename()<<"    "<<teacher[eee3[n]].getname()<<"    "<<classrooms[r1].getroomname()<<endl;
                    cout<<endl;
                    cout<<times[a2]<<"    "<<course[eee3[n2]].getcoursename()<<"    "<<teacher[eee3[n2]].getname()<<"    "<<classrooms[r2].getroomname()<<endl;
                    cout<<endl;
                    x+=1;
                    eee3[n2]=0;
                    eee3[n]=0;
                    tfriday[a][n]=0;
                    rfriday[a][r1]=0;
                    tfriday[a2][n2]=0;
                    rfriday[a2][r2]=0;
                }
            }
    }
        for(int i=0;i<4;i++){
            for(int j=0;j<15;j++){
                tmonday[i][j]=1;
                ttuesday[i][j]=1;
                twednesday[i][j]=1;
                tfriday[i][j]=1;
                tthursday[i][j]=1;
            }
        }

        for(int k=5;k<7;k++){//EME3
            cout<<cour3[k]<<": "<<endl;
            x=0;
            for(int i=126; i<138;i++){
                eme3[i-126]=i-1;
            }
            while(x<4){

                a=rand()%4;
                n=rand()%12;
                n2=rand()%12;
                a2=rand()%4;


                r1=rand()%29;
                r2=rand()%29;



                if(a2!=a  && n!=n2  &&  r1!=r2 && eme3[n]!=0 && eme3[n2]!=0 ){


                    if((x==0 && tmonday[a][n]==1 && rmonday[a][r1]==1 && tmonday[a2][n2]==1 && rmonday[a2][r2]==1 ) ||
                       (x==1 && ttuesday[a][n]==1 && rtuesday[a][r1]==1 && ttuesday[a2][n2]==1 && rtuesday[a2][r2]==1 ) ||
                       (x==2 && twednesday[a][n]==1 && rwednesday[a][r1]==1 && twednesday[a2][n2]==1 && rwednesday[a2][r2]==1 ) ||
                       (x==3 &&  tthursday[a][n]==1 && rthursday[a][r1]==1 && tthursday[a2][n2]==1 && rthursday[a2][r2]==1 ) ||
                       (x==4 && tfriday[a][n]==1 && rfriday[a][r1]==1 && tfriday[a2][n2]==1 && rfriday[a2][r2]==1 )){



                        if(x==0){tmonday[a][n]=0; tmonday[a2][n2]=0; rmonday[a][r1]=0; rmonday[a2][r2]=0; }
                        if(x==1){ttuesday[a][n]=0; ttuesday[a2][n2]=0;  rtuesday[a][r1]=0; rtuesday[a2][2]=0;}
                        if(x==2){twednesday[a][n]=0; twednesday[a2][n2]=0;  rwednesday[a][r1]=0; rwednesday[a2][r2]=0; }
                        if(x==3){tthursday[a][n]=0; tthursday[a2][n2]=0;  rthursday[a][r1]=0; rthursday[a2][r2]=0; }
                        if(x==4){tfriday[a][n]=0; tfriday[a2][n2]=0; rfriday[a][r1]=0; rfriday[a2][r2]=0; }
                        cout<<days[x]<<endl;
                        cout<<times[a]<<"    "<<course[eme3[n]].getcoursename()<<"    "<<teacher[eme3[n]].getname()<<"    "<<classrooms[r1].getroomname()<<endl;
                        cout<<endl;



                        cout<<times[a2]<<"    "<<course[eme3[n2]].getcoursename()<<"    "<<teacher[eme3[n2]].getname()<<"    "<<classrooms[r2].getroomname()<<endl;;
                        cout<<endl;




                        x+=1;
                        eme3[n]=0;
                        eme3[n2]=0;


                       }

                }

            }
            while(x<5){//eme3
                a=rand()%4;
                n=rand()%12;
                n2=rand()%12;
                a2=rand()%4;
                n3=rand()%12;
                a3=rand()%4;
                r1=rand()%29;
                r2=rand()%29;
                r3=rand()%29;
                a4=rand()%4;
                n4=rand()%12;
                r4=rand()%29;
                if(a2!=a && a!=a3 && a2!=a3 && a!=a4 && a2!=a4 && a3!=a4 && n!=n2 && n2!=n3 && n!=n3 && n!=n4 && n2!=n4 && n3!=n4 && r1!=r2 && r2!=r3 && r1!=r3 && r1!=r4 && r2!=r4 && r3!=r4 && eme3[n]!=0 && eme3[n2]!=0 && eme3[n3]!=0 && eme3[n4]!=0 &&
                   tfriday[a][n]==1 && rfriday[a][r1]==1 && tfriday[a2][n2]==1 && rfriday[a2][r2]==1 && tfriday[a3][n3]==1 && rfriday[a3][r3]==1 && tfriday[a4][n4]==1 && rfriday[a4][r4]==1){
                    cout<<days[x]<<endl;
                    cout<<times[a]<<"    "<<course[eme3[n]].getcoursename()<<"    "<<teacher[eme3[n]].getname()<<"    "<<classrooms[r1].getroomname()<<endl;
                    cout<<endl;
                    cout<<times[a2]<<"    "<<course[eme3[n2]].getcoursename()<<"    "<<teacher[eme3[n2]].getname()<<"    "<<classrooms[r2].getroomname()<<endl;
                    cout<<endl;
                    cout<<times[a3]<<"    "<<course[eme3[n3]].getcoursename()<<"    "<<teacher[eme3[n3]].getname()<<"    "<<classrooms[r3].getroomname()<<endl;
                    cout<<endl;
                    cout<<times[a4]<<"    "<<course[eme3[n4]].getcoursename()<<"    "<<teacher[eme3[n4]].getname()<<"    "<<classrooms[r4].getroomname()<<endl;
                    cout<<endl;
                    x+=1;
                    eme3[n]=0;
                    eme3[n2]=0;
                    eme3[n3]=0;
                    eme3[n4]=0;
                    tfriday[a][n]=0;
                    rfriday[a][r1]=0;
                    tfriday[a2][n2]=0;
                    rfriday[a2][r2]=0;
                    tfriday[a3][n3]=0;
                    rfriday[a3][r3]=0;
                    tfriday[a4][n4]=0;
                    rfriday[a4][r4]=0;
                }
            }
        }

    }


    {// IV-course
        for(int i=0;i<4;i++){
            for(int j=0;j<15;j++){
                tmonday[i][j]=1;
                ttuesday[i][j]=1;
                twednesday[i][j]=1;
                tfriday[i][j]=1;
                tthursday[i][j]=1;
            }
        }

        for(int k=0;k<2;k++){//ECE4
            cout<<cour4[k]<<": "<<endl; //ece4
            x=0;
            for(int i=40;i<47;i++){//ece4
                ece4[i-40]=i-1;
            }
            while(x<3){//ece4

                a=rand()%4;
                n=rand()%7;
                n2=rand()%7;
                a2=rand()%4;
                r1=rand()%29;
                r2=rand()%29;

                if(a2!=a && n!=n2 && r1!=r2 && ece4[n]!=0 && ece4[n2]!=0 ){




                    if((x==0 && tmonday[a][n]==1 && rmonday[a][r1]==1 && tmonday[a2][n2]==1 && rmonday[a2][r2]==1 ) ||
                       (x==1 && ttuesday[a][n]==1 && rtuesday[a][r1]==1 && ttuesday[a2][n2]==1 && rtuesday[a2][r2]==1 ) ||
                       (x==2 && twednesday[a][n]==1 && rwednesday[a][r1]==1 && twednesday[a2][n2]==1 && rwednesday[a2][r2]==1) ||
                       (x==3 &&  tthursday[a][n]==1 && rthursday[a][r1]==1 && tthursday[a2][n2]==1 && rthursday[a2][r2]==1 ) ||
                       (x==4 && tfriday[a][n]==1 && rfriday[a][r1]==1 && tfriday[a2][n2]==1 && rfriday[a2][r2]==1 )){



                        if(x==0){tmonday[a][n]=0; tmonday[a2][n2]=0;  rmonday[a][r1]=0; rmonday[a2][r2]=0; }
                        if(x==1){ttuesday[a][n]=0; ttuesday[a2][n2]=0;  rtuesday[a][r1]=0; rtuesday[a2][2]=0; }
                        if(x==2){twednesday[a][n]=0; twednesday[a2][n2]=0;  rwednesday[a][r1]=0; rwednesday[a2][r2]=0; }
                        if(x==3){tthursday[a][n]=0; tthursday[a2][n2]=0; rthursday[a][r1]=0; rthursday[a2][r2]=0; }
                        if(x==4){tfriday[a][n]=0; tfriday[a2][n2]=0; rfriday[a][r1]=0; rfriday[a2][r2]=0; }
                        cout<<days[x]<<endl;
                        cout<<times[a]<<"    "<<course[ece4[n]].getcoursename()<<"    "<<teacher[ece4[n]].getname()<<"    "<<classrooms[r1].getroomname()<<endl;
                        cout<<endl;



                        cout<<times[a2]<<"    "<<course[ece4[n2]].getcoursename()<<"    "<<teacher[ece4[n2]].getname()<<"    "<<classrooms[r2].getroomname()<<endl;;
                        cout<<endl;



                        x+=1;
                        ece4[n]=0;
                        ece4[n2]=0;


                       }

                }

            }
            while(x<4){//ECE4
                a2=rand()%4;
                n2=rand()%7;
                r2=rand()%29;
                if(ece4[n2]!=0 && tfriday[a2][n2]==1 && rfriday[a2][r2]==1){
                    cout<<days[x]<<endl;
                    cout<<times[a]<<"    "<<course[ece4[n2]].getcoursename()<<"    "<<teacher[ece4[n2]].getname()<<"    "<<classrooms[r2].getroomname()<<endl;
                    cout<<endl;
                    x+=1;
                    ece4[n2]=0;
                    tfriday[a2][n2]=0;
                    rfriday[a2][r2]=0;
                }
            }
        }

        cout<<cour4[2]<<": "<<endl;//ECHE4
        x=0;
        for(int i=102; i<116;i++){
            eche4[i-102]=i-1;
        }
        while(x<5){//ECHE4


            a=rand()%4;
            n=rand()%10;
            n2=rand()%10;
            a2=rand()%4;


            r1=rand()%29;
            r2=rand()%29;



            if(a2!=a  && n!=n2  &&  r1!=r2 && eche4[n]!=0 && eche4[n2]!=0 ){


                if((x==0 && tmonday[a][n]==1 && rmonday[a][r1]==1 && tmonday[a2][n2]==1 && rmonday[a2][r2]==1 ) ||
                   (x==1 && ttuesday[a][n]==1 && rtuesday[a][r1]==1 && ttuesday[a2][n2]==1 && rtuesday[a2][r2]==1 ) ||
                   (x==2 && twednesday[a][n]==1 && rwednesday[a][r1]==1 && twednesday[a2][n2]==1 && rwednesday[a2][r2]==1 ) ||
                   (x==3 &&  tthursday[a][n]==1 && rthursday[a][r1]==1 && tthursday[a2][n2]==1 && rthursday[a2][r2]==1 ) ||
                   (x==4 && tfriday[a][n]==1 && rfriday[a][r1]==1 && tfriday[a2][n2]==1 && rfriday[a2][r2]==1 )){



                    if(x==0){tmonday[a][n]=0; tmonday[a2][n2]=0; rmonday[a][r1]=0; rmonday[a2][r2]=0; }
                    if(x==1){ttuesday[a][n]=0; ttuesday[a2][n2]=0;  rtuesday[a][r1]=0; rtuesday[a2][2]=0;}
                    if(x==2){twednesday[a][n]=0; twednesday[a2][n2]=0;  rwednesday[a][r1]=0; rwednesday[a2][r2]=0; }
                    if(x==3){tthursday[a][n]=0; tthursday[a2][n2]=0;  rthursday[a][r1]=0; rthursday[a2][r2]=0; }
                    if(x==4){tfriday[a][n]=0; tfriday[a2][n2]=0; rfriday[a][r1]=0; rfriday[a2][r2]=0; }
                    cout<<days[x]<<endl;
                    cout<<times[a]<<"    "<<course[eche4[n]].getcoursename()<<"    "<<teacher[eche4[n]].getname()<<"    "<<classrooms[r1].getroomname()<<endl;
                    cout<<endl;



                    cout<<times[a2]<<"    "<<course[eche4[n2]].getcoursename()<<"    "<<teacher[eche4[n2]].getname()<<"    "<<classrooms[r2].getroomname()<<endl;;
                    cout<<endl;




                    x+=1;
                    eche4[n]=0;
                    eche4[n2]=0;


                   }

            }

        }
        for(int i=0;i<4;i++){
            for(int j=0;j<15;j++){
                tmonday[i][j]=1;
                ttuesday[i][j]=1;
                twednesday[i][j]=1;
                tfriday[i][j]=1;
                tthursday[i][j]=1;
            }
        }

        for(int k=3;k<5;k++){//EEE4
            cout<<cour4[k]<<": "<<endl; //eee4
            x=0;

            for(int i=88;i<102;i++){//eee4
                eee4[i-88]=i-1;
            }
            while(x<4){// eee4

                    a=rand()%4;
                    n=rand()%14;
                    n2=rand()%14;
                    a2=rand()%4;
                    n3=rand()%14;
                    a3=rand()%4;
                    r1=rand()%29;
                    r2=rand()%29;
                    r3=rand()%29;

                    if(a2!=a && a!=a3 && a2!=a3 && n!=n2 && n2!=n3 && n!=n3 &&  r1!=r2 && r2!=r3 && r1!=r3 && eee4[n]!=0 && eee4[n2]!=0 && eee4[n3]!=0){



                        if((x==0 && tmonday[a][n]==1 && rmonday[a][r1]==1 && tmonday[a2][n2]==1 && rmonday[a2][r2]==1 && tmonday[a3][n3]==1  && rmonday[a3][r3]==1) ||
                           (x==1 && ttuesday[a][n]==1 && rtuesday[a][r1]==1 && ttuesday[a2][n2]==1 && rtuesday[a2][r2]==1 && ttuesday[a3][n3]==1 && rtuesday[a3][r3]==1) ||
                           (x==2 && twednesday[a][n]==1 && rwednesday[a][r1]==1 && twednesday[a2][n2]==1 && rwednesday[a2][r2]==1 && twednesday[a3][n3]==1 && rwednesday[a3][r3]==1) ||
                           (x==3 &&  tthursday[a][n]==1 && rthursday[a][r1]==1 && tthursday[a2][n2]==1 && rthursday[a2][r2]==1 && tthursday[a3][n3]==1 && rthursday[a3][r3]==1) ||
                           (x==4 && tfriday[a][n]==1 && rfriday[a][r1]==1 && tfriday[a2][n2]==1 && rfriday[a2][r2]==1 && tfriday[a3][n3]==1 && rfriday[a3][r3]==1)){



                            if(x==0){tmonday[a][n]=0; tmonday[a2][n2]=0; tmonday[a3][n3]=0; rmonday[a][r1]=0; rmonday[a2][r2]=0; rmonday[a3][r3]=0;}
                            if(x==1){ttuesday[a][n]=0; ttuesday[a2][n2]=0; ttuesday[a3][n3]=0; rtuesday[a][r1]=0; rtuesday[a2][2]=0; rtuesday[a3][r3]=0;}
                            if(x==2){twednesday[a][n]=0; twednesday[a2][n2]=0; twednesday[a3][n3]=0; rwednesday[a][r1]=0; rwednesday[a2][r2]=0; rwednesday[a3][r3]=0;}
                            if(x==3){tthursday[a][n]=0; tthursday[a2][n2]=0; tthursday[a3][n3]=0; rthursday[a][r1]=0; rthursday[a2][r2]=0; rthursday[a3][r3]=0;}
                            if(x==4){tfriday[a][n]=0; tfriday[a2][n2]=0; tfriday[a3][n3]=0; rfriday[a][r1]=0; rfriday[a2][r2]=0; rfriday[a3][r3]=0;}
                            cout<<days[x]<<endl;
                            cout<<times[a]<<"    "<<course[eee4[n]].getcoursename()<<"    "<<teacher[eee4[n]].getname()<<"    "<<classrooms[r1].getroomname()<<endl;
                            cout<<endl;



                            cout<<times[a2]<<"    "<<course[eee4[n2]].getcoursename()<<"    "<<teacher[eee4[n2]].getname()<<"    "<<classrooms[r2].getroomname()<<endl;;
                            cout<<endl;



                            cout<<times[a3]<<"    "<<course[eee4[n3]].getcoursename()<<"    "<<teacher[eee4[n3]].getname()<<"    "<<classrooms[r3].getroomname()<<endl;;
                            cout<<endl;
                            x+=1;
                            eee4[n]=0;
                            eee4[n2]=0;
                            eee4[n3]=0;

                           }

                    }

            }
            while(x<5){//eee4
                a=rand()%4;
                n=rand()%14;
                r1=rand()%29;
                a2=rand()%4;
                n2=rand()%14;
                r2=rand()%29;
                if(a!=a2 && n!=n2 && r1!=r2 && eee4[n]!=0 && eee4[n2]!=0 &&  tfriday[a][n]==1 && rfriday[a][r1]==1 && tfriday[a2][n2]==1 && rfriday[a2][r2]==1){
                    cout<<days[x]<<endl;
                    cout<<times[a]<<"    "<<course[eee4[n]].getcoursename()<<"    "<<teacher[eee4[n]].getname()<<"    "<<classrooms[r1].getroomname()<<endl;
                    cout<<endl;
                    cout<<times[a2]<<"    "<<course[eee4[n2]].getcoursename()<<"    "<<teacher[eee4[n2]].getname()<<"    "<<classrooms[r2].getroomname()<<endl;
                    cout<<endl;
                    x+=1;
                    eee4[n2]=0;
                    eee4[n]=0;
                    tfriday[a][n]=0;
                    rfriday[a][r1]=0;
                    tfriday[a2][n2]=0;
                    rfriday[a2][r2]=0;
                }
            }
        }
        for(int i=0;i<4;i++){
            for(int j=0;j<15;j++){
                tmonday[i][j]=1;
                ttuesday[i][j]=1;
                twednesday[i][j]=1;
                tfriday[i][j]=1;
                tthursday[i][j]=1;
            }
        }

        for(int k=5;k<7;k++){//EME$
            cout<<cour4[k]<<": "<<endl;
            x=0;
            for(int i=138; i<150;i++){
                eme4[i-138]=i-1;
            }
            while(x<4){

                a=rand()%4;
                n=rand()%12;
                n2=rand()%12;
                a2=rand()%4;


                r1=rand()%29;
                r2=rand()%29;



                if(a2!=a  && n!=n2  &&  r1!=r2 && eme4[n]!=0 && eme4[n2]!=0 ){


                    if((x==0 && tmonday[a][n]==1 && rmonday[a][r1]==1 && tmonday[a2][n2]==1 && rmonday[a2][r2]==1 ) ||
                       (x==1 && ttuesday[a][n]==1 && rtuesday[a][r1]==1 && ttuesday[a2][n2]==1 && rtuesday[a2][r2]==1 ) ||
                       (x==2 && twednesday[a][n]==1 && rwednesday[a][r1]==1 && twednesday[a2][n2]==1 && rwednesday[a2][r2]==1 ) ||
                       (x==3 &&  tthursday[a][n]==1 && rthursday[a][r1]==1 && tthursday[a2][n2]==1 && rthursday[a2][r2]==1 ) ||
                       (x==4 && tfriday[a][n]==1 && rfriday[a][r1]==1 && tfriday[a2][n2]==1 && rfriday[a2][r2]==1 )){



                        if(x==0){tmonday[a][n]=0; tmonday[a2][n2]=0; rmonday[a][r1]=0; rmonday[a2][r2]=0; }
                        if(x==1){ttuesday[a][n]=0; ttuesday[a2][n2]=0;  rtuesday[a][r1]=0; rtuesday[a2][2]=0;}
                        if(x==2){twednesday[a][n]=0; twednesday[a2][n2]=0;  rwednesday[a][r1]=0; rwednesday[a2][r2]=0; }
                        if(x==3){tthursday[a][n]=0; tthursday[a2][n2]=0;  rthursday[a][r1]=0; rthursday[a2][r2]=0; }
                        if(x==4){tfriday[a][n]=0; tfriday[a2][n2]=0; rfriday[a][r1]=0; rfriday[a2][r2]=0; }
                        cout<<days[x]<<endl;
                        cout<<times[a]<<"    "<<course[eme4[n]].getcoursename()<<"    "<<teacher[eme4[n]].getname()<<"    "<<classrooms[r1].getroomname()<<endl;
                        cout<<endl;



                        cout<<times[a2]<<"    "<<course[eme4[n2]].getcoursename()<<"    "<<teacher[eme4[n2]].getname()<<"    "<<classrooms[r2].getroomname()<<endl;;
                        cout<<endl;




                        x+=1;
                        eme4[n]=0;
                        eme4[n2]=0;


                       }

                }

            }
            while(x<5){//eme4
                a=rand()%4;
                n=rand()%12;
                n2=rand()%12;
                a2=rand()%4;
                n3=rand()%12;
                a3=rand()%4;
                r1=rand()%29;
                r2=rand()%29;
                r3=rand()%29;
                a4=rand()%4;
                n4=rand()%12;
                r4=rand()%29;
                if(a2!=a && a!=a3 && a2!=a3 && a!=a4 && a2!=a4 && a3!=a4 && n!=n2 && n2!=n3 && n!=n3 && n!=n4 && n2!=n4 && n3!=n4 && r1!=r2 && r2!=r3 && r1!=r3 && r1!=r4 && r2!=r4 && r3!=r4 && eme4[n]!=0 && eme4[n2]!=0 && eme4[n3]!=0 && eme4[n4]!=0 &&
                   tfriday[a][n]==1 && rfriday[a][r1]==1 && tfriday[a2][n2]==1 && rfriday[a2][r2]==1 && tfriday[a3][n3]==1 && rfriday[a3][r3]==1 && tfriday[a4][n4]==1 && rfriday[a4][r4]==1){
                    cout<<days[x]<<endl;
                    cout<<times[a]<<"    "<<course[eme4[n]].getcoursename()<<"    "<<teacher[eme4[n]].getname()<<"    "<<classrooms[r1].getroomname()<<endl;
                    cout<<endl;
                    cout<<times[a2]<<"    "<<course[eme4[n2]].getcoursename()<<"    "<<teacher[eme4[n2]].getname()<<"    "<<classrooms[r2].getroomname()<<endl;
                    cout<<endl;
                    cout<<times[a3]<<"    "<<course[eme4[n3]].getcoursename()<<"    "<<teacher[eme4[n3]].getname()<<"    "<<classrooms[r3].getroomname()<<endl;
                    cout<<endl;
                    cout<<times[a4]<<"    "<<course[eme4[n4]].getcoursename()<<"    "<<teacher[eme4[n4]].getname()<<"    "<<classrooms[r4].getroomname()<<endl;
                    cout<<endl;
                    x+=1;
                    eme4[n]=0;
                    eme4[n2]=0;
                    eme4[n3]=0;
                    eme4[n4]=0;
                    tfriday[a][n]=0;
                    rfriday[a][r1]=0;
                    tfriday[a2][n2]=0;
                    rfriday[a2][r2]=0;
                    tfriday[a3][n3]=0;
                    rfriday[a3][r3]=0;
                    tfriday[a4][n4]=0;
                    rfriday[a4][r4]=0;
                }
            }
        }

    }
}



