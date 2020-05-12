#include <QtCore>
#include <TreeFrogView>
#include "featured.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT featured_createView : public TActionView
{
  Q_OBJECT
public:
  featured_createView() : TActionView() { }
  QString toString();
};

QString featured_createView::toString()
{
  responsebody.reserve(1249);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, featured);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>New Featured</h1>\n\n");
  responsebody += QVariant(formTag(urla("create"), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>Image<br /><input name=\"featured[image]\" value=\"");
  responsebody += THttpUtility::htmlEscape(featured["image"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <label>Html<br /><input name=\"featured[html]\" value=\"");
  responsebody += THttpUtility::htmlEscape(featured["html"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Create\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(featured_createView)

#include "featured_createView.moc"
