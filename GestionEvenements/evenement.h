#ifndef EMPLOYES_H
#define EMPLOYES_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class Evenement
{
public:
    Evenement();
    Evenement E(int ID,QString Nom,QString Date,QString Theme,int NbEmployes);
    Evenement(int,QString,QString,QString,int);
    int get_ID();
    QString get_Nom();
    QString get_Date();
    QString get_Theme();
    int get_NbEmployes();
    void setID(int);
    void setNom(QString);
    void setDate(QString);
    void setTheme(QString);
    void setNbEmployes(int);
    void saisirEvent();
    bool supprimerEvent(int);
    bool ajouterEvent();
    bool modifierEvent(int,QString,QString,QString,int);
    QSqlQueryModel* rechercheEvent(int);
    QSqlQueryModel* afficherEvent();
    QSqlQueryModel * trierEvent(Evenement E);

private:
    int ID,NbEmployes;
    QString Nom,Theme,Date;
};


#endif // EMPLOYES_H
