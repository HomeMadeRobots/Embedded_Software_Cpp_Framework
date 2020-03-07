#ifndef ASYNCHRONOUS_OPERATION_MANAGER_H
#define ASYNCHRONOUS_OPERATION_MANAGER_H


class Asynchronous_Operation_Manager {

public :
    Asynchronous_Operation_Manager( void );
    Asynchronous_Operation_Manager( void* parent );

    /* Server operations */
    void Srv_Notify_Operation_Finished( bool status );

    /* Callback, realized by the client, called by the server */
    virtual void Callback( bool status ) = 0 ;

protected :
    void* Client_Parent;
};

#endif