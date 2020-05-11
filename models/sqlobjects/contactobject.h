#ifndef CONTACTOBJECT_H
#define CONTACTOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ContactObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    QString phone;
    QString email;
    QString location;
    double latitude {0};
    double longitude {0};

    enum PropertyIndex {
        Id = 0,
        Phone,
        Email,
        Location,
        Latitude,
        Longitude,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("contact"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString phone READ getphone WRITE setphone)
    T_DEFINE_PROPERTY(QString, phone)
    Q_PROPERTY(QString email READ getemail WRITE setemail)
    T_DEFINE_PROPERTY(QString, email)
    Q_PROPERTY(QString location READ getlocation WRITE setlocation)
    T_DEFINE_PROPERTY(QString, location)
    Q_PROPERTY(double latitude READ getlatitude WRITE setlatitude)
    T_DEFINE_PROPERTY(double, latitude)
    Q_PROPERTY(double longitude READ getlongitude WRITE setlongitude)
    T_DEFINE_PROPERTY(double, longitude)
};

#endif // CONTACTOBJECT_H
