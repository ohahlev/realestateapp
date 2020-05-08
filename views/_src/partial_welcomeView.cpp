#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT partial_welcomeView : public TActionView
{
  Q_OBJECT
public:
  partial_welcomeView() : TActionView() { }
  QString toString();
};

QString partial_welcomeView::toString()
{
  responsebody.reserve(68);
  responsebody += QStringLiteral("<h1> welcome to ahlev1111</h1>");

  return responsebody;
}

T_DEFINE_VIEW(partial_welcomeView)

#include "partial_welcomeView.moc"
