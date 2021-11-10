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

    int ID = ui->lineEdit_ID->text().toInt();
    QString Nom = ui->lineEdit_Nom->text();
    int Date = ui->dateEdit->text().toInt();
    QString Theme = ui->lineEdit_Theme->text();
    int Nbr_Employés = ui->NbEmployes->text().toInt();
    Evenement E(ID,Nom,Date,Theme,Nbr_Employés);

    Dialog d;
    d.setevenement(E);
    d.exec();

}

void GestionEvenements::on_pb_ajouter_clicked()
{

}
