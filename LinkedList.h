
/*
    declaration of class LinkedList
*/

#ifndef LINKED_LIST
#define LINKED_LIST

#include "node.h"
#include "room_data.h"
#include "lab_data.h"
#include "lec_hall_data.h"

template<typename T> T get_max_elem(T* arr, int n);

class LinkedList
{
private:
    node* header;                 // pointer to first node
    node* trailer;		  // pointer to last node

public:
    int is_emp();                  // return 1 if Linked List is empty else return 0
    int add_bck(room_data*);       // add a room at the back of Linked List
    void remve_by_name(char*);     // remove a node by name
    void show_all();               // show details of all rooms
    void show_details(char*);	   // show details of a room by name
    node* get_header();	           // return header of the Linked List
    void save_and_exit(int);       // save the linked list in a text file
    void book_by_name(char*);      // book a room/hall/lab by name
    void unbook_by_name(char*);	   // unbook a room by name
    void min_rooms(int);           // show min rooms required to accomodate given number of persons
    void sma_lec(int);		   // show smallest lec hall that can accomodate given number of students
    void find_least_den_lab_and_add();  // find lab with least equipment density and add computer to it
    void room_nearest_to_loc(int,int);  // show the room nearest to the given location
    int does_exist(char*);		// return 1 if the room/lab/hall exists else return 
    void greatest_of_all(int);          // show the greatest room/hall/lab in terms of area and equipments

    LinkedList();  // constructor
    ~LinkedList(); // destructor

};

#endif // LINKED_LIST
