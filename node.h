
/*
     declaration of class node
*/

#ifndef NODE
#define NODE

#include "room_data.h"
#include "lab_data.h"
#include "lec_hall_data.h"
class node
{
private:
  node* next;                // pointer to next node
  room_data* elem;           // pointer to room_data , can also point to its derived classes
  friend class LinkedList;   // so that class LinkedList may have access to its private members 

public:
  room_data* get_element();  // return elem (pointer to room_data)
  node();		     // constructor
  ~node();		     // destructor
};

#endif // NODE
