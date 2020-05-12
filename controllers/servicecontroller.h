#ifndef SERVICECONTROLLER_H
#define SERVICECONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ServiceController : public ApplicationController
{
    Q_OBJECT
public:
    ServiceController() : ApplicationController() {}

public slots:
    void index();
    void show(const QString &id);
    void create();
    void save(const QString &id);
    void remove(const QString &id);
};

#endif // SERVICECONTROLLER_H
