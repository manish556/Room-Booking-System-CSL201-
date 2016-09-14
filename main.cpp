
/*
     definition of function main()
*/


#include "room_data.h"
#include "lab_data.h"
#include "lec_hall_data.h"
#include "gfun.h"
#include "LinkedList.h"
#include "node.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
using namespace std;



int main()
{
   LinkedList R,L,H;
   ifstream ifile_r,ifile_l,ifile_lh;
   char name[15];
   float area;
   int n_of_doors,x_cord,y_cord,b_status,n_of_comp,n_of_chairs,choice,choice2;

   make_LL_for_rooms(&R);
   make_LL_for_labs(&L);
   make_LL_for_l_halls(&H);

    do
    {
        header();

        cout<<"\n 1  to add room, lab, lecture hall\n";
        cout<<" 2  to remove room, lab, lecture hall\n";
        cout<<" 3  to book a room, lab, lecture hall\n";
        cout<<" 4  to find minimum no of rooms for persons\n";
        cout<<" 5  to find smallest lecture hall that can accomodate given no of students\n";
        cout<<" 6  to find lab with least equipment density and add computers in it\n";
        cout<<" 7  find a room nearest to given location\n";
        cout<<" 8  to unbook a room\n";
        cout<<" 9  print details of a room, lab or lecture hall\n";
        cout<<" 10 Other Functions\n";
        cout<<" 0  to save and exit\n";
        cout<<"\n Your Choice: ";
        cin>>choice;
        char name[20];
        int per,stu,add_eqip,x,y,min_r;

        room_data* ptr1=new room_data;
        room_data* ptr2=new lab_data;
        room_data* ptr3=new lec_hall_data;

        switch (choice)
        {
            case 1: cout<<"\n\n 1 to add room";
                    cout<<"\n 2 to add lab";
                    cout<<"\n 3 to add lecture hall\n";
                    cout<<"\n Your choice: ";
                    cin>>choice2;
                    switch(choice2)
                     {
                       case 1: ptr1->set_data();
                               if( R.add_bck(ptr1) )
                                cout<<"\n Room Added\n";
                               else
                                cout<<"\n Room Name already exists\n";
                               break;
                       case 2: ptr2->set_data();
                               if( L.add_bck(ptr2) )
                                cout<<"\n Lab Added\n";
                               else
                                cout<<"\n Lab Name already exists\n";
                               break;
                       case 3: ptr3->set_data();
                               if( H.add_bck(ptr3) )
                                cout<<"\n Lecture Hall Added\n";
                               else
                                cout<<"\n Lecture Hall Name already exists\n";
                               break;
                       default: cout<<"\n Enter valid choice\n";
                     }
                    break;

            case 2: cout<<"\n 1 to remove room";
                    cout<<"\n 2 to remove lab";
                    cout<<"\n 3 to remove lecture hall\n";
                    cout<<"\n Your choice: ";
                    cin>>choice2;

                    switch(choice2)
                     {
                       case 1: cout<<"\n Enter room name: ";
                               cin>>name;
                               R.remve_by_name(name);
                               break;
                       case 2: cout<<"\n Enter lab name: ";
                               cin>>name;
                               L.remve_by_name(name);
                               break;
                       case 3: cout<<"\n Enter Lecture Hall name: ";
                               cin>>name;
                               H.remve_by_name(name);
                               break;
                       default: cout<<"\n Enter valid choice\n";
                     }
                    break;

            case 3: cout<<"\n 1 to book a room";
                    cout<<"\n 2 to book a lab";
                    cout<<"\n 3 to book a lecture hall\n ";
                    cout<<"\n Your choice: ";
                    cin>>choice2;

                    switch(choice2)
                     {
                       case 1: cout<<"\n Enter room name: ";
                               cin>>name;
                               R.book_by_name(name);
                               break;
                       case 2: cout<<"\n Enter lab name: ";
                               cin>>name;
                               L.book_by_name(name);
                               break;
                       case 3: cout<<"\n Enter lecture hall name: ";
                               cin>>name;
                               H.book_by_name(name);
                               break;
                       default: cout<<"\n Enter valid choice\n";
                     }
                    break;

            case 4: cout<<"\n Enter No. of Persons: ";
                    cin>>per;
                    R.min_rooms(per);
                    break;

            case 5: cout<<"\n Enter No. of students: ";
                    cin>>stu;
                    H.sma_lec(stu);
                    break;

            case 6: L.find_least_den_lab_and_add();
                    break;

            case 7: cout<<"\n Enter x cordinate: ";
                    cin>>x;
                    cout<<"\n Enter y cordinate: ";
                    cin>>y;
                    R.room_nearest_to_loc(x,y);
                    break;

            case 8: cout<<"\n 1 to unbook a room";
                    cout<<"\n 2 to unbook a lab";
                    cout<<"\n 3 to unbook a lecture hall\n ";
                    cout<<"\n Your choice: ";
                    cin>>choice2;

                    switch(choice2)
                     {
                       case 1: cout<<"\n Enter room name: ";
                               cin>>name;
                               R.unbook_by_name(name);
                               break;
                       case 2: cout<<"\n Enter lab name: ";
                               cin>>name;
                               L.unbook_by_name(name);
                               break;
                       case 3: cout<<"\n Enter room name: ";
                               cin>>name;
                               H.unbook_by_name(name);
                               break;
                       default: cout<<"\n Enter valid choice\n";
                     }
                    break;

            case 9: cout<<"\n 1 to print details of a room";
                    cout<<"\n 2 to print details of a lab";
                    cout<<"\n 3 to print detail of a lecture hall\n ";
                    cout<<"\n Your choice: ";
                    cin>>choice2;

                    switch(choice2)
                    {
                    case 1: cout<<"\n Enter room name: ";
                            cin>>name;
                            R.show_details(name);
                            break;
                    case 2: cout<<"\n Enter lab name: ";
                            cin>>name;
                            L.show_details(name);
                            break;
                    case 3: cout<<"\n Enter room name: ";
                            cin>>name;
                            H.show_details(name);
                            break;
                    default: cout<<"\n Enter valid choice\n";
                    }
                    break;

             case 10: cout<<"\n 1 to print details of all Rooms";
                      cout<<"\n 2 to print details of all Labs";
                      cout<<"\n 3 to print details of all Lecture Halls";
                      cout<<"\n 4 to find greatest Room";
                      cout<<"\n 5 to find greatest Lab";
                      cout<<"\n 6 to find greatest Lecture Hall\n";
                      cout<<"\n Your choice: ";
                      cin>>choice2;

                      switch(choice2)
                      {
                       case 1: R.show_all();
                               break;
                       case 2: L.show_all();
                               break;
                       case 3: H.show_all();
                               break;
                       case 4: R.greatest_of_all(1);
                               break;
                       case 5: L.greatest_of_all(2);
                               break;
                       case 6: H.greatest_of_all(3);
                               break;

                       default: cout<<"\n Enter valid choice\n";
                      }
                      break;

            case 0: R.save_and_exit(1);
                    L.save_and_exit(2);
                    H.save_and_exit(3);
                    break;

            default: cout<<"\n Enter valid choice\n";

        }    // end of main switch

        if(choice)
        {
           cout<<"\n 1 to go to main menu\n 0 to save and exit\n";
           cout<<"\n Your choice: ";
           cin>>choice;
           switch (choice)
           {
             case 1: break;
             case 0: R.save_and_exit(1);
                     L.save_and_exit(2);
                     H.save_and_exit(3);
                     break;
           }
        }

 }  while (choice);         // end of do while

    return 0;
}
