#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "BankUser.h"
//#include "BankCustomerPut.h"
//#include "BankCustomerCall.h"
//#include "BankOfficer.h"
#include "usergui.h"
#include "officergui.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_lineEdit_textEdited(const QString &arg1)
{

}

void MainWindow::on_pushButton_clicked()
{
    QString nome=ui->txtName->text() ;
    QString cognome=ui->txtLastName->text();
    QString id=ui->txtID->text();

    if(id.length()==4){
        UserGUI *user_gui = new UserGUI(this, nome, cognome, id);

        user_gui->window();
        user_gui->show();
        user_gui->activateWindow();

    } else if(id.length()==5){
        OfficerGUI *officer_gui = new OfficerGUI(this, nome, cognome, id);

        officer_gui->window();
        officer_gui->show();
        officer_gui->activateWindow();
        //this->hide();
    } else{
        QMessageBox msg;
        msg.setIcon(QMessageBox::Critical);
        msg.setText("Inserire ID valido");
        msg.exec();
    }


}
