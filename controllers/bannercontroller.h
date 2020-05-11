#ifndef BANNERCONTROLLER_H
#define BANNERCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT BannerController : public ApplicationController
{
    Q_OBJECT
public:
    BannerController() : ApplicationController() {}

public slots:
    void index();
    void show(const QString &id);
    void create();
    void save(const QString &id);
    void remove(const QString &id);
};

#endif // BANNERCONTROLLER_H
