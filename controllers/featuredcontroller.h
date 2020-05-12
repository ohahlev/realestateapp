#ifndef FEATUREDCONTROLLER_H
#define FEATUREDCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT FeaturedController : public ApplicationController
{
    Q_OBJECT
public:
    FeaturedController() : ApplicationController() {}

public slots:
    void index();
    void show(const QString &id);
    void create();
    void save(const QString &id);
    void remove(const QString &id);
};

#endif // FEATUREDCONTROLLER_H
