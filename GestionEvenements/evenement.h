#ifndef EVENEMENT_H
#define EVENEMENT_H
#include<QString>

class Evenement
{
public:
    void setID(QString n);
    void setNom(QString n);
    void setDate(QString n);
    QString get_ID();
    QString get_Nom();
    QString get_Date();
    Evenement();

private:
    QString ID,Nom,Date;
};

#endif // EVENEMENT_H
