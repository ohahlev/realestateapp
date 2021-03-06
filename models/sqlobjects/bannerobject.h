#ifndef BANNEROBJECT_H
#define BANNEROBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT BannerObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    QString html;

    enum PropertyIndex {
        Id = 0,
        Html,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("banner"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString html READ gethtml WRITE sethtml)
    T_DEFINE_PROPERTY(QString, html)
};

#endif // BANNEROBJECT_H
