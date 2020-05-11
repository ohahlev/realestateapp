#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT home_indexView : public TActionView
{
  Q_OBJECT
public:
  home_indexView() : TActionView() { }
  QString toString();
};

QString home_indexView::toString()
{
  responsebody.reserve(490);
  responsebody += QVariant(renderPartial("featured")).toString();
  responsebody += QStringLiteral("\n");
  responsebody += QVariant(renderPartial("services")).toString();
  responsebody += QStringLiteral("\n");
  responsebody += QVariant(renderPartial("pricing")).toString();
  responsebody += QStringLiteral("\n");
  responsebody += QVariant(renderPartial("stats")).toString();
  responsebody += QStringLiteral("\n");
  responsebody += QVariant(renderPartial("testimonials")).toString();

  return responsebody;
}

T_DEFINE_VIEW(home_indexView)

#include "home_indexView.moc"
