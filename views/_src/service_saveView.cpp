#include <QtCore>
#include <TreeFrogView>
#include "service.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT service_saveView : public TActionView
{
  Q_OBJECT
public:
  service_saveView() : TActionView() { }
  QString toString();
};

QString service_saveView::toString()
{
  responsebody.reserve(1836);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, service);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Editing Service</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", service["id"]), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"service[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(service["id"]);
  responsebody += QStringLiteral("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Icon<br /><input type=\"text\" name=\"service[icon]\" value=\"");
  responsebody += THttpUtility::htmlEscape(service["icon"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Name<br /><input type=\"text\" name=\"service[name]\" value=\"");
  responsebody += THttpUtility::htmlEscape(service["name"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Subline<br /><input type=\"text\" name=\"service[subline]\" value=\"");
  responsebody += THttpUtility::htmlEscape(service["subline"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Save\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", service["id"]))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(service_saveView)

#include "service_saveView.moc"
