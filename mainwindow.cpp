#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIntValidator>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
ui->tab_employee->setModel(E.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int tel=ui->le_tel->text().toInt();
        QString nom=ui->le_nom->text();
        QString adress=ui->le_adress->text();
        QString prenom=ui->le_prenom->text();
        QString specialite=ui->le_specialite->text();
        QString id=ui->le_id->text();



             Employee E (id,tel,nom,prenom,specialite,adress);
            bool test=E.ajouter();
            QMessageBox msgBox;

            if(test)
               {


                msgBox.setText("Ajout avec succes.");
                ui->tab_employee->setModel(E.afficher());
               }
            else
                msgBox.setText("Echec d'ajout.!!!");
                msgBox.exec();

}

void MainWindow::on_pushButton_clicked()
{
    Employee E1; E1.setId(ui->le_id_supp->text());
       bool test=E1.supprimer(E1.getId());
QMessageBox msgbox;
if(test)
{msgbox.setText("suppressino avec succes ");
 ui->tab_employee->setModel(E.afficher());

}
else
    msgbox.setText("echec de suppression  ");
      msgbox.exec();
}


void MainWindow::on_pb_modifier_clicked()
{


    int tel=ui->le_tel->text().toInt();
        QString nom=ui->le_nom->text();
        QString adress=ui->le_adress->text();
        QString prenom=ui->le_prenom->text();
        QString specialite=ui->le_specialite->text();
        QString id=ui->le_id->text();


               Employee E (id,tel,nom,prenom,specialite,adress);

                bool test=E.modifier(E.getId(),E.getTel(),E.getNom(),E.getPrenom(),E.getSpecialite(),E.getAdress());

                QMessageBox msgBox;

                if(test)
                    {
                        msgBox.setText("Modification avec succes.");
                        ui->tab_employee->setModel(E.afficher());
                    }
                else
                    msgBox.setText("Echec de Modification!!!!!!");
                    msgBox.exec();
    }




