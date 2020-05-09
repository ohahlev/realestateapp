#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT partial_statsView : public TActionView
{
  Q_OBJECT
public:
  partial_statsView() : TActionView() { }
  QString toString();
};

QString partial_statsView::toString()
{
  responsebody.reserve(1390);
  responsebody += QStringLiteral("<div class=\"middlesection-agile py-5\">\n		<div class=\"container-fluid py-xl-5 py-lg-3\">\n			<div class=\"row\">\n				<div class=\"col-lg-6 left-build-wthree aboutright-agilewthree mt-0\">\n					<h4>Sell Your Best House</h4>\n					<h6 class=\"mt-3 mb-5\">Some words about our property</h6>\n					<div class=\"row mb-xl-5 mb-4\">\n						<div class=\"col-4 w3layouts_stats_left w3_counter_grid\">\n							<i class=\"fas fa-bed\"></i>\n							<p class=\"counter\">6</p>\n							<p class=\"para-text-w3ls\">Bedroom</p>\n						</div>\n						<div class=\"col-4 w3layouts_stats_left w3_counter_grid2\">\n							<i class=\"fas fa-bath\"></i>\n							<p class=\"counter\">4</p>\n							<p class=\"para-text-w3ls\">Bathroom</p>\n						</div>\n						<div class=\"col-4 w3layouts_stats_left w3_counter_grid1\">\n							<i class=\"fas fa-car\"></i>\n							<p class=\"counter\">2</p>\n							<p class=\"para-text-w3ls\">Car Parking</p>\n						</div>\n					</div>\n					<p>Cras sagittis mi sit amet malesuada mollis. Mauris porroinit consectetur cursus tortor vel interdum. Suspendisse interdum\n						velit vel qu dapibus condimentum. Pellentesque consequat.</p>\n				</div>\n				<div class=\"col-lg-6 text-lg-left text-center mt-lg-0 mt-md-5 mt-4\">\n					<img src=\"/images/middle.jpg\" alt=\"\" class=\"img-fluid\" />\n				</div>\n			</div>\n		</div>\n	</div>");

  return responsebody;
}

T_DEFINE_VIEW(partial_statsView)

#include "partial_statsView.moc"
