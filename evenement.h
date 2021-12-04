#ifndef EVENEMENT_H
#define EVENEMENT_H

#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
class evenement
{
public:
    evenement();
    evenement E(int ID,QString Nom,QString Date,QString Theme,int NbEmployes);
    evenement(int,QString,QString,QString,int);
    int get_IDEvent();
    QString get_NomEvent();
    QString get_DateEvent();
    QString get_Theme();
    int get_NbEmployes();
    void setIDEvent(int);
    void setNomEvent(QString);
    void setDateEvent(QString);
    void setTheme(QString);
    void setNbEmployes(int);
    bool ajouterEvent();
    QSqlQueryModel* afficherEvent();
    void saisirEvent();
    bool supprimerEvent(int);
    bool supprimerToutEvent();
    bool modifierEvent(int,QString,QString,QString,int);
    QSqlQueryModel* rechercheEvent(int,QString,QString,QString);
    QSqlQueryModel * RechercheEvent(QString a);
    QSqlQueryModel * trierEvent(evenement E);
    QSqlQueryModel* trierEventNom();
    QSqlQueryModel* trierEventDate();
    QSqlQueryModel* trierEventTheme();



    void CREATION_PDF();

private:
    int IDEvent,NbEmployes;
    QString NomEvent,Theme,DateEvent;
};

#endif // EVENEMENT_H
