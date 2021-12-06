#ifndef PRODUIT_H
#define PRODUIT_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QVariant>
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
class produit
{
public:
    produit();//constructeur par defaut
    produit(int,QString,QString,float,int);//constructeur parametré
    bool ajouter();
    bool modifier(int);
    bool supprimer(int);
    bool rechercher(int);
    QSqlQueryModel* afficher();
    QSqlQueryModel* rechercher(QString,QString);
    QSqlQueryModel* trier(QString);
    void stat(QPieSeries *series);

private:
    int ref;
    QString nom;
    QString categorie;
    float prix;
    int quantite;
};

#endif // PRODUIT_H
