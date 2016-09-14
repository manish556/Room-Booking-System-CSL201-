
/*
    definitions of functions of class lec_hall_data
*/

#include "lec_hall_data.h"
#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;

lec_hall_data::lec_hall_data()
    {
       no_of_chairs=0;
    }

lec_hall_data::~lec_hall_data(){}

void lec_hall_data::show()
    {
        cout<<"\nName:"<<setw(6)<<name<<" | Area:"<<setw(7)<<area<<" | Doors:"<<setw(2)<<doors;
        cout<<" | x:"<<setw(4)<<x<<" | y:"<<setw(4)<<y;
        cout<<" | Chair:"<<setw(3)<<no_of_chairs<<" | Book:"<<setw(2)<<booking_status<<endl;
    }

void lec_hall_data::set_data(char* p,float ar,int d, int a, int b, int c,int bst)
    {
        strcpy(name,p);
        area=ar;
        doors=d;
        x=a;
        y=b;
        no_of_chairs=c;
        booking_status=bst;
    }

void lec_hall_data::set_data(char* rn,float ar,int d, int a, int b,int c)
    {
        strcpy(name,rn);
        area=ar;
        doors=d;
        x=a;
        y=b;
        no_of_chairs=c;
    }

void lec_hall_data::set_data()
    {
        cout<<"\n Enter room name, Room area, No of doors, x axis, y axis, no of chairs:\n ";
        cin>>name>>area>>doors>>x>>y>>no_of_chairs;
    }

int lec_hall_data::get_no_of_chairs()
    {
        return no_of_chairs;
    }
