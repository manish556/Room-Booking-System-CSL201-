
/*
    definitions of all functions of class lab_data
*/

#include "lab_data.h"
#include <iomanip>
#include <iostream>
using namespace std;

lab_data::lab_data()
    {
       no_of_computers=0;
    }

lab_data::~lab_data(){}

void lab_data::show()
    {
        cout<<"\nName:"<<setw(7)<<name<<" | Area:"<<setw(7)<<area<<" | Doors:"<<setw(2)<<doors;
        cout<<" | x:"<<setw(4)<<x<<" | y:"<<setw(4)<<y;
        cout<<" | Comp:"<<setw(3)<<no_of_computers<<" | Book:"<<setw(2)<<booking_status<<endl;
    }

void lab_data::set_data(char* p, float ar, int d, int a, int b, int c, int bst)
    {
        strcpy(name,p);
        area=ar;
        doors=d;
        x=a;
        y=b;
        no_of_computers=c;
        booking_status=bst;
    }

void lab_data::set_data(char*p, float ar,int d, int a, int b,int c)
    {
        strcpy(name,p);
        area=ar;
        doors=d;
        x=a;
        y=b;
        no_of_computers=c;
    }

void lab_data::set_data()
    {
        cout<<"\n Enter room name, Room area, No of doors, x axis, y axis, no of computers:\n ";
        cin>>name>>area>>doors>>x>>y>>no_of_computers;
    }

int lab_data::get_no_of_computers()
{
    return no_of_computers;
}

void lab_data::add_comp(int n)
{
    no_of_computers += n;
}
