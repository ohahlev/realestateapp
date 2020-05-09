#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT partial_banner_bottomView : public TActionView
{
  Q_OBJECT
public:
  partial_banner_bottomView() : TActionView() { }
  QString toString();
};

QString partial_banner_bottomView::toString()
{
  responsebody.reserve(1705);
  responsebody += QStringLiteral("<div class=\"serach-w3agile py-5\">\n		<div class=\"container py-xl-4 py-lg-3\">\n			<h3 class=\"title-w3ls mb-md-5 mb-4 font-weight-bold text-center\">Find Your Property</h3>\n			<div class=\"place-grids\">\n				<form action=\"#\" method=\"post\">\n					<div class=\"row\">\n						<div class=\"col-sm-3 col-6 place-grid\">\n							<h5>Select City</h5>\n							<select class=\"sel\" required=\"\">\n								<option value=\"\">City 1</option>\n								<option value=\"\">City 2</option>\n								<option value=\"\">City 3</option>\n								<option value=\"\">City 4</option>\n								<option value=\"\">City 5</option>\n								<option value=\"\">City 6</option>\n							</select>\n						</div>\n						<div class=\"col-sm-3 col-6 place-grid\">\n							<h5>Property type</h5>\n							<select class=\"sel\" required=\"\">\n								<option value=\"\">Select</option>\n								<option value=\"\">Apartment</option>\n								<option value=\"\">Independent house</option>\n								<option value=\"\">Villa</option>\n								<option value=\"\">Pent House</option>\n							</select>\n						</div>\n						<div class=\"col-sm-3 col-6 place-grid mt-sm-0 mt-3\">\n							<h5>Type</h5>\n							<select class=\"sel\" required=\"\">\n								<option value=\"\">BHK</option>\n								<option value=\"\">1BHK</option>\n								<option value=\"\">2BHK</option>\n								<option value=\"\">3BHK</option>\n								<option value=\"\">4BHK</option>\n								<option value=\"\">5BHK</option>\n							</select>\n						</div>\n						<div class=\"col-sm-3 col-6 place-grid\">\n							<input type=\"submit\" value=\"Search\">\n						</div>\n					</div>\n				</form>\n			</div>\n		</div>\n	</div>");

  return responsebody;
}

T_DEFINE_VIEW(partial_banner_bottomView)

#include "partial_banner_bottomView.moc"
