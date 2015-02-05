#include "mainwidget.h"
#include "utils.h"
#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>
#include <QStringBuilder>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QString localeName = QLocale::system().name();

    QTranslator qtTranslator;
    qtTranslator.load(QLatin1String("qt_") % localeName,
                      QLibraryInfo::location(QLibraryInfo::TranslationsPath));
    app.installTranslator(&qtTranslator);

    QTranslator schematrickTranslator;
    schematrickTranslator.load(QLatin1String(":/schematrick_") % localeName);
    app.installTranslator(&schematrickTranslator);

    MainWidget mainWidget;
    mainWidget.show();

    return app.exec();
}
