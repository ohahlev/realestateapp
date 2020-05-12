#include <QtCore>
#include <TreeFrogView>
#include "banner.h"
#include "applicationhelper.h"

class T_VIEW_EXPORT partial_bannerView : public TActionView
{
  Q_OBJECT
public:
  partial_bannerView() : TActionView() { }
  QString toString();
};

QString partial_bannerView::toString()
{
  responsebody.reserve(321);
    tfetch(Banner, banner);
  responsebody += QStringLiteral("<div class=\"banner-text-agile\">\n  <div class=\"container\">\n    <div class=\"banner-w3lstexts text-white text-center\">\n      ");
  responsebody += QVariant(banner.html()).toString();
  responsebody += QStringLiteral("\n    </div>\n  </div>\n</div>\n");

  return responsebody;
}

T_DEFINE_VIEW(partial_bannerView)

#include "partial_bannerView.moc"
