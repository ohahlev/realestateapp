#include "homecontroller.h"
#include "contact.h"
#include "banner.h"
#include "featured.h"
#include "service.h"

void HomeController::index()
{
    /**
     * banner
     */

    // get banner list from database
    QList<Banner> bannerList = Banner::getAll();

    // check if there is banner info
    if(bannerList.length() == 0) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    // pass banner to view
    Banner banner = bannerList.at(0);
    texport(banner);

    /**
     * featured
     */

    QList<Featured> featuredList = Featured::getAll();
    if(featuredList.length() == 0) {
        renderErrorResponse(Tf::NotFound);
        return;
    }
    Featured featured = featuredList.at(0);
    texport(featured);

    /**
     * service
     */

    QList<Service> services = Service::getAll();
    if(services.length() == 0) {
        renderErrorResponse(Tf::NotFound);
        return;
    }
    texport(services);

    render();
}

// Don't remove below this line
T_DEFINE_CONTROLLER(HomeController)
