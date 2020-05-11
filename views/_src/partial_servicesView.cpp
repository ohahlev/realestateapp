#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT partial_servicesView : public TActionView
{
  Q_OBJECT
public:
  partial_servicesView() : TActionView() { }
  QString toString();
};

QString partial_servicesView::toString()
{
  responsebody.reserve(3061);
  responsebody += QStringLiteral("<div class=\"what-w3ls py-5\" id=\"services\">\n  <div class=\"container py-xl-5 py-lg-3\">\n    <div class=\"text-center mb-md-5 mb-4\">\n      <h3 class=\"tittle mb-sm-2\">Our Services</h3>\n      <p>Some words about our property services</p>\n    </div>\n    <div class=\"what-grids\">\n      <div class=\"row\">\n        <div class=\"col-md-6 what-grid1\">\n          <div class=\"row what-top\">\n            <div class=\"col-2 what-left\">\n              <i class=\"fas fa-key\"></i>\n            </div>\n            <div class=\"col-10 what-right\">\n              <h4>Renting Service</h4>\n              <p class=\"mt-2\">Consectetur adipisicing elit. Ab aut dignissimos ea est, laboriosam consectetur adipisicing elit.</p>\n            </div>\n          </div>\n          <div class=\"row what-top my-md-5 my-4\">\n            <div class=\"col-2 what-left\">\n              <i class=\"far fa-money-bill-alt\"></i>\n            </div>\n            <div class=\"col-10 what-right\">\n              <h4>Saling Service</h4>\n              <p class=\"mt-2\">Consectetur adipisicing elit. Ab aut dignissimos ea est, laboriosam consectetur adipisicing elit.</p>\n            </div>\n          </div>\n          <div class=\"row what-top\">\n            <div class=\"col-2 what-left\">\n              <i class=\"fas fa-user-secret\"></i>\n            </div>\n            <div class=\"col-10 what-right\">\n              <h4>Non Stop Security</h4>\n              <p class=\"mt-2\">Consectetur adipisicing elit. Ab aut dignissimos ea est, laboriosam consectetur adipisicing elit.</p>\n            </div>\n          </div>\n        </div>\n        <div class=\"col-md-6 what-grid1 my-md-0 my-4\">\n          <div class=\"row what-top\">\n            <div class=\"col-2 what-left\">\n              <i class=\"far fa-building\"></i>\n            </div>\n            <div class=\"col-10 what-right\">\n              <h4>Property Management</h4>\n              <p class=\"mt-2\">Consectetur adipisicing elit. Ab aut dignissimos ea est, laboriosam consectetur adipisicing elit.</p>\n            </div>\n          </div>\n          <div class=\"row what-top my-md-5 my-4\">\n            <div class=\"col-2 what-left\">\n              <i class=\"fas fa-clipboard-list\"></i>\n            </div>\n            <div class=\"col-10 what-right\">\n              <h4>Property Listing</h4>\n              <p class=\"mt-2\">Consectetur adipisicing elit. Ab aut dignissimos ea est, laboriosam consectetur adipisicing elit.</p>\n            </div>\n          </div>\n          <div class=\"row what-top\">\n            <div class=\"col-2 what-left\">\n              <i class=\"fas fa-wrench\"></i>\n            </div>\n            <div class=\"col-10 what-right\">\n              <h4>Luxurious Fittings</h4>\n              <p class=\"mt-2\">Consectetur adipisicing elit. Ab aut dignissimos ea est, laboriosam consectetur adipisicing elit.</p>\n            </div>\n          </div>\n        </div>\n      </div>\n    </div>\n  </div>\n</div>\n");

  return responsebody;
}

T_DEFINE_VIEW(partial_servicesView)

#include "partial_servicesView.moc"
