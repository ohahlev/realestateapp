#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT partial_testimonialsView : public TActionView
{
  Q_OBJECT
public:
  partial_testimonialsView() : TActionView() { }
  QString toString();
};

QString partial_testimonialsView::toString()
{
  responsebody.reserve(4087);
  responsebody += QStringLiteral("<div class=\"testimonials py-5\" id=\"clients\">\n		<div class=\"container py-xl-5 py-lg-3\">\n			<div class=\"text-center mb-lg-5 mb-4\">\n				<h3 class=\"tittle mb-2 text-white\">What Clients Say</h3>\n				<p class=\"test-title-paara\">A few word about our Clients</p>\n			</div>\n			<div class=\"w3_testimonials_grids\">\n				<section class=\"slider\">\n					<div class=\"flexslider\">\n						<ul class=\"slides\">\n							<li>\n								<div class=\"w3_testimonials_grid\">\n									<p>\"Nam Cumque nihil impedit quo minuslibero tempore, nihil impedit quo minus id quod possimus, Nam Cumque nihil impedit\n										quo minuslibero tempore, cum soluta nobis est eligendi optio cumque nihil impedit omnis voluptas\".</p>\n									<ul class=\"testi-w3ls-rate mt-4\">\n										<li>\n											<i class=\"fas fa-star\"></i>\n										</li>\n										<li class=\"mx-2\">\n											<i class=\"fas fa-star\"></i>\n										</li>\n										<li>\n											<i class=\"fas fa-star\"></i>\n										</li>\n										<li class=\"mx-2\">\n											<i class=\"fas fa-star\"></i>\n										</li>\n										<li>\n											<i class=\"fas fa-star\"></i>\n										</li>\n									</ul>\n									<div class=\"row person-w3ls-testi mt-5\">\n										<div class=\"col-6 agile-left-test text-right\">\n											<img src=\"/images/te1.jpg\" alt=\" \" class=\"img-fluid rounded-circle\" />\n										</div>\n										<div class=\"col-6 agile-right-test text-left mt-4\">\n											<h5>John Frank</h5>\n											<p>Tempore Quo</p>\n										</div>\n									</div>\n								</div>\n							</li>\n							<li>\n								<div class=\"w3_testimonials_grid\">\n									<p>\"Nam Cumque nihil impedit quo minuslibero tempore, nihil impedit quo minus id quod possimus, Nam Cumque nihil impedit\n										quo minuslibero tempore, cum soluta nobis est eligendi optio cumque nihil impedit omnis voluptas\".</p>\n									<ul class=\"testi-w3ls-rate mt-4\">\n										<li>\n											<i class=\"fas fa-star\"></i>\n										</li>\n										<li class=\"mx-2\">\n											<i class=\"fas fa-star\"></i>\n										</li>\n										<li>\n											<i class=\"fas fa-star\"></i>\n										</li>\n										<li class=\"mx-2\">\n											<i class=\"fas fa-star\"></i>\n										</li>\n										<li>\n											<i class=\"fas fa-star\"></i>\n										</li>\n									</ul>\n									<div class=\"row person-w3ls-testi mt-5\">\n										<div class=\"col-6 agile-left-test text-right\">\n											<img src=\"/images/te2.jpg\" alt=\" \" class=\"img-fluid rounded-circle\" />\n										</div>\n										<div class=\"col-6 agile-right-test text-left mt-4\">\n											<h5>John Frank</h5>\n											<p>Tempore Quo</p>\n										</div>\n									</div>\n								</div>\n							</li>\n							<li>\n								<div class=\"w3_testimonials_grid\">\n									<p>\"Nam Cumque nihil impedit quo minuslibero tempore, nihil impedit quo minus id quod possimus, Nam Cumque nihil impedit\n										quo minuslibero tempore, cum soluta nobis est eligendi optio cumque nihil impedit omnis voluptas\".</p>\n									<ul class=\"testi-w3ls-rate mt-4\">\n										<li>\n											<i class=\"fas fa-star\"></i>\n										</li>\n										<li class=\"mx-2\">\n											<i class=\"fas fa-star\"></i>\n										</li>\n										<li>\n											<i class=\"fas fa-star\"></i>\n										</li>\n										<li class=\"mx-2\">\n											<i class=\"fas fa-star\"></i>\n										</li>\n										<li>\n											<i class=\"fas fa-star\"></i>\n										</li>\n									</ul>\n									<div class=\"row person-w3ls-testi mt-5\">\n										<div class=\"col-6 agile-left-test text-right\">\n											<img src=\"/images/te3.jpg\" alt=\" \" class=\"img-fluid rounded-circle\" />\n										</div>\n										<div class=\"col-6 agile-right-test text-left mt-4\">\n											<h5>John Frank</h5>\n											<p>Tempore Quo</p>\n										</div>\n									</div>\n								</div>\n							</li>\n						</ul>\n					</div>\n				</section>\n\n			</div>\n		</div>\n	</div>");

  return responsebody;
}

T_DEFINE_VIEW(partial_testimonialsView)

#include "partial_testimonialsView.moc"
