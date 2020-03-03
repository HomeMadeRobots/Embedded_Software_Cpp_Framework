#include "Event.h"

Event::Event( void )
{
    this->Reception_Point_List = 0;
}

void Event::Send( void )
{
    Event_Reception_Point* current_point;
    current_point = this->Reception_Point_List;
    while( current_point != 0 )
    {
        current_point->On_Event_Reception(this);
        current_point = current_point->Next_Receiver;
    }
}

void Event::Add_Event_Reception_Point( Event_Reception_Point* reception_point )
{
    Event_Reception_Point** current_point = 0;
    current_point = &(this->Reception_Point_List);
    while( *current_point != 0 )
    {
        current_point = &((*current_point)->Next_Receiver);
    }
    *current_point = reception_point;
}