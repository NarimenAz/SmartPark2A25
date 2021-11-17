#ifndef CAGE_H
#define CAGE_H

#include <QString>
#include<QSqlQueryModel>

class cage
{
public:
    cage();
    cage(int,int,int,QString,QString);
    int getid();
    int getstatus();
    int gettaille();
    QString gettype();
    QString getdate();
    void setid(int);
    void setstatus(int);
    void settaille(int);
    void settype(QString);
    void setdate (QString);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifierCage(int,int,int,QString,QString );
    QSqlQueryModel*  chercherCage(int,int);
    QSqlQueryModel* trierCage();

private:
    int id, status,taille;
    QString type, date;

};

#endif // CAGE_H
