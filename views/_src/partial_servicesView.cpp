#include <QtCore>
#include <TreeFrogView>
#include "service.h"
#include "applicationhelper.h"

class T_VIEW_EXPORT partial_servicesView : public TActionView
{
  Q_OBJECT
public:
  partial_servicesView() : TActionView() { }
  QString toString();
};

QString partial_servicesView::toString()
{
  responsebody.reserve(1188);
    tfetch(QList<Service>, services);
  responsebody += QStringLiteral("<div class=\"what-w3ls py-5\" id=\"services\">\n  <div class=\"container py-xl-5 py-lg-3\">\n    <div class=\"text-center mb-md-5 mb-4\">\n      <h3 class=\"tittle mb-sm-2\">Our Services</h3>\n      <p>Some words about our property services</p>\n    </div>\n    <div class=\"row\">\n      ");
  for (const auto &i : services) {
  responsebody += QStringLiteral("        <div class=\"col-md-6\">\n          <div class=\"row what-top my-md-5 my-4\">\n            <div class=\"col-2 what-left\">\n              <i class=\"");
  responsebody += THttpUtility::htmlEscape(i.icon());
  responsebody += QStringLiteral("\"></i>\n            </div>\n            <div class=\"col-10 what-right\">\n              <h4>");
  responsebody += THttpUtility::htmlEscape(i.name());
  responsebody += QStringLiteral("</h4>\n              <p class=\"mt-2\">\n                ");
  responsebody += THttpUtility::htmlEscape(i.subline());
  responsebody += QStringLiteral("\n              </p>\n            </div>\n          </div>\n        </div>\n        ");
  };
  responsebody += QStringLiteral("      </div>\n    </div>\n  </div>\n");

  return responsebody;
}

T_DEFINE_VIEW(partial_servicesView)

#include "partial_servicesView.moc"
