#include "mainwindow.h"


#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection c;                 //creer objet de type connexion
    bool test=c.createconnect();//appel d'ouvrir une connexion
    MainWindow w;   // creer une instance de type mainwindow notre interface graphique
    if(test)                     // ouvrir connxion retourne true afficher connex successful
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else // snn echec de la connexion
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
