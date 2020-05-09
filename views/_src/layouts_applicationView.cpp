#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT layouts_applicationView : public TActionView
{
  Q_OBJECT
public:
  layouts_applicationView() : TActionView() { }
  QString toString();
};

QString layouts_applicationView::toString()
{
  responsebody.reserve(4705);
  responsebody += QStringLiteral("<!--\nAuthor: W3layouts\nAuthor URL: http://w3layouts.com\nLicense: Creative Commons Attribution 3.0 Unported\nLicense URL: http://creativecommons.org/licenses/by/3.0/\n-->\n\n<!DOCTYPE html>\n<html lang=\"zxx\">\n\n<head>\n	<title>District Real Estates Category Bootstrap Responsive website Template | Home :: W3layouts</title>\n	<!-- Meta tag Keywords -->\n	<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n	<meta charset=\"UTF-8\" />\n	<meta name=\"keywords\" content=\"District Responsive web template, Bootstrap Web Templates, Flat Web Templates, Android Compatible web template, Smartphone Compatible web template, free webdesigns for Nokia, Samsung, LG, SonyEricsson, Motorola web design\"\n	/>\n	<script>\n		addEventListener(\"load\", function () {\n			setTimeout(hideURLbar, 0);\n		}, false);\n\n		function hideURLbar() {\n			window.scrollTo(0, 1);\n		}\n	</script>\n	<!--// Meta tag Keywords -->\n\n	<!-- Custom-Files -->\n	<link rel=\"stylesheet\" href=\"/css/bootstrap.css\">\n	<!-- Bootstrap-Core-CSS -->\n	<link rel=\"stylesheet\" href=\"/css/style.css\" type=\"text/css\" media=\"all\" />\n	<!-- Style-CSS -->\n	<link rel=\"stylesheet\" href=\"/css/fontawesome-all.css\">\n	<!-- Font-Awesome-Icons-CSS -->\n	<!-- //Custom-Files -->\n\n	<!-- Web-Fonts -->\n	<link href=\"//fonts.googleapis.com/css?family=Roboto:100,100i,300,300i,400,400i,500,500i,700,700i,900,900i\" rel=\"stylesheet\">\n	<link href=\"//fonts.googleapis.com/css?family=Montserrat:100,100i,200,200i,300,300i,400,400i,500,500i,600,600i,700,700i,800,800i,900,900i\"\n	    rel=\"stylesheet\">\n	<!-- //Web-Fonts -->\n</head>\n\n<body>\n	<!-- banner -->\n	");
  responsebody += QVariant(renderPartial("banner")).toString();
  responsebody += QStringLiteral("\n\n	<!-- login -->\n	\n	");
  responsebody += QVariant(renderPartial("login")).toString();
  responsebody += QStringLiteral("\n\n	<!-- //login -->\n\n	<!-- register -->\n	\n	");
  responsebody += QVariant(renderPartial("register")).toString();
  responsebody += QStringLiteral("\n\n	<!--//register-->\n	<!-- //banner -->\n\n	<!-- banner-bottom -->\n	");
  responsebody += QVariant(renderPartial("banner_bottom")).toString();
  responsebody += QStringLiteral("\n	<!-- //banner-bottom -->\n\n	");
  responsebody += QVariant(yield()).toString();
  responsebody += QStringLiteral("\n	\n	<!-- footer top -->\n	<!-- footer -->\n	");
  responsebody += QVariant(renderPartial("footer")).toString();
  responsebody += QStringLiteral("\n\n	<!-- copyright -->\n	<!-- //copyright -->\n	");
  responsebody += QVariant(renderPartial("copyright")).toString();
  responsebody += QStringLiteral("\n\n	<!-- Js files -->\n	<!-- JavaScript -->\n	<script src=\"/js/jquery-2.2.3.min.js\"></script>\n	<!-- Default-JavaScript-File -->\n	<script src=\"/js/bootstrap.js\"></script>\n	<!-- Necessary-JavaScript-File-For-Bootstrap -->\n\n	<!-- flexSlider (for testimonials) -->\n	<link rel=\"stylesheet\" href=\"/css/flexslider.css\" type=\"text/css\" media=\"screen\" property=\"\" />\n	<script defer src=\"/js/jquery.flexslider.js\"></script>\n	<script>\n		$(window).load(function () {\n			$('.flexslider').flexslider({\n				animation: \"slide\",\n				start: function (slider) {\n					$('body').removeClass('loading');\n				}\n			});\n		});\n	</script>\n	<!-- //flexSlider (for testimonials) -->\n\n	<!-- stats -->\n	<script src=\"/js/jquery.waypoints.min.js\"></script>\n	<script src=\"/js/jquery.countup.js\"></script>\n	<script>\n		$('.counter').countUp();\n	</script>\n	<!-- //stats -->\n\n	<!-- password-script -->\n	<script>\n		window.onload = function () {\n			document.getElementById(\"password1\").onchange = validatePassword;\n			document.getElementById(\"password2\").onchange = validatePassword;\n		}\n\n		function validatePassword() {\n			var pass2 = document.getElementById(\"password2\").value;\n			var pass1 = document.getElementById(\"password1\").value;\n			if (pass1 != pass2)\n				document.getElementById(\"password2\").setCustomValidity(\"Passwords Don't Match\");\n			else\n				document.getElementById(\"password2\").setCustomValidity('');\n			//empty string means no validation error\n		}\n	</script>\n	<!-- //password-script -->\n\n	<!-- smooth scrolling -->\n	<script src=\"/js/SmoothScroll.min.js\"></script>\n	<!-- //smooth scrolling -->\n\n	<!-- move-top -->\n	<script src=\"/js/move-top.js\"></script>\n	<!-- easing -->\n	<script src=\"/js/easing.js\"></script>\n	<!--  necessary snippets for few javascript files -->\n	<script src=\"/js/district.js\"></script>\n\n	<script src=\"/js/bootstrap.js\"></script>\n	<!-- Necessary-JavaScript-File-For-Bootstrap -->\n	<!-- //Js files -->\n\n</body>\n\n</html>");

  return responsebody;
}

T_DEFINE_VIEW(layouts_applicationView)

#include "layouts_applicationView.moc"
