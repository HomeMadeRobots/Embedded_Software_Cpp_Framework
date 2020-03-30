#ifndef EVENT_H
#define EVENT_H

/**************************************************************************************************/
/* Event */
/**************************************************************************************************/
class Event_Reception_Point;

class Event {
/* Basic class to implement an Event_Interface. 
It shall be instanciated as part (private) of the Component_Types that realize an Event_Interface.
Shall be directly used for Event_Interfaces without arguments.
Shall be specialized for Event_Interfaces with arguments. */
public :
    /* Constructor */
    Event( void );

    /* Called by the Component_Type to "send" its Event. */
    void Send( void );
    
    /* Called within the Root_Software_Composition constructor to associate the Event to its 
    receivers. */
    void Add_Event_Reception_Point( Event_Reception_Point* reception_point );

private :
    /* List of the reception points linked to the Event.
    They will be notify when Send() method is called. */
    Event_Reception_Point* Reception_Point_List;

};


/**************************************************************************************************/
/* Event_Reception_Point */
/**************************************************************************************************/
class Event_Reception_Point {
/* Abstract class that shall be realized by a Component_Type that receive an Event. */
public :
    /* Constructor */
    Event_Reception_Point( void );
    Event_Reception_Point( void* x );

    virtual void On_Event_Reception( Event* ev ) = 0 ;
    
    /* Reference to the next Event_Reception_Point that shall be notified when Send() method of the
    Event is called. */
    Event_Reception_Point* Next_Receiver;
    
    /* Reference to the Component_Type that realize the Event_Reception_Point. */
    void* Parent;
};

#endif