#ifndef VISITEUR_H
#define VISITEUR_H

#include<QString>
#include <QSqlQueryModel>

class Visiteur
{
public:
      Visiteur();

      Visiteur(int,QString,QString,int,QString);

      int getId();
      QString getNom();
      QString getPrenom();
      int getAge();
      QString getAdresse();

    void setId(int);
    void setNom(QString);
    void setPrenom(QString);
    void setAge(int);
    void setAdresse(QString);

        ///****CRUD*****
    bool ajouterV();
    QSqlQueryModel* afficherV();
    bool supprimer(int);
    bool modifierV();

private:

    int id;
    QString nom;
    QString prenom;
    int age;
    QString adresse;



};

#endif // VISITEUR_H
