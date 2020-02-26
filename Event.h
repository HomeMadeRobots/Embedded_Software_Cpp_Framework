#ifndef EVENT_H
#define EVENT_H

class Event_Reception_Point;

class Event {

public :
    Event( void );
	
    void Send( void );
    void Add_Event_Reception_Point( Event_Reception_Point* reception_point );

private :
    Event_Reception_Point* Reception_Point_List;

};


class Event_Reception_Point {

public :
    Event_Reception_Point( void );
    Event_Reception_Point( void* x );
	
    virtual void On_Event_Reception( Event* ev ) = 0 ;
	
    Event_Reception_Point* Next_Receiver;
    void* Parent;
};

#endif