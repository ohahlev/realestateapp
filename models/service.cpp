#include <TreeFrogModel>
#include "service.h"
#include "sqlobjects/serviceobject.h"

Service::Service() :
    TAbstractModel(),
    d(new ServiceObject())
{
    d->id = 0;
}

Service::Service(const Service &other) :
    TAbstractModel(),
    d(other.d)
{ }

Service::Service(const ServiceObject &object) :
    TAbstractModel(),
    d(new ServiceObject(object))
{ }

Service::~Service()
{
    // If the reference count becomes 0,
    // the shared data object 'ServiceObject' is deleted.
}

int Service::id() const
{
    return d->id;
}

QString Service::icon() const
{
    return d->icon;
}

void Service::setIcon(const QString &icon)
{
    d->icon = icon;
}

QString Service::name() const
{
    return d->name;
}

void Service::setName(const QString &name)
{
    d->name = name;
}

QString Service::subline() const
{
    return d->subline;
}

void Service::setSubline(const QString &subline)
{
    d->subline = subline;
}

Service &Service::operator=(const Service &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Service Service::create(const QString &icon, const QString &name, const QString &subline)
{
    ServiceObject obj;
    obj.icon = icon;
    obj.name = name;
    obj.subline = subline;
    if (!obj.create()) {
        return Service();
    }
    return Service(obj);
}

Service Service::create(const QVariantMap &values)
{
    Service model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Service Service::get(int id)
{
    TSqlORMapper<ServiceObject> mapper;
    return Service(mapper.findByPrimaryKey(id));
}

int Service::count()
{
    TSqlORMapper<ServiceObject> mapper;
    return mapper.findCount();
}

QList<Service> Service::getAll()
{
    return tfGetModelListByCriteria<Service, ServiceObject>(TCriteria());
}

QJsonArray Service::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<ServiceObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<ServiceObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Service(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Service::modelData()
{
    return d.data();
}

const TModelObject *Service::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Service &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Service &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Service)
