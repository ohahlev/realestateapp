#ifndef CONTACT_H
#define CONTACT_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class ContactObject;
class QJsonArray;


class T_MODEL_EXPORT Contact : public TAbstractModel
{
public:
    Contact();
    Contact(const Contact &other);
    Contact(const ContactObject &object);
    ~Contact();

    int id() const;
    QString phone() const;
    void setPhone(const QString &phone);
    QString email() const;
    void setEmail(const QString &email);
    QString location() const;
    void setLocation(const QString &location);
    double latitude() const;
    void setLatitude(double latitude);
    double longitude() const;
    void setLongitude(double longitude);
    QString facebook() const;
    void setFacebook(const QString &facebook);
    QString youtube() const;
    void setYoutube(const QString &youtube);
    Contact &operator=(const Contact &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Contact create(const QString &phone, const QString &email, const QString &location, double latitude, double longitude, const QString &facebook, const QString &youtube);
    static Contact create(const QVariantMap &values);
    static Contact get(int id);
    static int count();
    static QList<Contact> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<ContactObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Contact &model);
    friend QDataStream &operator>>(QDataStream &ds, Contact &model);
};

Q_DECLARE_METATYPE(Contact)
Q_DECLARE_METATYPE(QList<Contact>)

#endif // CONTACT_H
