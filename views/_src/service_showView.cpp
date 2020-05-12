#include <QtCore>
#include <TreeFrogView>
#include "service.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT service_showView : public TActionView
{
  Q_OBJECT
public:
  service_showView() : TActionView() { }
  QString toString();
};

QString service_showView::toString()
{
  responsebody.reserve(1315);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(Service, service);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Showing Service</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(service.id());
  responsebody += QStringLiteral("</dd><br />\n<dt>Icon</dt><dd>");
  responsebody += THttpUtility::htmlEscape(service.icon());
  responsebody += QStringLiteral("</dd><br />\n<dt>Name</dt><dd>");
  responsebody += THttpUtility::htmlEscape(service.name());
  responsebody += QStringLiteral("</dd><br />\n<dt>Subline</dt><dd>");
  responsebody += THttpUtility::htmlEscape(service.subline());
  responsebody += QStringLiteral("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", service.id()))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(service_showView)

#include "service_showView.moc"
