#include "usergui.h"
#include "ui_usergui.h"
#include <QMessageBox>
#include "BankCustomerPut.h"
#include "BankCustomerCall.h"
#include <vector>


UserGUI::UserGUI(QWidget *parent, QString _firstName, QString _lastName, QString _id) :
    QDialog(parent),
    ui(new Ui::UserGUI)
{
    ui->setupUi(this);

    this->firstName = _firstName;
    this->lastName = _lastName;
    this->id = _id.toInt();

}

UserGUI::~UserGUI()
{
    delete ui;
}

void UserGUI::on_cmdCalcCoupon_clicked()
{
    double Bond_price = ui->txtPrice->text().toDouble();
    double Exercise_price = ui->txtExePrice->text().toDouble();
    double interest = ui->txtInterest->text().toDouble();
    double volatility = ui->txtVolatility->text().toDouble();
    double time = ui->txtTime->text().toDouble();
    double coupon_time_val = ui->txtCtime->text().toDouble();
    double coupon_amount_val = ui->txtCAmount->text().toDouble();
    int step = ui->txtStep->text().toInt();

    std::vector<double> coupon_time;
    std::vector<double> coupon_amount;
    coupon_time.push_back(coupon_time_val);
    coupon_amount.push_back(coupon_amount_val);

    this->customerPut= new BankCustomerPut (this->firstName.toStdString(), this->lastName.toStdString(), this->id,
                                            Bond_price,Exercise_price,interest,volatility,time,coupon_time,coupon_amount,step);

    double couponPrice = this->customerPut->getCouponPrice();

    ui->txtCouponPrice->setText(QString::number(couponPrice));

}

void UserGUI::on_cmdCalcZero_clicked()
{
    double Bond_price = ui->txtPrice->text().toDouble();
    double Exercise_price = ui->txtExePrice->text().toDouble();
    double interest = ui->txtInterest->text().toDouble();
    double volatility = ui->txtVolatility->text().toDouble();
    double time = ui->txtTime->text().toDouble();
    double coupon_time_val = ui->txtCtime->text().toDouble();
    double coupon_amount_val = ui->txtCAmount->text().toDouble();
    int step = ui->txtStep->text().toInt();

    std::vector<double> coupon_time;
    std::vector<double> coupon_amount;
    coupon_time.push_back(coupon_time_val);
    coupon_amount.push_back(coupon_amount_val);

    this->customerPut = new BankCustomerPut (this->firstName.toStdString(), this->lastName.toStdString(), this->id,
                                             Bond_price,Exercise_price,interest,volatility,time,coupon_time,coupon_amount,step);

    double zeroPrice = this->customerPut->getZeroPrice();

    ui->txtZeroPrice->setText(QString::number(zeroPrice));
}

void UserGUI::on_cmdCalcAmerican_clicked()
{
    double Bond_price = ui->txtPrice->text().toDouble();
    double Exercise_price = ui->txtExePrice->text().toDouble();
    double interest = ui->txtInterest->text().toDouble();
    double volatility = ui->txtVolatility->text().toDouble();
    double time = ui->txtTime->text().toDouble();
    double coupon_time_val = ui->txtCtime->text().toDouble();
    double coupon_amount_val = ui->txtCAmount->text().toDouble();
    int step = ui->txtStep->text().toInt();

    std::vector<double> coupon_time;
    std::vector<double> coupon_amount;
    coupon_time.push_back(coupon_time_val);
    coupon_amount.push_back(coupon_amount_val);

    this->customerPut = new BankCustomerPut (this->firstName.toStdString(), this->lastName.toStdString(), this->id,
                                             Bond_price,Exercise_price,interest,volatility,time,coupon_time,coupon_amount,step);

    double americanPrice = this->customerPut->getAmericanPrice();

    ui->txtAmericanPrice->setText(QString::number(americanPrice));
}

void UserGUI::on_cmdCalculateCall_clicked()
{
    double Bond_price = ui->txtBondPrice->text().toDouble();
    double option_maturity = ui->txtOption->text().toDouble();
    double volatility = ui->txtVol->text().toDouble();
    double term_structure = ui->txtTerm->text().toDouble();
    double interest = ui->txtInter->text().toDouble();
    double bond_maturity = ui->txtBondMatur->text().toDouble();
    double maturity_payment = ui->txtMaturityPay->text().toDouble();
    int step = ui->txtNumSteps->text().toInt();

    this->customerCall = new BankCustomerCall(this->firstName.toStdString(), this->lastName.toStdString(),this->id,
                                              Bond_price,option_maturity,volatility,term_structure,interest,bond_maturity,
                                              maturity_payment,step);
    double callPrice = this->customerCall->getAmericanCallPrice();

    ui->txtCallPrice->setText(QString::number(callPrice));
}

void UserGUI::on_cmdSave_clicked()
{
    QMessageBox msg;

    if(this->customerPut->storePrices()){
        msg.setText("Ok saved!");
    }else{
        msg.setText("Error");
    }
    msg.exec();
}

void UserGUI::on_cmdSaveCall_clicked()
{
    QMessageBox msg;

    if(this->customerCall->storePrices()){
        msg.setText("Ok saved!");
    }else{
        msg.setText("Error");
    }
    msg.exec();
}
