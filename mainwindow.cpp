 #include "mainwindow.h"
#include "ui_mainwindow.h"
#include "animaux.h"
#include "widget.h"
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




using qrcodegen::QrCode;



//test commit men andi

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


/********************************   rechercher  *****************************/
void MainWindow::on_pb_rechercher_clicked()
{
    /*animaux A1;
    A1.setidAnim(ui->le_idAnim ->text().toInt());
    A1.settypeAnim(ui->le_typeAnimal ->text());
    A1.setregimealim(ui->le_regime->text());

        ui->tab_animaux->setModel(A1.chercherAnim(A1.getidAnim(),A1.gettypeAnim(),A1.getregimealim()));



        ui->le_idAnim->clear();
        ui->le_typeAnimal->clear();
        ui->le_regime->clear();
       */


//recherche avancé avec trois critères

    QString rech=ui->le_rechercher->text();
       ui->tab_animaux->setModel(A.chercheranimal(rech));
       ui->le_rechercher->clear();



}


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


/*void MainWindow::on_pb_trier_clicked()
{


        ui->tab_animaux->setModel(A.trierAnim());


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
       ui->le_regime->clear();
       ui->le_age->clear();



}*/


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
        //printer.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/Ahmed.A.Hsouna/Desktop/Ahmed_Amin_Ben_Hsouna/logo.png"));


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



  /*  QPdfWriter pdf("C:\\Users\\asus\\Desktop\\pdf\\pdfanimaux.pdf");

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

*/
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

