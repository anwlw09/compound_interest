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
void MainWindow::on_quit_clicked()
{
    close();
}

void MainWindow::on_count_clicked()
{

}

    //数据传入部分
    //初始化界面数据
    void MainWindow::initialization_value()
    {
        //初始化计算模式
        QStringList account_mode;
        account_mode.clear();
        account_mode<<"单次投资单利计算利息"<<"单次投资复利计算利息"
                   <<"定期投资单利计算利息"<<"定期投资复利计算利息";
        ui->account_mode->clear();
        ui->account_mode->addItems(account_mode);
        ui->account_mode->setCurrentIndex(0);
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

