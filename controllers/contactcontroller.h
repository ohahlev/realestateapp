#ifndef CONTACTCONTROLLER_H
#define CONTACTCONTROLLER_H

#include "applicationcontroller.h"


class T_CONTROLLER_EXPORT ContactController : public ApplicationController
{
    Q_OBJECT
public:
    ContactController() : ApplicationController() {}

public slots:
    void index();
    void show(const QString &id);
    void create();
    void save(const QString &id);
    void remove(const QString &id);
};

#endif // CONTACTCONTROLLER_H
