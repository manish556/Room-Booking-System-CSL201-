
/*
     definition of function make_LL_for_l_halls()
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


void make_LL_for_l_halls(LinkedList *p)
{
   char name[15];
   float area;
   int n_of_doors,x_cord,y_cord,b_status,n_of_comp,n_of_chairs,choice,choice2;
   fstream ifile_lh;
   ifile_lh.open("LEC1.txt",ios::in);             // open LEC1.txt if it exists read from it else read from LEC.txt
    if(ifile_lh>>name)
    {
        while (1)
        {
         room_data* ptr=new lec_hall_data;

         if(!ifile_lh)
             break;

         ifile_lh>>area>>n_of_doors>>x_cord>>y_cord>>n_of_chairs>>b_status;
         ptr->set_data(name,area,n_of_doors,x_cord,y_cord,n_of_chairs,b_status);
         (*p).add_bck(ptr);
         ifile_lh>>name;
        }
    }
    else					// read from LEC.txt
    {
        ifile_lh.close();
        ifile_lh.open("LEC.txt",ios::in);
        while (1)
        {
         room_data* ptr=new lec_hall_data;
         ifile_lh>>name;

         if(!ifile_lh)
             break;

         ifile_lh>>area>>n_of_doors>>x_cord>>y_cord>>n_of_chairs;
         ptr->set_data(name,area,n_of_doors,x_cord,y_cord,n_of_chairs);
         (*p).add_bck(ptr);
        }
    }
}
