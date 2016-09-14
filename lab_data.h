
/*
    declaration of class lab_data
    fn overloading
*/

#ifndef LAB_DATA
#define LAB_DATA

#include "room_data.h"
#include <string.h>
class lab_data:public room_data
{
 private:
    int no_of_computers;

 public:
    lab_data();			// constructor
    ~lab_data();		// destructor

    void show();                                                              // to show all data of that room
    void set_data(char* p,float ar,int d, int a, int b, int c, int bst);      // to set data of that room       fn overloading
    void set_data(char* rn,float ar,int d, int a, int b, int c);              // to set data of that room       fn overloading
    void set_data();                                                          // to set data (add room fn)      fn overloadind
    int get_no_of_computers();						      // return number of computers
    void add_comp(int);							      // to add computers
};

#endif // LAB_DATA
