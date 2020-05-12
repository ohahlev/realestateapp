#include <TreeFrogModel>
#include "banner.h"
#include "sqlobjects/bannerobject.h"

Banner::Banner() :
    TAbstractModel(),
    d(new BannerObject())
{
    d->id = 0;
}

Banner::Banner(const Banner &other) :
    TAbstractModel(),
    d(other.d)
{ }

Banner::Banner(const BannerObject &object) :
    TAbstractModel(),
    d(new BannerObject(object))
{ }

Banner::~Banner()
{
    // If the reference count becomes 0,
    // the shared data object 'BannerObject' is deleted.
}

int Banner::id() const
{
    return d->id;
}

QString Banner::html() const
{
    return d->html;
}

void Banner::setHtml(const QString &html)
{
    d->html = html;
}

Banner &Banner::operator=(const Banner &other)
{
    d = other.d;  // increments the reference count of the data
    return *this;
}

Banner Banner::create(const QString &html)
{
    BannerObject obj;
    obj.html = html;
    if (!obj.create()) {
        return Banner();
    }
    return Banner(obj);
}

Banner Banner::create(const QVariantMap &values)
{
    Banner model;
    model.setProperties(values);
    if (!model.d->create()) {
        model.d->clear();
    }
    return model;
}

Banner Banner::get(int id)
{
    TSqlORMapper<BannerObject> mapper;
    return Banner(mapper.findByPrimaryKey(id));
}

int Banner::count()
{
    TSqlORMapper<BannerObject> mapper;
    return mapper.findCount();
}

QList<Banner> Banner::getAll()
{
    return tfGetModelListByCriteria<Banner, BannerObject>(TCriteria());
}

QJsonArray Banner::getAllJson()
{
    QJsonArray array;
    TSqlORMapper<BannerObject> mapper;

    if (mapper.find() > 0) {
        for (TSqlORMapperIterator<BannerObject> i(mapper); i.hasNext(); ) {
            array.append(QJsonValue(QJsonObject::fromVariantMap(Banner(i.next()).toVariantMap())));
        }
    }
    return array;
}

TModelObject *Banner::modelData()
{
    return d.data();
}

const TModelObject *Banner::modelData() const
{
    return d.data();
}

QDataStream &operator<<(QDataStream &ds, const Banner &model)
{
    auto varmap = model.toVariantMap();
    ds << varmap;
    return ds;
}

QDataStream &operator>>(QDataStream &ds, Banner &model)
{
    QVariantMap varmap;
    ds >> varmap;
    model.setProperties(varmap);
    return ds;
}

// Don't remove below this line
T_REGISTER_STREAM_OPERATORS(Banner)
