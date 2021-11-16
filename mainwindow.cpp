#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QPixmap>
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);
ui->tab_employee->setModel(E.afficher());
ui->le_id->setValidator(new QIntValidator(1000,9999,this));
ui->le_tel->setValidator(new QIntValidator(10000000,99999999,this));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
    int tel=ui->le_tel->text().toInt();
    float salaire=ui->le_salaire->text().toFloat();
        QString nom=ui->le_nom->text();
        QString adress=ui->le_adress->text();
        QString prenom=ui->le_prenom->text();
        QString specialite=ui->le_specialite->text();
        QString id=ui->le_id->text();



             Employee E (id,tel,nom,prenom,specialite,adress,salaire);
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
    Employee E1; E1.setId(ui->comboBox->currentText());
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
    float salaire=ui->le_salaire->text().toFloat();
        QString nom=ui->le_nom->text();
        QString adress=ui->le_adress->text();
        QString prenom=ui->le_prenom->text();
        QString specialite=ui->le_specialite->text();
        QString id=ui->le_id->text();


               Employee E (id,tel,nom,prenom,specialite,adress,salaire);

                bool test=E.modifier(E.getId(),E.getTel(),E.getNom(),E.getPrenom(),E.getSpecialite(),E.getAdress(),E.getsalaire());

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





void MainWindow::on_login_clicked()
{


    QString username = ui->username->text();
             QString password = ui->password->text();

             if (username == "admin" && password == "admin") {
                 QMessageBox::information(this, "Login", "Username and password are correct");
              ui->stackedWidget->setCurrentIndex(0);

             }
             else {
                 QMessageBox::warning(this, "Login", "Username and password are not correct");
             }
             ui->username->clear();
             ui->password->clear();





   /* QString username = ui->username->text();
      QString password = ui->password->text();

      if(username ==  "test" && password == "test") {
          QMessageBox::information(this, "Login", "Username and password is correct");
          //hide();
          dialog= new Dialog(this);
          dialog->show();
      }
      else {
          QMessageBox::warning(this,"Login", "Username and password is not correct");
      }*/
}

void MainWindow::on_load_pt_clicked()
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query= new QSqlQuery();
    query->prepare("SELECT id from EMPLOYEE") ;
    query->exec();
    model->setQuery(*query);
    ui->comboBox->setModel(model);

}

void MainWindow::on_pushButton_3_clicked()
{
    Employee e ;
    ui->tab_employee->setModel(e.trier());
}

void MainWindow::on_pushButton_4_clicked()
{
    Employee e ;
    ui->tab_employee->setModel(e.trier1());
}

void MainWindow::on_pushButton_5_clicked()
{
    Employee e ;
    ui->tab_employee->setModel(e.trier2());
}

void MainWindow::on_pushButton_6_clicked()
{
    Employee e ;
    QString rech =ui->rech->text();
    if (rech=="")

        ui->tab_employee->setModel(e.afficher());
    else
        ui->tab_employee->setModel(e.rechercher(rech));

}

void MainWindow::on_pb_calcul_clicked()
{
    QSqlQuery query=E.calculerSalaire();
        query.exec();
        query.next();
        ui->le_somme_salaire->setText(query.value(0).toString());
}
