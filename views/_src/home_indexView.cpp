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
  responsebody.reserve(183);
  responsebody += QStringLiteral("<h1>this is from home page</h1>\n");
  responsebody += QVariant(renderPartial("middle_section")).toString();
  responsebody += QStringLiteral("\n");

  return responsebody;
}

T_DEFINE_VIEW(home_indexView)

#include "home_indexView.moc"
