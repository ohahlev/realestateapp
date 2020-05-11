#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT partial_registerView : public TActionView
{
  Q_OBJECT
public:
  partial_registerView() : TActionView() { }
  QString toString();
};

QString partial_registerView::toString()
{
  responsebody.reserve(1876);
  responsebody += QStringLiteral("<div class=\"modal fade\" id=\"exampleModalCenter2\" tabindex=\"-1\" role=\"dialog\" aria-hidden=\"true\">\n  <div class=\"modal-dialog modal-dialog-centered\" role=\"document\">\n    <div class=\"modal-content\">\n      <div class=\"modal-header text-center\">\n        <button type=\"button\" class=\"close\" data-dismiss=\"modal\" aria-label=\"Close\">\n          <span aria-hidden=\"true\">&times;</span>\n        </button>\n      </div>\n      <div class=\"modal-body\">\n        <div class=\"login px-4 mx-auto mw-100\">\n          <h5 class=\"text-center mb-4\">Register Now</h5>\n          <form action=\"#\" method=\"post\">\n            <div class=\"form-group\">\n              <label>First Name</label>\n              <input type=\"text\" class=\"form-control\" name=\"text\" placeholder=\"\" required=\"\">\n            </div>\n            <div class=\"form-group\">\n              <label>Last Name</label>\n              <input type=\"text\" class=\"form-control\" name=\"text\" placeholder=\"\" required=\"\">\n            </div>\n            <div class=\"form-group\">\n              <label class=\"mb-2\">Password</label>\n              <input type=\"password\" class=\"form-control\" name=\"password\" id=\"password1\" placeholder=\"\" required=\"\">\n            </div>\n            <div class=\"form-group\">\n              <label>Confirm Password</label>\n              <input type=\"password\" class=\"form-control\" name=\"password\" id=\"password2\" placeholder=\"\" required=\"\">\n            </div>\n            <button type=\"submit\" class=\"btn btn-primary submit mb-4\">Register</button>\n            <p class=\"text-center pb-4\">\n              <a href=\"#\">By clicking Register, I agree to your terms</a>\n            </p>\n          </form>\n        </div>\n      </div>\n    </div>\n  </div>\n</div>\n");

  return responsebody;
}

T_DEFINE_VIEW(partial_registerView)

#include "partial_registerView.moc"
