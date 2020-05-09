#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT partial_middle_sectionView : public TActionView
{
  Q_OBJECT
public:
  partial_middle_sectionView() : TActionView() { }
  QString toString();
};

QString partial_middle_sectionView::toString()
{
  responsebody.reserve(1775);
  responsebody += QStringLiteral("<div class=\"middle-w3l\">\n		<div class=\"container-fluid\">\n			<div class=\"row\">\n				<div class=\"col-lg-6 col-md-4 button\">\n\n				</div>\n				<div class=\"col-lg-6 col-md-8 left-build-wthree py-5 px-sm-5 px-4\">\n					<div class=\"py-xl-5 py-lg-3 px-xl-4\">\n						<h4>A Beautiful Beach House</h4>\n						<h6 class=\"mt-3 mb-xl-5 mb-4\">Excepteur sint occaecat</h6>\n						<p>sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation\n							ullamco laboris nisi ut aliquip ex ea commodo consequat.</p>\n						<ul class=\"list-beach mt-lg-5 mt-4\">\n							<li>\n								<div class=\"row\">\n									<div class=\"col-1 text-center\">\n										<i class=\"fas fa-hand-point-right\"></i>\n									</div>\n									<div class=\"col-10\">\n										<p>Totam rem aperiamet quasi architecto beatae vitae dicta sunt explicabo beatae vitae dicta.</p>\n									</div>\n								</div>\n							</li>\n							<li class=\"my-3\">\n								<div class=\"row\">\n									<div class=\"col-1 text-center\">\n										<i class=\"fas fa-hand-point-right\"></i>\n									</div>\n									<div class=\"col-10\">\n										<p>A rchitecto beatae Totam rem aperiamet quasi architecto beatae vitae dicta sunt explicabo.</p>\n									</div>\n								</div>\n							</li>\n							<li>\n								<div class=\"row\">\n									<div class=\"col-1 text-center\">\n										<i class=\"fas fa-hand-point-right\"></i>\n									</div>\n									<div class=\"col-10\">\n										<p>Dicta sunt explicabo Totam rem aperiamet quasi architecto beatae vitae dicta sunt explicabo.</p>\n									</div>\n								</div>\n							</li>\n						</ul>\n					</div>\n				</div>\n			</div>\n		</div>\n	</div>");

  return responsebody;
}

T_DEFINE_VIEW(partial_middle_sectionView)

#include "partial_middle_sectionView.moc"
