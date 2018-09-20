#include <QMessageBox>
#include <fstream>
#include "officergui.h"
#include "ui_officergui.h"


OfficerGUI::OfficerGUI(QWidget *parent, QString _firstName, QString _lastName, QString _id) :
    QDialog(parent),
    ui(new Ui::OfficerGUI)
{
    ui->setupUi(this);
}

OfficerGUI::~OfficerGUI()
{
    delete ui;
}

void OfficerGUI::on_cmdOpenFile_clicked()
{
        using namespace std;
        uint ID = ui->txtCustomerID->text().toInt();

        ifstream db;

        string path = "Client_price/client_" + to_string(ID) + ".txt";
        try{
            db.open(path);
        }catch(const ifstream::failure& e){
            throw e;
        }
        string strfirstName;
        string strLastName;
        string strZeroCoupon;
        string strCuopon;
        string strAmerican;
        string strAmericanCall;


        db >> strfirstName >> strLastName >> strZeroCoupon >> strCuopon >> strAmerican >> strAmericanCall;

        ui->txtFirstName->setText(QString::fromStdString(strfirstName));
        ui->txtLastName->setText(QString::fromStdString(strLastName));
        ui->txtZeroCoupon->setText(QString::fromStdString(strZeroCoupon));
        ui->txtCuopon->setText(QString::fromStdString(strCuopon));
        ui->txtAmerican->setText(QString::fromStdString(strAmerican));

        ui->txtAmericanCall->setText(QString::fromStdString(strAmericanCall));


}

