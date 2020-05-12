#ifndef SERVICEOBJECT_H
#define SERVICEOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT ServiceObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    QString icon;
    QString name;
    QString subline;

    enum PropertyIndex {
        Id = 0,
        Icon,
        Name,
        Subline,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("service"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString icon READ geticon WRITE seticon)
    T_DEFINE_PROPERTY(QString, icon)
    Q_PROPERTY(QString name READ getname WRITE setname)
    T_DEFINE_PROPERTY(QString, name)
    Q_PROPERTY(QString subline READ getsubline WRITE setsubline)
    T_DEFINE_PROPERTY(QString, subline)
};

#endif // SERVICEOBJECT_H
