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
bool produit::rechercher(int ref)
{
    QString refer=QString::number(ref);
    QSqlQuery q("select * from produit where ref="+refer);
    while(q.next())
    {
        return true;
    }
    return false;
}


void produit::stat(QPieSeries *series)
{
    series->clear();
    QSqlQuery q("select categorie,count(*) from produit group by categorie");


     while(q.next())
     {series->append(q.value(0).toString()+": "+q.value(1).toString(),q.value(1).toInt());}
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
    bool test=rechercher(ref);
    QSqlQuery query;
    query.prepare("delete from produit where ref=:ref");
    query.bindValue(":ref",ref);
    query.exec();
    return test;
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
    query.exec();
    return rechercher(ref);
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

