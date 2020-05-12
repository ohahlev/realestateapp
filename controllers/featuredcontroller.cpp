#include "featuredcontroller.h"
#include "featured.h"


void FeaturedController::index()
{
    auto featuredList = Featured::getAll();
    texport(featuredList);
    render();
}

void FeaturedController::show(const QString &id)
{
    auto featured = Featured::get(id.toInt());
    texport(featured);
    render();
}

void FeaturedController::create()
{
    switch (httpRequest().method()) {
    case Tf::Get:
        render();
        break;

    case Tf::Post: {
        auto featured = httpRequest().formItems("featured");
        auto model = Featured::create(featured);

        if (!model.isNull()) {
            QString notice = "Created successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            QString error = "Failed to create.";
            texport(error);
            texport(featured);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void FeaturedController::save(const QString &id)
{
    switch (httpRequest().method()) {
    case Tf::Get: {
        auto model = Featured::get(id.toInt());
        if (!model.isNull()) {
            auto featured = model.toVariantMap();
            texport(featured);
            render();
        }
        break; }

    case Tf::Post: {
        QString error;
        auto model = Featured::get(id.toInt());
        
        if (model.isNull()) {
            error = "Original data not found. It may have been updated/removed by another transaction.";
            tflash(error);
            redirect(urla("save", id));
            break;
        }

        auto featured = httpRequest().formItems("featured");
        model.setProperties(featured);
        if (model.save()) {
            QString notice = "Updated successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            error = "Failed to update.";
            texport(error);
            texport(featured);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void FeaturedController::remove(const QString &id)
{
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto featured = Featured::get(id.toInt());
    featured.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_DEFINE_CONTROLLER(FeaturedController)
