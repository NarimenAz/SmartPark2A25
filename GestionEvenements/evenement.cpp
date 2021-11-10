#include "evenement.h"
#include <QSqlQuery>
#include <QtDebug>
Evenement::Evenement()
{
    ID=0;
    Nom="";
    Date="";
    Theme="";
    Employés=0;

}

Evenement::Evenement(int ID,QString Nom,int Date,QString Theme,int Nbr_Employés)
{
    this->ID=ID;
    this->Nom=Nom;
    this->Date=Date;
    this->Theme=Theme;
    this->NbEmployés=NbEmployés;


}

int Evenement::get_ID(){return ID;}
QString Evenement::get_Nom(){return Nom;}
int Evenement::get_Date(){return Date;}
QString Evenement::get_Theme(){return Theme;}
int Evenement::NbEmployés(){return NbEmployés;}

void Evenement::setID(int ID){this->ID=ID;}
void Evenement::setNom(QString Nom){this->Nom=Nom;}
void Evenement::setDate(int Date){this->Date=Date;}
void Evenement::setTheme(QString Theme){this->Theme=Theme;}
void Evenement::setNbEmployés(int NbEmployés){this->NbEmployés=NbEmployés;}
bool Evenement::ajouterEvent()
{
    bool test=false;
    QSqlQuery query;
       query.prepare("INSERT INTO evenements (id, forename, surname) "
                     "VALUES (:id, :forename, :surname)");
       query.bindValue(":id", 1001);
       query.bindValue(":forename", "Bart");
       query.bindValue(":surname", "Simpson");
       query.exec();
    return test;
}


