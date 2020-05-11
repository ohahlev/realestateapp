#include <QtCore>
#include <TreeFrogView>
#include "contact.h"
#include "applicationhelper.h"

class T_VIEW_EXPORT partial_headerView : public TActionView
{
  Q_OBJECT
public:
  partial_headerView() : TActionView() { }
  QString toString();
};

QString partial_headerView::toString()
{
  responsebody.reserve(1988);
    tfetch(Contact, contact);
  responsebody += QStringLiteral("\n<div class=\"row border-bottom py-lg-4 py-3\">\n  <div class=\"col-xl-7 col-lg-6 header_agileits_left\">\n    <ul>\n      <li class=\"mr-3\">\n        <i class=\"fas fa-phone mr-2\"></i> ");
  responsebody += THttpUtility::htmlEscape(contact.phone());
  responsebody += QStringLiteral(" </li>\n      <li>\n        <i class=\"fas fa-envelope mr-2\"></i>\n        <a href=\"mailto:info@example.com\"> ");
  responsebody += THttpUtility::htmlEscape(contact.email());
  responsebody += QStringLiteral(" </a>\n      </li>\n    </ul>\n  </div>\n  <div class=\"col-xl-5 col-lg-6 header_right text-center mt-lg-0 mt-2\">\n    <div class=\"row\">\n      <!-- social icons -->\n      <div class=\"col-4 w3social-icons\">\n        <ul>\n          <li>\n            <a href=\"#\" class=\"rounded-circle\">\n              <i class=\"fab fa-facebook-f\"></i>\n            </a>\n          </li>\n          <li class=\"px-2\">\n            <a href=\"#\" class=\"rounded-circle\">\n              <i class=\"fab fa-google-plus-g\"></i>\n            </a>\n          </li>\n          <li>\n            <a href=\"#\" class=\"rounded-circle\">\n              <i class=\"fab fa-twitter\"></i>\n            </a>\n          </li>\n          <li class=\"pl-2\">\n            <a href=\"#\" class=\"rounded-circle\">\n              <i class=\"fab fa-dribbble\"></i>\n            </a>\n          </li>\n        </ul>\n      </div>\n      <!-- //social icons -->\n      <div class=\"col-4 header-loginw3ls text-lg-right text-center\">\n        <a href=\"#\" class=\"log\" data-toggle=\"modal\" data-target=\"#exampleModalCenter1\">\n          <i class=\"fas fa-user mr-2\"></i> Login</a>\n      </div>\n      <div class=\"col-4 header-loginw3ls\">\n        <a href=\"#\" class=\"log\" data-toggle=\"modal\" data-target=\"#exampleModalCenter2\">\n          <i class=\"fas fa-key mr-2\"></i> Register</a>\n      </div>\n    </div>\n  </div>\n</div>\n");

  return responsebody;
}

T_DEFINE_VIEW(partial_headerView)

#include "partial_headerView.moc"
