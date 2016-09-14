
/*
    definitions of all functions of class LinkedList
*/

#include "LinkedList.h"
#include <string.h>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

ifstream ifile_r,ifile_l,ifile_lh;

bool operator < (node temp, int smallest)
    {
     if(temp.get_element()->get_no_of_chairs() < smallest)
        return true;
     else
        return false;
    }

LinkedList::LinkedList()  // constructor
    {
        header = NULL;
        trailer = NULL;
    }

LinkedList::~LinkedList(){}

node* LinkedList::get_header()
{
    return header;
}

int LinkedList::is_emp()
{
    if(header==NULL)
        return 1;
    return 0;
}

int LinkedList::add_bck(room_data* d)
{
    if( does_exist( d->get_name() ) )
        return 0;

    node* ptr = new node;
    ptr -> elem = d;
    ptr -> next = NULL;
    if(trailer==NULL)
        header=trailer=ptr;
    else
     {
        trailer -> next = ptr;
        trailer = ptr;
     }
    return 1;
}

void LinkedList::remve_by_name(char* a)
{
    node* temp=header;
    if(temp==NULL)
    {
        cout<<"\n Record Empty\n";
        return;
    }
    if(temp->next==NULL)
    {
        if( strcmp(temp->elem->get_name(),a)==0 )
         {
             header = trailer = NULL;
             cout<<"\n Record Deleted\n";
             return;
         }
        cout<<"\n Record not found\n";
        return;
    }

    if( strcmp(header->elem->get_name(),a) ==0 )
     {
          header=header->next;
    	  cout<<"\n Record Deleted\n";
          return;
     }

    node *temp2 = temp -> next;
    while(temp2!=NULL)
        {
            if( strcmp(temp2->elem->get_name(),a) ==0 )
            {
               temp->next=temp2->next;
               cout<<"\n Record Deleted\n";
               return;
            }
            temp2=temp2->next;
            temp=temp->next;
        }
   cout<<"\n Record Not Found\n";
}

void LinkedList::show_all()
{
    if (is_emp())
    {
        cout<<"\n Record Empty\n";
        return;
    }

    node*ptr = header;
    while(ptr!=NULL)
    {
        ptr->elem->show();
        ptr=ptr->next;
    }
}

void LinkedList::show_details(char* name)
{
   if(is_emp())
   {
       cout<<"\n Record Empty\n";
       return;
   }

    node *temp = header;
    while(temp!=NULL)
    {
        if( strcmp(temp->elem->get_name(),name) == 0)
        {
            temp->elem->show();
            return;
        }
           temp=temp->next;
    }
    cout<<"\n Record Not Found\n";
}


void LinkedList::save_and_exit(int n)
{
    fstream ofile;
    if(n==1)
     ofile.open("ROOM1.txt",ios::out);

    else if(n==2)
     ofile.open("LAB1.txt",ios::out);

    else
      ofile.open("LEC1.txt",ios::out);

    node* temp = header;
    while(temp!=NULL)
    {
        ofile<<temp->elem->get_name();
        ofile<<" ";
        ofile<<temp->elem->get_area();
        ofile<<" ";
        ofile<<temp->elem->get_doors();
        ofile<<" ";
        ofile<<temp->elem->get_x();
        ofile<<" ";
        ofile<<temp->elem->get_y();
        if(n==2)
            {
              ofile<<" ";
              ofile<<temp->elem->get_no_of_computers();
            }

        else if(n==3)
            {
              ofile<<" ";
              ofile<<temp->elem->get_no_of_chairs();
            }

        ofile<<" ";
        ofile<<temp->elem->get_booking_status();
        ofile<<"\n";

        temp = temp->next;
    }

}

void LinkedList::book_by_name(char* R)
{
    if(is_emp())
    {
        cout<<"\n Record Empty\n";
        return;
    }
    node* temp = header;
    while(temp!=NULL)
    {
        if( strcmp(temp->elem->get_name(), R) == 0 )
           {
               if(temp->elem->get_booking_status()==0)
               {
                temp->elem->change_booking_status();
                cout<<"\n Room Booked\n";
                return;
               }
               cout<<"\n Room Already Booked\n";
               return;
           }
        temp=temp->next;
    }
    cout<<"\n Room not found\n";
}

void LinkedList::unbook_by_name(char* R)
{
    if(is_emp())
    {
        cout<<"\n Record Empty\n";
        return;
    }
    node* temp = header;
    while(temp!=NULL)
    {
        if( strcmp(temp->elem->get_name(), R) == 0 )
           {
               if(temp->elem->get_booking_status()==1)
               {
                temp->elem->change_booking_status();
                cout<<"\n Room Unbooked\n";
                return;
               }
               cout<<"\n Room Already Unbooked\n";
               return;
           }
        temp=temp->next;
    }
    cout<<"\n Room not found\n";
}

void LinkedList::min_rooms(int per)    // from unbooked rooms
{
  if(is_emp())
   {
       cout<<"\n Record Empty\n";
       return;
   }

   int *arr = new int[1000];
   int i=-1;
   node*temp = header;
   while(temp!=NULL)
   {
       if(temp->elem->get_booking_status()==0)
        *(arr+(++i)) = temp->elem->get_area();
       temp=temp->next;
   }

   sort(arr,arr+i+1);
   double req_area = per*30;

   int j;
   for(j=i;j>=0;j--)
   {
       if(req_area<=0)
        break;
       req_area -= ((int)(*(arr+j)/30)*30);
   }

   if(req_area>0)
       cout<<"\n Cannot accomodate this much people\n";
   else
       {
           cout<<"\n No of Rooms required: "<<(i-j)<<endl;
       }
}

void LinkedList::sma_lec(int stu)   // from unbooked only
{

   if(is_emp())
   {
       cout<<"\n Record Empty\n";
       return;
   }

   int smallest = pow(2,30);
   node* temp = header;
   node* temp2 = NULL;
   while(temp!=NULL)
   {
     if( !(*temp < stu) && *temp < smallest && temp->elem->get_booking_status()==0 )
      {
        smallest = temp->elem->get_no_of_chairs();
        temp2=temp;
      }
     temp=temp->next;
   }

   if(temp2==NULL)
     cout<<"\n No such Lecture Hall\n";
   else
     cout<<"\n "<<temp2->elem->get_name()<<" is smallest such lecture hall\n";

}

void LinkedList::find_least_den_lab_and_add()   // from all labs
{
   if(is_emp())
   {
       cout<<"\n Record Empty\n";
       return;
   }

   node* temp = header;
   node* temp2 = NULL;
   float den = pow(2,30);

   while(temp!=NULL)
   {
       if ( (float)(temp->elem->get_no_of_computers()/(float)temp->elem->get_area()) < den )
       {
           den = (float)(temp->elem->get_no_of_computers()/(float)temp->elem->get_area());
           temp2=temp;
       }
       temp=temp->next;
   }

   int no_com;
   cout<<"\n Lab with least equipment density: "<<temp2->elem->get_name()<<endl;
   cout<<" With about "<<den<<" computers per lab\n";
   cout<<"\n Enter no. of computers to be added in this room: ";
   cin>>no_com;
   temp2->elem->add_comp(no_com);
   cout<<"\n Computers added\n";

}

void LinkedList::room_nearest_to_loc(int a,int b)  // from all rooms
{
    if(is_emp())
    {
        cout<<"\n Record Empty\n";
        return;
    }
    float min_dist=pow(2,30);
    node* temp=header;
    node *temp2=NULL;
    while(temp!=NULL)
    {
        if( temp->elem->dist_from_loc(a,b) < min_dist)
        {
            min_dist = temp->elem->dist_from_loc(a,b);
            temp2 = temp;
        }
        temp=temp->next;
    }

    cout<<"\n Room with minimum distance: "<<temp2->elem->get_name()<<endl;
}

int LinkedList::does_exist(char *r_name)
{
    node* temp = header;
    while(temp!=NULL)
    {
        if( strcmp(temp->elem->get_name(),r_name) == 0 )
            return 1;

        temp=temp->next;
    }
    return 0;
}

template<typename T> T get_max_elem(T* arr, int n)
{
    T max_elem = 0;
    for(int i=0; i<=n; i++)
    {
        if( *(arr+i) > max_elem )
            max_elem = *(arr+i);
    }
    return max_elem;
}


void LinkedList::greatest_of_all(int x)
{
    if(is_emp())
     {
        cout<<"\n Record Empty\n";
        return;
     }
    int *arr = new int[1000];
    int max_equip=0;
    float *arr2 = new float[1000];
    float max_area;
    node *temp = header;
    int i=-1;

    while(temp!=NULL)
    {
        *(arr+(++i)) = temp->elem->get_area();
        temp=temp->next;
    }

    max_area = get_max_elem(arr,i);

    temp=header;
    while(temp!=NULL)
    {
        if( max_area == temp->elem->get_area() )
        break;
        temp=temp->next;
    }
    cout<<"\n "<<temp->elem->get_name()<<" has maximum area of "<<max_area<<endl;

    if(x==2 || x==3)
    {
        i=-1;
        temp = header;
        while(temp!=NULL)
        {
          *(arr2+(++i)) = x==2 ? temp->elem->get_no_of_computers() : temp->elem->get_no_of_chairs();
          temp=temp->next;
        }
       max_equip = get_max_elem(arr2,i);

       temp=header;
       while(temp!=NULL)
       {
         if( max_equip == (x==2 ? temp->elem->get_no_of_computers() : temp->elem->get_no_of_chairs()) )
         break;
         temp=temp->next;
       }

       if(x==2)
           cout<<" "<<temp->elem->get_name()<<" has maximum computers: "<<max_equip<<endl;
       else
           cout<<" "<<temp->elem->get_name()<<" has maximum chairs: "<<max_equip<<endl;
    }
}
