#ifndef USERGUI_H
#define USERGUI_H

#include <QDialog>
#include "BankCustomerPut.h"
#include "BankCustomerCall.h"

namespace Ui {
class UserGUI;
}

class UserGUI : public QDialog
{
    Q_OBJECT

public:
    explicit UserGUI(QWidget *parent = nullptr, QString _firstName="", QString _lastName="", QString _id="");
    ~UserGUI();

private slots:

    void on_cmdCalcCoupon_clicked();

    void on_cmdCalcZero_clicked();

    void on_cmdCalcAmerican_clicked();

    void on_cmdCalculateCall_clicked();

    void on_cmdSave_clicked();

    void on_cmdSaveCall_clicked();

private:
    Ui::UserGUI *ui;
    BankCustomerPut *customerPut;
    BankCustomerCall *customerCall;
    QString firstName;
    QString lastName;
    int id;
};

#endif // USERGUI_H
