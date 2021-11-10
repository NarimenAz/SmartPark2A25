#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cage.h"
#include<QMessageBox>
#include<QIntValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->id->setValidator(new QIntValidator(0, 9999999, this));
    ui->tab_cage->setModel(C.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int id=ui->id->text().toInt();
    int status=ui->status->text().toInt();
    int taille=ui->taille->text().toInt();
    QString type=ui->type->text();
    QString date=ui->date->text();

    cage C(id,status,taille,type,date);
    bool test=C.ajouter();
    if (test)

    {
        ui->tab_cage->setModel(C.afficher());
        QMessageBox::information(nullptr, QObject::tr("ajout is open"),
                               QObject::tr("successful.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

           }
               else
                   QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                               QObject::tr("erreur.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimer_clicked()
{
    cage C1;
    C1.setid(ui->id_sup->text().toInt());
    bool test=C1.supprimer(C1.getid());
    if (test)

    {
        //refresh
        ui->tab_cage->setModel(C1.afficher());

        QMessageBox::information(nullptr, QObject::tr("suppression is open"),
                               QObject::tr("successful.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);


           }
               else
                   QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                               QObject::tr("erreur.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
}




void MainWindow::on_pb_modifier_clicked()
{
    int id=ui->id->text().toInt();
    int status=ui->status->text().toInt();
    int taille=ui->taille->text().toInt();
    QString type=ui->type->text();
    QString date=ui->date->text();

    cage C(id,status,taille,type,date);



    bool test=C.modifierCage(C.getid(),C.getstatus(),C.gettaille(),C.gettype(),C.getdate());


    QMessageBox msgBox;

    if(test)
       {
        ui->tab_cage->setModel(C.afficher());
        msgBox.setText("Modification avec succes.");
        ui->tab_cage->setModel(C.afficher());
       }
    else
        msgBox.setText("Echec de Modification.!!!");
        msgBox.exec();

        ui->id->clear();
        ui->date->clear();
        ui->type->clear();
        ui->taille->clear();
        ui->status->clear();

}
