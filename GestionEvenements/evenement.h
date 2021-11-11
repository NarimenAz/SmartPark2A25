#ifndef EVENEMENT_H
#define EVENEMENT_H
#include<QString>

class Evenement
{
public:
    Evenement();
    Evenement E(int ID,QString Nom,int Date,QString Theme,int NbEmployés);
    Evenement(int,QString,int,QString,int);
    int get_ID();
    QString get_Nom();
    int get_Date();
    QString get_Theme();
    int get_NbEmployés();
    void setID(int);
    void setNom(QString);
    void setDate(int);
    void setTheme(QString);
    void setNbEmployés(int);
    void saisirEvent();
    bool supprimerEvent();
    bool ajouterEvent();
    bool modifierEvent();
    void rechercheEvent(Evenement *E);
    void afficherEvent()const;
    void trierEvent(Evenement E);

private:
    int ID,Date,NbEmployés;
    QString Nom,Theme;
};

#endif // EVENEMENT_H
