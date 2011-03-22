#include "Render.h"
#include "WebPage.h"

Render::Render(WebPage *page, QObject *parent) : Command(page, parent) {
}

void Render::start(QStringList &arguments) {
  QStringList functionArguments(arguments);
  QString functionName = functionArguments.takeFirst();
  bool result = page()->render( functionName );
  QString t = QString("true");
  QString f = QString("false");

  emit finished(true, result ? t : f);
}

