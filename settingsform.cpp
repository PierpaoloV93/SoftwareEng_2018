#include "settingsform.h"
#include "ui_settingsform.h"
#include <QFileDialog>
#include <QMessageBox>
#include <fstream>
#include <iostream>
using namespace std;

SettingsForm::SettingsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SettingsForm)
{
    ui->setupUi(this);
    this->setWindowTitle("Settings Form");
    QPixmap image(":/img/male-body-base-mesh-3d-model-rigged-max-obj.jpg");
    if(!image)
    {
        QMessageBox::information(this, tr("ERROR!"), "Image not loaded", 0);
    }


}

SettingsForm::~SettingsForm()
{
    delete ui;
}

void SettingsForm::on_Meshbutton_clicked()
{
   QString mesh_file = QFileDialog::getOpenFileName(this, tr("Load the Mesh.txt"),"C://", "Text File(*.txt)");
    ui->Meshlabel->setText(mesh_file);
    mesh_path = ui->Meshlabel->text();
    QMessageBox::information(this, "Mesh_path", mesh_path, 0);
}




void SettingsForm::on_param_butt_clicked()
{
    QString val = ui->k_text->toPlainText();
    if (val.at(0).isDigit())
    {
        k = val.at(0).digitValue();
    }
    QString kk = QString::number(k);
    ui->k_val->setText(kk);

    QString valr = ui->ring_text->toPlainText();
    if(valr.at(0).isDigit())
    {
        ring = valr.at(0).digitValue();
    }
    QString rr = QString::number(ring);
    ui->ring_val->setText(rr);

    QMessageBox::information(this, "Parameters", "You inserted K = "+val+" and Ring = "+ valr+ " as parameters.", 0);
}

void SettingsForm::on_Calculate_Button_clicked()
{
    QMessageBox::information(this, "WHAT I WILL DO: ", "I WILL CALCULATE THE INTEREST POINTS FOR THE MESH FILE LOCATED AT: "+ mesh_path+
                             " AND I WILL USE K = "+k+" AND I WILL CALCULATE THE "+ ring+"TH NEIGHBOURHOOD.", 0);
}
