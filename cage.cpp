#include "cage.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QSqlQueryModel>
#include<QObject>

cage::cage()
{
  idcage=0; taillecage=0;statuscage=0;typecage="";datecage="";
}

cage::cage(int idcage,int statuscage,int taillecage,QString typecage,QString datecage )
{
    this ->idcage=idcage; this ->statuscage=statuscage; this->taillecage=taillecage;this->typecage=typecage;this->datecage=datecage;
}
int cage::getidcage(){return idcage;}
int cage::getstatuscage(){return statuscage;}
int cage::gettaillecage(){return taillecage;}
QString cage::gettypecage(){return typecage;}
QString cage::getdatecage(){return datecage;}

void cage::setidcage(int idcage){this ->idcage=idcage;}
void cage::setstatuscage(int statuscage){this ->statuscage=statuscage;}
void cage::settaillecage(int taillecage){this ->taillecage=taillecage;}
void cage::settypecage(QString typecage){this ->typecage=typecage;}
void cage::setdatecage(QString datecage){this ->datecage=datecage;}

bool cage::ajoutercage()
{
    QSqlQuery query;
    QString id_string= QString::number(idcage);
         query.prepare("INSERT INTO cages (identifiant,status,taille,type,datee) "
                       "VALUES (:id, :status, :taille, :type, :date)");
         query.bindValue(":id", id_string);
         query.bindValue(":status", statuscage);
         query.bindValue(":taille", taillecage);
         query.bindValue(":type", typecage);
         query.bindValue(":date", datecage);
         return query.exec();
}

QSqlQueryModel* cage::affichercage()
{
    QSqlQueryModel* model=new QSqlQueryModel();


          model->setQuery("SELECT* FROM cages");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant")); //setheader t7ot les entite ta3 etableau
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("datee"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("status"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("taille"));


    return model;
}


bool cage::supprimercage(int idcage)
{
    QSqlQuery query;
         query.prepare("Delete from cages where identifiant=:id");
         query.bindValue(":id", idcage); //bin

         return query.exec();
}

bool cage::modifierCage(int idcage,int statuscage,int taillecage,QString typecage,QString datecage)
{
    QSqlQuery query;
    QString res= QString::number(idcage);
    query.prepare("UPDATE cages set status=:status,taille=:taille,type=:type,datee=:date where identifiant=:id");

        QString id_string= QString::number(idcage);
    query.bindValue(":id", id_string);
    query.bindValue(":status", statuscage);
    query.bindValue(":taille", taillecage);
    query.bindValue(":type", typecage);
    query.bindValue(":date", datecage);
    return query.exec();
}

QSqlQueryModel * cage::chercherCage(int idcage,int taillecage)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * from cages where identifiant like :id or taille like :taille ");
    query.bindValue(":id",idcage);// ID VARIABLE LOCAL BA3D BCH NA3MALOU APPEL BIL getIDANIM()
    query.bindValue(":taille",taillecage);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("datee"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("status"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("taille"));

    return model;
}

QSqlQueryModel* cage::trierCage()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *FROM cages ORDER BY identifiant ASC");


        model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant")); //setheader t7ot les entite ta3 etableau
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("datee"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("status"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("taille"));

    return model;
}


QSqlQueryModel* cage::trierCage1()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *FROM cages ORDER BY taille ASC");


        model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant")); //setheader t7ot les entite ta3 etableau
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("datee"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("status"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("taille"));

    return model;
}

QSqlQueryModel* cage::trierCage2()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *FROM cages ORDER BY taille ASC");


        model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant")); //setheader t7ot les entite ta3 etableau
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("datee"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("status"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("taille"));

    return model;
}



QSqlQueryModel * cage::cherchercage(QString a)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM cages WHERE (identifiant LIKE '%"+a+"%' OR status LIKE '%"+a+"%' OR datee LIKE '%"+a+"%' OR type LIKE '%"+a+"%' OR taille LIKE '%"+a+"%' ) ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("identifiant")); //setheader t7ot les entite ta3 etableau
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("datee"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("status"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("taille"));

    return model;
}
