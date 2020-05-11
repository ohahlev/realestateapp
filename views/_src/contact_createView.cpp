#include <QtCore>
#include <TreeFrogView>
#include "contact.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT contact_createView : public TActionView
{
  Q_OBJECT
public:
  contact_createView() : TActionView() { }
  QString toString();
};

QString contact_createView::toString()
{
  responsebody.reserve(1849);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, contact);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>New Contact</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>Phone<br /><input name=\"contact[phone]\" value=\"");
  responsebody += THttpUtility::htmlEscape(contact["phone"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Email<br /><input name=\"contact[email]\" value=\"");
  responsebody += THttpUtility::htmlEscape(contact["email"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Location<br /><input name=\"contact[location]\" value=\"");
  responsebody += THttpUtility::htmlEscape(contact["location"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Latitude<br /><input name=\"contact[latitude]\" value=\"");
  responsebody += THttpUtility::htmlEscape(contact["latitude"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Longitude<br /><input name=\"contact[longitude]\" value=\"");
  responsebody += THttpUtility::htmlEscape(contact["longitude"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(contact_createView)

#include "contact_createView.moc"
