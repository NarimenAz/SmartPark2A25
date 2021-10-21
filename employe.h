#ifndef EMPLOYÉ_H
#define EMPLOYÉ_H
#include <string>
#include <iostream>
#endif // EMPLOYÉ_H
using namespace std;

class
        employe
{
  private:

    int cin;
    string nom;
    string prenom;
    string email;
    int age ;
    string role;
    string birthdate;
     string birthplace;
     int salaire ;
     int password ;
     int poste;

public:
    void ajouteremploye();
    void suppemploye();
    void getageEmp();
    void modifEmp();
    void affichEmp();
    string getnameEmp();
    void trierEmp();
    void calculSalaireEmp();
    void getbirthplaceEmp();




};

