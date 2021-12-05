#include "cage.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QSqlQueryModel>
#include<QObject>

cage::cage()
{
  id=0; taille=0;status=0;type="";date="";
}

cage::cage(int id,int status,int taille,QString type,QString date )
{
    this ->id=id; this ->status=status; this->taille=taille;this->type=type;this->date=date;
}
int cage::getid(){return id;}
int cage::getstatus(){return status;}
int cage::gettaille(){return taille;}
QString cage::gettype(){return type;}
QString cage::getdate(){return date;}

void cage::setid(int id){this ->id=id;}
void cage::setstatus(int status){this ->status=status;}
void cage::settaille(int taille){this ->taille=taille;}
void cage::settype(QString type){this ->type=type;}
void cage::setdate(QString date){this ->date=date;}

bool cage::ajouter()
{
    QSqlQuery query;
    QString id_string= QString::number(id);
         query.prepare("INSERT INTO cages (identifiant,status,taille,type,datee) "
                       "VALUES (:id, :status, :taille, :type, :date)");
         query.bindValue(":id", id_string);
         query.bindValue(":status", status);
         query.bindValue(":taille", taille);
         query.bindValue(":type", type);
         query.bindValue(":date", date);
         return query.exec();
}

QSqlQueryModel* cage::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();


          model->setQuery("SELECT* FROM cages");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant")); //setheader t7ot les entite ta3 etableau
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("status"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("datee"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("taille"));


    return model;
}


bool cage::supprimer(int id)
{
    QSqlQuery query;
         query.prepare("Delete from cages where identifiant=:id");
         query.bindValue(":id", id); //bin

         return query.exec();
}

bool cage::modifierCage(int id,int status,int taille,QString type,QString date)
{
    QSqlQuery query;
    QString res= QString::number(id);
    query.prepare("UPDATE cages set status=:status,taille=:taille,type=:type,datee=:date where identifiant=:id");

        QString id_string= QString::number(id);
    query.bindValue(":id", id_string);
    query.bindValue(":status", status);
    query.bindValue(":taille", taille);
    query.bindValue(":type", type);
    query.bindValue(":date", date);
    return query.exec();
}

QSqlQueryModel * cage::chercherCage(int id,int taille)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * from cages where identifiant like :id or taille like :taille ");
    query.bindValue(":id",id);// ID VARIABLE LOCAL BA3D BCH NA3MALOU APPEL BIL getIDANIM()
    query.bindValue(":taille",taille);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("status"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("datee"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("taille"));

    return model;
}

QSqlQueryModel* cage::trierCage()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *FROM cages ORDER BY identifiant ASC");


        model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("status"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("datee"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("taille"));

    return model;
}


QSqlQueryModel* cage::trierCage1()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *FROM cages ORDER BY taille ASC");


        model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("status"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("datee"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("taille"));

    return model;
}

QSqlQueryModel* cage::trierCage2()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *FROM cages ORDER BY taille ASC");


        model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("status"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("datee"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("taille"));

    return model;
}



QSqlQueryModel * cage::chercher(QString a)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM cages WHERE (identifiant LIKE '%"+a+"%' OR status LIKE '%"+a+"%' OR datee LIKE '%"+a+"%' OR type LIKE '%"+a+"%' OR taille LIKE '%"+a+"%' ) ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("status"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("datee"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("taille"));

    return model;
}
