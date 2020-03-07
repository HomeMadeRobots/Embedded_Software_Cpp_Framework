#include "Asynchronous_Operation_Manager.h"

Asynchronous_Operation_Manager::Asynchronous_Operation_Manager( void )
{
}

Asynchronous_Operation_Manager::Asynchronous_Operation_Manager( void* parent )
{
    this->Client_Parent = parent;
}

/* Server operations */
void Asynchronous_Operation_Manager::Srv_Notify_Operation_Finished( bool status )
{
    this->Callback( status );
}
