/********************************************************************************
** Form generated from reading UI file 'gestionevenements.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GESTIONEVENEMENTS_H
#define UI_GESTIONEVENEMENTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GestionEvenements
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *tab_5;
    QWidget *tab_6;
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QLabel *label;
    QLineEdit *lineEdit_ID;
    QLabel *label_2;
    QLineEdit *lineEdit_Nom;
    QLabel *label_3;
    QDateEdit *dateEdit;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QLabel *label_5;
    QSpinBox *spinBox;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QWidget *tab_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *GestionEvenements)
    {
        if (GestionEvenements->objectName().isEmpty())
            GestionEvenements->setObjectName(QStringLiteral("GestionEvenements"));
        GestionEvenements->resize(1142, 693);
        centralwidget = new QWidget(GestionEvenements);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(60, 40, 1051, 581));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        pushButton = new QPushButton(tab_6);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(750, 40, 93, 28));
        pushButton->setCursor(QCursor(Qt::PointingHandCursor));
        groupBox = new QGroupBox(tab_6);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(40, 20, 471, 501));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 60, 56, 16));
        lineEdit_ID = new QLineEdit(groupBox);
        lineEdit_ID->setObjectName(QStringLiteral("lineEdit_ID"));
        lineEdit_ID->setGeometry(QRect(220, 60, 113, 22));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 130, 56, 16));
        lineEdit_Nom = new QLineEdit(groupBox);
        lineEdit_Nom->setObjectName(QStringLiteral("lineEdit_Nom"));
        lineEdit_Nom->setGeometry(QRect(220, 130, 113, 22));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 200, 56, 16));
        dateEdit = new QDateEdit(groupBox);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setGeometry(QRect(220, 200, 111, 22));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 270, 56, 16));
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(220, 270, 113, 22));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 330, 181, 16));
        spinBox = new QSpinBox(groupBox);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(220, 330, 42, 22));
        pushButton_3 = new QPushButton(groupBox);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(90, 420, 93, 28));
        pushButton_3->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(280, 420, 93, 28));
        pushButton_2->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_4 = new QPushButton(tab_6);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(750, 220, 93, 28));
        pushButton_4->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_5 = new QPushButton(tab_6);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(750, 160, 93, 28));
        pushButton_5->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_6 = new QPushButton(tab_6);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(750, 100, 93, 28));
        pushButton_6->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_8 = new QPushButton(tab_6);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(750, 280, 93, 28));
        pushButton_8->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_9 = new QPushButton(tab_6);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));
        pushButton_9->setGeometry(QRect(750, 340, 93, 28));
        pushButton_9->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_10 = new QPushButton(tab_6);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(750, 400, 93, 28));
        pushButton_10->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_11 = new QPushButton(tab_6);
        pushButton_11->setObjectName(QStringLiteral("pushButton_11"));
        pushButton_11->setGeometry(QRect(750, 460, 93, 28));
        pushButton_11->setCursor(QCursor(Qt::PointingHandCursor));
        tabWidget->addTab(tab_6, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        GestionEvenements->setCentralWidget(centralwidget);
        menubar = new QMenuBar(GestionEvenements);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1142, 26));
        GestionEvenements->setMenuBar(menubar);
        statusbar = new QStatusBar(GestionEvenements);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        GestionEvenements->setStatusBar(statusbar);

        retranslateUi(GestionEvenements);

        tabWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(GestionEvenements);
    } // setupUi

    void retranslateUi(QMainWindow *GestionEvenements)
    {
        GestionEvenements->setWindowTitle(QApplication::translate("GestionEvenements", "Gestion des Ev\303\250nements", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("GestionEvenements", "Gestion des animaux", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("GestionEvenements", "Gestion des employ\303\251s", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("GestionEvenements", "Gestion des clients", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("GestionEvenements", "Gestion des enclos", Q_NULLPTR));
        pushButton->setText(QApplication::translate("GestionEvenements", "Afficher", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("GestionEvenements", "Ajouter un \303\251v\303\250nement", Q_NULLPTR));
        label->setText(QApplication::translate("GestionEvenements", "ID", Q_NULLPTR));
        label_2->setText(QApplication::translate("GestionEvenements", "Nom", Q_NULLPTR));
        label_3->setText(QApplication::translate("GestionEvenements", "Date", Q_NULLPTR));
        label_4->setText(QApplication::translate("GestionEvenements", "Th\303\250me", Q_NULLPTR));
        label_5->setText(QApplication::translate("GestionEvenements", "Nombre d'employ\303\251s requis", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("GestionEvenements", "Valider", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("GestionEvenements", "Quitter", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("GestionEvenements", "Mis \303\240 jour", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("GestionEvenements", "Supprimer", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("GestionEvenements", "Chercher", Q_NULLPTR));
        pushButton_8->setText(QApplication::translate("GestionEvenements", "Calendrier", Q_NULLPTR));
        pushButton_9->setText(QApplication::translate("GestionEvenements", "Trier", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("GestionEvenements", "Statistiques", Q_NULLPTR));
        pushButton_11->setText(QApplication::translate("GestionEvenements", "PDF", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("GestionEvenements", "Gestion des \303\251v\303\250nements", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("GestionEvenements", "Gestion des produits", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GestionEvenements: public Ui_GestionEvenements {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GESTIONEVENEMENTS_H
