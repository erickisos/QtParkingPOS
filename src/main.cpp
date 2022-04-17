#include <QtCore/QFile>
#include <QtCore/QStringLiteral>
#include <QtCore/QUrl>
#include <QtQml/QQmlApplicationEngine>
#include <QtWidgets/QApplication>

int main(int argc, char *argv[]) {
  // load the QSS file
  QFile styleFile(":/qss/style.qss");
  styleFile.open(QFile::ReadOnly);

  QString styleSheet(styleFile.readAll());
  styleFile.close();

  // create the application
  QApplication app(argc, argv);
  app.setStyleSheet(styleSheet);

  // create the QML engine
  QQmlApplicationEngine engine;
  engine.load(QUrl(QString("qrc:/qml/main.qml")));

  // run the application
  return app.exec();
}
