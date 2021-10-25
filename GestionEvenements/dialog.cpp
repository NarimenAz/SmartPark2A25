#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::setevenement(Evenement E)
{
    ui->lineEdit_IDD->setText(E.get_ID());
    ui->lineEdit_NomD->setText(E.get_Nom());
   // ui->dateEditD->setDate(E.get_Date());

}
