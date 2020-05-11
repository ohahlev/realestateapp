#include "bannercontroller.h"
#include "banner.h"


void BannerController::index()
{
    auto bannerList = Banner::getAll();
    texport(bannerList);
    render();
}

void BannerController::show(const QString &id)
{
    auto banner = Banner::get(id.toInt());
    texport(banner);
    render();
}

void BannerController::create()
{
    switch (httpRequest().method()) {
    case Tf::Get:
        render();
        break;

    case Tf::Post: {
        auto banner = httpRequest().formItems("banner");
        auto model = Banner::create(banner);

        if (!model.isNull()) {
            QString notice = "Created successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            QString error = "Failed to create.";
            texport(error);
            texport(banner);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void BannerController::save(const QString &id)
{
    switch (httpRequest().method()) {
    case Tf::Get: {
        auto model = Banner::get(id.toInt());
        if (!model.isNull()) {
            auto banner = model.toVariantMap();
            texport(banner);
            render();
        }
        break; }

    case Tf::Post: {
        QString error;
        auto model = Banner::get(id.toInt());
        
        if (model.isNull()) {
            error = "Original data not found. It may have been updated/removed by another transaction.";
            tflash(error);
            redirect(urla("save", id));
            break;
        }

        auto banner = httpRequest().formItems("banner");
        model.setProperties(banner);
        if (model.save()) {
            QString notice = "Updated successfully.";
            tflash(notice);
            redirect(urla("show", model.id()));
        } else {
            error = "Failed to update.";
            texport(error);
            texport(banner);
            render();
        }
        break; }

    default:
        renderErrorResponse(Tf::NotFound);
        break;
    }
}

void BannerController::remove(const QString &id)
{
    if (httpRequest().method() != Tf::Post) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    auto banner = Banner::get(id.toInt());
    banner.remove();
    redirect(urla("index"));
}


// Don't remove below this line
T_DEFINE_CONTROLLER(BannerController)
