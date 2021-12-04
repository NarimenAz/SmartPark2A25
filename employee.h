#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QString>
#include <QSqlQueryModel>
class employee
{
public:
employee();
employee(QString,int,QString,QString,QString,QString,int salaire);
QString getIdEmploy();
int getTel();
float getsalaire();
QString getNomEmploy();
QString getPrenomEmploy();
QString getSpecialite();
QString getAdress();

void setIdEmploy(QString) ;
void setNomEmploy(QString);
void setPrenomEmploy(QString);
void setTel(int);
void setsalaire(float);
void setSpecialite(QString);
void setAdress(QString);
bool ajouterEmploye ();
QSqlQueryModel *afficherEmploye();
bool supprimerEmploye(QString);
bool modifierEmploye(QString,int,QString,QString,QString,QString,int);
 QSqlQueryModel * trierEmploye();
 QSqlQueryModel * trierEmploye1();
  QSqlQueryModel * trierEmploye2();
  QSqlQueryModel * rechercherEmploye(QString nom);
  QSqlQuery  calculerSalaire();
private:
int tel;
float salaire;
QString idEmploye,prenomEmploye, nomEmploye,adress,specialite;


};

#endif // EMPLOYEE_H
