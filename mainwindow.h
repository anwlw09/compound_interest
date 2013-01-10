#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
    float single_interest(float principal , int interest_rate , int interest_number );
    float compound_interest(float principal , int interest_rate , int interest_number );
    float append_single_interest(float principal , int interest_rate , int interest_number );
    float append_compound_interest(float principal , int interest_rate , int interest_number );
};

#endif // MAINWINDOW_H
