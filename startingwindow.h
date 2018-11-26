#ifndef STARTINGWINDOW_H
#define STARTINGWINDOW_H

#include <QMainWindow>
#include "settingsform.h"

namespace Ui {
class StartingWindow;
}

class StartingWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartingWindow(QWidget *parent = nullptr);
    ~StartingWindow();

private slots:
    void on_StartingBotton_clicked();

private:
    Ui::StartingWindow *ui;
};

#endif // STARTINGWINDOW_H
