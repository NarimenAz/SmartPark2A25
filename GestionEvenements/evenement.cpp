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
    Date="";
    Theme="";
    NbEmployes=0;

}

Evenement::Evenement(int ID,QString Nom,QString Date,QString Theme,int NbEmployes)
{
    this->ID=ID;
    this->Nom=Nom;
    this->Date=Date;
    this->Theme=Theme;
    this->NbEmployes= NbEmployes;


}

int Evenement::get_ID(){return ID;}
QString Evenement::get_Nom(){return Nom;}
QString Evenement::get_Date(){return Date;}
QString Evenement::get_Theme(){return Theme;}
int Evenement::get_NbEmployes(){return NbEmployes;}

void Evenement::setID(int ID){this->ID=ID;}
void Evenement::setNom(QString Nom){this->Nom=Nom;}
void Evenement::setDate(QString Date){this->Date=Date;}
void Evenement::setTheme(QString Theme){this->Theme=Theme;}
void Evenement::setNbEmployes(int NbEmployes){this->NbEmployes=NbEmployes;}

/*******************************************************************************************************************************/
/**********************************************Ajouter************************************************************************/


bool Evenement::ajouterEvent()
{

    QString ID_string = QString::number(ID);
    QString NbEmployes_string = QString::number(NbEmployes);
    QSqlQuery query;
       query.prepare("INSERT INTO evenements (ID,nom,datee,theme,nb_employes) "
                     "VALUES (:ID, :Nom, :Date, :Theme, :NbEmployes)");
       query.bindValue(":ID", ID_string);
       query.bindValue(":Nom", Nom);
       query.bindValue(":Date", Date);
       query.bindValue(":Theme", Theme);
       query.bindValue(":NbEmployes", NbEmployes_string);
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
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("NbEmployes"));



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


bool Evenement::modifierEvent(int ID,QString Nom,QString Date,QString Theme,int NbEmployes)

{



    QSqlQuery query;

    query.prepare("update EVENEMENTS set nom=:Nom, datee=:Date, theme=:Theme, nb_employes=:NbEmployes,where ID=:ID");
    query.bindValue(":ID",ID);
    query.bindValue(":Nom",Nom);
    query.bindValue(":Date",Date);
    query.bindValue(":Theme",Theme);
    query.bindValue(":NbEmployes",NbEmployes);

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
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("NbEmployes"));

     return model;

}

/*******************************************************************************************************************************/
/***************************************************Trier********************************************************************/



QSqlQueryModel * Evenement::trierEvent(Evenement)

{



    QSqlQuery * q = new  QSqlQuery ();

           QSqlQueryModel * model = new  QSqlQueryModel ();

           q->prepare("SELECT * FROM EVENEMENTS order by ID ASC");

           q->exec();

           model->setQuery(*q);

           return model;

}









































