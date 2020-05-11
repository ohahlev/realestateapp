#include <TreeFrogModel>
#include "contact.h"
#include "sqlobjects/contactobject.h"

Contact::Contact() :
    TAbstractModel(),
    d(new ContactObject())
{
    d->id = 0;
    d->latitude = 0;
    d->longitude = 0;
}

Contact::Contact(const Contact &other) :
    TAbstractModel(),
    d(other.d)
{ }

Contact::Contact(const ContactObject &object) :
    TAbstractModel(),
    d(new ContactObject(object))
{ }

Contact::~Contact()
{
    // If the reference count becomes 0,
    // the shared data object 'ContactObject' is deleted.
}

int Contact::id() const
{
    return d->id;
}

QString Contact::phone() const
{
    return d->phone;
}

void Contact::setPhone(const QString &phone)
{
    d->phone = phone;
}

QString Contact::email() const
{
    return d->email;
}

void Contact::setEmail(const QString &email)
{
    d->email = email;
}

QString Contact::location() const
{
    return d->location;
}

void Contact::setLocation(const QString &location)
{
    d->location = location;
}

double Contact::latitude() const
{
    return d->latitude;
}

void Contact::setLatitude(double latitude)
{
    d->latitude = latitude;
}

double Contact::longitude() const
{
    return d->longitude;
}

void Contact::setLongitude(double longitude)
{
    d->longitude = longitude;
}

Contact &Contact::operator=(const Contact &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Contact Contact::create(const QString &phone, const QString &email, const QString &location, double latitude, double longitude)
{
    ContactObject obj;
    obj.phone = phone;
    obj.email = email;
    obj.location = location;
    obj.latitude = latitude;
    obj.longitude = longitude;
    if (!obj.create()) {
        return Contact();
    }
    return Contact(obj);
}

Contact Contact::create(const QVariantMap &values)
{
    Contact model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Contact Contact::get(int id)
{
    TSqlORMapper<ContactObject> mapper;
    return Contact(mapper.findByPrimaryKey(id));
}

int Contact::count()
{
    TSqlORMapper<ContactObject> mapper;
    return mapper.findCount();
}

QList<Contact> Contact::getAll()
{
    return tfGetModelListByCriteria<Contact, ContactObject>(TCriteria());
}

QJsonArray Contact::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<ContactObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<ContactObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Contact(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Contact::modelData()
{
    return d.data();
}

const TModelObject *Contact::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Contact &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Contact &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Contact)
