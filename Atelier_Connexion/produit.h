#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QVariant>
class produit
{
public:
    produit();//constructeur par defaut
    produit(int,QString,QString,float,int);//constructeur parametré
    bool ajouter();
    bool modifier(int);
    bool supprimer(int);
    QSqlQueryModel* afficher();
    QSqlQueryModel* rechercher(QString,QString);
    QSqlQueryModel* trier(QString);

private:
    int ref;
    QString nom;
    QString categorie;
    float prix;
    int quantite;
};

#endif // PRODUIT_H
