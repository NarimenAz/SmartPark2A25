#ifndef GESTIONEVENEMENTS_H
#define GESTIONEVENEMENTS_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class GestionEvenements; }
QT_END_NAMESPACE

class GestionEvenements : public QMainWindow
{
    Q_OBJECT

public:
    GestionEvenements(QWidget *parent = nullptr);
    ~GestionEvenements();

private slots:
    void on_pushButton_clicked();

    void on_pb_ajouter_clicked();

    void on_Afficher_clicked();

    void on_Supprimer_clicked();

    void on_MiseAJour_clicked();

    void on_Recherche_clicked();

    void on_Trier_clicked();

private:
    Ui::GestionEvenements *ui;
};
#endif // GESTIONEVENEMENTS_H
