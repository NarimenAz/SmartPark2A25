#ifndef ANIMEAUX_H
#define ANIMEAUX_H

#include <iostream>
#include <string>
using namespace std;

class animeaux
{

private:
    int idAnim;
    string nomAnim;
    string typeAnim;
    int ageAnim;
    string pays;
    string status;
    string regimeAliment;
    int nbrRepas;
    int quantitéRepas;

public:
    string getNomAnim()const{return nomAnim;}
    int getIdAnim()const{return idAnim;}
    int getageAnim()const{return ageAnim;}
    void saisirAnim();
    void supprimerAnim(float);
    void ajouterAnim(float);
    void modifierAnim();
    void  chercherAnim(animeaux *A);
    void afficherAnim()const;
    void trierAnim( animeaux A);
    // void transfererArgent3(ANIMEAU & A);

};

#endif // ANIMEAUX_H
