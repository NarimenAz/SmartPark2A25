
#include "visiteur.h"
#include <QSqlQuery>


#include <QtDebug> ///car il ya des erreurs au niveau du bindvalue
#include<QObject>
visiteur::visiteur()

{

    idVisiteur=0;
    nomVisiteur="X";
    prenomVisiteur="X";
    ageVisiteur=0;
    adresseVisiteur="X";


}


visiteur::visiteur(int idVisiteur,QString nomVisiteur,QString prenomVisiteur,int ageVisiteur,QString adresseVisiteur)
{

    this->idVisiteur=idVisiteur;
    this->nomVisiteur=nomVisiteur;
    this->prenomVisiteur=prenomVisiteur;
    this->ageVisiteur=ageVisiteur;
    this->adresseVisiteur=adresseVisiteur;

}

int visiteur::getIdVisiteur(){return idVisiteur;}
QString visiteur::getNomVisiteur(){return nomVisiteur;}
QString visiteur::getPrenomVisiteur(){return  prenomVisiteur;}
int visiteur::getAgeVisiteur(){return ageVisiteur;}
QString visiteur::getAdresseVisiteur(){return adresseVisiteur;}



void visiteur::setIdVisiteur(int idVisiteur){ this->idVisiteur=idVisiteur;  }
void visiteur::setNomVisiteur(QString nomVisiteur){ this->nomVisiteur=nomVisiteur; }
void visiteur::setPrenomVisiteur(QString prenomVisiteur){this->prenomVisiteur=prenomVisiteur;}
void visiteur::setAgeVisiteur(int ageVisiteur){this->ageVisiteur=ageVisiteur; }
void visiteur::setAdresseVisiteur(QString adresseVisiteur){ this->adresseVisiteur=adresseVisiteur;}

bool visiteur::ajouterV()
{


    QSqlQuery q;

    QString id_string= QString::number(idVisiteur);


     q.prepare("INSERT INTO VISITEURS  (IDVISITEUR, nom_visiteur, prenom_visiteur, age_visiteur, adresse)" "VALUES (:id, :nom, :prenom, :age, :adresse)");
        ///inserer into table avec le nom visiteurs (noms des colone du tableau)
        ///creation des variables
        ///bindvalue sert a faire correspondance entre le nom de la variavle et valeur sotcke au nveau de lazone saisie par l utilisateurs
     q.bindValue(0,id_string);
     q.bindValue(1,nomVisiteur);
     q.bindValue(2,prenomVisiteur);
     q.bindValue(3,ageVisiteur);
     q.bindValue(4,adresseVisiteur);

  return q.exec();




}


QSqlQueryModel* visiteur::afficherV()
{
    QSqlQueryModel* model=new QSqlQueryModel();///creation du model ,comment je vais remplir ce model


    model->setQuery("SELECT* from VISITEURS ");///la requette est nomme seelct ///remplir le model a partir table de la base


   /// creation d'autre nom pour les colonne je peux les pas faire cet etape
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("ID"));///ajouter header data =je suis entrain  d'ajouter le nom de colonne de mon tableau
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("Prenom"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("Age"));
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("Adresse"));
    return model;


}


  bool visiteur::supprimerV(int id)
  {

      QSqlQuery q;
          ///requete de suppression

          q.prepare("Delete from VISITEURS where IDVISITEUR=:id");  ///je vais supprimer du tableau VISITEURS dont colonne:idvisiteur = valeur entré par l'utilsateur
          q.bindValue(0,id);
          return q.exec();

  }


  bool visiteur::modifierV()
  { QSqlQuery q;

     QString id_string= QString::number(idVisiteur);

      q.prepare("UPDATE VISITEURS" " SET IDVISITEUR = :id, nom_visiteur = :nom, prenom_visiteur = :prenom, age_visiteur = :age, adresse = :adresse" " WHERE IDVISITEUR=:id");

      q.bindValue(":id",id_string);
      q.bindValue(":nom",nomVisiteur);
      q.bindValue(":prenom",prenomVisiteur);
      q.bindValue(":age",ageVisiteur);
      q.bindValue(":adresse",adresseVisiteur);



        return q.exec();//retrun false or true


  }
///
///
///
///
///
///
/// ******************








 ///****************************



  QSqlQueryModel*  visiteur::chercherVisiteur( QString a)
  {


          QSqlQueryModel *model=new QSqlQueryModel();
          model->setQuery("SELECT * FROM VISITEURS WHERE (idvisiteur LIKE '%"+a+"%' OR prenom_visiteur LIKE '%"+a+"%' OR nom_visiteur LIKE '%"+a+"%' ) ");

          model->setHeaderData(2, Qt::Horizontal,QObject::tr("ID"));///ajouter header data =je suis entrain  d'ajouter le nom de colonne de mon tableau
          model->setHeaderData(3, Qt::Horizontal,QObject::tr("Nom"));
          model->setHeaderData(4, Qt::Horizontal,QObject::tr("Prenom"));
          model->setHeaderData(1, Qt::Horizontal,QObject::tr("Age"));
          model->setHeaderData(0, Qt::Horizontal,QObject::tr("Adresse"));
          return model;






  }

 QSqlQueryModel* visiteur::trierVisiteur()
 {


         QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("select * from VISITEURS  order by idvisiteur ASC");
         model->setHeaderData(2, Qt::Horizontal,QObject::tr("ID"));///ajouter header data =je suis entrain  d'ajouter le nom de colonne de mon tableau
         model->setHeaderData(3, Qt::Horizontal,QObject::tr("Nom"));
         model->setHeaderData(4, Qt::Horizontal,QObject::tr("Prenom"));
         model->setHeaderData(1, Qt::Horizontal,QObject::tr("Age"));
         model->setHeaderData(0, Qt::Horizontal,QObject::tr("Adresse"));

     return  model ;



 }
 QSqlQueryModel* visiteur::trierVisiteur2()
 {



     QSqlQueryModel *model=new QSqlQueryModel();
     model->setQuery("select * from VISITEURS  order by nom_visiteur ASC");
     model->setHeaderData(2, Qt::Horizontal,QObject::tr("ID"));///ajouter header data =je suis entrain  d'ajouter le nom de colonne de mon tableau
     model->setHeaderData(3, Qt::Horizontal,QObject::tr("Nom"));
     model->setHeaderData(4, Qt::Horizontal,QObject::tr("Prenom"));
     model->setHeaderData(1, Qt::Horizontal,QObject::tr("Age"));
     model->setHeaderData(0, Qt::Horizontal,QObject::tr("Adresse"));

 return  model ;


 }
 QSqlQueryModel* visiteur::trierVisiteur3()
 {


     QSqlQueryModel *model=new QSqlQueryModel();
     model->setQuery("select * from VISITEURS  order by age_visiteur ASC");
     model->setHeaderData(2, Qt::Horizontal,QObject::tr("ID"));///ajouter header data =je suis entrain  d'ajouter le nom de colonne de mon tableau
     model->setHeaderData(3, Qt::Horizontal,QObject::tr("Nom"));
     model->setHeaderData(4, Qt::Horizontal,QObject::tr("Prenom"));
     model->setHeaderData(1, Qt::Horizontal,QObject::tr("Age"));
     model->setHeaderData(0, Qt::Horizontal,QObject::tr("Adresse"));

 return  model ;



 }




 void visiteur::notification_ajouteV()
 {

     QSystemTrayIcon *notifyIcon = new QSystemTrayIcon; /// alloc dyn de licon

    // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
     notifyIcon->show();
     notifyIcon->showMessage("visiteur ","nouveau ajouter ",QSystemTrayIcon::Information,15000);

 }

 void visiteur::notification_supprimerV()
 {
     QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
     notifyIcon->show();
     notifyIcon->showMessage("visiteur ","nouveau supprimer",QSystemTrayIcon::Information,15000);
 }


 void visiteur::notification_modifierV(){
     QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
     notifyIcon->show();
     notifyIcon->showMessage("visiteur ","nouveau modifier",QSystemTrayIcon::Information,15000);
 }

