
/*
    definition of class room_data 
*/

#ifndef ROOMDATA
#define ROOMDATA

class room_data
{
protected:
    char name[20];						// stores name
    float area;							// stores area
    int doors;							// stores no of doors
    int x,y;        						// x and y are cordinates
    int booking_status;

public:
    room_data();    // constructor

    ~room_data();   // distructor

    virtual void show();                                            // fn to show details of that room
    virtual void set_data(char*,float,int,int,int,int,int dummy);   // fn to set data of that room       fn overloading
    virtual void set_data(char*,float,int,int,int b,int dummy);     // fn to set data of that room       fn overloading
    virtual void set_data();                                        // fn to set data of that room       fn overloading

    void change_booking_status();    				    // change booking status
    char* get_name();						    // return name
    int get_area();						    // return area
    int get_doors();						    // return no of doors
    int get_x();						    // return x cordinate
    int get_y();						    // return y cordinate
    int get_booking_status();					    // return booking status

    float dist_from_loc(int,int);				    // return distance from given cordinates

    virtual int get_no_of_computers();                              // return no of computers redundant in this class (inherited)
    virtual int get_no_of_chairs();				    // return no of chairs    redundant in this class (inherited)
    virtual void add_comp(int);					    // add computers          redundant in this class (inherited)

};

#endif // ROOMDATA
