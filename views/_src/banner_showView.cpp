#include <QtCore>
#include <TreeFrogView>
#include "banner.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT banner_showView : public TActionView
{
  Q_OBJECT
public:
  banner_showView() : TActionView() { }
  QString toString();
};

QString banner_showView::toString()
{
  responsebody.reserve(1047);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(Banner, banner);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Showing Banner</h1>\n<dt>ID</dt><dd>");
  responsebody += THttpUtility::htmlEscape(banner.id());
  responsebody += QStringLiteral("</dd><br />\n<dt>Text</dt><dd>");
  responsebody += THttpUtility::htmlEscape(banner.text());
  responsebody += QStringLiteral("</dd><br />\n\n");
  responsebody += QVariant(linkTo("Edit", urla("save", banner.id()))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(banner_showView)

#include "banner_showView.moc"
