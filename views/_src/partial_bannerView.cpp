#include <QtCore>
#include <TreeFrogView>
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
  responsebody.reserve(570);
  responsebody += QStringLiteral("<div class=\"banner-text-agile\">\n  <div class=\"container\">\n    <div class=\"banner-w3lstexts text-white text-center\">\n      <h1>Perfect Property</h1>\n      <h4 class=\"text-uppercase mt-md-3 mt-2 mb-md-4 mb-3\">for your home</h4>\n      <p class=\"text-white\">Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation\n        ullamco laboris</p>\n      <a href=\"about.html\" class=\"banner-button btn mt-md-5 mt-4\">Know More</a>\n    </div>\n  </div>\n</div>\n");

  return responsebody;
}

T_DEFINE_VIEW(partial_bannerView)

#include "partial_bannerView.moc"
