#ifndef ANIMAUX_H
#define ANIMAUX_H


#include <QString>
//#include <QSqlQuery>
#include <QSqlQueryModel>
#include <cstdlib>
class animaux
{
private:
    int idAnim;
    QString nomAnim;
    QString typeAnim;
    int ageAnim;
    QString pays;
    QString status;
    QString regimeAliment;
    //int nbrRepas;
   // int quantitéRepas;

public:
    int getidAnim();
    QString getNomAnim();
    QString gettypeAnim();
    QString getpays();
    QString getstatus();
    QString getregimealim();
    int getageAnim();
    //int getnbrrepas();
   // int getquantitéRepas();

    void setidAnim(int);
    void setNomAnim(QString);
    void settypeAnim(QString);
    void setpays(QString);
    void setstatus(QString);
    void setregimealim(QString);
    void setageAnim(int);
  //  void setnbrrepas(int);
 //   void setquantitérepas(int);

void CREATION_PDF();


    bool ajouterAnim();
    QSqlQueryModel* afficherAnim();

    bool supprimerAnim(int);

    bool modifierAnim(int , QString,QString ,QString ,int,QString ,QString );
    QSqlQueryModel*  chercherAnim(int,QString,QString);

     QSqlQueryModel* trierAnim();
     QSqlQueryModel* trierAnimAge();
     QSqlQueryModel* trierAnimpays();

     bool supprimerTout();


     QSqlQueryModel * chercher(QString a);

    animaux(int idAnim, QString nomAnim,QString typeAnim,QString pays,int ageAnim,QString status,QString regimeAliment );
    animaux();
};

#endif // ANIMAUX_H


