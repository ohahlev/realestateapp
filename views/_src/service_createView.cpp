#include <QtCore>
#include <TreeFrogView>
#include "service.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT service_createView : public TActionView
{
  Q_OBJECT
public:
  service_createView() : TActionView() { }
  QString toString();
};

QString service_createView::toString()
{
  responsebody.reserve(1437);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, service);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>New Service</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>Icon<br /><input name=\"service[icon]\" value=\"");
  responsebody += THttpUtility::htmlEscape(service["icon"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Name<br /><input name=\"service[name]\" value=\"");
  responsebody += THttpUtility::htmlEscape(service["name"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Subline<br /><input name=\"service[subline]\" value=\"");
  responsebody += THttpUtility::htmlEscape(service["subline"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(service_createView)

#include "service_createView.moc"
