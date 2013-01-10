#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_quit_clicked()
{
    close();
}

float MainWindow::single_interest(float principal , int interest_rate , int interest_number )
{

}

float MainWindow::compound_interest(float principal , int interest_rate , int interest_number )
{

}

float MainWindow::append_single_interest(float principal , int interest_rate , int interest_number )
{

}

float MainWindow::append_compound_interest(float principal , int interest_rate , int interest_number )
{

}
