#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT partial_topView : public TActionView
{
  Q_OBJECT
public:
  partial_topView() : TActionView() { }
  QString toString();
};

QString partial_topView::toString()
{
  responsebody.reserve(532);
  responsebody += QStringLiteral("<div class=\"bannerbg-w3l\">\n  <header>\n    <div class=\"header_topw3layouts_bar\">\n      <div class=\"container\">\n        ");
  responsebody += QVariant(renderPartial("header")).toString();
  responsebody += QStringLiteral("\n        ");
  responsebody += QVariant(renderPartial("nav")).toString();
  responsebody += QStringLiteral("\n      </div>\n    </div>\n  </header>\n  ");
  responsebody += QVariant(renderPartial("banner")).toString();
  responsebody += QStringLiteral("\n</div>\n");

  return responsebody;
}

T_DEFINE_VIEW(partial_topView)

#include "partial_topView.moc"
