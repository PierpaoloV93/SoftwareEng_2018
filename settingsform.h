#ifndef SETTINGSFORM_H
#define SETTINGSFORM_H

#include <QWidget>

namespace Ui {
class SettingsForm;
}

class SettingsForm : public QWidget
{
    Q_OBJECT

public :
    explicit SettingsForm(QWidget *parent = nullptr);
    int on_K_spinBox_value();
    int get_k(){return k;}
    int set_k(int val){k = val;}
    int get_ring(){return ring;}
    int set_ring(int val){ring = val;}
    ~SettingsForm();

private slots:
    void on_Meshbutton_clicked();


    void on_param_butt_clicked();

    void on_Calculate_Button_clicked();

private:
    //Private arguments I will need
    QString mesh_path;
    int k, ring;
    Ui::SettingsForm *ui;
};

#endif // SETTINGSFORM_H
