#ifndef ASYNCHRONOUS_OPERATION_MANAGER_H
#define ASYNCHRONOUS_OPERATION_MANAGER_H


class Asynchronous_Operation_Manager {
/* Shall be used (by reference) as the first parameter of an Asynchronous_Operation. */
/* For each used Asynchronous_Operation a Component_Type (the client) shall realize this abstract 
class and pass the reference to its object to the provider Component_Type (the server). */
public :
    Asynchronous_Operation_Manager( void );
    Asynchronous_Operation_Manager( void* parent );

    /* Server operations */
    void Srv_Notify_Operation_Finished( bool status );

    /* Callback, realized by the client, called by the server */
    virtual void Callback( bool status ) = 0;

protected :
    /* Reference to the Compponent_Type that call the Asynchronous_Operation. */
    void* Client_Parent;
};

#endif