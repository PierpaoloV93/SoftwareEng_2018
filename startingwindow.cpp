#include "startingwindow.h"
#include "ui_startingwindow.h"
#include <QPixmap>
#include <QMessageBox>


StartingWindow::StartingWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartingWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Software Engineering Project");
    QPixmap logos(":/Images/Images/logo.jpeg");
    if(!logos)
    {
        QMessageBox::information(this, tr("ERROR!"), "Immagine non caricata", 0);
    }
    ui->logos->setPixmap(logos);

    QPixmap back (":/Images/mesh.jpg");
    if(!back)
    {
        QMessageBox::information(this, tr("ERROR!"), "Background not loaded", 0);
    }
    ui->BackgroundLabel->setPixmap(back);
    ui->statusBar->showMessage("Pierpaolo Vendittelli, Khrystyna Faryna, Anindya Shaha");
}

StartingWindow::~StartingWindow()
{
    delete ui;
}

void StartingWindow::on_StartingBotton_clicked()
{
    this->hide();
    SettingsForm *settings = new SettingsForm;
    settings->show();



}
