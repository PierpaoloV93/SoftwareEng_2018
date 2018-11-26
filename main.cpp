#include "startingwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen *splash = new QSplashScreen;
    splash ->setPixmap(QPixmap(":/img/background_window_1.jpg"));
    splash->show();
    StartingWindow w;

    QTimer::singleShot(5000, splash, SLOT(close()));
    QTimer::singleShot(5000, &w, SLOT(show()));


    return a.exec();
}
