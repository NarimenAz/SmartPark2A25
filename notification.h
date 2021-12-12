#ifndef NOTIFICATION_H
#define NOTIFICATION_H


#include <QSystemTrayIcon>
#include<QString>
class Notification
{
public:
    Notification();
    void notification_ajoutanimau();

    void notification_supprimeranimau();

    void notification_modifieranimau();
    void notification_carte();
    void notification_ouverture();
    void notification_fermeture();



};


#endif // NOTIFICATION_H
