#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "produit.h"
#include<QIntValidator>
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab_produit->setModel(p.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
int ref=ui->le_id->text().toInt();
QString nom=ui->le_nom->text();
QString categorie=ui->le_categorie->text();
float prix=ui->le_prix->text().toFloat();
int quantite=ui->le_quantite->text().toInt();
produit p(ref,nom,categorie,prix,quantite);
bool test=p.ajouter();
if (test==true)
{
 ui->tab_produit->setModel(p.afficher());
    QMessageBox::information(nullptr, QObject::tr("ajout avec succes"),
                QObject::tr(" successful.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
{
    QMessageBox::critical(nullptr, QObject::tr("erreur"),
                QObject::tr(" erreur.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

}

void MainWindow::on_pb_supprimer_clicked()
{

int ref=ui->le_id_supp->text().toInt();


bool test=p.supprimer(ref);
if (test==true)
{ ui->tab_produit->setModel(p.afficher());

    QMessageBox::information(nullptr, QObject::tr("supression avec succes"),
                QObject::tr(" successful.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
{
    QMessageBox::critical(nullptr, QObject::tr("erreur"),
                QObject::tr(" erreur.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
    }


void MainWindow::on_pushButton_clicked()
{
    int ref=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString categorie=ui->le_categorie->text();
    float prix=ui->le_prix->text().toFloat();
    int quantite=ui->le_quantite->text().toInt();
    produit p(ref,nom,categorie,prix,quantite);
    bool test=p.modifier(ref);
    if (test==true)
    {
 ui->tab_produit->setModel(p.afficher());
        QMessageBox::information(nullptr, QObject::tr("modification avec succes"),
                    QObject::tr(" successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("erreur"),
                    QObject::tr(" erreur.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    QString selon=ui->selon->currentText();
    QString rech=ui->Rech->text();
     ui->tab_produit->setModel(p.rechercher(selon,rech));
}



void MainWindow::on_pushButton_3_clicked()
{
    QString selon=ui->comboBoxTri->currentText();
     ui->tab_produit->setModel(p.trier(selon));
}
