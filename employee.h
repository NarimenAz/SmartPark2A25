#ifndef EMPLOOYEE_H
#define EMPLOYEE_H
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QSqlQueryModel>
class Employee
{

public:
Employee();
Employee(QString,int,QString,QString,QString,QString);
QString getId();
int getTel();
QString getNom();
QString getPrenom();
QString getSpecialite();
QString getAdress();

void setId(QString) ;
void setNom(QString);
void setPrenom(QString);
void setTel(int);
void setSpecialite(QString);
void setAdress(QString);
bool ajouter ();
QSqlQueryModel *afficher();
bool supprimer(QString);
bool modifier(QString,int,QString,QString,QString,QString);
private:
int tel;
QString id,prenom, nom,adress,specialite;


};

#endif // ETUDIANT_H
