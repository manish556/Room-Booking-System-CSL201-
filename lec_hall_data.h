
/*
    declaration of class lec_hall_data
*/

#ifndef ROOM_DATA
#define ROOM_DATA

#include "room_data.h"
class lec_hall_data:public room_data
{
 private:
    int no_of_chairs;

 public:
    lec_hall_data();
    ~lec_hall_data();

    void show();
    void set_data(char* p,float ar,int d, int a, int b, int c, int bst);       // fn to set data of that lec hall      fn overloading
    void set_data(char* rn,float ar,int d, int a, int b, int c);               // fn to set data of that lec hall      fn overloading
    void set_data();							       // fn to set data (used by lec hall fn) fn overloading  
    int get_no_of_chairs();						       // return no of chairs

};

#endif // ROOM_DATA
