#include "Event.h"

/**************************************************************************************************/
/* Event */
/**************************************************************************************************/
Event::Event( void )
{
    /* Initialize the receivers list (empty). */
    this->Reception_Point_List = nullptr;
}

void Event::Send( void )
{ /* Browse all the reception points associated to this Event and call their reception method. */

    Event_Reception_Point* current_point;
    
    /* Take the first reception point of the list. */
    current_point = this->Reception_Point_List;
    
    /* Test if the end of the list is reached. */
    while( current_point != nullptr )
    { /* End of the list is not reached. */

        /* Call the reception method. */
        current_point->On_Event_Reception(this);
        
        /* Take the next element of the list. */
        current_point = current_point->Next_Receiver;
    }
}

void Event::Add_Event_Reception_Point( Event_Reception_Point* reception_point )
{ /* Add a receiver of this Event */

    Event_Reception_Point** current_point = nullptr;
    
    /* Take the reference to the first receiver. */
    current_point = &(this->Reception_Point_List);
    
    /* Test if it is the last receiver. */
    while( *current_point != nullptr )
    { /* Current receiver is not the last. */

        /* Take the reference to the next receiver. */
        current_point = &((*current_point)->Next_Receiver);
    }
    
    /* Add the new receiver add the end of this Event list. */
    *current_point = reception_point;
}


/**************************************************************************************************/
/* Event_Reception_Point */
/**************************************************************************************************/
Event_Reception_Point::Event_Reception_Point( void )
{
    this->Next_Receiver = nullptr;
    this->Parent = nullptr;
}

Event_Reception_Point::Event_Reception_Point( void* x )
{
    this->Next_Receiver = nullptr;
    this->Parent = x;
}
