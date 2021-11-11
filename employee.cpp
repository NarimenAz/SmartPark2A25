#include "employee.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

Employee::Employee()
{
  id=""; tel=0;nom="";prenom="";adress="";specialite="";
}


Employee::Employee(QString id,int tel,QString adress,QString specialite,QString prenom,QString nom)
{this->id=id; this->nom=nom;this->prenom=prenom; this->adress=adress; this->specialite=specialite; this->tel=tel; }
QString Employee::getId(){return id;}
int Employee::getTel(){return tel;}
QString Employee::getNom(){ return nom;}
QString Employee::getPrenom() {return prenom;}
QString Employee::getAdress() {return adress;}
QString Employee::getSpecialite() {return specialite;}
void Employee::setId(QString id){this->id=id;}
void Employee::setTel(int tel){this-> tel=tel;}
void Employee::setNom(QString nom){this->nom=nom;}
void Employee::setPrenom(QString prenom){this->prenom=prenom;}
void Employee::setAdress(QString adress){this->adress=adress;}


bool Employee::ajouter()
{
             QSqlQuery query;
                QString res= QString(id);
            QString re= QString::number(tel);
             query.prepare("INSERT INTO EMPLOYEE ( TEL,NOM,ADRESS,SPECIALITE,ID,PRENOM) "
                 "VALUES (:tel, :nom, :adress, :specialite, :id, :prenom)");

             query.bindValue(":tel", re );


             query.bindValue(":nom", nom );
             query.bindValue(":adress", adress );
              query.bindValue(":specialite", specialite );

              query.bindValue(":id",res);
               query.bindValue(":prenom", prenom);

            return query.exec();

         }





bool Employee::supprimer(QString id)
{

    QSqlQuery query;
          query.prepare("delete from EMPLOYEE where id=:id" );
          query.bindValue(0, id);

         return query.exec();


}


QSqlQueryModel* Employee::afficher()
{


    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT* FROM EMPLOYEE");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("tel"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("specialte"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("adress"));

    return model ;

}

bool Employee::modifier(QString id,int tel,QString adress,QString specialite,QString prenom,QString nom)
{
    QSqlQuery query;

    query.prepare("UPDATE EMPLOYEE set NOM=:nom,adress=:adress,specialite=:specialite,prenom=:prenom ,tel=:tel where ID=:id");
    QString res= QString(id);
QString re= QString::number(tel);
    query.bindValue(":tel", re);


    query.bindValue(":nom", nom );
    query.bindValue(":adress", adress );
     query.bindValue(":specialite", specialite );

     query.bindValue(":id",res);
      query.bindValue(":prenom", prenom);
     return query.exec();
}
