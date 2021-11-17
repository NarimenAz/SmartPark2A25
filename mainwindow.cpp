#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "cage.h"
#include<QMessageBox>
#include<QIntValidator>
#include <QSqlQuery>
#include <QComboBox>
//print
#include <QPrinter>
#include <QPrintDialog>
#include <QDate>
#include <QTextStream>
//statistique
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QCategoryAxis>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

#include <QtWidgets>
#include <QDialog>
#include <QCheckBox>    //class QCheckBox;
#include <QLabel>       //class QLabel;
#include <QLineEdit>    //class QLineEdit;
#include <QPushButton>  //class QPushButton;
#include <QHBoxLayout>  //in the finddialog.cpp
#include <QVBoxLayout>  //in the finddialog.cpp
//openfile:
#include <QFileDialog>
#include <QDir>
#include <QDialog>
#include <QFile>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->id->setValidator(new QIntValidator(0,99999999, this));
    ui->status->setValidator(new QIntValidator(0, 1, this));
    ui->taille->setValidator(new QIntValidator(1, 99999999, this));
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
        //refresh
        ui->tab_cage->setModel(C.afficher());
        QMessageBox::information(nullptr, QObject::tr("ajout is open"),
                               QObject::tr("successful.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

           }
               else
                   QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                               QObject::tr("erreur.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

                       ui->id->clear();
                       ui->status->clear();
                       ui->taille->clear();
                       ui->type->clear();
                       ui->date->clear();
}

void MainWindow::on_pb_supprimer_clicked()
{
    ///appel du methode supprimer
       cage C1;
       ///acoorder a V1 l id saisie au niveau du line edit

       C1.setid(ui->comboBox->currentText().toInt());

       ///appel du methode supprimer
       /// recuperer le resultat dans test
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
                        ui->id->clear();
                        ui->status->clear();
                        ui->taille->clear();
                        ui->type->clear();
                        ui->date->clear();
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



void MainWindow::on_pb_rechercher_clicked()
{
    cage C1;
    C1.setid(ui->id ->text().toInt());
    C1.settaille(ui->taille->text().toInt());

        ui->tab_cage->setModel(C1.chercherCage(C1.getid(),C1.gettaille()));

        ui->id->clear();
        ui->date->clear();
        ui->type->clear();
        ui->taille->clear();
        ui->status->clear();
}

void MainWindow::on_pb_tri_clicked()
{
    ui->tab_cage->setModel(C.trierCage());


    int id=ui->id->text().toInt();
    int status=ui->status->text().toInt();
    int taille=ui->taille->text().toInt();
    QString type=ui->type->text();
    QString date=ui->date->text();
            cage C(id, status,taille,type,date);

            QMessageBox msg;
           if(C.trierCage())
           {
                ui->tab_cage->setModel(C.trierCage());
               msg.setText("ceci est la liste des cages avec tri croissant selon l'ID");
               msg.exec();
           }


           ui->id->clear();
           ui->date->clear();
           ui->type->clear();
           ui->taille->clear();
           ui->status->clear();
}

void MainWindow::on_pushButton_clicked()
{
    QString strStream;
     QTextStream out(&strStream);

                     const int rowCount = ui->tab_cage->model()->rowCount();
                     const int columnCount = ui->tab_cage->model()->columnCount();
                     QString TT = QDate::currentDate().toString("yyyy/MM/dd");

                     out <<"<html>\n"
                           "<head>\n"
                            "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         << "<title>ERP - COMmANDE LIST<title>\n "
                         << "</head>\n"
                         "<body bgcolor=#ffffff link=#5000A0>\n"
                         "<h1 style=\"text-align: center;\"><strong> ******LISTE DES  licence commerciale ******"+TT+" </strong></h1>"
                         "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                           "</br> </br>";
                     // headers
                     out << "<thead><tr bgcolor=#d6e5ff>";
                     for (int column = 0; column < columnCount; column++)
                         if (!ui->tab_cage->isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(ui->tab_cage->model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     // data table
                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!ui->tab_cage->isColumnHidden(column)) {
                                 QString data =ui->tab_cage->model()->data(ui->tab_cage->model()->index(row, column)).toString().simplified();
                                 out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                             }
                         }
                         out << "</tr>\n";
                     }
                     out <<  "</table>\n"
                         "</body>\n"
                         "</html>\n";

                     QTextDocument *document = new QTextDocument();
                     document->setHtml(strStream);
                     QPrinter printer;

                                      QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
                                      if (dialog->exec() == QDialog::Accepted) {
                                          document->print(&printer);
                                      }

                              delete document;

}

QT_CHARTS_USE_NAMESPACE
void MainWindow::on_pushButton_2_clicked()
{
    //ui->stackedWidget_2->setCurrentIndex(1);
        QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from cages where taille < 50 ");
        float taille=model->rowCount();
        model->setQuery("select * from cages where taille  between 50 and 200 ");
        float taillee=model->rowCount();
        model->setQuery("select * from cages where taille >200 ");
        float tailleee=model->rowCount();
        float total=taille+taillee+tailleee;
        QString a=QString("moins de 50 Metre . "+QString::number((taille*100)/total,'f',2)+"%" );
        QString b=QString("entre 50 et 200 Metre .  "+QString::number((taillee*100)/total,'f',2)+"%" );
        QString c=QString("plus de 200 Metre ."+QString::number((tailleee*100)/total,'f',2)+"%" );
        QPieSeries *series = new QPieSeries();
        series->append(a,taille);
        series->append(b,taillee);
        series->append(c,tailleee);
        if (taille!=0)
        {QPieSlice *slice = series->slices().at(0);
            slice->setLabelVisible();
            slice->setPen(QPen());}
        if ( taillee!=0)
        {
            // Add label, explode and define brush for 2nd slice
            QPieSlice *slice1 = series->slices().at(1);
            //slice1->setExploded();
            slice1->setLabelVisible();
        }
        if(tailleee!=0)
        {
            // Add labels to rest of slices
            QPieSlice *slice2 = series->slices().at(2);
            //slice1->setExploded();
            slice2->setLabelVisible();
        }
        // Create the chart widget
        QChart *chart = new QChart();
        // Add data to chart with title and hide legend
        chart->addSeries(series);
        chart->setTitle("cages Par taille :Nombre Des cages "+ QString::number(total));
        chart->legend()->hide();
        // Used to display the chart
        QChartView *chartView = new QChartView(chart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->resize(1000,500);
        chartView->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    QSqlQueryModel *model= new QSqlQueryModel();
                    QSqlQuery   *q= new QSqlQuery();
                    q->prepare("SELECT identifiant from cages");
                    q->exec();
                    model->setQuery(*q); ///
                    ui->comboBox->setModel(model);
}

void MainWindow::on_comboBox_2_activated(const QString &arg1) //combobox modify
{
    QString id=arg1;
         QSqlQueryModel *model= new QSqlQueryModel();
             QSqlQuery   *query= new QSqlQuery();
              query->prepare("SELECT * from cages where identifiant='"+id+"'");
              if(query->exec())
              {
                  while (query->next())
                  {

                      ui->id->setText(query->value(0).toString());
                      ui->status->setText(query->value(1).toString());
                      ui->taille->setText(query->value(2).toString());
                      ui->type->setText(query->value(3).toString());
                      ui->date->setText(query->value(4).toString());


                  }
              }

              model->setQuery(*query);
}

void MainWindow::on_pushButton_4_clicked() //combobox sup
{
    QSqlQueryModel *model= new QSqlQueryModel();
                    QSqlQuery   *q= new QSqlQuery();
                    q->prepare("SELECT identifiant from cages");
                    q->exec();
                    model->setQuery(*q); ///
                    ui->comboBox_2->setModel(model);
}

void MainWindow::on_pushButton_5_clicked()  //clear
{
    ui->id->clear();
    ui->date->clear();
    ui->type->clear();
    ui->taille->clear();
    ui->status->clear();
}



void MainWindow::on_pushButton_7_clicked()
{
    files.clear();

        QFileDialog dialog(this);
        dialog.setDirectory(QDir::homePath());
        dialog.setFileMode(QFileDialog::ExistingFiles);

        if (dialog.exec())
            files = dialog.selectedFiles();

        QString fileListString;
        foreach(QString file, files)
            fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

        ui->file->setText( fileListString );
}
