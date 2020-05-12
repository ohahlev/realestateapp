#include <QtCore>
#include <TreeFrogView>
#include "featured.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT featured_saveView : public TActionView
{
  Q_OBJECT
public:
  featured_saveView() : TActionView() { }
  QString toString();
};

QString featured_saveView::toString()
{
  responsebody.reserve(1638);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, featured);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Editing Featured</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", featured["id"]), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"featured[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(featured["id"]);
  responsebody += QStringLiteral("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Image<br /><input type=\"text\" name=\"featured[image]\" value=\"");
  responsebody += THttpUtility::htmlEscape(featured["image"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Html<br /><input type=\"text\" name=\"featured[html]\" value=\"");
  responsebody += THttpUtility::htmlEscape(featured["html"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Save\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", featured["id"]))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(featured_saveView)

#include "featured_saveView.moc"
