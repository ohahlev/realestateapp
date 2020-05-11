#include <QtCore>
#include <TreeFrogView>
#include "banner.h" 
#include "applicationhelper.h"

class T_VIEW_EXPORT banner_saveView : public TActionView
{
  Q_OBJECT
public:
  banner_saveView() : TActionView() { }
  QString toString();
};

QString banner_saveView::toString()
{
  responsebody.reserve(1415);
  responsebody += QStringLiteral("<!DOCTYPE html>\n");
    tfetch(QVariantMap, banner);
  responsebody += QStringLiteral("<html>\n<head>\n  <meta charset=\"UTF-8\">\n  <title>");
  responsebody += THttpUtility::htmlEscape(controller()->name() + ": " + controller()->activeAction());
  responsebody += QStringLiteral("</title>\n</head>\n<body>\n<p style=\"color: red\">");
  tehex(error);
  responsebody += QStringLiteral("</p>\n<p style=\"color: green\">");
  tehex(notice);
  responsebody += QStringLiteral("</p>\n\n<h1>Editing Banner</h1>\n\n");
  responsebody += QVariant(formTag(urla("save", banner["id"]), Tf::Post)).toString();
  responsebody += QStringLiteral("\n  <p>\n    <label>ID<br /><input type=\"text\" name=\"banner[id]\" value=\"");
  responsebody += THttpUtility::htmlEscape(banner["id"]);
  responsebody += QStringLiteral("\" readonly=\"readonly\" /></label>\n  </p>\n  <p>\n    <label>Text<br /><input type=\"text\" name=\"banner[text]\" value=\"");
  responsebody += THttpUtility::htmlEscape(banner["text"]);
  responsebody += QStringLiteral("\" /></label>\n  </p>\n  <p>\n    <input type=\"submit\" value=\"Save\" />\n  </p>\n</form>\n\n");
  responsebody += QVariant(linkTo("Show", urla("show", banner["id"]))).toString();
  responsebody += QStringLiteral(" |\n");
  responsebody += QVariant(linkTo("Back", urla("index"))).toString();
  responsebody += QStringLiteral("\n</body>\n</html>\n");

  return responsebody;
}

T_DEFINE_VIEW(banner_saveView)

#include "banner_saveView.moc"
