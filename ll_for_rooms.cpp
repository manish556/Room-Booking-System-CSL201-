
/*
     definition of function make_LL_for_rooms()
*/

#include "gfun.h"
#include "room_data.h"
#include "lab_data.h"
#include "lec_hall_data.h"
#include "node.h"
#include "LinkedList.h"
#include <iostream>
#include <fstream>
using namespace std;


void make_LL_for_rooms(LinkedList *p)
{
   
   char name[15];
   float area;
   int n_of_doors,x_cord,y_cord,b_status,n_of_comp,n_of_chairs,choice,choice2;
    ifstream ifile_r;
    int dummy;
    ifile_r.open("ROOM1.txt",ios::in);        // open ROOM1.txt if it exists read from it else read from ROOM.txt
    if(ifile_r>>name)
    {
        cout<<"rooms add\n";
        while (1)
        {
         room_data* ptr=new room_data;

         if(!ifile_r)
             break;

         ifile_r>>area>>n_of_doors>>x_cord>>y_cord>>b_status;
         ptr->set_data(name,area,n_of_doors,x_cord,y_cord,b_status,dummy);
         (*p).add_bck(ptr);
	 ifile_r>>name;
        }
    }
    else
    {  
        ifile_r.close();
        ifile_r.open("ROOM.txt",ios::in);
        while (1)
        {
         room_data* ptr=new room_data;
         ifile_r>>name;

         if(!ifile_r)
             break;

         ifile_r>>area>>n_of_doors>>x_cord>>y_cord;
         ptr->set_data(name,area,n_of_doors,x_cord,y_cord,dummy);
         (*p).add_bck(ptr);
        }
    }
}
