#include "servicecontroller.h"
#include "service.h"


void ServiceController::index()
{
    auto serviceList = Service::getAll();
    texport(serviceList);
    render();
}

void ServiceController::show(const QString &id)
{
    auto service = Service::get(id.toInt());
    texport(service);
    render();
}

void ServiceController::create()
{
    switch (httpRequest().method()) {
    case Tf::Get:
        render();
        break;

    case Tf::Post: {
        auto service = httpRequest().formItems("service");
        auto model = Service::create(service);

        if (!model.isNull()) {
            QString notice = "Created successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            QString error = "Failed to create.";
            texport(error);
            texport(service);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void ServiceController::save(const QString &id)
{
    switch (httpRequest().method()) {
    case Tf::Get: {
        auto model = Service::get(id.toInt());
        if (!model.isNull()) {
            auto service = model.toVariantMap();
            texport(service);
            render();
        }
        break; }

    case Tf::Post: {
        QString error;
        auto model = Service::get(id.toInt());
        
        if (model.isNull()) {
            error = "Original data not found. It may have been updated/removed by another transaction.";
            tflash(error);
            redirect(urla("save", id));
            break;
        }

        auto service = httpRequest().formItems("service");
        model.setProperties(service);
        if (model.save()) {
            QString notice = "Updated successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            error = "Failed to update.";
            texport(error);
            texport(service);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void ServiceController::remove(const QString &id)
{
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto service = Service::get(id.toInt());
    service.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_DEFINE_CONTROLLER(ServiceController)
