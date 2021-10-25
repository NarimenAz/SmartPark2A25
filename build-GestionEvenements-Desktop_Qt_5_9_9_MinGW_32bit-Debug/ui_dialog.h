/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_4;
    QLineEdit *lineEdit_IDD;
    QLineEdit *lineEdit_NomD;
    QDateEdit *dateEditD;
    QTabWidget *tabWidget;
    QWidget *tab;
    QWidget *tab_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(1176, 633);
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(850, 110, 331, 261));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 70, 56, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 120, 56, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 170, 56, 16));
        lineEdit_IDD = new QLineEdit(groupBox);
        lineEdit_IDD->setObjectName(QStringLiteral("lineEdit_IDD"));
        lineEdit_IDD->setGeometry(QRect(170, 70, 113, 22));
        lineEdit_IDD->setCursor(QCursor(Qt::ArrowCursor));
        lineEdit_NomD = new QLineEdit(groupBox);
        lineEdit_NomD->setObjectName(QStringLiteral("lineEdit_NomD"));
        lineEdit_NomD->setGeometry(QRect(170, 110, 113, 22));
        dateEditD = new QDateEdit(groupBox);
        dateEditD->setObjectName(QStringLiteral("dateEditD"));
        dateEditD->setGeometry(QRect(180, 160, 111, 22));
        tabWidget = new QTabWidget(Dialog);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(260, 130, 411, 311));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Afficher les \303\251v\303\250nements", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Dialog", "Ev\303\250nement", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog", "ID", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog", "Nom", Q_NULLPTR));
        label_4->setText(QApplication::translate("Dialog", "Date", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Dialog", "Tab 1", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Dialog", "Tab 2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
