#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employee.h"
#include <QMainWindow>
#include  "Widget.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pushButton_clicked();

    void on_pb_modifier_clicked();

    void on_login_clicked();

    void on_load_pt_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pb_calcul_clicked();

    void on_camera_pt_clicked();

    void on_rech_textEdited(const QString &arg1);

    void on_rech_2_textEdited(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_comboBox_2_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
     Widget *dialog;
    Employee E;
};

#endif // MAINWINDOW_H
