#include "applicationcontroller.h"
#include "contact.h"

ApplicationController::ApplicationController()
    : TActionController()
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
}

ApplicationController::~ApplicationController()
{ }

void ApplicationController::staticInitialize()
{ }

void ApplicationController::staticRelease()
{ }

bool ApplicationController::preFilter()
{
    return true;
}

// Don't remove below this line
T_DEFINE_CONTROLLER(ApplicationController)
