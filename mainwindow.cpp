 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include "animaux.h"
#include "employee.h"
//#include "widget.h"
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
#include <QValidator>
#include"notification.h"
#include <QPrinter>
#include <QtPrintSupport/QPrinter>
#include <QPrintDialog>
#include <QDate>
#include<QFileDialog>
#include <QTextDocument>
#include <QTextStream>
#include <QPdfWriter>
#include <QSystemTrayIcon>

#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

#include <string>
#include <vector>
#include<QDirModel>
#include <qrcode.h>

#include <iostream>
#include <fstream>
#include <QtSvg/QSvgRenderer>
#include "qrcode.h"

#include<QRegularExpression>
# include "notification.h"
#include <QPainter>
#include <QSqlQueryModel>
#include <QSystemTrayIcon>
#include <QTextStream>
#include<QDirModel>

#include"visiteur.h"
#include "excel.h"

#include <QPixmap>

#include "cage.h"
#include <QComboBox>
#include <QtWidgets>
#include "evenement.h"

#include "smtp.h"

#include <QPixmap>

using qrcodegen::QrCode;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
ui->tab_animaux->setModel(A.afficherAnim());
        ui->le_idAnim->setValidator( new QIntValidator(0, 99999999, this));
        ui->le_age->setValidator( new QIntValidator(0, 999, this));
        ui->le_nom->setMaxLength(15); // max longueur de nom (line_edit)
        ui->le_status->setMaxLength(15);
        ui->le_nom->setInputMask("A<AAAAAAAAAAA AAAAAAAA");
        ui->le_pays->setInputMask("A<AAAAAAAAAAAAAAA");
        ui->le_rechercher->setPlaceholderText(QString("Research ID ,REGIME , TYPE "));



        /****** OMAR GEST EMPLOYES ***/


        ui->stackedWidget->setCurrentIndex(1);
    ui->tab_employee->setModel(E.afficherEmploye());
    ui->le_idemploye->setValidator(new QIntValidator(1000,9999,this));
    ui->le_telemploye->setValidator(new QIntValidator(10000000,99999999,this));
    ui->password_1->setValidator(new QIntValidator(0,9999,this));
    ui->le_salaireemploye->setValidator(new QIntValidator(0,999999999,this));


     /****** arbia gest visiteur ***/



      ui->le_idvisiteur->setValidator(new QIntValidator(0,99999999,this));
      ui->le_agevisiteur->setValidator(new QIntValidator(0,99,this));
    ui->tab_visiteur->setModel(V.afficherV());


    /****** aziz gest cages ***/


    ui->idcage->setValidator(new QIntValidator(0,99999999, this));
    ui->statuscage->setValidator(new QIntValidator(0, 1, this));
    ui->taillecage->setValidator(new QIntValidator(1, 99999999, this));
    ui->tab_cage->setModel(C.affichercage());

    /****** youssef gest event ***/

    ui->table_event->setModel(e.afficherEvent());
    ui->lineEdit_IDevent->setValidator(new QIntValidator(0,9999999,this));
    ui->lineEdit_NbEmployesevent->setValidator(new QIntValidator(0,999,this));



    /******************  narimen gest produit ************************/




    QPixmap pix("C:/Users/asus/Desktop/integration/fond");
    QPixmap pix1("C:/Users/asus/Desktop/integration/back");
    ui->labelanimaux->setPixmap(pix);
    ui->labelphotoemploye->setPixmap(pix);
    ui->labelphotocage->setPixmap(pix);
    ui->labelphotoproduit->setPixmap(pix);
    ui->labelphotoevent->setPixmap(pix);
    ui->labelvisiteurs->setPixmap(pix);

    ui->labelphotologin->setPixmap(pix1);

    QIntValidator *val=new QIntValidator(100000,999999,this);
    ui->le_idproduit->setValidator(val);
      connect(ui->Rechproduit, SIGNAL(textChanged(QString)), this, SLOT(affrech()));
 p.statproduit(series);

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


    ui->tab_produit->setModel(p.afficherproduit());


}
MainWindow::~MainWindow()
{
    delete ui;


}

QModelIndex MainWindow::on_tab_animaux_activated( QModelIndex index)
{
    index =ui->tab_animaux->currentIndex();
    return (index);

}


bool MainWindow::search(int t)
{bool test=false;

       for (int var = 0; var < ui->tab_animaux->model()->rowCount(); ++var) {
           if(ui->tab_animaux->model()->index(var,0).data().toInt()==t){

              test=true;
           }
       }
       return test;
}



/********************************   afficher  *****************************/
void MainWindow::on_pb_afficher_clicked()
{
    ui->tab_animaux->setModel(A.afficherAnim());

}



/********************************   ajouter  *****************************/
void MainWindow::on_bp_ajouter_clicked()
{

    Notification N;
    int idAnim=ui->le_idAnim->text().toInt();
    QString nomAnim=ui->le_nom->text();
    QString typeAnim=ui->le_typeAnimal->text();
    int ageAnim=ui->le_age->text().toInt();
    QString pays=ui->le_pays->text();
    QString regimeAliment=ui->le_regime->text();
    QString status=ui->le_status->text();

    ui->le_nom->setMaxLength(15); // max longueur de nom (line_edit)
    ui->le_status->setMaxLength(15);

        animaux A(idAnim, nomAnim,typeAnim,pays,ageAnim,status,regimeAliment );
        bool test=A.ajouterAnim();
        QMessageBox msgBox;

        if(test)
           {
               ui->tab_animaux->setModel(A.afficherAnim());
               N.notification_ajoutanimau();

                msgBox.setText("Ajout avec succes.");

           }
        else
            msgBox.setText("Echec d'ajout.!!!");
            msgBox.exec();


                   ui->le_nom->clear();
                   ui->le_pays->clear();
                   ui->le_idAnim->clear();
                   ui->le_status->clear();
                   ui->le_typeAnimal->clear();
                   ui->le_regime->clear();
                   ui->le_age->clear();

}




/********************************   supprimer  *****************************/
void MainWindow::on_pb_supprimer_clicked()
{

    Notification N;
    QMessageBox msgBox;
    QModelIndex index;
    index=on_tab_animaux_activated(index);
    QVariant value=ui->tab_animaux->model()->data(index);
    QString v=value.toString();

    ui->le_idAnim->setText(v);

    animaux A1;
    A1.setidAnim(ui->le_idAnim ->text().toInt());

    int c=A1.getidAnim();
    bool t=search(c);
    qDebug() << t;


    if(t==false)
    {
        QMessageBox::critical(nullptr, QObject::tr("CIN exist"),
                    QObject::tr("supression failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }

    else
       {
    bool test=A1.supprimerAnim(A1.getidAnim());



    if(test)
       { N.notification_supprimeranimau();
        msgBox.setText("suppression  avec succes.");
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
        ui->le_regime->clear();
        ui->le_age->clear();


     }
}

/********************************   ACTIVE  TABLE  *****************************/


void MainWindow::on_tab_animaux_clicked(const QModelIndex &index)
{
    ui->le_idAnim->setText(ui->tab_animaux->model()->data(ui->tab_animaux->model()->index(index.row(),0)).toString());
     ui->le_nom->setText(ui->tab_animaux->model()->data(ui->tab_animaux->model()->index(index.row(),1)).toString());
      ui->le_typeAnimal->setText(ui->tab_animaux->model()->data(ui->tab_animaux->model()->index(index.row(),2)).toString());
       ui->le_age->setText(ui->tab_animaux->model()->data(ui->tab_animaux->model()->index(index.row(),3)).toString());
        ui->le_pays->setText(ui->tab_animaux->model()->data(ui->tab_animaux->model()->index(index.row(),4)).toString());
          ui->le_regime->setText(ui->tab_animaux->model()->data(ui->tab_animaux->model()->index(index.row(),5)).toString());
           ui->le_status->setText(ui->tab_animaux->model()->data(ui->tab_animaux->model()->index(index.row(),6)).toString());
}





/********************************  modifier  *****************************/
void MainWindow::on_pb_modifier_clicked()
{
    Notification N;
    QModelIndex index;
    index=on_tab_animaux_activated(index);
    QVariant value=ui->tab_animaux->model()->data(index);
    QString v=value.toString();

    ui->le_idAnim->setText(v);



    int idAnim=ui->le_idAnim->text().toInt();
    QString nomAnim=ui->le_nom->text();
    QString typeAnim=ui->le_typeAnimal->text();
    int ageAnim=ui->le_age->text().toInt();
    QString pays=ui->le_pays->text();
    QString regimeAliment=ui->le_regime->text();
    QString status=ui->le_status->text();
    animaux A(idAnim, nomAnim,typeAnim,pays,ageAnim,status,regimeAliment );


    bool test=A.modifierAnim(A.getidAnim(),A.getNomAnim(),A.gettypeAnim(),A.getpays(),A.getageAnim(),A.getregimealim(),A.getstatus());

    QMessageBox msgBox;

    if(test)
       {
        N.notification_modifieranimau();
        msgBox.setText("Modification avec succes.");
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
        ui->le_regime->clear();
        ui->le_age->clear();
}
/*
void MainWindow::on_le_rechercher_textEdit()
{
    QString rech=ui->le_rechercher->text();
       ui->tab_animaux->setModel(A.chercheranimal(rech));
       ui->le_rechercher->clear();
}

*/


/********************************   rechercher  *****************************/
/*void MainWindow::on_pb_rechercher_clicked()
{
    animaux A1;
    A1.setidAnim(ui->le_idAnim ->text().toInt());
    A1.settypeAnim(ui->le_typeAnimal ->text());
    A1.setregimealim(ui->le_regime->text());

        ui->tab_animaux->setModel(A1.chercherAnim(A1.getidAnim(),A1.gettypeAnim(),A1.getregimealim()));



        ui->le_idAnim->clear();
        ui->le_typeAnimal->clear();
        ui->le_regime->clear();
       */


//recherche avancé avec trois critères

   /* QString rech=ui->le_rechercher->text();
       ui->tab_animaux->setModel(A.chercheranimal(rech));
       ui->le_rechercher->clear();



}
*/

/********************************   trier  *****************************/

void MainWindow::on_comboBox_trier_activated()
{
    if(ui->comboBox_trier->currentText()=="tri par id")
        ui->tab_animaux->setModel(A.trierAnim());
    if(ui->comboBox_trier->currentText()=="tri par age")
        ui->tab_animaux->setModel(A.trierAnimAge());
    if(ui->comboBox_trier->currentText()=="tri par pays")
        ui->tab_animaux->setModel(A.trierAnimpays());

}

/********************************   reset  *****************************/
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
        ui->le_regime->clear();
        ui->le_age->clear();

}



/********************************  pdf   *****************************/

void MainWindow::on_pb_pdf_clicked()
{
    QString strStream;
    strStream = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
        if (QFileInfo(strStream).suffix().isEmpty()) { strStream.append(".pdf"); }

        QPrinter printer(QPrinter::PrinterResolution);
        printer.setOutputFormat(QPrinter::PdfFormat);
        printer.setPaperSize(QPrinter::A4);
        printer.setOutputFileName(strStream);



              QTextStream out(&strStream);

              const int rowCount = ui->tab_animaux->model()->rowCount();
              const int columnCount = ui->tab_animaux->model()->columnCount();
              QString TT = QDateTime::currentDateTime().toString();
              out <<"<html>\n"
                    "<head>\n"
                     "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                  << "<title>ERP - COMmANDE LIST<title>\n "
                  << "</head>\n"
                  "<body bgcolor=#ffffff link=#5000A0>\n"
                     "<h1 style=\"text-align: center;\"><strong> "+TT+"</strong></h1>"
                    +"<img src=C:\\Users\\asus\\Desktop\\pdf\\logo_projet />"
                  "<h1 style=\"text-align: center;\"><strong> ******LISTE DES ANIMAUX ****** </strong></h1>"

                  "<table style=\"text-align: center; font-size: 10px;\" border=1>\n "
                    "</br> </br>";
              // headers
              out << "<thead><tr bgcolor=#d6e5ff>";
              for (int column = 0; column < columnCount; column++)
                  if (!ui->tab_animaux->isColumnHidden(column))
                      out << QString("<th>%1</th>").arg(ui->tab_animaux->model()->headerData(column, Qt::Horizontal).toString());
              out << "</tr></thead>\n";

              // data table
              for (int row = 0; row < rowCount; row++) {
                  out << "<tr>";
                  for (int column = 0; column < columnCount; column++) {
                      if (!ui->tab_animaux->isColumnHidden(column)) {
                          QString data =ui->tab_animaux->model()->data(ui->tab_animaux->model()->index(row, column)).toString().simplified();
                          out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                      }
                  }
                  out << "</tr>\n";
              }
              out <<  "</table>\n"
                  "</body>\n"
                  "</html>\n";

              QTextDocument document;
              document.setHtml(strStream);
              document.print(&printer);

}


/********************************  imprimer   *****************************/
void MainWindow::on_pb_imprimer_clicked()
{

    QString strStream;
                 QTextStream out(&strStream);

                 const int rowCount = ui->tab_animaux->model()->rowCount();
                 const int columnCount = ui->tab_animaux->model()->columnCount();
                 QString TT = QDateTime::currentDateTime().toString();
                 out <<"<html>\n"
                       "<head>\n"
                        "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                     << "<title>ERP - COMmANDE LIST<title>\n "
                     << "</head>\n"
                     "<body bgcolor=#ffffff link=#5000A0>\n"
                        "<h1 style=\"text-align: center;\"><strong> "+TT+"</strong></h1>"
                        +"<img src=C:\\Users\\asus\\Desktop\\pdf\\logo_projet />"
                        "<h1 style=\"text-align: center;\"><strong> ******LISTE DES  licence commerciale ****** </strong></h1>"


                     "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                       "</br> </br>";
                 // headers
                 out << "<thead><tr bgcolor=#d6e5ff>";
                 for (int column = 0; column < columnCount; column++)
                     if (!ui->tab_animaux->isColumnHidden(column))
                         out << QString("<th>%1</th>").arg(ui->tab_animaux->model()->headerData(column, Qt::Horizontal).toString());
                 out << "</tr></thead>\n";

                 // data table
                 for (int row = 0; row < rowCount; row++) {
                     out << "<tr>";
                     for (int column = 0; column < columnCount; column++) {
                         if (!ui->tab_animaux->isColumnHidden(column)) {
                             QString data =ui->tab_animaux->model()->data(ui->tab_animaux->model()->index(row, column)).toString().simplified();
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




/********************************  statistiques   *****************************/


void MainWindow::on_pb_stat_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                     model->setQuery("select * from animaux where AGE_ANIMAL < 5 ");
                     float age=model->rowCount();
                     model->setQuery("select * from animaux where AGE_ANIMAL  between 5 and 10 ");
                     float agee=model->rowCount();
                     model->setQuery("select * from animaux where AGE_ANIMAL>10 ");
                     float ageee=model->rowCount();
                     float total=age+agee+ageee;
                     QString a=QString("moins de 5 ans "+QString::number((age*100)/total,'f',2)+"%" );
                     QString b=QString("entre 5 et 10 Ans"+QString::number((agee*100)/total,'f',2)+"%" );
                     QString c=QString("+10 Ans"+QString::number((ageee*100)/total,'f',2)+"%" );
                     QPieSeries *series = new QPieSeries();
                     series->append(a,age);
                     series->append(b,agee);
                     series->append(c,ageee);
             if (age!=0)
             {QPieSlice *slice = series->slices().at(0);
              slice->setLabelVisible();
              slice->setPen(QPen());}
             if ( agee!=0)
             {
                      // Add label, explode and define brush for 2nd slice
                      QPieSlice *slice1 = series->slices().at(1);
                      //slice1->setExploded();
                      slice1->setLabelVisible();
             }
             if(ageee!=0)
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
                     chart->setTitle("Pourcentage Par Age :Nombre Des Aimaux "+ QString::number(total));
                     chart->legend()->hide();
                     // Used to display the chart
                     QChartView *chartView = new QChartView(chart);
                     chartView->setRenderHint(QPainter::Antialiasing);
                     chartView->resize(1000,500);
                     chartView->show();


             /************************   statistique par regime   *****************************/


                     //QSqlQueryModel * model1= new QSqlQueryModel();

                     int i=0,j=0,k=0;
                     for (int var = 0; var < ui->tab_animaux->model()->rowCount(); ++var) {
                             if(ui->tab_animaux->model()->index(var,5).data().toString()=="herbivore"){

                                 i++;

                             }
                             else if(ui->tab_animaux->model()->index(var,5).data().toString()=="carnivore")
                             {
                                 j++;
                             }
                             else
                                 k++;
                         }


                                      float total1=i+j+k;
                                      QString a1=QString("herbivore "+QString::number((i*100)/total1,'f',2)+"%" );
                                      QString b1=QString("autre"+QString::number((k*100)/total1,'f',2)+"%" );
                                      QString c1=QString("carnivore"+QString::number((j*100)/total1,'f',2)+"%" );
                                      QPieSeries *series1 = new QPieSeries();
                                      series1->append(a1,i);
                                      series1->append(b1,k);
                                      series1->append(c1,j);
                              if (i!=0)
                              {QPieSlice *slice3 = series1->slices().at(0);
                               slice3->setLabelVisible();
                               slice3->setPen(QPen());}
                              if ( k!=0)
                              {
                                       // Add label, explode and define brush for 2nd slice
                                       QPieSlice *slice4 = series1->slices().at(1);
                                       //slice4->setExploded();
                                       slice4->setLabelVisible();
                              }
                              if(j!=0)
                              {
                                       // Add labels to rest of slices
                                       QPieSlice *slice5 = series1->slices().at(2);
                                       //slice1->setExploded();
                                       slice5->setLabelVisible();
                              }
                                      // Create the chart widget
                                      QChart *chart1 = new QChart();
                                      // Add data to chart with title and hide legend
                                      chart1->addSeries(series1);
                                      chart1->setTitle("Pourcentage Par regime :Nombre Des Aimaux "+ QString::number(total1));
                                      chart1->legend()->hide();
                                      // Used to display the chart
                                      QChartView *chartView1 = new QChartView(chart1);
                                      chartView1->setRenderHint(QPainter::Antialiasing);
                                      chartView1->resize(1000,500);
                                      chartView1->show();
}




/********************************  qrcode   *****************************/
void MainWindow::on_pb_code_clicked()
{

     animaux A;
    if(ui->tab_animaux->currentIndex().row()==-1)
           QMessageBox::information(nullptr, QObject::tr("Suppression"),
                                    QObject::tr("Veuillez Choisir un animal du Tableau.\n"
                                                "Click Ok to exit."), QMessageBox::Ok);
       else
       {




                   A.setidAnim(ui->le_idAnim ->text().toInt());
                   A.setNomAnim(ui->le_nom ->text());
                   A.settypeAnim(ui->le_typeAnimal ->text());
                   A.setageAnim(ui->le_age ->text().toInt());
                   A.setpays(ui->le_pays ->text());
                   A.setregimealim(ui->le_regime ->text());
                   A.setstatus(ui->le_status ->text());
           // int idAnim=ui->tab_animaux->model()->data(ui->tab_animaux->model()->index(ui->tab_animaux->currentIndex().row(),0)).toInt();





         QString  rawQr = "ID_ANIMAL:%1 Nom_ANIMAL:%2 TYPE_ANIMAL:%3 AGE_ANIMAL:%4 PAYS:%5 REGIME_ALIMENT:%6 STATUS:%7 " ;
            rawQr = rawQr.arg(A.getidAnim()).arg(A.getNomAnim()).arg(A.gettypeAnim()).arg(A.getageAnim()).arg(A.getpays()).arg(A.getregimealim()).arg(A.getstatus());
            QrCode qr = QrCode::encodeText(rawQr.toUtf8().constData(), QrCode::Ecc::HIGH);


          //  const QrCode qr = QrCode::encodeText(std::to_string(idAnim).c_str(), QrCode::Ecc::LOW);
            std::ofstream myfile;
            myfile.open ("qrcode.svg") ;
            myfile << qr.toSvgString(1);
            myfile.close();
            QSvgRenderer svgRenderer(QString("qrcode.svg"));
            QPixmap pix( QSize(140, 140) );
            QPainter pixPainter( &pix );
            svgRenderer.render( &pixPainter );
            ui->label_qrcode->setPixmap(pix);
       }
}


void MainWindow::on_le_rechercher_textEdited(const QString &arg1)
{
    ui->tab_animaux->setModel(A.chercher(arg1));
}





/************************* gestion des employe   omar ******************************/

    /************************* gestion des employe   omar ******************************/

        /************************* gestion des employe   omar ******************************/


            /************************* gestion des employe   omar ******************************/




void MainWindow::on_tab_employee_clicked(const QModelIndex &index)
{
    ui->le_idemploye->setText(ui->tab_employee->model()->data(ui->tab_employee->model()->index(index.row(),0)).toString());
     ui->le_nomemploye->setText(ui->tab_employee->model()->data(ui->tab_employee->model()->index(index.row(),1)).toString());
     ui->le_prenomemploye->setText(ui->tab_employee->model()->data(ui->tab_employee->model()->index(index.row(),2)).toString());
     ui->le_telemploye->setText(ui->tab_employee->model()->data(ui->tab_employee->model()->index(index.row(),3)).toString());
     ui->le_specialiteemploye->setText(ui->tab_employee->model()->data(ui->tab_employee->model()->index(index.row(),4)).toString());
     ui->le_adressemploye->setText(ui->tab_employee->model()->data(ui->tab_employee->model()->index(index.row(),5)).toString());
     ui->le_salaireemploye->setText(ui->tab_employee->model()->data(ui->tab_employee->model()->index(index.row(),6)).toString());
}





void MainWindow::on_pb_ajouteremploye_clicked()
{
    QString id=ui->le_idemploye->text();
    QString nomemploy=ui->le_nomemploye->text();
    QString prenom=ui->le_prenomemploye->text();
    int tel=ui->le_telemploye->text().toInt();
    QString specialite=ui->le_specialiteemploye->text();
        QString adress=ui->le_adressemploye->text();
        float salaire=ui->le_salaireemploye->text().toFloat();



             employee E (id,tel,nomemploy,prenom,specialite,adress,salaire);
            bool test=E.ajouterEmploye();
            QMessageBox msgBox;

            if(test)
               {

                msgBox.setText("Ajout avec succes.");
                ui->tab_employee->setModel(E.afficherEmploye());
               }
            else
                msgBox.setText("Echec d'ajout.!!!");
                msgBox.exec();

}

void MainWindow::on_pb_supprimeremploye_clicked()
{
   /* employee E1; E1.setIdEmploy(ui->comboBoxemploye->currentText());
       bool test=E1.supprimerEmploye(E1.getIdEmploy());
QMessageBox msgbox;
if(test)
{msgbox.setText("suppressino avec succes ");
 ui->tab_employee->setModel(E.afficherEmploye());

}
else
    msgbox.setText("echec de suppression  ");
      msgbox.exec();
      */

      /******************/

      ///appel du methode supprimer
         employee C1;
         ///acoorder a V1 l id saisie au niveau du line edit

         C1.setIdEmploy(ui->le_idemploye->text());

         bool test=C1.supprimerEmploye(C1.getIdEmploy());

      if (test)

      {
          //refresh
          ui->tab_employee->setModel(C1.afficherEmploye());

          QMessageBox::information(nullptr, QObject::tr("suppression is open"),
                                 QObject::tr("successful.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);


             }
                 else
                     QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                 QObject::tr("erreur.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
                          ui->le_idemploye->clear();
                          ui->le_telemploye->clear();
                          ui->le_nomemploye->clear();
                          ui->le_prenomemploye->clear();
                          ui->le_salaireemploye->clear();
                          ui->le_adressemploye->clear();
                          ui->le_specialiteemploye->clear();


}


void MainWindow::on_pb_modifieremploye_clicked()
{


    int tel=ui->le_telemploye->text().toInt();
    float salaire=ui->le_salaireemploye->text().toFloat();
        QString nomemploy=ui->le_nomemploye->text();
        QString adress=ui->le_adressemploye->text();
        QString prenom=ui->le_prenomemploye->text();
        QString specialite=ui->le_specialiteemploye->text();
        QString id=ui->le_idemploye->text();


               employee E (id,tel,nomemploy,prenom,specialite,adress,salaire);

                bool test=E.modifierEmploye(E.getIdEmploy(),E.getTel(),E.getNomEmploy(),E.getPrenomEmploy(),E.getSpecialite(),E.getAdress(),E.getsalaire());

                QMessageBox msgBox;

                if(test)
                    {
                        msgBox.setText("Modification avec succes.");
                        ui->tab_employee->setModel(E.afficherEmploye());
                    }
                else
                    msgBox.setText("Echec de Modification!!!!!!");
                    msgBox.exec();
    }





void MainWindow::on_login_1_clicked()
{


    QString username = ui->username_1->text();
             QString password = ui->password_1->text();

             if (username == "admin" && password == "1234") {
                 QMessageBox::information(this, "Login", "Username and password are correct");
              ui->stackedWidget->setCurrentIndex(0);

             }
             else {
                 QMessageBox::warning(this, "Login", "Username and password are not correct");
             }
             ui->username_1->clear();
             ui->password_1->clear();


}

void MainWindow::on_load_pt_clicked()
{
    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery *query= new QSqlQuery();
    query->prepare("SELECT id from EMPLOYEE") ;
    query->exec();
    model->setQuery(*query);
    ui->comboBoxemploye->setModel(model);

}

void MainWindow::on_pb_triidemploye_clicked()
{
    employee e ;
    ui->tab_employee->setModel(e.trierEmploye());
}

void MainWindow::on_pb_trinomemploye_clicked()
{
    employee e ;
    ui->tab_employee->setModel(e.trierEmploye1());
}

void MainWindow::on_pb_triprenomemploye_clicked()
{
    employee e ;
    ui->tab_employee->setModel(e.trierEmploye2());
}

void MainWindow::on_pb_rechercheremploye_clicked()
{
    employee e ;
    QString rech =ui->rechemploye->text();
    if (rech=="")

        ui->tab_employee->setModel(e.afficherEmploye());
    else
        ui->tab_employee->setModel(e.rechercherEmploye(rech));

}

void MainWindow::on_pb_calculemploye_clicked()
{
    QSqlQuery query=E.calculerSalaire();
        query.exec();
        query.next();
        ui->le_somme_salaireemploye->setText(query.value(0).toString());
}

void MainWindow::on_camera_pt1_clicked()
{
Widget w ;
w.setModal(true);
w.exec();

}

/*************************   visiteur arbia  ****************************/

    /*************************   visiteur arbia  ****************************/

        /*************************   visiteur arbia  ****************************/

            /*************************   visiteur arbia  ****************************/





void MainWindow::on_tab_visiteur_clicked(const QModelIndex &index)
{

    ui->le_adressevisiteur->setText(ui->tab_visiteur->model()->data(ui->tab_visiteur->model()->index(index.row(),0)).toString());
    ui->le_agevisiteur->setText(ui->tab_visiteur->model()->data(ui->tab_visiteur->model()->index(index.row(),1)).toString());

    ui->le_idvisiteur->setText(ui->tab_visiteur->model()->data(ui->tab_visiteur->model()->index(index.row(),2)).toString());
     ui->le_nomvisiteur->setText(ui->tab_visiteur->model()->data(ui->tab_visiteur->model()->index(index.row(),3)).toString());
     ui->le_prenomvisiteur->setText(ui->tab_visiteur->model()->data(ui->tab_visiteur->model()->index(index.row(),4)).toString());



}
void MainWindow  ::on_pb_ajoutervisiteur_clicked()
{ ///recuperation des valeurs saisie dans le line edite pour visiteurs
    int id=ui->le_idvisiteur->text().toInt();
    QString nom=ui->le_nomvisiteur->text();
    QString prenom=ui->le_prenomvisiteur->text();
    int age=ui->le_agevisiteur->text().toInt();
    QString adresse=ui->le_adressevisiteur->text();

///appel du constructeur parametre des variables du line edit
    visiteur V(id,nom,prenom,age,adresse);

    bool test=V.ajouterV();
    if (test)

    {   ///refresh =actualisation de l'affichage
         ui->tab_visiteur->setModel(V.afficherV());

         V.notification_ajouteV();
        QMessageBox ::information(nullptr, QObject::tr("Gestion_Visiteurs"),
                                   QObject::tr("ajout effectue\n"
                                                           "Click Cancel to exit."),QMessageBox::Cancel);
     }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                              QObject::tr("Ajout non effectue.\n"
                                          "Click Cancel to exit."),QMessageBox::Cancel);



///control de saisie

    ui->le_idvisiteur->clear();
    ui->le_nomvisiteur->clear();
    ui->le_prenomvisiteur->clear();
    ui->le_agevisiteur->clear();
    ui->le_adressevisiteur->clear();

}



void MainWindow::on_pb_modifiervisiteur_clicked()
{

    int id=ui->le_idvisiteur->text().toInt();
    QString nom=ui->le_nomvisiteur->text();
    QString prenom=ui->le_prenomvisiteur->text();
    int age=ui->le_agevisiteur->text().toInt();
    QString adresse=ui->le_adressevisiteur->text();

///appel du constructeur parametre des variables du line edit
    visiteur V(id,nom,prenom,age,adresse);

    bool test=V.modifierV();

    if (test)

    {
         V.notification_modifierV();
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




//----refresh de l'affichage


void MainWindow::on_pb_actualvisiteur_clicked()
{

    ui->tab_visiteur->setModel(V.afficherV());


}



//----modifier avec control de saisie



void MainWindow::on_pb_loadvisiteur_clicked()
{


    /// aabit comboox b idvisiteur


             QSqlQueryModel *model= new QSqlQueryModel();
             QSqlQuery   *q= new QSqlQuery();
             q->prepare("SELECT idvisiteur from VISITEURS");
             q->exec();
             model->setQuery(*q);

             //ui->comboBox_modifvisiteur->setModel(model);





}

void MainWindow::on_comboBox_modifvisiteur_activated(const QString &arg1)
{
    QString id=arg1;
     QSqlQueryModel *model= new QSqlQueryModel();
         QSqlQuery   *query= new QSqlQuery();
          query->prepare("SELECT * from VISITEURS where idvisiteur='"+id+"'");
          if(query->exec())
          {
              while (query->next())
              {

                  ui->le_idvisiteur->setText(query->value(0).toString());
                  ui->le_nomvisiteur->setText(query->value(1).toString());
                  ui->le_prenomvisiteur->setText(query->value(2).toString());
                  ui->le_agevisiteur->setText(query->value(3).toString());
                  ui->le_adressevisiteur->setText(query->value(4).toString());


              }
          }

          model->setQuery(*query);




}




          ///************les metiers***********





//  tripar id---

  void MainWindow::on_triidvisiteur_clicked()

{


   ui->tab_visiteur->setModel(V.trierVisiteur());


}


  //  statiqtique---


void MainWindow::on_pb_statvisiteur_clicked()
{


    QT_CHARTS_USE_NAMESPACE;


            QSqlQueryModel * model= new QSqlQueryModel();
            model->setQuery("select * from VISITEURS where age_visiteur < 18 ");
            int age=model->rowCount();///compter le nombre de ligne affecte par la requette select

            model->setQuery("select * from VISITEURS where age_visiteur between 18 and 50");
            int agee=model->rowCount();
            model->setQuery("select * from VISITEURS where age_visiteur >50 ");
            int ageee=model->rowCount();
            int total=age+agee+ageee;

            QString a=QString("moins de 18 Ans . "+QString::number((age*100)/total,'f',2)+"%" );
            QString b=QString("entre 18 et 50 Ans .  "+QString::number((agee*100)/total,'f',2)+"%" );
            QString c=QString("plus de 50 Ans ."+QString::number((ageee*100)/total,'f',2)+"%" );


            QPieSeries *series = new QPieSeries();
            series->append(a,age);
            series->append(b,agee);
            series->append(c,ageee);


            if (age!=0)
            {QPieSlice *slice = series->slices().at(0); ///slice renvoie un objet tableau contenent une copie superficielled'une portion du  tableau d'un tableau original
                slice->setLabelVisible();
                slice->setPen(QPen());}
            if ( agee!=0)
            {
                // Add label, explode and define brush for 2nd slice
                QPieSlice *slice1 = series->slices().at(1); ///nhseb poucentage mtaa ctual slice
                //slice1->setExploded();
                slice1->setLabelVisible();
            }

            if(ageee!=0)
            {
                // Add labels to rest of slices
                QPieSlice *slice2 = series->slices().at(2);
                //slice1->setExploded();
                slice2->setLabelVisible();/// tafichi slice
            }
            // Create the chart widget
            QChart *chart = new QChart();

            // Add data to chart with title and hide legend
            chart->addSeries(series);
            chart->setTitle("visiteurs Par id :Nombre Des visiteurs "+ QString::number(total));
            chart->legend()->hide();

            // Used to display the chart
            QChartView *chartView = new QChartView(chart); //creation du fenetre widget
            chartView->setRenderHint(QPainter::Antialiasing);
            chartView->resize(1000,500);
            chartView->show();


}


///fichier excel


//-----tri par nom


void MainWindow::on_le_trinomvisiteur_clicked()
{
   ui->tab_visiteur->setModel(V.trierVisiteur2());
}

//------tri par age
void MainWindow::on_le_triagevisiteur_clicked()
{

   ui->tab_visiteur->setModel(V.trierVisiteur3());

}

//---fichier excel

void MainWindow::on_le_fich_excel_clicked()
{

    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                        tr("Excel Files (*.xls)"));
        if (fileName.isEmpty())
            return;

        ExportExcelObject obj(fileName, "mydata", ui->tab_visiteur);   ///

        //colums to export
        obj.addField(2, "id", "char(20)");
        obj.addField(3, "nom", "char(20)");
        obj.addField(4, "prenom", "char(20)");
        obj.addField(1, "age", "char(20)");
        obj.addField(0, "adresse", "char(20)");


        int retVal = obj.export2Excel();
        if( retVal > 0)
        {
            QMessageBox::information(this, tr("Done"),
                                     QString(tr("%1 records exported!")).arg(retVal)
                                     );
        }

}


//-----recherche avance

void MainWindow::on_le_rechvisiteur_textEdited(const QString &arg1)
{
       ui->tab_visiteur->setModel(V.chercherVisiteur(arg1));
}

//-----suppression avec control de saisie
void MainWindow::on_pb_chargementtvisiteur_clicked()
{

    QSqlQueryModel *model= new QSqlQueryModel();
    QSqlQuery   *q= new QSqlQuery();
    q->prepare("SELECT idvisiteur from VISITEURS");
    q->exec();
    model->setQuery(*q); ///
  //  ui->comboBoxxvisiteur->setModel(model);

}

void MainWindow::on_le_id_supprimerrvisiteur_clicked()
{
    ///appel du methode supprimer
   visiteur V1;
   ///acoorder a V1 l id saisie au niveau du line edit

   V1.setIdVisiteur(ui->le_idvisiteur->text().toInt());

   ///appel du methode supprimer
   /// recuperer le resultat dans test
   bool test=V1.supprimerV(V1.getIdVisiteur());

   ///afficherd'un un message
   if (test)
   {
       V1.notification_supprimerV();
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





/*************************   cage aziz  ****************************/

    /*************************   cage aziz  ****************************/

        /*************************   cage aziz  ****************************/

            /*************************   cage aziz  ****************************/




void MainWindow::on_tab_cage_clicked(const QModelIndex &index)
{
    ui->idcage->setText(ui->tab_cage->model()->data(ui->tab_cage->model()->index(index.row(),0)).toString());
    ui->typecage->setText(ui->tab_cage->model()->data(ui->tab_cage->model()->index(index.row(),1)).toString());
    ui->datecage->setText(ui->tab_cage->model()->data(ui->tab_cage->model()->index(index.row(),2)).toString());
     ui->statuscage->setText(ui->tab_cage->model()->data(ui->tab_cage->model()->index(index.row(),3)).toString());
      ui->taillecage->setText(ui->tab_cage->model()->data(ui->tab_cage->model()->index(index.row(),4)).toString());


}




void MainWindow::on_pb_ajoutercage_clicked()
{
    int id=ui->idcage->text().toInt();
    int status=ui->statuscage->text().toInt();
    int taille=ui->taillecage->text().toInt();
    QString type=ui->typecage->text();
    QString date=ui->datecage->text();

    cage C(id,status,taille,type,date);
    bool test=C.ajoutercage();
    if (test)

    {
        //refresh
        ui->tab_cage->setModel(C.affichercage());
        QMessageBox::information(nullptr, QObject::tr("ajout is open"),
                               QObject::tr("successful.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

           }
               else
                   QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                               QObject::tr("erreur.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);

                       ui->idcage->clear();
                       ui->statuscage->clear();
                       ui->taillecage->clear();
                       ui->typecage->clear();
                       ui->datecage->clear();
}

void MainWindow::on_pb_supprimercage_clicked()
{
    ///appel du methode supprimer
       cage C1;
       ///acoorder a V1 l id saisie au niveau du line edit

       C1.setidcage(ui->idcage->text().toInt());

       ///appel du methode supprimer
       /// recuperer le resultat dans test
       bool test=C1.supprimercage(C1.getidcage());

    if (test)

    {
        //refresh
        ui->tab_cage->setModel(C1.affichercage());

        QMessageBox::information(nullptr, QObject::tr("suppression is open"),
                               QObject::tr("successful.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);


           }
               else
                   QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                               QObject::tr("erreur.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
                        ui->idcage->clear();
                        ui->statuscage->clear();
                        ui->taillecage->clear();
                        ui->typecage->clear();
                        ui->datecage->clear();
}




void MainWindow::on_pb_modifiercage_clicked()
{
    int id=ui->idcage->text().toInt();
    int status=ui->statuscage->text().toInt();
    int taille=ui->taillecage->text().toInt();
    QString type=ui->typecage->text();
    QString date=ui->datecage->text();

    cage C(id,status,taille,type,date);



    bool test=C.modifierCage(C.getidcage(),C.getstatuscage(),C.gettaillecage(),C.gettypecage(),C.getdatecage());


    QMessageBox msgBox;

    if(test)
       {
        ui->tab_cage->setModel(C.affichercage());
        msgBox.setText("Modification avec succes.");
        ui->tab_cage->setModel(C.affichercage());
       }
    else
        msgBox.setText("Echec de Modification.!!!");
        msgBox.exec();

        ui->idcage->clear();
        ui->datecage->clear();
        ui->typecage->clear();
        ui->taillecage->clear();
        ui->statuscage->clear();

}



void MainWindow::on_pb_recherchercage_clicked()
{
    cage C1;
    C1.setidcage(ui->idcage ->text().toInt());
    C1.settaillecage(ui->taillecage->text().toInt());

        ui->tab_cage->setModel(C1.chercherCage(C1.getidcage(),C1.gettaillecage()));

        ui->idcage->clear();
        ui->datecage->clear();
        ui->typecage->clear();
        ui->taillecage->clear();
        ui->statuscage->clear();
}

void MainWindow::on_pb_tricage_clicked()
{
    ui->tab_cage->setModel(C.trierCage());


    int id=ui->idcage->text().toInt();
    int status=ui->statuscage->text().toInt();
    int taille=ui->taillecage->text().toInt();
    QString type=ui->typecage->text();
    QString date=ui->datecage->text();
            cage C(id, status,taille,type,date);

            QMessageBox msg;
           if(C.trierCage())
           {
                ui->tab_cage->setModel(C.trierCage());
               msg.setText("ceci est la liste des cages avec tri croissant selon l'ID");
               msg.exec();
           }


           ui->idcage->clear();
           ui->datecage->clear();
           ui->typecage->clear();
           ui->taillecage->clear();
           ui->statuscage->clear();
}

void MainWindow::on_pushButtoncage_clicked()
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
void MainWindow::on_pushButton_2cage_clicked()
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

void MainWindow::on_pushButton_3cage_clicked()
{
    QSqlQueryModel *model= new QSqlQueryModel();
                    QSqlQuery   *q= new QSqlQuery();
                    q->prepare("SELECT identifiant from cages");
                    q->exec();
                    model->setQuery(*q); ///
                   // ui->comboBoxcage->setModel(model);
}

void MainWindow::on_comboBox_2cage_activated(const QString &arg1) //combobox modify
{
    QString id=arg1;
         QSqlQueryModel *model= new QSqlQueryModel();
             QSqlQuery   *query= new QSqlQuery();
              query->prepare("SELECT * from cages where identifiant='"+id+"'");
              if(query->exec())
              {
                  while (query->next())
                  {

                      ui->idcage->setText(query->value(0).toString());
                      ui->statuscage->setText(query->value(1).toString());
                      ui->taillecage->setText(query->value(2).toString());
                      ui->typecage->setText(query->value(3).toString());
                      ui->datecage->setText(query->value(4).toString());


                  }
              }

              model->setQuery(*query);
}

void MainWindow::on_pushButton_4cage_clicked() //combobox sup
{
    QSqlQueryModel *model= new QSqlQueryModel();
                    QSqlQuery   *q= new QSqlQuery();
                    q->prepare("SELECT identifiant from cages");
                    q->exec();
                    model->setQuery(*q); ///
                   // ui->comboBox_2cage->setModel(model);
}

void MainWindow::on_pushButton_5cage_clicked()  //clear
{
    ui->idcage->clear();
    ui->datecage->clear();
    ui->typecage->clear();
    ui->taillecage->clear();
    ui->statuscage->clear();
}


         /*insert image*/

void MainWindow::on_pushButton_6cage_clicked()
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

        ui->filecage->setText( fileListString );
}

void MainWindow::on_lineEditcage_textEdited(const QString &arg1)
{
    ui->tab_cage->setModel(C.cherchercage(arg1));
}


void MainWindow::on_pushButton_7cage_clicked()
{
    ui->tab_cage->setModel(C.trierCage1());


    int id=ui->idcage->text().toInt();
    int status=ui->statuscage->text().toInt();
    int taille=ui->taillecage->text().toInt();
    QString type=ui->typecage->text();
    QString date=ui->datecage->text();
            cage C(id, status,taille,type,date);

            QMessageBox msg;
           if(C.trierCage1())
           {
                ui->tab_cage->setModel(C.trierCage1());
               msg.setText("ceci est la liste des cages avec tri croissant selon la taille");
               msg.exec();
           }


           ui->idcage->clear();
           ui->datecage->clear();
           ui->typecage->clear();
           ui->taillecage->clear();
           ui->statuscage->clear();
}

void MainWindow::on_pushButton_8cage_clicked()
{
    ui->tab_cage->setModel(C.trierCage2());


    int id=ui->idcage->text().toInt();
    int status=ui->statuscage->text().toInt();
    int taille=ui->taillecage->text().toInt();
    QString type=ui->typecage->text();
    QString date=ui->datecage->text();
            cage C(id, status,taille,type,date);

            QMessageBox msg;
           if(C.trierCage2())
           {
                ui->tab_cage->setModel(C.trierCage2());
               msg.setText("ceci est la liste des cages avec tri croissant selon la taille");
               msg.exec();
           }


           ui->idcage->clear();
           ui->datecage->clear();
           ui->typecage->clear();
           ui->taillecage->clear();
           ui->statuscage->clear();
}




/*************************** gest event youssef   *************************/
    /*************************** gest event youssef   *************************/

        /*************************** gest event youssef   *************************/
        /*************************** gest event youssef   *************************/

/*************************** gest event youssef   *************************/
/*************************** gest event youssef   *************************/






bool MainWindow::searchevent(int t)
{bool test=false;

       for (int var = 0; var < ui->table_event->model()->rowCount(); ++var) {
           if(ui->table_event->model()->index(var,0).data().toInt()==t){

              test=true;
           }
       }
       return test;
}
void MainWindow::on_pb_ajouterevent_clicked()
{
    int ID = ui->lineEdit_IDevent->text().toInt();
    QString Nom = ui->lineEdit_Nomevent->text();
    QString Date = ui->lineEdit_Dateevent->text();
    QString Theme = ui->lineEdit_Themeevent->text();
    int NbEmployes = ui->lineEdit_NbEmployesevent->text().toInt();
    evenement e(ID,Nom,Date,Theme,NbEmployes);

           bool test=e.ajouterEvent();
                if(test)
                 {    QMessageBox::information(nullptr, QObject::tr("Ajout avec succés"),
                                               QObject::tr("Ajout successful.\n"
                                                           "Click Cancel to exit."), QMessageBox::Cancel);
                                ui->table_event->setModel(e.afficherEvent());


                 }
                               else
                                   QMessageBox::critical(nullptr, QObject::tr("Ajout failed"),
                                               QObject::tr("Ajout failed.\n"
                                                           "Click Cancel to exit."), QMessageBox::Cancel);
                                  ui->lineEdit_IDevent->clear();
                                  ui->lineEdit_Nomevent->clear();
                                  ui->lineEdit_Dateevent->clear();
                                  ui->lineEdit_Themeevent->clear();
                                  ui->lineEdit_NbEmployesevent->clear();

}

QModelIndex MainWindow::on_table_event_activated(QModelIndex index)
{
    index =ui->table_event->currentIndex();
        return (index);
}

void MainWindow::on_Afficherevent_clicked()
{

    ui->table_event->setModel(e.afficherEvent());
    ui->table_event->setModel(e.afficherEvent());
}

void MainWindow::on_Supprimerevent_clicked()
{
    QModelIndex index;
    index=on_table_event_activated(index);
    QVariant value=ui->table_event->model()->data(index);
    QString v=value.toString();

    ui->lineEdit_IDevent->setText(v);

    evenement E1;

        E1.setIDEvent(ui->lineEdit_IDevent->text().toInt());

        int c=E1.get_IDEvent();
        bool t=search(c);
        qDebug() << t;

        QMessageBox msgBox;


        if(t==false)
            {
                QMessageBox::critical(nullptr, QObject::tr("ID exist"),
                            QObject::tr("Supression failed.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            }
            else
               {
                    bool test=E1.supprimerEvent(E1.get_IDEvent());
                        if(test)
                            {
                                msgBox.setText("Suppression avec succes.");
                                ui->table_event->setModel(e.afficherEvent());
                            }
                        else
                            msgBox.setText("Echec de suppression!!!!!");
                            msgBox.exec();
                            ui->lineEdit_IDevent->clear();
                            ui->lineEdit_Nomevent->clear();
                            ui->lineEdit_Dateevent->clear();
                            ui->lineEdit_Themeevent->clear();
                            ui->lineEdit_NbEmployesevent->clear();
               }

}
void MainWindow::on_Resetevent_clicked()
{

    evenement E1;



        bool test=E1.supprimerToutEvent();

        QMessageBox msgBox;

        if(test)
            {
                msgBox.setText("Reset avec succes.");
                ui->table_event->setModel(E1.afficherEvent());
            }
        else
            msgBox.setText("Echec de reset!!!!!");
            msgBox.exec();
            ui->lineEdit_IDevent->clear();
            ui->lineEdit_Nomevent->clear();
            ui->lineEdit_Dateevent->clear();
            ui->lineEdit_Themeevent->clear();
            ui->lineEdit_NbEmployesevent->clear();

}


void MainWindow::on_table_event_clicked(const QModelIndex &index)
{
    ui->lineEdit_IDevent->setText(ui->table_event->model()->data(ui->table_event->model()->index(index.row(),0)).toString());
    ui->lineEdit_Nomevent->setText(ui->table_event->model()->data(ui->table_event->model()->index(index.row(),1)).toString());
    ui->lineEdit_Dateevent->setText(ui->table_event->model()->data(ui->table_event->model()->index(index.row(),2)).toString());
    ui->lineEdit_Themeevent->setText(ui->table_event->model()->data(ui->table_event->model()->index(index.row(),3)).toString());
    ui->lineEdit_NbEmployesevent->setText(ui->table_event->model()->data(ui->table_event->model()->index(index.row(),4)).toString());


}
/*void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    ui->linedata(ui->table_event->model()

}*/


void MainWindow::on_Modifierevent_clicked()
{
    QModelIndex index;
    index=on_table_event_activated(index);
    QVariant value=ui->table_event->model()->data(index);
    QString v=value.toString();

    ui->lineEdit_IDevent->setText(v);


    int ID = ui->lineEdit_IDevent->text().toInt();
    QString Nom = ui->lineEdit_Nomevent->text();
    QString Date = ui->lineEdit_Dateevent->text();
    QString Theme = ui->lineEdit_Themeevent->text();
    int NbEmployes = ui->lineEdit_NbEmployesevent->text().toInt();
    evenement E(ID,Nom,Date,Theme,NbEmployes);
        bool test=E.modifierEvent(E.get_IDEvent(),E.get_NomEvent(),E.get_DateEvent(),E.get_Theme(),E.get_NbEmployes());

        QMessageBox msgBox;

        if(test)
            {
                msgBox.setText("Modification avec succes.");
                ui->table_event->setModel(E.afficherEvent());
            }
        else

            msgBox.setText("Echec de Modification!!!!!!");
            msgBox.exec();

            ui->lineEdit_IDevent->clear();
            ui->lineEdit_Nomevent->clear();
            ui->lineEdit_Dateevent->clear();
            ui->lineEdit_Themeevent->clear();
            ui->lineEdit_NbEmployesevent->clear();

}

void MainWindow::on_Rechercheevent_clicked()
{
    evenement E;

    E.setIDEvent(ui->lineEdit_IDevent->text().toInt());

    ui->table_event->setModel(E.rechercheEvent(E.get_IDEvent(),E.get_NomEvent(),E.get_DateEvent(),E.get_Theme()));

    ui->lineEdit_IDevent->clear();
    ui->lineEdit_Nomevent->clear();
    ui->lineEdit_Dateevent->clear();
    ui->lineEdit_Themeevent->clear();
    ui->lineEdit_NbEmployesevent->clear();

}



void MainWindow::on_Statistiqueevent_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
                         model->setQuery("select * from EVENEMENTS where nb_employes < 5 ");
                         float nb_employes=model->rowCount();
                         model->setQuery("select * from EVENEMENTS where nb_employes  between 5 and 10 ");
                         float nb_employes2=model->rowCount();
                         model->setQuery("select * from EVENEMENTS where nb_employes>10 ");
                         float nb_employes3=model->rowCount();
                         float total=nb_employes+nb_employes2+nb_employes3;
                         QString a=QString("moins de 5 employees "+QString::number((nb_employes*100)/total,'f',2)+"%" );
                         QString b=QString("entre 5 et 10 employees"+QString::number((nb_employes2*100)/total,'f',2)+"%" );
                         QString c=QString("+10 employees"+QString::number((nb_employes3*100)/total,'f',2)+"%" );
                         QPieSeries *series = new QPieSeries();
                         series->append(a,nb_employes);
                         series->append(b,nb_employes2);
                         series->append(c,nb_employes3);
                 if (nb_employes!=0)
                 {QPieSlice *slice = series->slices().at(0);
                  slice->setLabelVisible();
                  slice->setPen(QPen());}
                 if ( nb_employes2!=0)
                 {
                          // Add label, explode and define brush for 2nd slice
                          QPieSlice *slice1 = series->slices().at(1);
                          //slice1->setExploded();
                          slice1->setLabelVisible();
                 }
                 if(nb_employes3!=0)
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
                         chart->setTitle("Pourcentage Par nbr employes :Nombre Des employes "+ QString::number(total));
                         chart->legend()->hide();
                         // Used to display the chart
                         QChartView *chartView = new QChartView(chart);
                         chartView->setRenderHint(QPainter::Antialiasing);
                         chartView->resize(1000,500);
                         chartView->show();
}



void MainWindow::on_comboBoxevent_activated()
{
    if(ui->comboBoxevent->currentText()=="Trier par ID")
            ui->table_event->setModel(e.trierEvent(e));
        if(ui->comboBoxevent->currentText()=="Trier par Nom")
            ui->table_event->setModel(e.trierEventNom());
        if(ui->comboBoxevent->currentText()=="Trier par Thème")
            ui->table_event->setModel(e.trierEventTheme());


}

void MainWindow::on_pushButton_11event_clicked()
{
      QPdfWriter pdf("C:\\Users\\asus\\Desktop\\pdf");

                              QPainter painter(&pdf);
                             int i = 4000;
                                  painter.setPen(Qt::red);
                                  painter.setFont(QFont("Arial", 25));
                                  painter.drawText(2000,1200,"Les évènements");
                                  painter.setPen(Qt::black);
                                  painter.setFont(QFont("Arial", 15));
                                 // painter.drawText(1100,2000,afficheDC);
                                  painter.drawRect(100,100,9000,2000); // dimension ta3 rectangle eli fih liste des animaux
                                  painter.drawPixmap(QRect(7000,200,1600,1600),QPixmap("C:\\Users\\asus\\Desktop\\pdf\\logo_projet"));
                                  painter.drawRect(0,3000,9000,500);
                                  painter.setFont(QFont("Arial", 9));
                                  painter.drawText(200,3300,"ID");
                                  painter.drawText(1600,3300,"NOM");
                                  painter.drawText(3600,3300,"DATE");
                                  painter.drawText(5600,3300,"THEME");
                                  painter.drawText(7400,3300,"Nombre d'employés");
                                  painter.drawRect(0,3000,9000,9000);
                                //  painter.drawText(5300,3300,"LIEU");
                                  //painter.drawText(7400,3300,"ETAT_MATRIMATIONALE");


                                  QSqlQuery query;
                                  query.prepare("select * from EVENEMENTS");
                                  query.exec();
                                  while (query.next())
                                  {
                                      painter.drawText(200,i,query.value(0).toString());
                                      painter.drawText(1600,i,query.value(1).toString());
                                      painter.drawText(3600,i,query.value(2).toString());
                                      painter.drawText(5600,i,query.value(3).toString());
                                      painter.drawText(7600,i,query.value(4).toString());



                                     i = i + 500;
        }
                                  QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
                                              QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_lineEditevent_textEdited(const QString &arg1)
{
    ui->table_event->setModel(e.RechercheEvent(arg1));
}




    /******************************  gest produit narimen  *******************************/

/******************************  gest produit narimen  *******************************/
    /******************************  gest produit narimen  *******************************/
/******************************  gest produit narimen  *******************************/




void MainWindow::on_pb_ajouterproduit_clicked()
{
int ref=ui->le_idproduit->text().toInt();
QString nom=ui->le_nomproduit->text();
QString categorie=ui->le_categorieproduit->text();
float prix=ui->le_prixproduit->text().toFloat();
int quantite=ui->le_quantiteproduit->text().toInt();
produit p(ref,nom,categorie,prix,quantite);
if((prix>0) && (quantite>0))
{
bool test=p.ajouterproduit();
if (test==true)
{
     p.statproduit(series);
 ui->tab_produit->setModel(p.afficherproduit());
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

void MainWindow::on_pb_supprimerproduit_clicked()
{

int ref=ui->le_id_suppproduit->text().toInt();


bool test=p.supprimerproduit(ref);
if (test==true)
{  p.statproduit(series);
    ui->tab_produit->setModel(p.afficherproduit());

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


void MainWindow::on_pushButtonproduit_clicked()
{
    int ref=ui->le_idproduit->text().toInt();
    QString nom=ui->le_nomproduit->text();
    QString categorie=ui->le_categorieproduit->text();
    float prix=ui->le_prixproduit->text().toFloat();
    int quantite=ui->le_quantiteproduit->text().toInt();
    produit p(ref,nom,categorie,prix,quantite);
    if((prix>0) && (quantite>0))
    {
    bool test=p.modifierproduit(ref);
    if (test==true)
    { p.statproduit(series);
 ui->tab_produit->setModel(p.afficherproduit());
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

void MainWindow::on_pushButton_2produit_clicked()
{

}



void MainWindow::on_pushButton_3produit_clicked()
{
    QString selon=ui->comboBoxTriproduit->currentText();
     ui->tab_produit->setModel(p.trierproduit(selon));
}

void MainWindow::on_pushButton_4produit_clicked()
{

        Smtp* smtp = new Smtp("narimen.azzouz@esprit.tn","201JFT3127", "smtp.gmail.com");
        connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


            smtp->sendMail("narimen.azzouz@esprit.tn",ui->destinataireproduit->text(), ui->objetproduit->text(),ui->texteproduit->toPlainText());
            QMessageBox::information(nullptr, QObject::tr("Mail sent"),
                        QObject::tr(" successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
       }

void MainWindow::on_pushButton_5produit_clicked()
{
if (ui->comboBoxproduit->currentText()=="ENG")
{
    ui->tabWidgetproduit->setTabText(0,"Add product");
    ui->tabWidgetproduit->setTabText(1,"View products");
    ui->tabWidgetproduit->setTabText(2,"Delete product");
    ui->tabWidgetproduit->setTabText(3,"Statistics");
    ui->tabWidgetproduit->setTabText(4,"Send mail");
    ui->groupBox->setTitle("Add");
    ui->label_2produit->setText("Name");
    ui->label_3produit->setText("Category");
    ui->label_5produit->setText("Price");
    ui->label_6produit->setText("Quantity");
    ui->pushButtonproduit->setText("Edit");
    ui->pb_ajouterproduit->setText("Add");
    ui->pushButton_3produit->setText("Sort");
    ui->pb_supprimer->setText("Delete");
    ui->pushButton_5produit->setText("Change");
    ui->pushButton_6produit->setText("Generate");






}
else if (ui->comboBoxproduit->currentText()=="FR")
{
    ui->tabWidgetproduit->setTabText(0,"Ajouter produit");
    ui->tabWidgetproduit->setTabText(1,"Affciher produits");
    ui->tabWidgetproduit->setTabText(2,"Supprimer produit");
    ui->tabWidgetproduit->setTabText(3,"Statistiques");
    ui->tabWidgetproduit->setTabText(4,"Envoyer mail");
    ui->groupBox->setTitle("Ajouter");
    ui->label_2produit->setText("Nom");
    ui->label_3produit->setText("Categorie");
    ui->label_5produit->setText("Prix");
    ui->label_6produit->setText("Quantite");
    ui->pushButtonproduit->setText("Modifier");
    ui->pb_ajouterproduit->setText("Ajouter");
    ui->pushButton_3produit->setText("Trier");
    ui->pb_supprimerproduit->setText("Supprimer");
    ui->pushButton_5produit->setText("Changer");
    ui->pushButton_6produit->setText("Generer");






}
}
void MainWindow::affrechproduit()
{
    QString selon=ui->selonproduit->currentText();
    QString rech=ui->Rechproduit->text();
     ui->tab_produit->setModel(p.rechercherproduit(selon,rech));
}

void MainWindow::on_pushButton_6produit_clicked()
{
    if(ui->le_idproduit->text() !="")
    {
        QSqlQuery q("select * from produit where ref="+ui->le_idproduit->text());
        while(q.next())
        {
            ui->le_nomproduit->setText(q.value(1).toString());
            ui->le_prixproduit->setText(q.value(3).toString());
            ui->le_quantiteproduit->setText(q.value(4).toString());
            ui->le_categorieproduit->setText(q.value(2).toString());
        }
    }
}



