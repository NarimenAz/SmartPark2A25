#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "produit.h"
#include<QIntValidator>
#include <QMessageBox>
#include "smtp.h"
#include <QIntValidator>
#include <QPixmap>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/Users/toshiba/Desktop/Atelier_Connexion/backgroundpng.jpg");
    ui->label_8->setPixmap(pix);
    QIntValidator *val=new QIntValidator(100000,999999,this);
    ui->le_id->setValidator(val);
      connect(ui->Rech, SIGNAL(textChanged(QString)), this, SLOT(affrech()));
 p.stat(series);


        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("Statistiques");
        chart->setBackgroundBrush(Qt::transparent);
        QChartView *chartview = new QChartView(chart);
        chartview->setRenderHint(QPainter::Antialiasing);
        chartview->setParent(ui->horizontalFrame);
        chartview->resize(400,300);

        chart->setAnimationOptions(QChart::AllAnimations);
        chart->legend()->setVisible(true);
        chart->legend()->setAlignment(Qt::AlignRight);
        series->setLabelsVisible(true);


    ui->tab_produit->setModel(p.afficher());
    int ret=a.connect_arduino();
          switch (ret) {
          case(0):qDebug()<<"arduino is available and connected to :"<<a.getarduino_port_name();
              break;
          case(1):qDebug()<<"arduino is available but not connected to :"<<a.getarduino_port_name();
              break;
          case(-1):qDebug()<<"arduino is not available";
          }
    QObject::connect(a.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::update_label()
{
data=a.read_from_arduino();

if (data == "1")
  {
    QMessageBox::critical(nullptr, QObject::tr("Alert"),
                QObject::tr("detection de chaleur.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}

}
void MainWindow::on_pb_ajouter_clicked()
{
int ref=ui->le_id->text().toInt();
QString nom=ui->le_nom->text();
QString categorie=ui->le_categorie->text();
float prix=ui->le_prix->text().toFloat();
int quantite=ui->le_quantite->text().toInt();
produit p(ref,nom,categorie,prix,quantite);
if((prix>0) && (quantite>0))
{
bool test=p.ajouter();
if (test==true)
{
     p.stat(series);
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
else
    QMessageBox::critical(nullptr, QObject::tr("erreur"),
                QObject::tr(" Verifier Votre informations.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_supprimer_clicked()
{

int ref=ui->le_id_supp->text().toInt();


bool test=p.supprimer(ref);
if (test==true)
{  p.stat(series);
    ui->tab_produit->setModel(p.afficher());

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
    if((prix>0) && (quantite>0))
    {
    bool test=p.modifier(ref);
    if (test==true)
    { p.stat(series);
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
    }}
    else

            QMessageBox::critical(nullptr, QObject::tr("erreur"),
                        QObject::tr(" Verifier Votre informations.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_2_clicked()
{

}



void MainWindow::on_pushButton_3_clicked()
{
    QString selon=ui->comboBoxTri->currentText();
     ui->tab_produit->setModel(p.trier(selon));
}

void MainWindow::on_pushButton_4_clicked()
{

        Smtp* smtp = new Smtp("narimen.azzouz@esprit.tn","201JFT3127", "smtp.gmail.com");
        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


            smtp->sendMail("narimen.azzouz@esprit.tn",ui->destinataire->text(), ui->objet->text(),ui->texte->toPlainText());
            QMessageBox::information(nullptr, QObject::tr("Mail sent"),
                        QObject::tr(" successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
       }

void MainWindow::on_pushButton_5_clicked()
{
if (ui->comboBox->currentText()=="ENG")
{
    ui->tabWidget->setTabText(0,"Add product");
    ui->tabWidget->setTabText(1,"View products");
    ui->tabWidget->setTabText(2,"Delete product");
    ui->tabWidget->setTabText(3,"Statistics");
    ui->tabWidget->setTabText(4,"Send mail");
    ui->groupBox->setTitle("Add");
    ui->label_2->setText("Name");
    ui->label_3->setText("Category");
    ui->label_5->setText("Price");
    ui->label_6->setText("Quantity");
    ui->pushButton->setText("Edit");
    ui->pb_ajouter->setText("Add");
    ui->pushButton_3->setText("Sort");
    ui->pb_supprimer->setText("Delete");
    ui->pushButton_5->setText("Change");
    ui->pushButton_6->setText("Generate");






}
else if (ui->comboBox->currentText()=="FR")
{
    ui->tabWidget->setTabText(0,"Ajouter produit");
    ui->tabWidget->setTabText(1,"Affciher produits");
    ui->tabWidget->setTabText(2,"Supprimer produit");
    ui->tabWidget->setTabText(3,"Statistiques");
    ui->tabWidget->setTabText(4,"Envoyer mail");
    ui->groupBox->setTitle("Ajouter");
    ui->label_2->setText("Nom");
    ui->label_3->setText("Categorie");
    ui->label_5->setText("Prix");
    ui->label_6->setText("Quantite");
    ui->pushButton->setText("Modifier");
    ui->pb_ajouter->setText("Ajouter");
    ui->pushButton_3->setText("Trier");
    ui->pb_supprimer->setText("Supprimer");
    ui->pushButton_5->setText("Changer");
    ui->pushButton_6->setText("Generer");






}
}
void MainWindow::affrech()
{
    QString selon=ui->selon->currentText();
    QString rech=ui->Rech->text();
     ui->tab_produit->setModel(p.rechercher(selon,rech));
}

void MainWindow::on_pushButton_6_clicked()
{
    if(ui->le_id->text() !="")
    {
        QSqlQuery q("select * from produit where ref="+ui->le_id->text());
        while(q.next())
        {
            ui->le_nom->setText(q.value(1).toString());
            ui->le_prix->setText(q.value(3).toString());
            ui->le_quantite->setText(q.value(4).toString());
            ui->le_categorie->setText(q.value(2).toString());
        }
    }
}
