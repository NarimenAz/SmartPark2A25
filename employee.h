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
Employee(QString,int,QString,QString,QString,QString,int salaire);
QString getId();
int getTel();
float getsalaire();
QString getNom();
QString getPrenom();
QString getSpecialite();
QString getAdress();

void setId(QString) ;
void setNom(QString);
void setPrenom(QString);
void setTel(int);
void setsalaire(float);
void setSpecialite(QString);
void setAdress(QString);
bool ajouter ();
QSqlQueryModel *afficher();
bool supprimer(QString);
bool modifier(QString,int,QString,QString,QString,QString,int);
 QSqlQueryModel * trier();
 QSqlQueryModel * trier1();
  QSqlQueryModel * trier2();
  QSqlQueryModel * rechercher(QString nom);
  QSqlQueryModel * rechercher1(QString a);
  QSqlQuery  calculerSalaire();
private:
int tel;
float salaire;
QString id,prenom, nom,adress,specialite;


};

#endif // ETUDIANT_H
