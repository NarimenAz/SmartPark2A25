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
    bool ajouterproduit();
    bool modifierproduit(int);
    bool supprimerproduit(int);
    bool rechercherproduit(int);
    QSqlQueryModel* afficherproduit();
    QSqlQueryModel* rechercherproduit(QString,QString);
    QSqlQueryModel* trierproduit(QString);
    void statproduit(QPieSeries *series);

private:
    int ref;
    QString nomproduit;
    QString categorie;
    float prix;
    int quantite;
};

#endif // PRODUIT_H
