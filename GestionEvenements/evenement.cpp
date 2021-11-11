#include "evenement.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>

Evenement::Evenement()
{
    ID=0;
    Nom="";
    Date=0;
    Theme="";
    NbEmployés=0;

}

Evenement::Evenement(int ID,QString Nom,int Date,QString Theme,int NbEmployés)
{
    this->ID=ID;
    this->Nom=Nom;
    this->Date=Date;
    this->Theme=Theme;
    this->NbEmployés= NbEmployés;


}

int Evenement::get_ID(){return ID;}
QString Evenement::get_Nom(){return Nom;}
int Evenement::get_Date(){return Date;}
QString Evenement::get_Theme(){return Theme;}
int Evenement::get_NbEmployés(){return NbEmployés;}

void Evenement::setID(int ID){this->ID=ID;}
void Evenement::setNom(QString Nom){this->Nom=Nom;}
void Evenement::setDate(int Date){this->Date=Date;}
void Evenement::setTheme(QString Theme){this->Theme=Theme;}
void Evenement::setNbEmployés(int NbEmployés){this->NbEmployés=NbEmployés;}

/*******************************************************************************************************************************/
/**********************************************Ajouter************************************************************************/


bool Evenement::ajouterEvent()
{
    bool test=false;
    QString ID_string = QString::number(ID);
    QString Date_string = QString::number(Date);
    QString NbEmployés_string = QString::number(NbEmployés);
    QSqlQuery query;
       query.prepare("INSERT INTO EVENEMENTS (ID,NOM,DATE,THEME,NB_EMPLOYES) "
                     "VALUES (:ID, :Nom, :Date, :Theme, :NbEmployés");
       query.bindValue(0, ID_string);
       query.bindValue(1, Nom);
       query.bindValue(2, Date_string);
       query.bindValue(3, Theme);
       query.bindValue(4, NbEmployés_string);
       return query.exec();

}
/*******************************************************************************************************************************/
/**********************************************Afficher*************************************************************************/

QSqlQueryModel* Evenement::afficherEvent()

{
     QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT *  FROM EVENEMENTS ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Date"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Theme"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("NbEmployés"));



     return model;

}

/*******************************************************************************************************************************/
/**********************************************Supprimer************************************************************************/

bool Evenement::supprimerEvent(int ID)

{

    QSqlQuery query;

    query.prepare(" Delete from EVENEMENTS where ID=:ID ");

    query.bindValue(":ID",ID);



    return query.exec();

}

/*******************************************************************************************************************************/
/***************************************************Modifier********************************************************************/


bool Evenement::modifierEvent(int ID,QString Nom,int Date,QString Theme,int NbEmployés)

{



    QSqlQuery query;

    query.prepare("update EVENEMENTS set Nom=:Nom, Date=:Date, Theme=:Theme, NbEmployés=:NbEmployés,where ID=:ID");
    query.bindValue(":ID",ID);
    query.bindValue(":Nom",Nom);
    query.bindValue(":Date",Date);
    query.bindValue(":Theme",Theme);
    query.bindValue(":NbEmployés",NbEmployés);

    return query.exec();



}


/*******************************************************************************************************************************/
/***************************************************Recherche********************************************************************/



QSqlQueryModel* Evenement::rechercheEvent(int ID)

 {

     QSqlQueryModel * model= new QSqlQueryModel();
     QSqlQuery query;
     query.prepare("select * from EVENEMENTS where ID like :ID");
     query.bindValue(":ID",ID);
     query.exec();
     model->setQuery(query);
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Date"));
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Theme"));
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("NbEmployés"));

     return model;

}

/*******************************************************************************************************************************/
/***************************************************Trier********************************************************************/



QSqlQueryModel * Evenement::trierEvent()

{



    QSqlQuery * q = new  QSqlQuery ();

           QSqlQueryModel * model = new  QSqlQueryModel ();

           q->prepare("SELECT * FROM EVENEMENTS order by ID ASC");

           q->exec();

           model->setQuery(*q);

           return model;

}









































