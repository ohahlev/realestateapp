#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT partial_navView : public TActionView
{
  Q_OBJECT
public:
  partial_navView() : TActionView() { }
  QString toString();
};

QString partial_navView::toString()
{
  responsebody.reserve(1911);
  responsebody += QStringLiteral("<nav class=\"navbar navbar-expand-lg navbar-light bg-light\">\n  <a class=\"navbar-brand\" href=\"#\">District\n    <span>Real Property</span>\n  </a>\n  <button class=\"navbar-toggler\" type=\"button\" data-toggle=\"collapse\" data-target=\"#navbarSupportedContent\" aria-controls=\"navbarSupportedContent\"\n						    aria-expanded=\"false\" aria-label=\"Toggle navigation\">\n    <span class=\"navbar-toggler-icon\"></span>\n  </button>\n  <div class=\"collapse navbar-collapse\" id=\"navbarSupportedContent\">\n    <ul class=\"navbar-nav ml-auto\">\n      <li class=\"nav-item active\">\n        <a class=\"nav-link\" href=\"/\">Home\n          <span class=\"sr-only\">(current)</span>\n        </a>\n      </li>\n      \n      <!--\n      <li class=\"nav-item dropdown\">\n        <a class=\"nav-link dropdown-toggle\" href=\"#\" id=\"navbarDropdown\" role=\"button\" data-toggle=\"dropdown\" aria-haspopup=\"true\"\n									    aria-expanded=\"false\">\n          Dropdown\n        </a>\n        <div class=\"dropdown-menu\" aria-labelledby=\"navbarDropdown\">\n          <a class=\"dropdown-item scroll\" href=\"#services\">Services</a>\n          <a class=\"dropdown-item scroll\" href=\"#pricings\">Pricings</a>\n          <div class=\"dropdown-divider\"></div>\n          <a class=\"dropdown-item scroll\" href=\"#clients\">Clients</a>\n          <a class=\"dropdown-item\" href=\"about.html\">Our Agents</a>\n        </div>\n      </li>\n      -->\n\n      <li class=\"nav-item mx-xl-4 mx-lg-3 my-lg-0 my-3\">\n        <a class=\"nav-link\" href=\"/properties\">Properties</a>\n      </li>\n      <li class=\"nav-item\">\n        <a class=\"nav-link\" href=\"/contact\">Contact Us</a>\n      </li>\n      <li class=\"nav-item mx-xl-4 mx-lg-3 my-lg-0 my-3\">\n        <a class=\"nav-link\" href=\"/about\">About Us</a>\n      </li>\n    </ul>\n  </div>\n</nav>\n");

  return responsebody;
}

T_DEFINE_VIEW(partial_navView)

#include "partial_navView.moc"
