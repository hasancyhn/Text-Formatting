#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_pushButton_clicked()
{
    QFont fontumuz;                                                 //font isminde QFont tipinde bir nesne olusturuldu.
    fontumuz.setFamily(ui->fontComboBox_Yazi_Fontu->currentText()); //setFamily ile yazi tipi fontComboBox'tan alinacak.
    fontumuz.setPointSize(ui->spinBox_Yazi_Buyuklugu->value());     //setPointSize sayesinde yazinin buyuklugu value sayesinde (int olarak)  alindi.
    QPalette renk;                                                  //colour isminde QPalette tipinde nesne olusturuldu.
    renk.setColor(QPalette::WindowText, ui->comboBox_Yazi_Rengi->currentText()); //, sonra ui->colours ile secili text ile renk seciliyor.

    fontumuz.setBold(ui->checkBox_Bold->isChecked());
    fontumuz.setBold(ui->checkBox_Italic->isChecked());

    if(ui->checkBox_Bold->isChecked()){
        fontumuz.setBold(true);
    }
    if(ui->checkBox_Italic->isChecked()){
        fontumuz.setItalic(true);
    }
    ui->label_Ekranda_Goster->setFont(fontumuz);
    ui->label_Ekranda_Goster->setPalette(renk);
    ui->label_Ekranda_Goster->setText(ui->lineEdit_Yaziyi_Giriniz->text());
}

