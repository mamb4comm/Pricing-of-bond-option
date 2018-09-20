#ifndef OFFICERGUI_H
#define OFFICERGUI_H

#include <QDialog>

namespace Ui {
class OfficerGUI;
}

class OfficerGUI : public QDialog
{
    Q_OBJECT

public:
    explicit OfficerGUI(QWidget *parent = nullptr, QString _firstName="", QString _lastName="", QString _id="");
    ~OfficerGUI();

private slots:
    void on_cmdOpenFile_clicked();


private:
    Ui::OfficerGUI *ui;
    QString firstName;
    QString lastName;
    int id;
};

#endif // OFFICERGUI_H
