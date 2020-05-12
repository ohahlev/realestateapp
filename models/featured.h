#ifndef FEATURED_H
#define FEATURED_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class FeaturedObject;
class QJsonArray;


class T_MODEL_EXPORT Featured : public TAbstractModel
{
public:
    Featured();
    Featured(const Featured &other);
    Featured(const FeaturedObject &object);
    ~Featured();

    int id() const;
    QString image() const;
    void setImage(const QString &image);
    QString html() const;
    void setHtml(const QString &html);
    Featured &operator=(const Featured &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Featured create(const QString &image, const QString &html);
    static Featured create(const QVariantMap &values);
    static Featured get(int id);
    static int count();
    static QList<Featured> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<FeaturedObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Featured &model);
    friend QDataStream &operator>>(QDataStream &ds, Featured &model);
};

Q_DECLARE_METATYPE(Featured)
Q_DECLARE_METATYPE(QList<Featured>)

#endif // FEATURED_H
