#include <QtCore>
#include <TreeFrogView>
#include "applicationhelper.h"

class T_VIEW_EXPORT partial_copyrightView : public TActionView
{
  Q_OBJECT
public:
  partial_copyrightView() : TActionView() { }
  QString toString();
};

QString partial_copyrightView::toString()
{
  responsebody.reserve(216);
  responsebody += tr("<div class=\"copy_right py-4 text-center\">\n  <p class=\"text-white\">© 2018 District. All rights reserved | Design by\n    <a href=\"http://w3layouts.com/\">W3layouts</a>\n  </p>\n</div>\n");

  return responsebody;
}

T_DEFINE_VIEW(partial_copyrightView)

#include "partial_copyrightView.moc"
