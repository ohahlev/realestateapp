#include <TreeFrogModel>
#include "featured.h"
#include "sqlobjects/featuredobject.h"

Featured::Featured() :
    TAbstractModel(),
    d(new FeaturedObject())
{
    d->id = 0;
}

Featured::Featured(const Featured &other) :
    TAbstractModel(),
    d(other.d)
{ }

Featured::Featured(const FeaturedObject &object) :
    TAbstractModel(),
    d(new FeaturedObject(object))
{ }

Featured::~Featured()
{
    // If the reference count becomes 0,
    // the shared data object 'FeaturedObject' is deleted.
}

int Featured::id() const
{
    return d->id;
}

QString Featured::image() const
{
    return d->image;
}

void Featured::setImage(const QString &image)
{
    d->image = image;
}

QString Featured::html() const
{
    return d->html;
}

void Featured::setHtml(const QString &html)
{
    d->html = html;
}

Featured &Featured::operator=(const Featured &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Featured Featured::create(const QString &image, const QString &html)
{
    FeaturedObject obj;
    obj.image = image;
    obj.html = html;
    if (!obj.create()) {
        return Featured();
    }
    return Featured(obj);
}

Featured Featured::create(const QVariantMap &values)
{
    Featured model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Featured Featured::get(int id)
{
    TSqlORMapper<FeaturedObject> mapper;
    return Featured(mapper.findByPrimaryKey(id));
}

int Featured::count()
{
    TSqlORMapper<FeaturedObject> mapper;
    return mapper.findCount();
}

QList<Featured> Featured::getAll()
{
    return tfGetModelListByCriteria<Featured, FeaturedObject>(TCriteria());
}

QJsonArray Featured::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<FeaturedObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<FeaturedObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Featured(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Featured::modelData()
{
    return d.data();
}

const TModelObject *Featured::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Featured &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Featured &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Featured)
