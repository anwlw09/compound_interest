#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QMessageBox>
#include <QDoubleValidator>

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
    float single_interest(float present_value , short int interest_rate , short int interest_period ,
                          short int interest_period_unit , short int time_period , short int time_period_unit);
    float compound_interest(float principal , int interest_rate , int interest_number );
    float append_single_interest(float principal , int interest_rate , int interest_number );
    float append_compound_interest(float principal , int interest_rate , int interest_number );
    bool data_check();
};

#endif // MAINWINDOW_H
