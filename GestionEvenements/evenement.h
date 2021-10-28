#ifndef EVENEMENT_H
#define EVENEMENT_H
#include<QString>

class Evenement
{
public:
    void setID(QString n);
    void setNom(QString n);
    void setDate(QString n);
    void setTheme(QString n);
    QString get_ID();
    QString get_Nom();
    QString get_Date();
    QString get_Theme();
    Evenement();

private:
    QString ID,Nom,Date,Theme;
};

#endif // EVENEMENT_H
