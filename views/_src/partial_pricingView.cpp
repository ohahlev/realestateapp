#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT partial_pricingView : public TActionView
{
  Q_OBJECT
public:
  partial_pricingView() : TActionView() { }
  QString toString();
};

QString partial_pricingView::toString()
{
  responsebody.reserve(3588);
  responsebody += QStringLiteral("<section class=\"pricing py-5\" id=\"pricings\">\n  <div class=\"container py-xl-5 py-lg-3\">\n    <div class=\"text-center mb-lg-5 mb-4\">\n      <h3 class=\"tittle mb-2 text-white\">Our Pricings</h3>\n      <p class=\"test-title-paara\">A few word about our Planes</p>\n    </div>\n    <div class=\"inner-sec\">\n      <div class=\"card-deck text-center row mt-5\">\n        <div class=\"price-info-grid col-lg-4\">\n          <div class=\"price-inner\">\n            <div class=\"price-header\">\n              <h4>Starter</h4>\n            </div>\n            <div class=\"price-body\">\n              <h5 class=\"pricing-title\">\n                <span class=\"dolor\">$</span> 789.00\n                <label>Per Month</label>\n              </h5>\n              <ul class=\"list-unstyled mt-3 mb-4\">\n                <li class=\"py-2 border-bottom\">Advertising</li>\n                <li class=\"py-2 border-bottom\">Branding Services</li>\n                <li class=\"py-2 border-bottom\">Online Marketing</li>\n                <li class=\"py-2 border-bottom\">Creative Marketing</li>\n                <li class=\"py-2\">-</li>\n              </ul>\n              <a href=\"#\" class=\"btn btn-block py-2\" data-toggle=\"modal\" data-target=\"#exampleModalCenter2\">\n                <i class=\"far fa-user\"></i> Get Started</a>\n            </div>\n          </div>\n        </div>\n        <div class=\"price-info-grid col-lg-4 my-lg-0 my-3\">\n          <div class=\"price-inner\">\n            <div class=\"price-header\">\n              <h4>Professional</h4>\n            </div>\n            <div class=\"price-body\">\n              <h5 class=\"pricing-title\">\n                <span class=\"dolor\">$</span>1089.00\n                <label>Per Month</label>\n              </h5>\n              <ul class=\"list-unstyled mt-3 mb-4\">\n                <li class=\"py-2 border-bottom\">Advertising</li>\n                <li class=\"py-2 border-bottom\">Branding Services</li>\n                <li class=\"py-2 border-bottom\">Online Marketing</li>\n                <li class=\"py-2 border-bottom\">Creative Marketing</li>\n                <li class=\"py-2\">-</li>\n              </ul>\n              <a href=\"#\" class=\"btn btn-block btn-outline-primary py-2\" data-toggle=\"modal\" data-target=\"#exampleModalCenter2\">\n                <i class=\"far fa-user\"></i> Get Started</a>\n            </div>\n          </div>\n        </div>\n        <div class=\"price-info-grid col-lg-4\">\n          <div class=\"price-inner\">\n            <div class=\"price-header\">\n              <h4>Enterprise</h4>\n            </div>\n            <div class=\"price-body\">\n              <h5 class=\"pricing-title\">\n                <span class=\"dolor\">$</span>2189.00\n                <label>Per Month</label>\n              </h5>\n              <ul class=\"list-unstyled mt-3 mb-4\">\n                <li class=\"py-2 border-bottom\">Advertising</li>\n                <li class=\"py-2 border-bottom\">Branding Services</li>\n                <li class=\"py-2 border-bottom\">Online Marketing</li>\n                <li class=\"py-2 border-bottom\">Creative Marketing</li>\n                <li class=\"py-2\">-</li>\n              </ul>\n              <a href=\"#\" class=\"btn btn-block btn-outline-primary py-2\" data-toggle=\"modal\" data-target=\"#exampleModalCenter2\">\n                <i class=\"far fa-user\"></i> Get Started</a>\n            </div>\n          </div>\n        </div>\n      </div>\n    </div>\n  </div>\n</section>\n");

  return responsebody;
}

T_DEFINE_VIEW(partial_pricingView)

#include "partial_pricingView.moc"
