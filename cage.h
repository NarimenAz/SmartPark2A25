#ifndef CAGE_H
#define CAGE_H

#include <QString>
#include<QSqlQueryModel>

class cage
{
public:
    cage();
    cage(int,int,int,QString,QString);
    int getidcage();
    int getstatuscage();
    int gettaillecage();
    QString gettypecage();
    QString getdatecage();
    void setidcage(int);
    void setstatuscage(int);
    void settaillecage(int);
    void settypecage(QString);
    void setdatecage (QString);
    bool ajoutercage();
    QSqlQueryModel* affichercage();
    bool supprimercage(int);
    bool modifierCage(int,int,int,QString,QString );
    QSqlQueryModel*  chercherCage(int,int);
    QSqlQueryModel* trierCage();
    QSqlQueryModel* trierCage1();
    QSqlQueryModel* trierCage2();
   QSqlQueryModel*  cherchercage(QString a);
private:
    int idcage, statuscage,taillecage;
    QString typecage, datecage;

};

#endif // CAGE_H
