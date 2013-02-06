#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::initialization_value();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//控制部分
//计算
void MainWindow::on_count_clicked()
{
    MainWindow::data_check();
//    MainWindow::data_count();
}

void MainWindow::on_about_clicked()
{
    QMessageBox::about( NULL , tr("About") , tr(" Copyright (c) anwlw09 since 2013 ")) ;
}

//退出
void MainWindow::on_quit_clicked()
{
    close();
}


    //数据传入部分
    //初始化界面数据
    void MainWindow::initialization_value()
    {
        //初始化计算模式
        QStringList interest_period_unit;
        interest_period_unit.clear();
        interest_period_unit<<tr("year")<<tr("month")<<tr("day");
        ui->interest_period_unit->clear();
        ui->interest_period_unit->addItems(interest_period_unit);
        ui->interest_period_unit->setCurrentIndex(0);

        QStringList invest_period_unit;
        invest_period_unit.clear();
        invest_period_unit<<tr("year")<<tr("month")<<tr("day");
        ui->invest_period_unit->clear();
        ui->invest_period_unit->addItems(invest_period_unit);
        ui->invest_period_unit->setCurrentIndex(0);

        QStringList count_mode;
        count_mode.clear();
        count_mode<<tr("one time single interest")<<tr("one time compound interest")
                   <<tr("automatic investment plan single interest")<<tr("automatic investment plan compound interest");
        ui->count_mode->clear();
        ui->count_mode->addItems(count_mode);
        ui->count_mode->setCurrentIndex(0);

        //控制输入范围
        QDoubleValidator* present_value_validator = new QDoubleValidator ;
        present_value_validator->setRange(0 , 100000000.0 , 2 );
        ui->present_value->setValidator(present_value_validator);

        QIntValidator* interest_rate_validator = new QIntValidator ;
        interest_rate_validator->setRange(0 , 99 );
        ui->interest_rate->setValidator(interest_rate_validator);

        QIntValidator* interest_period_validator = new QIntValidator ;
        interest_period_validator->setRange(0 , 999 );
        ui->interest_period->setValidator(interest_period_validator);

        QIntValidator* invest_period_validator = new QIntValidator ;
        invest_period_validator->setRange(0,999);
        ui->invest_period->setValidator(invest_period_validator);
    }

    //数据合法性检查部分
    bool MainWindow::data_check()
    {
        if ( ui->present_value->displayText().toFloat() > 100000000. )
        {
            QMessageBox::information( NULL , tr("money is too much") , tr("too much money can't be take") , QMessageBox::Ok , QMessageBox::Ok ) ;
            return 0 ;
        }
        if ( ui->interest_period_unit->currentText().operator ==("year") && ui->interest_period->displayText().toInt() > 1 )
        {
            QMessageBox::information( NULL , tr("too later") , tr("so sad , no interest more than 1 year") , QMessageBox::Ok , QMessageBox::Ok ) ;
            return 0 ;
        }

        return 1 ;
    }


//运算部分
//数据整理部分


//计算公式部分
float MainWindow::data_count(unsigned char count_mode, float present_value, short interest_rate, short invest_period,
                             float automatic_investment_plan_value, float automatic_investment_plan_period )
{
    float final_value=0 , temp = 0 ;
    switch ( count_mode )
    {
    case 1 :
        final_value = present_value * interest_rate * invest_period ;
        return final_value ;
        break ;
    case 2 :
        final_value = present_value * pow( ( 1 + interest_rate ) , invest_period ) ;
        return final_value ;
        break ;
    case 3 :
        final_value = automatic_investment_plan_value * ( 1 * automatic_investment_plan_period + interest_rate * automatic_investment_plan_period *
                                                                ( automatic_investment_plan_period + 1 ) / 2 ) ;
        return final_value ;
        break ;
    case 4 :
        for ( ;automatic_investment_plan_period>0 ;automatic_investment_plan_period-- )
        {
            temp = pow ( ( 1 + interest_rate ) , automatic_investment_plan_period ) ;
            final_value = final_value + temp ;
            temp = 0 ;
        }
    }
}

    //数据传出部分
