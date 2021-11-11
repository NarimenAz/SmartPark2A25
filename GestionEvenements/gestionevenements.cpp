#include "gestionevenements.h"
#include "ui_gestionevenements.h"
#include "evenement.h"
#include "dialog.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QApplication>


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

void GestionEvenements::on_pb_ajouter_clicked()
{
    int ID = ui->lineEdit_ID->text().toInt();
    QString Nom = ui->lineEdit_Nom->text();
    int Date = ui->dateEdit->text().toInt();
    QString Theme = ui->lineEdit_Theme->text();
    int Nbr_Employés = ui->NbEmployes->text().toInt();
    Evenement E(ID,Nom,Date,Theme,Nbr_Employés);

           bool test=E.ajouterEvent();
                if(test)
                 {    QMessageBox::information(nullptr, QObject::tr("Ajout avec succés"),
                                               QObject::tr("Ajout successful.\n"
                                                           "Click Cancel to exit."), QMessageBox::Cancel);
                                ui->table_event->setModel(E.afficherEvent());


                 }
                               else
                                   QMessageBox::critical(nullptr, QObject::tr("Ajout failed"),
                                               QObject::tr("ajout failed.\n"
                                                           "Click Cancel to exit."), QMessageBox::Cancel);

}


void GestionEvenements::on_Afficher_clicked()
{
    Evenement E;
    ui->table_event->setModel(E.afficherEvent());
}

void GestionEvenements::on_Supprimer_clicked()
{
    Evenement E1;
    Evenement E;

        E1.setID(ui->lineEdit_ID->text().toInt());
        bool test=E1.supprimerEvent(E1.get_ID());

        QMessageBox msgBox;

        if(test)
            {
                msgBox.setText("Suppression avec succes.");
                ui->table_event->setModel(E.afficherEvent());
            }
        else
            msgBox.setText("Echec de suppression!!!!!");
            msgBox.exec();
}

void GestionEvenements::on_MiseAJour_clicked()
{


    int ID = ui->lineEdit_ID->text().toInt();
    QString Nom = ui->lineEdit_Nom->text();
    int Date = ui->dateEdit->text().toInt();
    QString Theme = ui->lineEdit_Theme->text();
    int Nbr_Employés = ui->NbEmployes->text().toInt();
    Evenement E(ID,Nom,Date,Theme,Nbr_Employés);
        bool test=E.modifierEvent(E.get_ID(),E.get_Nom(),E.get_Date(),E.get_Theme(),E.get_NbEmployés());

        QMessageBox msgBox;

        if(test)
            {
                msgBox.setText("Modification avec succes.");
                ui->table_event->setModel(E.afficherEvent());
            }
        else
            msgBox.setText("Echec de Modification!!!!!!");
            msgBox.exec();
}

void GestionEvenements::on_Recherche_clicked()
{
    Evenement E;

    E.setID(ui->lineEdit_ID->text().toInt());
    ui->table_event->setModel(E.rechercheEvent(E.get_ID()));

    ui->lineEdit_ID->clear();
    ui->lineEdit_Nom->clear();
    ui->dateEdit->clear();
    ui->lineEdit_Theme->clear();
    ui->NbEmployes->clear();

}

void GestionEvenements::on_Trier_clicked()
{
    Evenement E;

    //QMessageBox msg;
    if(E.trierEvent())
    {
        ui->table_event->setModel(E.trierEvent());

    }
}
