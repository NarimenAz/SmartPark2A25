#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "animaux.h"
#include<QObject>
#include "employee.h"
#include "visiteur.h"
#include "cage.h"
#include "evenement.h"
#include "produit.h"

#include  "Widget.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_bp_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();
    void on_pb_afficher_clicked();
    void on_pb_pdf_clicked();
    void on_pb_reset_clicked();
    QModelIndex on_tab_animaux_activated( QModelIndex index);
    void on_pb_imprimer_clicked();
   void on_tab_animaux_clicked(const QModelIndex &index);

void on_pb_stat_clicked();

void on_comboBox_trier_activated();

void on_comboBox_trier_activated(const QString &arg1);

void on_pb_code_clicked();

bool search(int);
//void on_le_rechercher_textChanged();

void on_le_rechercher_textEdited(const QString &arg1);


/************************ gestion des employés omar **************************/


void on_pb_ajouteremploye_clicked();

void on_pb_supprimeremploye_clicked();

void on_pb_modifieremploye_clicked();

void on_login_1_clicked();

void on_load_pt_clicked();

void on_pb_triidemploye_clicked();

void on_pb_trinomemploye_clicked();

void on_pb_triprenomemploye_clicked();

void on_pb_rechercheremploye_clicked();

void on_pb_calcul_clicked();

void on_camera_pt_clicked();


/******************** visiteur arbia  *********************/


void on_pb_ajoutervisiteur_clicked();

void on_pb_modifiervisiteur_clicked();

void on_pb_actualvisiteur_clicked();

void on_triidvisiteur_clicked();

void on_pb_loadvisiteur_clicked();

void on_comboBox_modifvisiteur_activated(const QString &arg1);

void on_pb_statvisiteur_clicked();

void on_le_trinomvisiteur_clicked();

void on_le_triagevisiteur_clicked();

void on_le_fich_excel_clicked();

void on_le_rechvisiteur_textEdited(const QString &arg1);

void on_pb_chargementtvisiteur_clicked();

void on_le_id_supprimerrvisiteur_clicked();




/*****************   gest cage aziz   ***************************/

void on_pb_ajoutercage_clicked();

void on_pb_supprimercage_clicked();

void on_pb_modifiercage_clicked();

void on_pb_recherchercage_clicked();

void on_pb_tricage_clicked();

void on_pushButtoncage_clicked();

void on_pushButton_2cage_clicked();

void on_pushButton_3cage_clicked();

void on_comboBox_2cage_activated(const QString &arg1);

void on_pushButton_4cage_clicked();

void on_pushButton_5cage_clicked();

void on_pushButton_6cage_clicked();

void on_pushButton_7cage_clicked();

void on_lineEditcage_textEdited(const QString &arg1);

void on_lineEditcage_cursorPositionChanged(int arg1, int arg2);

void on_pushButton_8cage_clicked();



/*****************   gest event youssef   ***************************/


void on_pb_ajouterevent_clicked();

void on_Afficherevent_clicked();

void on_Supprimerevent_clicked();

void on_Rechercheevent_clicked();

QModelIndex on_table_event_activated(QModelIndex);

void on_table_event_clicked(const QModelIndex &index);

void on_Modifierevent_clicked();

void on_Statistiqueevent_clicked();

void on_Resetevent_clicked();

void on_comboBoxevent_activated();

void on_pushButton_11event_clicked();
bool searchevent(int);

void on_lineEditevent_textEdited(const QString &arg1);

void on_pushButton_8event_clicked();

void on_calendarWidget_clicked(const QDate &date);


/********************  gest produit narimen  *******************/



void on_pb_ajouterproduit_clicked();

void on_pb_supprimerproduit_clicked();

void on_pushButtonproduit_clicked();

void on_pushButton_2produit_clicked();

void on_pushButton_3produit_clicked();

void on_pushButton_4produit_clicked();

void on_pushButton_5produit_clicked();

void on_pushButton_6produit_clicked();

void affrechproduit();




private:
    Ui::MainWindow *ui;


    animaux A;
    Widget *dialog;
   employee E;
   visiteur V;
   cage C;
   QStringList files;
   evenement e ;
   produit p;
   QPieSeries *series = new QPieSeries();
};
#endif // MAINWINDOW_H
