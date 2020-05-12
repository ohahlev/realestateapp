#ifndef FEATUREDOBJECT_H
#define FEATUREDOBJECT_H

#include <TSqlObject>
#include <QSharedData>


class T_MODEL_EXPORT FeaturedObject : public TSqlObject, public QSharedData
{
public:
    int id {0};
    QString image;
    QString html;

    enum PropertyIndex {
        Id = 0,
        Image,
        Html,
    };

    int primaryKeyIndex() const override { return Id; }
    int autoValueIndex() const override { return Id; }
    QString tableName() const override { return QStringLiteral("featured"); }

private:    /*** Don't modify below this line ***/
    Q_OBJECT
    Q_PROPERTY(int id READ getid WRITE setid)
    T_DEFINE_PROPERTY(int, id)
    Q_PROPERTY(QString image READ getimage WRITE setimage)
    T_DEFINE_PROPERTY(QString, image)
    Q_PROPERTY(QString html READ gethtml WRITE sethtml)
    T_DEFINE_PROPERTY(QString, html)
};

#endif // FEATUREDOBJECT_H
