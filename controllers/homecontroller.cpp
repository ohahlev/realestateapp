#include "homecontroller.h"
#include "contact.h"

void HomeController::index()
{   
    // get all contacts
    QList<Contact> contactList = Contact::getAll();
    
    // check if no contact found in database
    if(contactList.length() == 0) {
        renderErrorResponse(Tf::NotFound);
        return;
    }
    
    // pass contact to view
    Contact contact = contactList.at(0);
    texport(contact);
    render();
}

// Don't remove below this line
T_DEFINE_CONTROLLER(HomeController)
