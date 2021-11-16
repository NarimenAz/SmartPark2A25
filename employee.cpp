#include "employee.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

Employee::Employee()
{
  id=""; tel=0;nom="";prenom="";adress="";specialite="";
}


Employee::Employee(QString id,int tel,QString adress,QString specialite,QString prenom,QString nom,int salaire)
{this->id=id; this->nom=nom;this->prenom=prenom; this->adress=adress; this->specialite=specialite; this->tel=tel,this->salaire=salaire; }
QString Employee::getId(){return id;}
int Employee::getTel(){return tel;}
float Employee::getsalaire(){return salaire;}
QString Employee::getNom(){ return nom;}
QString Employee::getPrenom() {return prenom;}
QString Employee::getAdress() {return adress;}
QString Employee::getSpecialite() {return specialite;}
void Employee::setId(QString id){this->id=id;}
void Employee::setTel(int tel){this-> tel=tel;}
void Employee::setsalaire(float salaire){this-> salaire=salaire;}
void Employee::setNom(QString nom){this->nom=nom;}
void Employee::setPrenom(QString prenom){this->prenom=prenom;}
void Employee::setAdress(QString adress){this->adress=adress;}


bool Employee::ajouter()
{
             QSqlQuery query;
                QString res= QString(id);
            QString re= QString::number(tel);
            QString res1=QString::number(salaire);
             query.prepare("INSERT INTO EMPLOYEE ( TEL,NOM,ADRESS,SPECIALITE,ID,PRENOM,SALAIRE) "
                 "VALUES (:tel, :nom, :adress, :specialite, :id, :prenom,:salaire)");

             query.bindValue(":tel", re );


             query.bindValue(":nom", nom );
             query.bindValue(":salaire", res1 );
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
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("salaire"));

    return model ;

}

bool Employee::modifier(QString id,int tel,QString adress,QString specialite,QString prenom,QString nom,int salaire)
{
    QSqlQuery query;

    query.prepare("UPDATE EMPLOYEE set NOM=:nom,salaire=:salaire,adress=:adress,specialite=:specialite,prenom=:prenom ,tel=:tel where ID=:id");
    QString res= QString(id);
QString re= QString::number(tel);
    query.bindValue(":tel", re);


    query.bindValue(":nom", nom );
    query.bindValue(":adress", adress );
     query.bindValue(":specialite", specialite );

     query.bindValue(":id",res);
      query.bindValue(":prenom", prenom);
      query.bindValue(":salaire", salaire);
     return query.exec();
}


QSqlQueryModel *Employee::trier()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from EMPLOYEE order by id ASC") ;
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("tel"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("specialite"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("adress"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("salaire"));


    return  model ;

}

QSqlQueryModel *Employee::trier1()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from EMPLOYEE order by NOM") ;
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("tel"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("specialite"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("adress"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("salaire"));


    return  model ;

}
QSqlQueryModel *Employee::trier2()
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from EMPLOYEE order by prenom") ;
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("tel"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("specialite"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("adress"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("salaire"));

    return  model ;

}

QSqlQueryModel *Employee::rechercher(QString nom)
{
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("select * from EMPLOYEE WHERE(nom='"+nom+"')");

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("tel"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("specialite"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("adress"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("salaire"));
    return  model ;




}



QSqlQuery  Employee::calculerSalaire()
{

    QSqlQuery query;
       query.prepare("SELECT SUM(salaire) FROM EMPLOYEE");
       return query;

}
