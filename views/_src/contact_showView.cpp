#include <QtCore>
#include <TreeFrogView>
#include "contact.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT contact_showView : public TActionView
{
  Q_OBJECT
public:
  contact_showView() : TActionView() { }
  QString toString();
};

QString contact_showView::toString()
{
  responsebody.reserve(1595);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(Contact, contact);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Showing Contact</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(contact.id());
  responsebody += QStringLiteral("</dd><br />\n<dt>Phone</dt><dd>");
  responsebody += THttpUtility::htmlEscape(contact.phone());
  responsebody += QStringLiteral("</dd><br />\n<dt>Email</dt><dd>");
  responsebody += THttpUtility::htmlEscape(contact.email());
  responsebody += QStringLiteral("</dd><br />\n<dt>Location</dt><dd>");
  responsebody += THttpUtility::htmlEscape(contact.location());
  responsebody += QStringLiteral("</dd><br />\n<dt>Latitude</dt><dd>");
  responsebody += THttpUtility::htmlEscape(contact.latitude());
  responsebody += QStringLiteral("</dd><br />\n<dt>Longitude</dt><dd>");
  responsebody += THttpUtility::htmlEscape(contact.longitude());
  responsebody += QStringLiteral("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", contact.id()))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(contact_showView)

#include "contact_showView.moc"
