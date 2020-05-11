#include "contactcontroller.h"
#include "contact.h"


void ContactController::index()
{
    auto contactList = Contact::getAll();
    texport(contactList);
    render();
}

void ContactController::show(const QString &id)
{
    auto contact = Contact::get(id.toInt());
    texport(contact);
    render();
}

void ContactController::create()
{
    switch (httpRequest().method()) {
    case Tf::Get:
        render();
        break;

    case Tf::Post: {
        auto contact = httpRequest().formItems("contact");
        auto model = Contact::create(contact);

        if (!model.isNull()) {
            QString notice = "Created successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            QString error = "Failed to create.";
            texport(error);
            texport(contact);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void ContactController::save(const QString &id)
{
    switch (httpRequest().method()) {
    case Tf::Get: {
        auto model = Contact::get(id.toInt());
        if (!model.isNull()) {
            auto contact = model.toVariantMap();
            texport(contact);
            render();
        }
        break; }

    case Tf::Post: {
        QString error;
        auto model = Contact::get(id.toInt());
        
        if (model.isNull()) {
            error = "Original data not found. It may have been updated/removed by another transaction.";
            tflash(error);
            redirect(urla("save", id));
            break;
        }

        auto contact = httpRequest().formItems("contact");
        model.setProperties(contact);
        if (model.save()) {
            QString notice = "Updated successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            error = "Failed to update.";
            texport(error);
            texport(contact);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void ContactController::remove(const QString &id)
{
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto contact = Contact::get(id.toInt());
    contact.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_DEFINE_CONTROLLER(ContactController)
