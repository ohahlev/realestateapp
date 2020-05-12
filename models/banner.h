#ifndef BANNER_H
#define BANNER_H

#include <QStringList>
#include <QDateTime>
#include <QVariant>
#include <QSharedDataPointer>
#include <TGlobal>
#include <TAbstractModel>

class TModelObject;
class BannerObject;
class QJsonArray;


class T_MODEL_EXPORT Banner : public TAbstractModel
{
public:
    Banner();
    Banner(const Banner &other);
    Banner(const BannerObject &object);
    ~Banner();

    int id() const;
    QString html() const;
    void setHtml(const QString &html);
    Banner &operator=(const Banner &other);

    bool create() override { return TAbstractModel::create(); }
    bool update() override { return TAbstractModel::update(); }
    bool save()   override { return TAbstractModel::save(); }
    bool remove() override { return TAbstractModel::remove(); }

    static Banner create(const QString &html);
    static Banner create(const QVariantMap &values);
    static Banner get(int id);
    static int count();
    static QList<Banner> getAll();
    static QJsonArray getAllJson();

private:
    QSharedDataPointer<BannerObject> d;

    TModelObject *modelData() override;
    const TModelObject *modelData() const override;
    friend QDataStream &operator<<(QDataStream &ds, const Banner &model);
    friend QDataStream &operator>>(QDataStream &ds, Banner &model);
};

Q_DECLARE_METATYPE(Banner)
Q_DECLARE_METATYPE(QList<Banner>)

#endif // BANNER_H
