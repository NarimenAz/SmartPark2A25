#include "evenement.h"

Evenement::Evenement()
{
    ID="";
    Nom="";
    Date="";

}
void Evenement::setID(QString n){ID=n;}
void Evenement::setNom(QString n){Nom=n;}
void Evenement::setDate(QString n){Date=n;}

QString Evenement::get_ID(){return ID;}
QString Evenement::get_Nom(){return Nom;}
QString Evenement::get_Date(){return Date;}
