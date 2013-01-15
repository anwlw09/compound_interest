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
}

void MainWindow::on_about_clicked()
{
    QMessageBox::about( NULL , "关于" , " copyright (c) anwlw09 since 2013 ") ;
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
        interest_period_unit<<"年"<<"月"<<"日";
        ui->interest_period_unit->clear();
        ui->interest_period_unit->addItems(interest_period_unit);
        ui->interest_period_unit->setCurrentIndex(0);

        QStringList account_mode;
        account_mode.clear();
        account_mode<<"单次投资单利计算利息"<<"单次投资复利计算利息"
                   <<"定期投资单利计算利息"<<"定期投资复利计算利息";
        ui->account_mode->clear();
        ui->account_mode->addItems(account_mode);
        ui->account_mode->setCurrentIndex(0);

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

        QIntValidator* time_period_validator = new QIntValidator ;
        time_period_validator->setRange(0,999);
        ui->time_period->setValidator(time_period_validator);
    }

    //数据合法性检查部分
    bool MainWindow::data_check()
    {
        if ( ui->present_value->displayText().toFloat() > 100000000. )
        {
            QMessageBox::information( NULL , "钱太多了" , "钱太多装不下了！" , QMessageBox::Ok , QMessageBox::Ok ) ;
            return 0 ;
        }
        if ( ui->interest_period_unit->currentText().operator ==("年") && ui->interest_period->displayText().toInt() > 1 )
        {
            QMessageBox::information( NULL , "太久不给利息了！" , "郁闷，一年都不给利息，人都快饿死了啊" , QMessageBox::Ok , QMessageBox::Ok ) ;
            return 0 ;
        }

        return 1 ;
    }


//运算部分
float MainWindow::single_interest(float present_value , short int interest_rate , short int interest_period ,
                                  short int interest_period_unit , short int time_period , short int time_period_unit)
{
    float final_value = present_value * ( interest_rate * interest_period / interest_period_unit) * time_period / time_period_unit ;
    return final_value ;
}

//float MainWindow::compound_interest(float present_value , int interest_rate , int interest_number )
//{

//}

//float MainWindow::append_single_interest(float present_value , int interest_rate , int interest_number )
//{

//}

//float MainWindow::append_compound_interest(float present_value , int interest_rate , int interest_number )
//{

//}

    //数据传出部分

