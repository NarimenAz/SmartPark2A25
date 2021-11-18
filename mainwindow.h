#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "animaux.h"
#include<QObject>

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

    void on_pb_rechercher_clicked();

    void on_pb_afficher_clicked();

   // void on_pb_trier_clicked();

    void on_pb_pdf_clicked();

    void on_pb_reset_clicked();

QModelIndex on_tab_animaux_activated( QModelIndex index);


    void on_pb_imprimer_clicked();

void on_tab_animaux_clicked(const QModelIndex &index);


void on_pb_stat_clicked();

void on_comboBox_trier_activated();

void on_comboBox_trier_activated(const QString &arg1);

void on_pb_camera_clicked();

void on_pb_code_clicked();

bool search(int);
private:
    Ui::MainWindow *ui;
    animaux A;
};
#endif // MAINWINDOW_H
