#ifndef SERVICE_H
#define SERVICE_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ServiceObject;
class QJsonArray;


class T_MODEL_EXPORT Service : public TAbstractModel
{
public:
    Service();
    Service(const Service &other);
    Service(const ServiceObject &object);
    ~Service();

    int id() const;
    QString icon() const;
    void setIcon(const QString &icon);
    QString name() const;
    void setName(const QString &name);
    QString subline() const;
    void setSubline(const QString &subline);
    Service &operator=(const Service &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Service create(const QString &icon, const QString &name, const QString &subline);
    static Service create(const QVariantMap &values);
    static Service get(int id);
    static int count();
    static QList<Service> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<ServiceObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Service &model);
    friend QDataStream &operator>>(QDataStream &ds, Service &model);
};

Q_DECLARE_METATYPE(Service)
Q_DECLARE_METATYPE(QList<Service>)

#endif // SERVICE_H
