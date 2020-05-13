#include <QtCore>
#include <TreeFrogView>
#include "contact.h"
#include "applicationhelper.h"

class T_VIEW_EXPORT partial_footerView : public TActionView
{
  Q_OBJECT
public:
  partial_footerView() : TActionView() { }
  QString toString();
};

QString partial_footerView::toString()
{
  responsebody.reserve(2862);
    tfetch(Contact, contact);
  responsebody += QStringLiteral("<div class=\"footer-top py-5 text-ce#nter\">\n  <div class=\"container py-xl-5 py-lg-3\">\n    <h2 class=\"text-white mb-4\">Select Your Dream Property</h2>\n    <h5 class=\"text-white mb-sm-5 mb-4 pb-sm-5 pb-4\">Contact Us</h5>\n    <i class=\"fas fa-map-marker-alt\"></i>\n  </div>\n</div>\n<!-- //footer top -->\n<!-- footer -->\n<div class=\"footer py-5 text-center\">\n  <div class=\"container py-xl-5 py-lg-3\">\n    <div class=\"address row mb-4\">\n      <div class=\"col-lg-4 address-grid\">\n        <div class=\"row address-info\">\n          <div class=\"col-md-3 address-left text-center\">\n            <i class=\"far fa-envelope\"></i>\n          </div>\n          <div class=\"col-md-9 address-right text-left\">\n            <h6 class=\"ad-info text-uppercase mb-2\">Email</h6>\n            <p>\n              <a href=\"mailto:example@email.com\"> mail ");
  responsebody += THttpUtility::htmlEscape(contact.email());
  responsebody += QStringLiteral("</a>\n            </p>\n    \n          </div>\n        </div>\n      </div>\n      <div class=\"col-lg-4 address-grid my-lg-0 my-4\">\n        <div class=\"row address-info\">\n          <div class=\"col-md-3 address-left text-center\">\n            <i class=\"fas fa-mobile-alt\"></i>\n          </div>\n          <div class=\"col-md-9 address-right text-left\">\n            <h6 class=\"ad-info text-uppercase mb-2\">call us</h6>\n            <p>");
  responsebody += THttpUtility::htmlEscape(contact.phone());
  responsebody += QStringLiteral("</p>\n          </div>\n        </div>\n      </div>\n      <div class=\"col-lg-4 address-grid\">\n        <div class=\"row address-info\">\n          <div class=\"col-md-3 address-left text-center\">\n            <i class=\"far fa-map\"></i>\n          </div>\n          <div class=\"col-md-9 address-right text-left\">\n            <h6 class=\"ad-info text-uppercase mb-2\">Address</h6>\n            <p>");
  responsebody += THttpUtility::htmlEscape(contact.location());
  responsebody += QStringLiteral("</p>\n          </div>\n        </div>\n      </div>\n    </div>\n    <!-- social icons footer -->\n    <div class=\"w3social-icons-footer text-center pt-sm-5 pt-3\">\n      <ul>\n        <li>\n          <a href=\"");
  responsebody += THttpUtility::htmlEscape(contact.facebook());
  responsebody += QStringLiteral("\" class=\"rounded-circle\">\n            <i class=\"fab fa-facebook-f\"></i>\n          </a>\n        </li>\n        <li class=\"px-2\">\n          <a href=\"");
  responsebody += THttpUtility::htmlEscape(contact.youtube());
  responsebody += QStringLiteral("\" class=\"rounded-circle\">\n            <i class=\"fab fa-youtube\"></i>\n          </a>\n        </li>\n      \n      </ul>\n    </div>\n    <!-- //social icons footer -->\n  </div>\n</div>\n");

  return responsebody;
}

T_DEFINE_VIEW(partial_footerView)

#include "partial_footerView.moc"
