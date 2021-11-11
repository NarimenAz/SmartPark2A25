#ifndef DIALOG_H
#define DIALOG_H
#include "evenement.h"


#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    void setevenement(Evenement E);
    ~Dialog();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
