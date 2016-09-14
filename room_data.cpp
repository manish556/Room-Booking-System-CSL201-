
/*
    definitions of all functions of class room_data
*/

#include "room_data.h"
#include <iostream>
#include <iomanip>
#include <string.h>
#include <math.h>

using namespace std;

room_data::room_data()   // constructor
    {
        strcpy(name,"XXXXX");
        area=0;
        doors=x=y=booking_status=0;
    }

room_data:: ~room_data() {}

void room_data::show()
    {
        cout<<"\nName:"<<setw(9)<<name<<" | Area:"<<setw(7)<<area<<" | Doors:"<<setw(3)<<doors;
        cout<<" | x:"<<setw(4)<<x<<" | y:"<<setw(4)<<y;
        cout<<" | Book:"<<setw(2)<<booking_status<<endl;
    }

void room_data::set_data(char* p,float ar,int d, int a, int b,int bst,int dummy)
    {
        strcpy(name,p);
        area=ar;
        doors=d;
        x=a;
        y=b;
        booking_status=bst;
    }

void room_data::set_data(char* rn,float ar,int d, int a, int b, int dummy)
    {
        strcpy(name,rn);
        area=ar;
        doors=d;
        x=a;
        y=b;
    }

void room_data::set_data()
    {
        cout<<"\n Enter room name, Room area, No of doors, x axis, y axis:\n ";
        cin>>name>>area>>doors>>x>>y;
    }

void room_data::change_booking_status()
    {
        booking_status = booking_status?0:1;
    }

char* room_data::get_name()
    {
        return name;
    }

int room_data::get_area()
    {
        return area;
    }

int room_data::get_doors()
    {
        return doors;
    }

int room_data::get_x()
    {
        return x;
    }

int room_data::get_y()
    {
        return y;
    }

int room_data::get_booking_status()
    {
        return booking_status;
    }

float room_data::dist_from_loc(int a,int b)
{
    float dist=sqrt( pow(a-x,2)+pow(b-y,2) );
    return dist;
}

int room_data::get_no_of_computers(){}
int room_data::get_no_of_chairs(){}
void room_data::add_comp(int x){}
