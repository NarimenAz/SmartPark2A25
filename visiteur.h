#ifndef VISITEUR_H
#define VISITEUR_H

#include<QString>
#include <QSqlQueryModel>
#include <QSystemTrayIcon>


class visiteur
{

public:
      visiteur();

      visiteur(int,QString,QString,int,QString);

      int getIdVisiteur();
      QString getNomVisiteur();
      QString getPrenomVisiteur();
      int getAgeVisiteur();
      QString getAdresseVisiteur();

    void setIdVisiteur(int);
    void setNomVisiteur(QString);
    void setPrenomVisiteur(QString);
    void setAgeVisiteur(int);
    void setAdresseVisiteur(QString);

        ///****CRUD*****
    bool ajouterV();
    QSqlQueryModel* afficherV();
    bool supprimerV(int);
    bool modifierV();




    QSqlQueryModel*  chercherVisiteur( QString a);
        QSqlQueryModel* trierVisiteur();
        QSqlQueryModel* trierVisiteur2();
        QSqlQueryModel* trierVisiteur3();

        void notification_ajouteV();

        void notification_supprimerV();

        void notification_modifierV();

private:

    int idVisiteur;
    QString nomVisiteur;
    QString prenomVisiteur;
    int ageVisiteur;
    QString adresseVisiteur;

};

#endif // VISITEUR_H
