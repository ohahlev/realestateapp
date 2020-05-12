#include <QtCore>
#include <TreeFrogView>
#include "featured.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT featured_showView : public TActionView
{
  Q_OBJECT
public:
  featured_showView() : TActionView() { }
  QString toString();
};

QString featured_showView::toString()
{
  responsebody.reserve(1190);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(Featured, featured);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Showing Featured</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(featured.id());
  responsebody += QStringLiteral("</dd><br />\n<dt>Image</dt><dd>");
  responsebody += THttpUtility::htmlEscape(featured.image());
  responsebody += QStringLiteral("</dd><br />\n<dt>Html</dt><dd>");
  responsebody += THttpUtility::htmlEscape(featured.html());
  responsebody += QStringLiteral("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", featured.id()))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(featured_showView)

#include "featured_showView.moc"
