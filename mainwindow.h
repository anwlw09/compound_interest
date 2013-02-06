#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QMessageBox>
#include <QDoubleValidator>
#include <QTranslator>
#include <qmath.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
public slots:
   void on_quit_clicked();

private slots:
   void on_count_clicked();

   void on_about_clicked();

private:
    Ui::MainWindow *ui;
    void initialization_value();
    float data_count(unsigned char count_mode, float present_value, short interest_rate, short invest_period,
                                 float automatic_investment_plan_value, float automatic_investment_plan_period );
    bool data_check();
};

#endif // MAINWINDOW_H
