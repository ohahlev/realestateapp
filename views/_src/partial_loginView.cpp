#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT partial_loginView : public TActionView
{
  Q_OBJECT
public:
  partial_loginView() : TActionView() { }
  QString toString();
};

QString partial_loginView::toString()
{
  responsebody.reserve(1468);
  responsebody += QStringLiteral("<div class=\"modal fade\" id=\"exampleModalCenter1\" tabindex=\"-1\" role=\"dialog\" aria-hidden=\"true\">\n		<div class=\"modal-dialog modal-dialog-centered\" role=\"document\">\n			<div class=\"modal-content\">\n				<div class=\"modal-header text-center\">\n					<button type=\"button\" class=\"close\" data-dismiss=\"modal\" aria-label=\"Close\">\n						<span aria-hidden=\"true\">&times;</span>\n					</button>\n				</div>\n				<div class=\"modal-body\">\n					<div class=\"login px-4 mx-auto mw-100\">\n						<h5 class=\"text-center mb-4\">Login Now</h5>\n						<form action=\"#\" method=\"post\">\n							<div class=\"form-group\">\n								<label>Username</label>\n								<input type=\"text\" class=\"form-control\" name=\"text\" placeholder=\"\" required=\"\">\n							</div>\n							<div class=\"form-group\">\n								<label class=\"mb-2\">Password</label>\n								<input type=\"password\" class=\"form-control\" name=\"password\" placeholder=\"\" required=\"\">\n							</div>\n							<button type=\"submit\" class=\"btn btn-primary submit mb-4\">Login</button>\n							<p class=\"text-center pb-4\">\n								<a href=\"#\">Forgot your password?</a>\n							</p>\n							<p class=\"text-center pb-4\">\n								Don't have an account?\n								<a href=\"#\" data-toggle=\"modal\" data-target=\"#exampleModalCenter2\">Create one now</a>\n							</p>\n						</form>\n					</div>\n				</div>\n			</div>\n		</div>\n	</div>");

  return responsebody;
}

T_DEFINE_VIEW(partial_loginView)

#include "partial_loginView.moc"
