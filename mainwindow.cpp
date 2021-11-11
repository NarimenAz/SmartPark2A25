#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"visiteur.h"
#include <QMessageBox>
#include<QIntValidator>


MainWindow::MainWindow(QWidget *parent) :

    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ///set validator sera applique sur lineedit de   id
      ///control de saisie je peux le faire aussi par l interface graphique
      ui->le_id->setValidator(new QIntValidator(0,99999999,this));
      ui->le_age->setValidator(new QIntValidator(0,99,this));

     ui->le_id_supp->setValidator(new QIntValidator(0,99999999,this));

    ui->tab_visiteur->setModel(V.afficherV());
     } ///prend en parametre l appel d'une fonction afficher retourne un tableau de type sqlquerymodel
     ///creation du objet V dans mainwindow.h just pour l appel a la methode  afficher
  ///set model vat etre appliquer sur un table view


MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow  ::on_pb_ajouter_clicked()
{ ///recuperation des valeurs saisie dans le line edite pour visiteurs
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    int age=ui->le_age->text().toInt();
    QString adresse=ui->le_adresse->text();

///appel du constructeur parametre des variables du line edit
    Visiteur V(id,nom,prenom,age,adresse);

    bool test=V.ajouterV();
    if (test)

    {   ///refresh =actualisation de l'affichage
         ui->tab_visiteur->setModel(V.afficherV());

        QMessageBox ::information(nullptr, QObject::tr("Gestion_Visiteurs"),
                                   QObject::tr("ajout effectue\n"
                                                           "Click Cancel to exit."),QMessageBox::Cancel);
     }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectue.\n"
                                          "Click Cancel to exit."),QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimer_clicked()
{





    ///appel du methode supprimer
   Visiteur V1;
   ///acoorder a V1 l id saisie au niveau du line edit

   V1.setId(ui->le_id_supp->text().toInt());

   ///appel du methode supprimer
   /// recuperer le resultat dans test
   bool test=V1.supprimer(V1.getId());

   ///afficherd'un un message
   if (test)
   {

       QMessageBox ::information(nullptr, QObject::tr("Gestion_Visiteurs"),
                                  QObject::tr("suppression effectue\n"
                                                          "Click Cancel to exit."),QMessageBox::Cancel);

       ///refresh =actualisation de l'affichage
         ui->tab_visiteur->setModel(V.afficherV());

    }
   else
     {  QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                             QObject::tr("suppression non effectue.\n"
                                         "Click Cancel to exit."),QMessageBox::Cancel);
     }


}




void MainWindow::on_pb_modifier_clicked()
{

    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    int age=ui->le_age->text().toInt();
    QString adresse=ui->le_adresse->text();

///appel du constructeur parametre des variables du line edit
    Visiteur V(id,nom,prenom,age,adresse);

    bool test=V.modifierV();
    if (test)

    {

        QMessageBox ::information(nullptr, QObject::tr("Gestion_Visiteurs"),
                                   QObject::tr("modification effectue\n"
                                                           "Click Cancel to exit."),QMessageBox::Cancel);
        ///refresh =actualisation de l'affichage
        ui->tab_visiteur->setModel(V.afficherV());
     }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("modification non effectue.\n"
                                          "Click Cancel to exit."),QMessageBox::Cancel);


}
