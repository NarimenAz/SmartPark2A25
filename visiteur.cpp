   #include "visiteur.h"
#include <QSqlQuery>


#include <QtDebug> ///car il ya des erreurs au niveau du bindvalue
#include<QObject>
Visiteur::Visiteur()

{

    id=0;
    nom="X";
    prenom="X";
    age=0;
    adresse="X";


}


Visiteur::Visiteur(int id,QString nom,QString prenom,int age,QString adresse)
{

    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
    this->age=age;
    this->adresse=adresse;

}

int Visiteur::getId(){return id;}
QString Visiteur::getNom(){return nom;}
QString Visiteur::getPrenom(){return  prenom;}
int Visiteur::getAge(){return age;}
QString Visiteur::getAdresse(){return adresse;}



void Visiteur::setId(int id){ this->id=id;  }
void Visiteur::setNom(QString nom){ this->nom=nom; }
void Visiteur::setPrenom(QString prenom){this->prenom=prenom;}
void Visiteur::setAge(int age){this->age=age; }
void Visiteur::setAdresse(QString adresse){ this->adresse=adresse;}

bool Visiteur::ajouterV()
{


    QSqlQuery q;
    ///dans notre requette on a injecete des chaines or id et un entie r
    QString id_string= QString::number(id);

    ///prepare prend la requette en parametre pour la preparer à l'execution
     q.prepare("INSERT INTO VISITEURS  (idvisiteur, nom_visiteur, prenom_visiteur, age_visiteur, adresse)" "VALUES (:id, :nom, :prenom, :age, :adresse)");
        ///inserer into table avec le nom visiteurs (noms des colone du tableau)
        ///creation des variables
        ///bindvalue sert a faire correspondance entre le nom de la variavle et valeur sotcke au nveau de lazone saisie par l utilisateurs
     q.bindValue(":id",id_string);
     q.bindValue(":nom",nom);
     q.bindValue(":prenom",prenom);
     q.bindValue(":age",age);
     q.bindValue(":adresse",adresse);





  return q.exec();//retrun false or true
}


QSqlQueryModel* Visiteur::afficherV()
{
    QSqlQueryModel* model=new QSqlQueryModel();///creation du model ,comment je vais remplir ce model


    model->setQuery("SELECT* from VISITEURS ");///la requette est nomme seelct


   /// creation d'autre nom pour les colonne je peux les pas faire cet etape
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));///ajouter header data =je suis entrain  d'ajouter le nom de colonne de mon tableau
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("Age"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("Adresse"));

    return model;


}


  bool Visiteur::supprimer(int)
  {
     QSqlQuery q;
     ///requete de suppression
     QString id_string= QString::number(id);
     q.prepare("Delete from visiteurs where IDVISITEUR=:id");  ///je vais supprimer du tableau VISITEURS dont colonne:idvisiteur = valeur entré par l'utilsateur
     q.bindValue(":id",id_string);
     return q.exec();


  }


  bool Visiteur::modifierV()
  { QSqlQuery q;

     QString id_string= QString::number(id);

      q.prepare("UPDATE VISITEURS" " SET IDVISITEUR = :id, nom_visiteur = :nom, prenom_visiteur = :prenom, age_visiteur = :age, adresse = :adresse" " WHERE IDVISITEUR= :id");

      q.bindValue(":id",id_string);
      q.bindValue(":nom",nom);
      q.bindValue(":prenom",prenom);
      q.bindValue(":age",age);
      q.bindValue(":adresse",adresse);



        return q.exec();//retrun false or true


  }






