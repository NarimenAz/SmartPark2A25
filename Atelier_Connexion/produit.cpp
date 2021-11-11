#include "produit.h"

produit::produit()
{


}
produit::produit(int ref,QString nom,QString categorie,float prix,int quantite)
{
    this->ref=ref;
    this->nom=nom;
    this->categorie=categorie;
    this->prix=prix;
    this->quantite=quantite;
}


bool produit::ajouter()
{
    QString pr=QString::number(prix);
    QSqlQuery query;
    query.prepare("insert into produit(ref,nom,categorie,prix,quantite) VALUES(:ref,:nom,:categorie,:prix,:quantite)");
    query.bindValue(":ref",ref);//injection SQL => securite
    query.bindValue(":nom",nom);
    query.bindValue(":categorie",categorie);
    query.bindValue(":prix",pr);
    query.bindValue(":quantite",quantite);
    return query.exec();
}

bool produit::supprimer(int ref)
{
    QSqlQuery query;
    query.prepare("delete from produit where ref=:ref");
    query.bindValue(":ref",ref);
    return query.exec();
}

bool produit::modifier(int ref)
{
    QSqlQuery query;
    QString pr=QString::number(prix);
    query.prepare("update produit set nom=:nom,categorie=:categorie,prix=:prix,quantite=:quantite where ref=:ref");
    query.bindValue(":ref",ref);//injection SQL => securite
    query.bindValue(":nom",nom);
    query.bindValue(":categorie",categorie);
    query.bindValue(":prix",pr);
    query.bindValue(":quantite",quantite);
    return query.exec();
}
QSqlQueryModel* produit::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from produit");
    return model;
}
QSqlQueryModel* produit::rechercher(QString selon,QString rech)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from produit where "+selon+" like '"+rech+"%'");
    return model;
}

QSqlQueryModel* produit::trier(QString selon)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from produit order by "+selon+"");
    return model;
}

