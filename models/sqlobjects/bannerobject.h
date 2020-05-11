#ifndef BANNEROBJECT_H
#define BANNEROBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT BannerObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    QString text;

    enum PropertyIndex {
        Id = 0,
        Text,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("banner"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString text READ gettext WRITE settext)
    T_DEFINE_PROPERTY(QString, text)
};

#endif // BANNEROBJECT_H
