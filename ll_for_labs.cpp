
/*
    definition of function make_LL_for_labs()
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


void make_LL_for_labs(LinkedList *p)
{
   char name[15];
   float area;
   int n_of_doors,x_cord,y_cord,b_status,n_of_comp,n_of_chairs,choice,choice2;
   fstream ifile_l;
   ifile_l.open("LAB1.txt",ios::in);         // open LAB1.txt if it exists read from it else read from LAB.txt
    if(ifile_l>>name)
    {  
        while (1)
        {
          if(!ifile_l)
             break;

         room_data* ptr=new lab_data;
         
         ifile_l>>area>>n_of_doors>>x_cord>>y_cord>>n_of_comp>>b_status;
         ptr->set_data(name,area,n_of_doors,x_cord,y_cord,n_of_comp,b_status);
         (*p).add_bck(ptr);
	 ifile_l>>name;
        }
    }
    else                         	    // reading from LAB.txt
    {
  	ifile_l.close();
        ifile_l.open("LAB.txt",ios::in);
        while (1)
        {
         room_data* ptr=new lab_data;
         ifile_l>>name;

         if(!ifile_l)
             break;

         ifile_l>>area>>n_of_doors>>x_cord>>y_cord>>n_of_comp;
         ptr->set_data(name,area,n_of_doors,x_cord,y_cord,n_of_comp);
         (*p).add_bck(ptr);
        }
    }
}
