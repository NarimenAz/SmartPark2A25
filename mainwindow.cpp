#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "animaux.h"
#include <QIntValidator>
#include <QMessageBox>
#include <QSqlQuery>
#include <QFile>
#include <QFileDialog>
#include <QTextDocument>
#include <QDebug>

#include <QtPrintSupport/QPrinter>

#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>
#include <QUrl>

#include <QSystemTrayIcon>
#include"notification.h"









//test commit men andi

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

        ui->le_idAnim->setValidator( new QIntValidator(100, 99999999, this));
        ui->le_idAnim->setValidator( new QIntValidator(100, 99999999, this));
        ui->tab_animaux->setModel(A.afficherAnim());

}
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_afficher_clicked()
{
    ui->tab_animaux->setModel(A.afficherAnim());
}


void MainWindow::on_bp_ajouter_clicked()
{

    notification n;
    int idAnim=ui->le_idAnim->text().toInt();
    QString nomAnim=ui->le_nom->text();
    QString typeAnim=ui->le_typeAnimal->text();
    int ageAnim=ui->spinBox_age->text().toInt();
    QString pays=ui->le_pays->text();
    QString regimeAliment=ui->comboBox_regime->currentText();
    QString status=ui->le_status->text();



        animaux A(idAnim, nomAnim,typeAnim,pays,ageAnim,status,regimeAliment );
        bool test=A.ajouterAnim();
        QMessageBox msgBox;

        if(test)
           {

            n.setPopupText("Animal a été Ajouté");
                    n.show();
                //    mysystem->showMessage(tr("Notification"),tr("Il y a un Ajout d'un animal"));

            msgBox.setText("Ajout avec succes.");
            ui->tab_animaux->setModel(A.afficherAnim());
           }
        else
            msgBox.setText("Echec d'ajout.!!!");
            msgBox.exec();


                   ui->le_nom->clear();
                   ui->le_pays->clear();
                   ui->le_idAnim->clear();
                   ui->le_status->clear();
                   ui->le_typeAnimal->clear();
                   ui->comboBox_regime->currentText();
                   ui->spinBox_age->clear();

}





void MainWindow::on_pb_supprimer_clicked()
{
    animaux A1;
    A1.setidAnim(ui->le_idAnim ->text().toInt());
    bool test=A1.supprimerAnim(A1.getidAnim());

    QMessageBox msgBox;

    if(test)
       { msgBox.setText("suppression  avec succes.");
        ui->tab_animaux->setModel(A1.afficherAnim());
       }
    else
        msgBox.setText("Echec de suppression.!!!");
        msgBox.exec();
        ui->le_nom->clear();
        ui->le_pays->clear();
        ui->le_idAnim->clear();
        ui->le_status->clear();
        ui->le_typeAnimal->clear();
        ui->comboBox_regime->currentText();
        ui->spinBox_age->clear();


}

void MainWindow::on_pb_modifier_clicked()
{
    int idAnim=ui->le_idAnim->text().toInt();
    QString nomAnim=ui->le_nom->text();
    QString typeAnim=ui->le_typeAnimal->text();
    int ageAnim=ui->spinBox_age->text().toInt();
    QString pays=ui->le_pays->text();
    QString regimeAliment=ui->comboBox_regime->currentText();
    QString status=ui->le_status->text();
    animaux A(idAnim, nomAnim,typeAnim,pays,ageAnim,status,regimeAliment );



    bool test=A.modifierAnim(A.getidAnim(),A.getNomAnim(),A.gettypeAnim(),A.getpays(),A.getageAnim(),A.getregimealim(),A.getstatus());


    QMessageBox msgBox;

    if(test)
       { msgBox.setText("Modification avec succes.");
        ui->tab_animaux->setModel(A.afficherAnim());
       }
    else
        msgBox.setText("Echec de Modification.!!!");
        msgBox.exec();

        ui->le_nom->clear();
        ui->le_pays->clear();
        ui->le_idAnim->clear();
        ui->le_status->clear();
        ui->le_typeAnimal->clear();
        ui->comboBox_regime->currentText();
        ui->spinBox_age->clear();
}

void MainWindow::on_pb_rechercher_clicked()
{
    animaux A1;
    A1.setidAnim(ui->le_idAnim ->text().toInt());
    A1.settypeAnim(ui->le_typeAnimal ->text());
    A1.setregimealim(ui->comboBox_regime->currentText());

        ui->tab_animaux->setModel(A1.chercherAnim(A1.getidAnim(),A1.gettypeAnim(),A1.getregimealim()));

        ui->le_nom->clear();
        ui->le_pays->clear();
        ui->le_idAnim->clear();
        ui->le_status->clear();
        ui->le_typeAnimal->clear();
        ui->comboBox_regime->currentText();
        ui->spinBox_age->clear();



}


void MainWindow::on_pb_trier_clicked()
{


        ui->tab_animaux->setModel(A.trierAnim());


       /* int idAnim=ui->le_idAnim->text().toInt();
        QString nomAnim=ui->le_nom->text();
        QString typeAnim=ui->le_typeAnimal->text();
        int ageAnim=ui->spinBox_age->text().toInt();
        QString pays=ui->le_pays->text();
        QString regimeAliment=ui->comboBox_regime->currentText();
        QString status=ui->le_status->text();
        animaux A(idAnim, nomAnim,typeAnim,pays,ageAnim,status,regimeAliment );*/

        QMessageBox msg;
       if(A.trierAnim())
       {
            ui->tab_animaux->setModel(A.trierAnim());
           msg.setText("Voilà la liste des animaux avec tri croissant selon l'ID");
           msg.exec();
       }


       ui->le_nom->clear();
       ui->le_pays->clear();
       ui->le_idAnim->clear();
       ui->le_status->clear();
       ui->le_typeAnimal->clear();
       ui->comboBox_regime->currentText();
       ui->spinBox_age->clear();



}

void MainWindow::on_pb_pdf_clicked()
{

    QPdfWriter pdf("C:\\Users\\asus\\Desktop\\pdf\\pdfanimaux.pdf");

                          QPainter painter(&pdf);
                         int i = 4000;
                              painter.setPen(Qt::red);
                              painter.setFont(QFont("Arial", 25));
                              painter.drawText(950,1400,"Liste Des ANIMAUX");
                              painter.setPen(Qt::black);
                              painter.setFont(QFont("Arial", 15));
                             // painter.drawText(1100,2000,afficheDC);
                              painter.drawRect(100,100,8000,2000); // dimension ta3 rectangle eli fih liste des animaux
                             // painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:\\Users\\Ahmed.A.Hsouna\\Desktop\\Integration_municipalité_2A2_DEvSpace\\logo.png"));
                              painter.drawRect(0,3000,8000,500);
                              painter.setFont(QFont("Arial", 9));
                              painter.drawText(500,3300,"ID");
                              painter.drawText(1600,3300,"NOM");
                              painter.drawText(2400,3300,"TYPE");
                              painter.drawText(3700,3300,"AGE");
                              painter.drawText(4700,3300,"PAYS");
                              painter.drawText(5700,3300,"REGIME");
                              painter.drawText(6700,3300,"STATUS");
                              painter.drawRect(0,3000,8000,9000);
                            //  painter.drawText(5300,3300,"LIEU");
                              //painter.drawText(7400,3300,"ETAT_MATRIMATIONALE");


                              QSqlQuery query;
                              query.prepare("select * from animaux");
                              query.exec();
                              while (query.next())
                              {
                                  painter.drawText(500,i,query.value(0).toString());
                                  painter.drawText(1650,i,query.value(1).toString());
                                  painter.drawText(2450,i,query.value(2).toString());
                                  painter.drawText(3750,i,query.value(3).toString());
                                   painter.drawText(4750,i,query.value(4).toString());
                                    painter.drawText(5750,i,query.value(5).toString());
                                     painter.drawText(6750,i,query.value(6).toString());



                                 i = i + 500;
    }
                              QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
                                          QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}


void MainWindow::on_pb_reset_clicked()
{
    animaux A1;

    bool test=A1.supprimerTout();

    QMessageBox msgBox;

    if(test)
       { msgBox.setText("reset  avec succes.");
        ui->tab_animaux->setModel(A1.afficherAnim());
       }
    else
        msgBox.setText("Echec de reset.!!!");
        msgBox.exec();

        ui->le_nom->clear();
        ui->le_pays->clear();
        ui->le_idAnim->clear();
        ui->le_status->clear();
        ui->le_typeAnimal->clear();
        ui->comboBox_regime->currentText();
        ui->spinBox_age->clear();

}
