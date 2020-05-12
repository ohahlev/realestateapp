#include <QtCore>
#include <TreeFrogView>
#include "featured.h"
#include "applicationhelper.h"

class T_VIEW_EXPORT partial_featuredView : public TActionView
{
  Q_OBJECT
public:
  partial_featuredView() : TActionView() { }
  QString toString();
};

QString partial_featuredView::toString()
{
  responsebody.reserve(664);
    tfetch(Featured, featured);
  responsebody += QStringLiteral("\n<div class=\"middle-w3l\" style=\"background: url(");
  responsebody += QVariant(featured.image()).toString();
  responsebody += QStringLiteral(") no-repeat right;\">\n  <div class=\"container-fluid\">\n    <div class=\"row\">\n      <div class=\"col-lg-6 col-md-4 button\">\n      </div>\n      <div class=\"col-lg-6 col-md-8 left-build-wthree py-5 px-sm-5 px-4\">\n        <div class=\"py-xl-5 py-lg-3 px-xl-4\">\n          ");
  responsebody += QVariant(featured.html()).toString();
  responsebody += QStringLiteral("\n        </div>          \n      </div>\n    </div>\n  </div>\n</div>\n");

  return responsebody;
}

T_DEFINE_VIEW(partial_featuredView)

#include "partial_featuredView.moc"
