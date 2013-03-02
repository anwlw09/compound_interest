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
    bool data_check();

    float present_value_trim(QString present_value);
    float interest_rate_trim();
    float invest_period_trim();
    float automatic_investment_plan_value_trim(QString automatic_investment_plan_value);
    float automatic_investment_plan_period_trim(QString automatic_investment_plan_period,
                                                QString automatic_investment_plan_period_unit);
    unsigned char count_mode_trim(QString count_mode);
    float data_count(unsigned char count_mode, float present_value, float interest_rate, float invest_period,
                     float automatic_investment_plan_value, float automatic_investment_plan_period );
    void data_show(float final_value);
};

#endif // MAINWINDOW_H
