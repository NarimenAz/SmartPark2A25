#include "animaux.h"
#include<QSqlQuery>
#include<QtDebug>
#include<QObject>
#include <QWidget>
#include <QFileDialog>
#include <QTextDocument>
#include <QDebug>
#include <QtPrintSupport/QPrinter>
/********************** ta3 pdf ***************/
#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>
//#include <QPrinter>
#include <QFileDialog>
#include <QTextDocument>



//#include <cstdlib>



animaux::animaux()
{
 idAnim=0;nomAnim="";typeAnim="";
 pays="";ageAnim=0;
 status="";regimeAliment="";
}

animaux::animaux(int idAnim, QString nomAnim,QString typeAnim,QString pays,int ageAnim,QString status,QString regimeAliment )
{
 this->idAnim=idAnim;this->nomAnim=nomAnim;this->typeAnim=typeAnim;
 this->pays=pays;this->ageAnim=ageAnim;
 this->status=status;this->regimeAliment=regimeAliment;
}

int animaux::getidAnim(){return idAnim ;}
QString animaux::getNomAnim(){return nomAnim ;}
QString animaux::gettypeAnim(){return typeAnim;}
QString animaux::getpays(){return pays;}
QString animaux::getstatus(){return status;}
QString animaux::getregimealim(){return regimeAliment;}
int animaux::getageAnim(){return ageAnim;}
//int animaux::getnbrrepas(){return nbrRepas;}
//int animaux::getquantitérepas(){return quantitéRepas;}

void animaux::setidAnim(int idAnim)
{this->idAnim=idAnim;}
void animaux::setNomAnim(QString nomAnim)
{this->nomAnim=nomAnim;}
void animaux::settypeAnim(QString typeAnim)
{this->typeAnim=typeAnim;}
void animaux::setpays(QString pays){this->pays=pays;}
void animaux::setstatus(QString status){this->status=status;}
void animaux::setregimealim(QString regimeAliment){this->regimeAliment=regimeAliment;}
void animaux::setageAnim(int ageAnim){this->ageAnim=ageAnim;}
//void animaux::setnbrrepas(int nbrRepas){this->nbrRepas=nbrRepas;}
//void animaux::setquantitérepas(int quantitéRepas){this->quantitéRepas=quantitéRepas;}


bool animaux::ajouterAnim()
{


//bool test=false;

   QSqlQuery query;

     query.prepare("INSERT INTO animaux (ID_ANIMAL, NOM_ANIMAL, TYPE_ANIMAL ,AGE_ANIMAL,PAYS,REGIME_ALIMENT,STATUS_ANIMAL) "
                   "VALUES (:idAnim, :nomAnim, :typeAnim, :ageAnim, :pays, :regimeAliment, :status)" );
     query.bindValue(":idAnim", idAnim);
     query.bindValue(":nomAnim", nomAnim);
     query.bindValue(":typeAnim",typeAnim );
     query.bindValue(":ageAnim",ageAnim );
     query.bindValue(":pays",pays );
     query.bindValue(":regimeAliment",regimeAliment );
     query.bindValue(":status",status );

     return query.exec();



   // return test;
}


QSqlQueryModel* animaux::afficherAnim()
{
    QSqlQueryModel* model=new QSqlQueryModel() ;


    model->setQuery("SELECT* FROM ANIMAUX");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID  ANIMAL"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM ANIMAL"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE ANIMAL"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE ANIMAL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PAYS ANIMAL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("REGIME ALIMENTAIRE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("STATUS ANIMAL"));



return model;

}



bool animaux::supprimerAnim(int idA)
{

    QSqlQuery query;

         query.prepare("delete from animaux where id_animal=:id");
         query.bindValue(":id", idA);

              return query.exec();



}




bool animaux::modifierAnim(int idAnim, QString nomAnim,QString typeAnim,QString pays,int ageAnim,QString status,QString regimeAliment )
{
    QSqlQuery query;
    //QString res= QString::number(id);
    query.prepare("UPDATE ANIMAUX set NOM_ANIMAL=:nom,TYPE_ANIMAL=:type,AGE_ANIMAL=:age,PAYS=:pays,REGIME_ALIMENT=:regimeAliment,STATUS_ANIMAL=:status where ID_ANIMAL=:id");

    query.bindValue(":id",idAnim);
    query.bindValue(":nom",nomAnim);
    query.bindValue(":type",typeAnim);
    query.bindValue(":age",ageAnim);
    query.bindValue(":pays",pays);
       query.bindValue(":regimeAliment",regimeAliment);
       query.bindValue(":status",status);
    return query.exec();
}


/////////////////////////////// finnnn dimplementation des crud  /////////////////////////////////


QSqlQueryModel * animaux::chercherAnim(int id,QString type,QString regime)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * from ANIMAUX where ID_ANIMAL like :id or TYPE_ANIMAL like :type or REGIME_ALIMENT like :regime ");
    query.bindValue(":id",id);// ID VARIABLE LOCAL BA3D BCH NA3MALOU APPEL BIL getIDANIM()
    query.bindValue(":type",type);
    query.bindValue(":regime",regime);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID  ANIMAL"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM ANIMAL"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("TYPE ANIMAL"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("AGE ANIMAL"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PAYS ANIMAL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("REGIME ALIMENTAIRE"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("STATUS ANIMAL"));

    return model;
}




QSqlQueryModel* animaux::trierAnim()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *FROM ANIMAUX ORDER BY ID_ANIMAL ASC");


    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ROLE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("PASS"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("REPASS"));

    return model;
}



bool animaux::supprimerTout()
{ QSqlQuery query;

   query.prepare("delete from animaux ");

  return query.exec();
}

/*
void animaux::CREATION_PDF()
{
   /* QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setPaperSize(QPrinter::A4);
    printer.setOutputFileName(fileName);

    QTextDocument doc;
    QSqlQuery q;
    q.prepare("SELECT * FROM ANIMAUX ");
    q.exec();
    QString pdf="<br> <h1  style='color:blue'>LISTE DES ANIMAUX  <br></h1>\n <br> <table>  <tr>  <th>CIN </th> <th>LIEU </th> <th> CODE POSTALE </th> </tr>" ;


    while ( q.next()) {

    pdf= pdf+ " <br> <tr>  <td>"+ q.value(0).toString()+"    &nbsp;&nbsp;&nbsp;     " + q.value(1).toString() +"</td>  &nbsp;&nbsp;&nbsp; <td>" +q.value(2).toString() +" &nbsp; </td> </td>" ;
    }
    doc.setHtml(pdf);
    doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
    doc.print(&printer);


}

*/




/*
    *************************** exemple de tri croissant et decroissant ***********************


 QSqlQueryModel * coli::affichertriccoli()
                   {
                       QSqlQueryModel * model= new QSqlQueryModel();

                       model->setQuery("select * from coli ORDER BY reference ASC");
                       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference"));
                       model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Client expediteur"));
                       model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Client dest"));
                       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Poids"));
                       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nombre de pièces"));
                       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Etat"));
                       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Moyen dePaiement"));
                       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Montant"));
                       model->setHeaderData(8, Qt::Horizontal, QObject::tr("Adresse destinataire"));
                       model->setHeaderData(9, Qt::Horizontal, QObject::tr("Adresse expéditeur"));
                       return model;
                   }
                   QSqlQueryModel * coli::affichertridcoli()
                   {
                       QSqlQueryModel * model= new QSqlQueryModel();

                       model->setQuery("select * from coli ORDER BY reference DESC");
                       model->setHeaderData(0, Qt::Horizontal, QObject::tr("Reference"));
                       model->setHeaderData(1, Qt::Horizontal, QObject::tr("ID Client expediteur"));
                       model->setHeaderData(2, Qt::Horizontal, QObject::tr("ID Client dest"));
                       model->setHeaderData(3, Qt::Horizontal, QObject::tr("Poids"));
                       model->setHeaderData(4, Qt::Horizontal, QObject::tr("Nombre de pièces"));
                       model->setHeaderData(5, Qt::Horizontal, QObject::tr("Etat"));
                       model->setHeaderData(6, Qt::Horizontal, QObject::tr("Moyen de Paiement"));
                       model->setHeaderData(7, Qt::Horizontal, QObject::tr("Montant"));
                       model->setHeaderData(8, Qt::Horizontal, QObject::tr("Adresse destinataire"));
                       model->setHeaderData(9, Qt::Horizontal, QObject::tr("Adresse expéditeur"));

                       return model;
                   }

*/

