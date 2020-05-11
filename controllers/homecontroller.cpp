#include "homecontroller.h"
#include "contact.h"
#include "banner.h"

void HomeController::index()
{   
    // get banner list from database
    QList<Banner> bannerList = Banner::getAll();

    // check if there is no banner information
    if(bannerList.length() == 0) {
        renderErrorResponse(Tf::NotFound);
        return;
    }

    // pass banner to view
    Banner banner = bannerList.at(0);
    texport(banner);
    render();
}

// Don't remove below this line
T_DEFINE_CONTROLLER(HomeController)
