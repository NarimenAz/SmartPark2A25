#include "employee.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>

employee::employee()
{
  idEmploye=""; tel=0;nomEmploye="";prenomEmploye="";adress="";specialite="";
}


employee::employee(QString idEmploye,int tel,QString adress,QString specialite,QString prenomEmploye,QString nomEmploye,int salaire)
{this->idEmploye=idEmploye; this->nomEmploye=nomEmploye;this->prenomEmploye=prenomEmploye; this->adress=adress; this->specialite=specialite; this->tel=tel,this->salaire=salaire; }
QString employee::getIdEmploy(){return idEmploye;}
int employee::getTel(){return tel;}
float employee::getsalaire(){return salaire;}
QString employee::getNomEmploy(){ return nomEmploye;}
QString employee::getPrenomEmploy() {return prenomEmploye;}
QString employee::getAdress() {return adress;}
QString employee::getSpecialite() {return specialite;}
void employee::setIdEmploy(QString id){this->idEmploye=id;}
void employee::setTel(int tel){this-> tel=tel;}
void employee::setsalaire(float salaire){this-> salaire=salaire;}
void employee::setNomEmploy(QString nom){this->nomEmploye=nom;}
void employee::setPrenomEmploy(QString prenom){this->prenomEmploye=prenom;}
void employee::setAdress(QString adress){this->adress=adress;}


bool employee::ajouterEmploye()
{
             QSqlQuery query;
                QString res= QString(idEmploye);
            QString re= QString::number(tel);
            QString res1=QString::number(salaire);

             query.prepare("INSERT INTO EMPLOYEE ( ID,NOM,PRENOM,TEL,SPECIALITE,ADRESS,SALAIRE) "
                 "VALUES (:id, :nom, :prenom, :tel, :specialite,  :adress,:salaire)");



       //      query.prepare("UPDATE EMPLOYEE set NOM=:nom,salaire=:salaire,adress=:adress,specialite=:specialite,prenom=:prenom ,tel=:tel where ID=:id");
             query.bindValue(":id",res);
             query.bindValue(":prenom", prenomEmploye);
             query.bindValue(":nom", nomEmploye );
             query.bindValue(":tel", re);
             query.bindValue(":adress", adress );
              query.bindValue(":specialite", specialite );

               query.bindValue(":salaire", res1);



            return query.exec();

         }





bool employee::supprimerEmploye(QString id)
{

    QSqlQuery query;
          query.prepare("delete from EMPLOYEE where id=:id" );
          query.bindValue(":id", id);

         return query.exec();


}


QSqlQueryModel* employee::afficherEmploye()
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

bool employee::modifierEmploye(QString id,int tel,QString adress,QString specialite,QString prenom,QString nom,int salaire)
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


QSqlQueryModel *employee::trierEmploye()
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

QSqlQueryModel *employee::trierEmploye1()
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
QSqlQueryModel *employee::trierEmploye2()
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

QSqlQueryModel *employee::rechercherEmploye(QString nom)
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



QSqlQuery  employee::calculerSalaire()
{

    QSqlQuery query;
       query.prepare("SELECT SUM(salaire) FROM EMPLOYEE");
       return query;

}
