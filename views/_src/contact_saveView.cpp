#include <QtCore>
#include <TreeFrogView>
#include "contact.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT contact_saveView : public TActionView
{
  Q_OBJECT
public:
  contact_saveView() : TActionView() { }
  QString toString();
};

QString contact_saveView::toString()
{
  responsebody.reserve(2701);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, contact);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Editing Contact</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", contact["id"]), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"contact[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(contact["id"]);
  responsebody += QStringLiteral("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Phone<br /><input type=\"text\" name=\"contact[phone]\" value=\"");
  responsebody += THttpUtility::htmlEscape(contact["phone"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Email<br /><input type=\"text\" name=\"contact[email]\" value=\"");
  responsebody += THttpUtility::htmlEscape(contact["email"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Location<br /><input type=\"text\" name=\"contact[location]\" value=\"");
  responsebody += THttpUtility::htmlEscape(contact["location"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Latitude<br /><input type=\"text\" name=\"contact[latitude]\" value=\"");
  responsebody += THttpUtility::htmlEscape(contact["latitude"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Longitude<br /><input type=\"text\" name=\"contact[longitude]\" value=\"");
  responsebody += THttpUtility::htmlEscape(contact["longitude"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Facebook<br /><input type=\"text\" name=\"contact[facebook]\" value=\"");
  responsebody += THttpUtility::htmlEscape(contact["facebook"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Youtube<br /><input type=\"text\" name=\"contact[youtube]\" value=\"");
  responsebody += THttpUtility::htmlEscape(contact["youtube"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Save\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", contact["id"]))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(contact_saveView)

#include "contact_saveView.moc"
