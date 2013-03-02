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
    data_check();
    unsigned char count_mode = count_mode_trim(ui->count_mode->currentText());
    float present_value = present_value_trim(ui->present_value->text());
    float interest_rate = interest_rate_trim();
    float invest_period = invest_period_trim();
    float automatic_investment_plan_value = automatic_investment_plan_value_trim(ui->automatic_investment_plan_value->text());
    float automatic_investment_plan_period = automatic_investment_plan_period_trim(ui->automatic_investment_plan_period->text(),
                                                                                   ui->automatic_investment_plan_period_unit->currentText());
    float final_value = data_count(count_mode,present_value,interest_rate,invest_period,
                                   automatic_investment_plan_value,automatic_investment_plan_period );
    data_show(final_value);
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
        QString present_value;
        present_value = "10000.00";
        ui->present_value->setText(present_value);

        QString interest_rate;
        interest_rate = "5";
        ui->interest_rate->setText(interest_rate);

        QString interest_period;
        interest_period = "1";
        ui->interest_period->setText(interest_period);

        QStringList interest_period_unit;
        interest_period_unit.clear();
        interest_period_unit<<tr("year")<<tr("month")<<tr("day");
        ui->interest_period_unit->clear();
        ui->interest_period_unit->addItems(interest_period_unit);
        ui->interest_period_unit->setCurrentIndex(0);

        QString invest_period;
        invest_period = "1";
        ui->invest_period->setText(invest_period);

        QStringList invest_period_unit;
        invest_period_unit.clear();
        invest_period_unit<<tr("year")<<tr("month")<<tr("day");
        ui->invest_period_unit->clear();
        ui->invest_period_unit->addItems(invest_period_unit);
        ui->invest_period_unit->setCurrentIndex(0);

        QString final_value;
        final_value = "0";
        ui->final_value->setText(final_value);

        QString automatic_investment_plan_value;
        automatic_investment_plan_value = "10000.00";
        ui->automatic_investment_plan_value->setText(automatic_investment_plan_value);

        QString automatic_investment_plan_period;
        automatic_investment_plan_period = "20";
        ui->automatic_investment_plan_period->setText(automatic_investment_plan_period);

        QStringList automatic_investment_plan_period_unit;
        automatic_investment_plan_period_unit.clear();
        automatic_investment_plan_period_unit<<tr("year")<<tr("month")<<tr("day");
        ui->automatic_investment_plan_period_unit->clear();
        ui->automatic_investment_plan_period_unit->addItems(automatic_investment_plan_period_unit);
        ui->automatic_investment_plan_period_unit->setCurrentIndex(0);

        QStringList count_mode;
        count_mode.clear();
        count_mode<<tr("one time single interest")<<tr("one time compound interest")
                   <<tr("automatic investment plan single interest")<<tr("automatic investment plan compound interest");
        ui->count_mode->clear();
        ui->count_mode->addItems(count_mode);
        ui->count_mode->setCurrentIndex(0);

        //控制输入范围
        QDoubleValidator* present_value_validator = new QDoubleValidator ;
        present_value_validator->setRange(0.0 , 100000000.0 , 2 );
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
        if ( ui->present_value->displayText().toFloat() > 100000000.0 )
        {
            QMessageBox::information( NULL , tr("money is too much") , tr("too much money can't be take") ,
                                      QMessageBox::Ok , QMessageBox::Ok ) ;
            return 0 ;
        }
        if ( ui->interest_period_unit->currentText().operator ==("year") && ui->interest_period->displayText().toInt() > 1 )
        {
            QMessageBox::information( NULL , tr("too later") , tr("so sad , no interest more than 1 year") ,
                                      QMessageBox::Ok , QMessageBox::Ok ) ;
            return 0 ;
        }

        return 1 ;
    }


//运算部分
//数据整理部分

float MainWindow::present_value_trim(QString present_value)
{
    return present_value.toFloat();
}

float MainWindow::interest_rate_trim()
{
    if (ui->interest_period_unit->currentText().operator ==("day"))
    {
        return ui->interest_rate->text().toShort()/(ui->interest_period->text().toShort()*365.0)/100.0 ;
    }
    else if (ui->interest_period_unit->currentText().operator ==("month"))
    {
        return ui->interest_rate->text().toShort()/(ui->interest_period->text().toShort()*12.0)/100.0 ;
    }
    else
    {
        return ui->interest_rate->text().toShort()/(ui->interest_period->text().toShort()*1.0)/100.0 ;
    }
}

float MainWindow::invest_period_trim()
{
    if (ui->invest_period_unit->currentText().operator ==("day"))
    {
        return ui->invest_period->text().toShort()/365.0 ;
    }
    else if (ui->invest_period_unit->currentText().operator ==("month"))
    {
        return ui->invest_period->text().toShort()/12.0 ;
    }
    else
    {
        return ui->invest_period->text().toShort()/1.0 ;
    }
}

float MainWindow::automatic_investment_plan_value_trim(QString automatic_investment_plan_value)
{
    return automatic_investment_plan_value.toFloat();
}

float MainWindow::automatic_investment_plan_period_trim(QString automatic_investment_plan_period,
                                                        QString automatic_investment_plan_period_unit)
{
    if (automatic_investment_plan_period_unit== "day")
    {
        return automatic_investment_plan_period.toShort()/365.0 ;
    }
    else if (automatic_investment_plan_period_unit== "month")
    {
        return automatic_investment_plan_period.toShort()/12.0 ;
    }
    else
    {
        return automatic_investment_plan_period.toShort()/1.0 ;
    }
}

unsigned char MainWindow::count_mode_trim(QString count_mode)
{
    if (count_mode == "one time single interest"){return 1;}
    else if (count_mode == "one time compound interest"){return 2;}
    else if (count_mode == "automatic investment plan single interest"){return 3;}
    else if (count_mode == "automatic investment plan compound interest"){return 4;}
    return 0;
}

//计算公式部分
float MainWindow::data_count(unsigned char count_mode, float present_value, float interest_rate, float invest_period,
                             float automatic_investment_plan_value, float automatic_investment_plan_period )
{
    float final_value=0 , temp = 0 ;
    switch ( count_mode )
    {
    case 1 :
        final_value = present_value * (1.0 + interest_rate * invest_period ) ;
        return final_value ;
        break ;
    case 2 :
        final_value = present_value * pow( ( 1.0 + interest_rate ) , invest_period ) ;
        return final_value ;
        break ;
    case 3 :
        final_value = automatic_investment_plan_value * ( 1.0 * automatic_investment_plan_period + interest_rate *
                                                          automatic_investment_plan_period *
                                                          ( automatic_investment_plan_period + 1.0 ) / 2.0 ) ;
        return final_value ;
        break ;
    case 4 :
        for ( ;automatic_investment_plan_period>0 ;automatic_investment_plan_period-- )
        {
            temp = automatic_investment_plan_value * pow ( ( 1.0 + interest_rate ) , automatic_investment_plan_period ) ;
            final_value = final_value + temp ;
            temp = 0 ;
        }
        return final_value ;
        break ;
    default :
        return 0 ;
    }
}

    //数据传出部分
    void MainWindow::data_show(float final_value_input)
    {
        QString final_value;
        final_value.setNum(final_value_input,'g',6);
        ui->final_value->setText(final_value);
    }
