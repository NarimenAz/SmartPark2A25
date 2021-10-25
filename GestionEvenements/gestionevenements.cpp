#include "gestionevenements.h"
#include "ui_gestionevenements.h"
#include "evenement.h"
#include "dialog.h"

GestionEvenements::GestionEvenements(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::GestionEvenements)
{
    ui->setupUi(this);
    ui->lineEdit_ID->setValidator(new QIntValidator(0,9999999,this));
}

GestionEvenements::~GestionEvenements()
{
    delete ui;
}



void GestionEvenements::on_pushButton_clicked()
{
    Evenement E;
    E.setID(ui->lineEdit_ID->text());
    E.setNom(ui->lineEdit_Nom->text());
    E.setID(ui->dateEdit->text());

    Dialog d;
    d.setevenement(E);
    d.exec();

}
